#ifndef RISPOSTA_H_
#define RISPOSTA_H_
#include <iostream>
#include <string>

using namespace std;

class risposta
{
public:
    risposta();
    ~risposta();
    void set_risp(string);
    void set_esatto(bool);
    string get_risp();
    bool get_esatto();

public:
    string risp;
    bool esatto;
    void operator = (risposta);
};

#endif // RISPOSTA_H_
