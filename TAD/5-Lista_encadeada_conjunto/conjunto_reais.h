typedef struct conjuntoReais ConjuntoReais;

ConjuntoReais* criarConjunto(float valor);
ConjuntoReais* AlocarConjunto();
int ehVazio(ConjuntoReais* PrimeiroTermo); //usa
int existe(ConjuntoReais* primeiroTermo, float valor); //usa
void limpa(ConjuntoReais** primeiroTermo); //usa
int remover(ConjuntoReais** primeiroTermo, float valor); //usa
int insereOrdem(ConjuntoReais** primeiroTermo, float valor); //usa
ConjuntoReais* uniao(ConjuntoReais* primeiroTermo1, ConjuntoReais* primeiroTermo2);
ConjuntoReais* intercessao(ConjuntoReais* primeiroTermo1, ConjuntoReais* primeiroTermo2);
int igualdade(ConjuntoReais* primeiroTermo1, ConjuntoReais* primeiroTermo2);
int tamanho(ConjuntoReais* primeiroTermo);
void printConjunto(ConjuntoReais* primeiroTermo, char* mensagem);