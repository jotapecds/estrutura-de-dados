#include <stdio.h>
#include <stdlib.h>

struct NO {
	int info;
    int alt;
	struct NO *esq;
	struct NO *dir;
};

int maior(int x, int y);
int encontrar_altura(struct NO *no);
int encontrar_fator_de_balanceamento(struct NO *no);
struct NO* criar_novo_no(int info);
struct NO* rodar_no(struct NO *raiz, char direcao);
struct NO* inserir(struct NO* no, int info);
void atualizar_altura(struct NO **no);
void imprimeNo(struct NO *raiz);

int main(void){
    int info;
    struct NO *raiz = NULL;

    while (scanf("%d", &info) == 1)
      raiz = inserir(raiz, info);

    imprimeNo(raiz);

    return 0;
}

int maior(int x, int y){
	if(x > y) return x;
	else return y;
}

int encontrar_altura(struct NO *no){
	if (no == NULL)
		return 0;
	return no->alt;
}

int encontrar_fator_de_balanceamento(struct NO *no){
	if (no == NULL)
		return 0;
	return encontrar_altura(no->esq) - encontrar_altura(no->dir);
}

void atualizar_altura(struct NO **no){
	(*no)->alt = maior(encontrar_altura((*no)->esq), encontrar_altura((*no)->dir)) + 1;
	return;
}

struct NO* criar_novo_no(int info){
	struct NO *novo_no = (struct NO*) malloc(sizeof(struct NO));
	novo_no->info = info;
	novo_no->esq = NULL;
	novo_no->dir = NULL;
	novo_no->alt = 1;
	return(novo_no);
}

struct NO* rodar_no(struct NO *raiz, char direcao){
	struct NO *nova_raiz;
	struct NO *aux;

	if(direcao == 'd'){
		// Rotação à direita
		nova_raiz = raiz->esq;
		aux = nova_raiz->dir;

		nova_raiz->dir = raiz;
		raiz->esq = aux;
	}
	else{
		// Rotação à esquerda
		nova_raiz = raiz->dir;
		aux = nova_raiz->esq;

		nova_raiz->esq = raiz;
		raiz->dir = aux;
	}

	atualizar_altura(&raiz);
	atualizar_altura(&nova_raiz);

	return nova_raiz;
}

struct NO* inserir(struct NO* no, int info){
	if(no == NULL)
		return criar_novo_no(info);

	if(info < no->info)
		no->esq = inserir(no->esq, info);

	else if(info > no->info)
		no->dir = inserir(no->dir, info);

	else
		return no;

	atualizar_altura(&no);

	int fator_de_balanceamento = encontrar_fator_de_balanceamento(no);

	// Balanceamento LL
	if(fator_de_balanceamento > 1 && info < no->esq->info)
		return rodar_no(no, 'd');

	// Balanceamento RR
	if(fator_de_balanceamento < -1 && info > no->dir->info)
		return rodar_no(no, 'e');

	// Balanceamento LR
	if(fator_de_balanceamento > 1 && info > no->esq->info){
		no->esq = rodar_no(no->esq, 'e');
		return rodar_no(no, 'd');
	}

	// Balanceamento RL
	if(fator_de_balanceamento < -1 && info < no->dir->info){
		no->dir = rodar_no(no->dir, 'd');
		return rodar_no(no, 'e');
	}

	return no;
}

void imprimeNo(struct NO *raiz){
	if(raiz != NULL){
		printf("%d\n", raiz->info);
		imprimeNo(raiz->esq);
		imprimeNo(raiz->dir);
	}
}