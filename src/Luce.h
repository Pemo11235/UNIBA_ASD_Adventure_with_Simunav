#ifndef LUCE_H
#define LUCE_H

#include <string>
#include <iostream>

using namespace std;

class Luce
{
public:
    Luce();
    virtual ~Luce();
    string getNome();
    void setNome(string Nome);
    bool operator==(const Luce& l) const;
    bool operator!=(const Luce& l) const;
    bool operator<(const Luce& l) const;
    bool operator<=(const Luce& l) const;
    friend ostream& operator<<(ostream& os, const Luce& luc); //OVERLOAD OPERATORE COUT
protected:

private:
    string nomeLuce;
};

#endif // LUCE_H
