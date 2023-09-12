
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* auxiliar = primeiro;
	while (auxiliar != NULL) {
		if (auxiliar->valor == novo->valor) {
			cout << "Valor duplicado. Por favor, insira um valor diferente." << endl;
			return;
		}
		auxiliar = auxiliar->prox;
	}

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		NO* auxiliar = primeiro;
		while (auxiliar->prox != NULL) {
			auxiliar = auxiliar->prox;
		}
		auxiliar->prox = novo;
	}
}


void excluirElemento() {
	
	int valor;
	cout << "Digite o valor que você quer excluir: ";
	cin >> valor;

	NO* anterior = NULL;
	NO* atual = primeiro;

	while (atual != NULL) {
		if (atual->valor == valor) {
			if (anterior == NULL) {
				primeiro = atual->prox;
			}
			else {
				anterior->prox = atual->prox;
			}
			delete atual;
			cout << "O elemento " << valor << " excluído com sucesso." << endl;
			return;
		}
		anterior = atual;
		atual = atual->prox;
	}

	cout << "O elemento " << valor << " não encontrado na lista." << endl;
}


void buscarElemento() {
	
	int valor;
	cout << "Digite o valor que você quer procurar: ";
	cin >> valor;

	NO* encontrado = posicaoElemento(valor);
	if (encontrado != NULL) {
		cout << "O elemento " << valor << " foi encontrado na lista." << endl;
	}
	else {
		cout << "O elemento " << valor << "nao foi encontrado na lista." << endl;
	}
}

// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}
