#include <iostream>
#include <cassert>

using namespace std;

int GCD(int num1, int num2){
    int numSmall=(num1<num2)?num1:num2;
    int numBig=(num1<num2)?num2:num1;
    int numTemp=numBig%numSmall;
    while(numTemp!=0){
        numBig=numSmall;
        numSmall=numTemp;
        numTemp=numBig%numSmall;
    }
    return numSmall;
}

bool is_duffinian(int num) {
    int n=num;
    int divisorSum=0;
    for(int i=1; i<=num; i++){ 
        if(n%i==0){divisorSum+=i;}
    }
    if(divisorSum<=num+1){return false;}
    if(1==GCD(divisorSum,num)){return true;}
    else{return false;}
}

void test_duffinian() {
    assert(!is_duffinian(6));  // 6 is not a Duffinian number
    assert(is_duffinian(35));
    assert(!is_duffinian(12));
    assert(!is_duffinian(18));
    cout << "Duffinian number tests passed!" << endl;
}
