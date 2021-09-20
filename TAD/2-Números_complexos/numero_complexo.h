
struct numero_complexo
{
    double real;
    double imaginario;
};

typedef struct numero_complexo Numero_complexo;

Numero_complexo* cria_numero_complexo(double real, double imaginario);
void libera_numero_complexo(Numero_complexo* numero_complexo);

int atribui_numero_complexo(Numero_complexo* numero_complexo, double real, double imaginario);
void acessa_numero_complexo(Numero_complexo* numero_complexo);

Numero_complexo* soma_numero_complexo(Numero_complexo *a, Numero_complexo *b);
Numero_complexo* subtrai_numero_complexo(Numero_complexo *a, Numero_complexo *b);
Numero_complexo* multiplica_numero_complexo(Numero_complexo *a, Numero_complexo *b);
Numero_complexo* divide_numero_complexo(Numero_complexo *a, Numero_complexo *b);
