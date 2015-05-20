#include"HugeInt.h"
#include<iostream>
#include<string>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<iomanip>

using namespace std;

istream &operator >> (istream &in, HugeInt &num){
    in>>num.number;
    int t=num.number.size();
    num.n.resize(t);
    for(int i=0,j=t;i<t,j>0;j--,i++){
        num.n[i]=num.number[j-1]-48;
    }
    return in;
}

ostream &operator << (ostream &out, const HugeInt &num){
    for(int i=num.n.size();i>0;i--){
        out<<num.n[i-1];
    }
    return out;
}

HugeInt operator + (const HugeInt &left,const HugeInt &right){
    HugeInt sum;
    int large,small;
    int size_left=left.n.size();
    int size_right=right.n.size();
    if(size_left>size_right){
        large=size_left;
        small=size_right;
    }
    else{
        large=size_right;
        small=size_left;
    }
    if(size_left==size_right){
        large=size_left;
        small=large;
        if((left.n[size_left-1]+right.n[size_right-1])>=10)
            sum.n.resize(large+1);
        else
            sum.n.resize(large);
    }
    else
        sum.n.resize(large);
    int i=0;
    for(;i<small;i++){
        if((left.n[i]+right.n[i])>=10){
            sum.n[i]=sum.n[i]+left.n[i]+right.n[i]-10;
            sum.n[i+1]++;
        }
        else
            sum.n[i]=sum.n[i]+left.n[i]+right.n[i];
    }
    if (large==size_right){
        for(;i<large;i++)
            sum.n[i]+=right.n[i];
    }
    else
        for(;i<large;i++)
            sum.n[i]+=left.n[i];
    return sum;
}

HugeInt operator - (const HugeInt &left, const HugeInt &right){
    HugeInt sum;
    int large,small;
    int size_left=left.n.size();
    int size_right=right.n.size();
    if(size_left>size_right){
        large=size_left;
        small=size_right;
    }
    else{
        large=size_right;
        small=size_left;
    }
    if(size_left==size_right){
        if(left.n[size_left-1]<right.n[size_right-1]){
            large=size_right;
            size_left--;
        }
        else
            large=size_left;
        small=large;
        if(left.n[size_left-1]==right.n[size_right-1]||(left.n[size_left-1]*10+left.n[size_left-2]-right.n[size_right-1])/10==0)
            sum.n.resize(large-1);
        else
            sum.n.resize(large);
    }
    else
        sum.n.resize(large);
    if(large==size_left){
        int i=0;
        for(;i<small;i++){
            if((sum.n[i]+left.n[i]-right.n[i])<0){
                sum.n[i]=sum.n[i]+(10-right.n[i])+left.n[i];
                sum.n[i+1]--;
            }
            else
                sum.n[i]=sum.n[i]+left.n[i]-right.n[i];
        }
        for(;i<large;i++)
            sum.n[i]+=left.n[i];
    }
    else if (large==size_right){
        if(large==small){
            
        }
        int i=0;
        for(;i<small;i++){
            if((sum.n[i]+right.n[i]-left.n[i])<0){
                sum.n[i]=sum.n[i]+(10-left.n[i])+right.n[i];
                sum.n[i+1]--;
            }
            else
                sum.n[i]=sum.n[i]+right.n[i]-left.n[i];
            if(small==large||i==small-1)
                sum.n[i]*=(-1);
        }
        for(;i<large;i++){
            sum.n[i]+=right.n[i];
            if(i==(large-1)){
                sum.n[i]*=(-1);
            }
        }
    }
    return sum;
}

HugeInt::HugeInt():num(0){}

HugeInt::HugeInt(int nu):num(nu){
    int i=0;
    while(num/pow(10,i)>1){
        i++;
    }
    n.resize(i);
    for(int j=0;j<i;j++){
        if(j==0)
            n[j]=num%10;
        else{
            int temp=pow(10,j+1);
            n[j]=floor((num % temp)/pow(10,j));
        }
    }
}


HugeInt::HugeInt(string s){
    int t=s.size();
    n.resize(t);
    for(int i=0,j=t;i<t,j>0;j--,i++){
        n[i]=s[j-1]-48;
    }
}

HugeInt::~HugeInt(){}

