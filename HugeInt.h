#ifndef HUGEINT_H
#define HUGEINT_H

#include<string>
#include<vector>

using namespace std;

class HugeInt{
    friend ostream &operator<<(ostream &, const HugeInt &);
    friend istream &operator>>(istream &, HugeInt &);
    friend HugeInt operator + (const HugeInt &,const HugeInt &);
    friend HugeInt operator - (const HugeInt &,const HugeInt &);
public:
    HugeInt();
    HugeInt(int);
    HugeInt(string);
    ~HugeInt();
private:
    int num;
    string number;
    vector<int> n;
};

#endif
