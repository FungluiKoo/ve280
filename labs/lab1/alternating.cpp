#include <iostream>
#include <cassert>

using namespace std;

bool is_alternating(int num, int base) {
    int n=num;
    int num2=0; //to be the inversed-digit number
    while(n>0){
        num2= num2*base + n%base; //gradually, the least significant bit will become the most significant
        n/=base;
    }
    if(num2==num){return true;} //yes
    else{return false;} //no
}

void test_alternating() {
    assert(!is_alternating(24, 10));  // 24 is not an alternating number in base 10
    assert(is_alternating(645, 2));
    assert(!is_alternating(24, 8));
    assert(!is_alternating(24, 16));
    cout << "Alternating number tests passed!" << endl;
}
