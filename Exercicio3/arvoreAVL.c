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
struct NO* rodar_a_direita(struct NO *y);
struct NO *rodar_a_esquerda(struct NO *x);
struct NO* inserir(struct NO* no, int info);
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
	return (x > y)? x : y;
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

struct NO* criar_novo_no(int info){
	struct NO *novo_no = (struct NO*) malloc(sizeof(struct NO));
	novo_no->info = info;
	novo_no->esq = NULL;
	novo_no->dir = NULL;
	novo_no->alt = 1; // o novo nó é inicialmente alocado como uma folha
	return(novo_no);
}

struct NO* rodar_a_direita(struct NO *y){
	struct NO *x = y->esq;
	struct NO *T2 = x->dir;

	x->dir = y;
	y->esq = T2;

	y->alt = maior(encontrar_altura(y->esq), encontrar_altura(y->dir))+1;
	x->alt = maior(encontrar_altura(x->esq), encontrar_altura(x->dir))+1;

	return x;
}

struct NO *rodar_a_esquerda(struct NO *x){
	struct NO *y = x->dir;
	struct NO *T2 = y->esq;

	y->esq = x;
	x->dir = T2;

	x->alt = maior(encontrar_altura(x->esq), encontrar_altura(x->dir))+1;
	y->alt = maior(encontrar_altura(y->esq), encontrar_altura(y->dir))+1;

	return y;
}

struct NO* inserir(struct NO* no, int info){
	if (no == NULL)
		return(criar_novo_no(info));

	if (info < no->info)
		no->esq = inserir(no->esq, info);
	else if (info > no->info)
		no->dir = inserir(no->dir, info);
	else // Equal keys are not allowed in BST
		return no;

	// Atualiza a altura do nó ancestral
	no->alt = 1 + maior(encontrar_altura(no->esq), encontrar_altura(no->dir));

	int fator_de_balanceamento = encontrar_fator_de_balanceamento(no);

	// Balanceamento LL
	if (fator_de_balanceamento > 1 && info < no->esq->info)
		return rodar_a_direita(no);

	// Balanceamento RR
	if (fator_de_balanceamento < -1 && info > no->dir->info)
		return rodar_a_esquerda(no);

	// Balanceamento LR
	if (fator_de_balanceamento > 1 && info > no->esq->info){
		no->esq = rodar_a_esquerda(no->esq);
		return rodar_a_direita(no);
	}

	// Balanceamento RL
	if (fator_de_balanceamento < -1 && info < no->dir->info){
		no->dir = rodar_a_direita(no->dir);
		return rodar_a_esquerda(no);
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
