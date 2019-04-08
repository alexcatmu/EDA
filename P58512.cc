#include <iostream>

using namespace std;

double exponent(double n, int k){
    if(k == 0) return 1;
    else{
        double y = exponent(n, k/2);
        if(k % 2 == 0) return (y*y);
        else return (y*y*n);
    }
}

int interest_rates(int day_min, int day_max, double money, double charge_daily, double interest){
    //cout << day_min << " " << day_max << endl;
    if(day_min <= day_max){
        int middle = (day_max + day_min)/2;
        double bank_interest = exponent(interest, middle)*money;
        double obokaman_interest = charge_daily * middle + money;
        if(obokaman_interest > bank_interest) return interest_rates(middle+1, day_max, money, charge_daily, interest);
        else if(obokaman_interest < bank_interest) return interest_rates(day_min, middle-1, money, charge_daily, interest);
        else return middle;
    }
    else return day_min;
}

int main(){
    double m, f, r;
    while(cin >> m >> f >> r){
        double interest_bank = r/100 +1;
        cout << interest_rates(1, 100000000, m, f, interest_bank) << endl;
    }
}
