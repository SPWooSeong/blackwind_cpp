#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    int coin_array[6] = {0, 0, 0, 0, 0, 0}; // the number of 1₩, 5₩, 10₩, 50₩, 100₩, 500₩ in sequence
    int banknote_array[4] = {0, 0, 0, 0}; // the number of 1000₩, 5000₩, 10000₩, 50000₩ in sequence
    string cards[6] = {};
public:
    Wallet();
    int getCountCoins();
    int getCountBanknotes();
    int getCountCards();
    int sumCoins();
    int sumBanknotes();
    int getMoney();
    void getCards();
    void addMoney(int unit, int amount);
    void useMoney(int uint, int amount);
    void changeCard(string cardName, bool isAdd);
};

//-------IMPLEMENT HERE---------
Wallet::Wallet(){

}
int Wallet::getCountCoins(){
    int sum = 0;
    for (int i =0; i<6;i++){
        sum += coin_array[i];
    }
    return sum;
}
int Wallet::getCountBanknotes(){
    int sum = 0;
    for (int i =0; i<4;i++){
        sum += banknote_array[i];
    }
    return sum;
}
int Wallet::getCountCards(){
    int sum=0;
    for (int i =0;i<6;i++){
        if (cards[i] != ""){
            ++sum;
        }
    }
    return sum;
}
int Wallet::sumCoins(){
    int sum=0;
    sum += coin_array[0]*1;
    sum += coin_array[1]*5;
    sum += coin_array[2]*10;
    sum += coin_array[3]*50;
    sum += coin_array[4]*100;
    sum += coin_array[5]*500;
    return sum;
}
int Wallet::sumBanknotes(){
    int sum=0;
    sum += banknote_array[0]*1000;
    sum += banknote_array[1]*5000;
    sum += banknote_array[2]*10000;
    sum += banknote_array[3]*50000;
    return sum;
}
int Wallet::getMoney(){
    int sum=0;
    sum = sumCoins() + sumBanknotes();
    return sum;
}
void Wallet::getCards(){
    for (int i=0;i<6;i++){
        if (cards[i] != ""){
            cout << cards[i]<<" ";
        }
    }
    cout <<"\n";
}
void Wallet::addMoney(int unit, int amount){
    switch (unit)
    {
        case 1:
            coin_array[0]+=amount;
            break;
        case 5:
            coin_array[1]+=amount;
            break;
        case 10:
            coin_array[2]+=amount;
            break;
        case 50:
            coin_array[3]+=amount;
            break;
        case 100:
            coin_array[4]+=amount;
            break;
        case 500:
            coin_array[5]+=amount;
            break;
        case 1000:
            banknote_array[0]+=amount;
            break;
        case 5000:
            banknote_array[1]+=amount;
            break;
        case 10000:
            banknote_array[2]+=amount;
            break;
        case 50000:
            banknote_array[3]+=amount;
            break;
        default:
            cout <<"Unknown";
            break;
    }
}
void Wallet::useMoney(int unit, int amount){
    switch (unit)
    {
        case 1:
            coin_array[0]-=amount;
            break;
        case 5:
            coin_array[1]-=amount;
            break;
        case 10:
            coin_array[2]-=amount;
            break;
        case 50:
            coin_array[3]-=amount;
            break;
        case 100:
            coin_array[4]-=amount;
            break;
        case 500:
            coin_array[5]-=amount;
            break;
        case 1000:
            banknote_array[0]-=amount;
            break;
        case 5000:
            banknote_array[1]-=amount;
            break;
        case 10000:
            banknote_array[2]-=amount;
            break;
        case 50000:
            banknote_array[3]-=amount;
            break;
        default:
            cout <<"Unknown";
            break;
    }
}
void Wallet::changeCard(string cardName, bool isAdd){
    if (isAdd ==1){
        int yesCard =0;
        for (int i=0; i<6; i++){
            if (cards[i]==cardName){
                cout<<"Error: Cardname Duplicated"<<endl;
                return;
            }
        }
        for (int i=0; i<6; i++){
            if (cards[i]==""){
                break;
            }
            yesCard++;
        }
        if (yesCard ==6){
            cout<<"Error: The number of card is already 6"<<endl;
            return;
        }
        for (int i=0; i<6; i++){
            if (cards[i] ==""){
                cards[i] = cardName;
                break;
            }
        }
    }
    else if (isAdd ==0){
        int noCard =0;
        for (int i=0; i<6; i++)
        {
            if (cards[i]=="") noCard++;
        }
        if (noCard==6){
            cout<<"Error: No Card"<<endl;
            return;
        }
        for (int i=0; i<6; i++){
            if (cards[i] == cardName){
                cards[i] = "";
                return;
            }
        }
        cout<<"Error: Card not found"<<endl;

    }
}
//-------IMPLEMENT HERE---------


int main() {
    Wallet myWallet;
    myWallet.addMoney(1000, 5);
    myWallet.changeCard("carddd1", 0);
    cout << myWallet.sumBanknotes() << endl;
    myWallet.addMoney(500, 2);
    myWallet.useMoney(1000, 2);
    cout << myWallet.getMoney() << endl;
    myWallet.getCards();

    return 0;
}