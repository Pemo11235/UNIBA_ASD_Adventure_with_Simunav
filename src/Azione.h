#ifndef H_AZIONE
#define H_AZIONE

using namespace std;

class Azione
{
private:
    int comando;
    int codice;
public:
    Azione();
    void set(int com, int cod);
    int get_codice();
    int get_comando();
};

#endif
