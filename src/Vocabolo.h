#ifndef H_VOCABOLO
#define H_VOCABOLO

#include <string>

using namespace std;

class Vocabolo
{
private:
    string parola;
    int codice;
public:
    Vocabolo();
    void set(string p, int c);
    string get_parola();
    int get_codice();
};

#endif
