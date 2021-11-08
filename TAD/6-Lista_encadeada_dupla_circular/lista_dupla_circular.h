typedef struct listaDuplaCircular ListaDuplaCircular;

ListaDuplaCircular* criarLista(int valor);
int ehVazio(ListaDuplaCircular* PrimeiroTermo);
int insereInicio(ListaDuplaCircular** primeiroTermo, int valor);
int insereFim(ListaDuplaCircular** primeiroTermo, int valor);
int existe(ListaDuplaCircular* primeiroTermo, int valor);
void printLista(ListaDuplaCircular* primeiroTermo, char* mensagem);
void limpa(ListaDuplaCircular** primeiroTermo);
int remover(ListaDuplaCircular** primeiroTermo, int valor);
int insereOrdem(ListaDuplaCircular** primeiroTermo, int valor)