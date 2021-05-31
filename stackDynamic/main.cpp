#include <iostream>
#define SIZE 5

using namespace std;

struct node{
    int data;
    node* next;
};


struct stack{
    node* top=NULL;
    int counter=0;
};

bool isFull(stack *stk){return (stk->counter==SIZE);}

bool isEmpty(stack *stk){return (stk->counter==0);}

void push(stack * stk, int key){ //Dugum ekler
    node* eleman= new node();
    eleman->data=key;

    if(isFull(stk)){ //Stack doluysa
        cout << "Stack doludur!" << endl;}

    else if(isEmpty(stk)){ //Bos stack'e dugum ekleme
        stk->top=eleman;
        stk->top->next=NULL;
        cout << "Stack olusturuldu ve ilk dugum eklendi!" << endl;
        stk->counter++;}

    else{ //Stack ne bos ne de doluysa
        eleman->next=stk->top;
        stk->top=eleman;
        cout << eleman->data << " dugumu Stack'e eklendi!" << endl;
        stk->counter++;}

}

void pop(stack *stk){ //En ustteki dugumu siler yapar
    if(isEmpty(stk))
        cout << "Stack bos!" << endl;
    else{
        cout << stk->top->data << " degerini iceren dugum silindi!" << endl;
        node* temp= stk->top->next;
        delete stk->top;
        stk->top= temp;
        stk->counter--;}
}


void top(stack *stk){ //En ust degeri gosterir
    if(isEmpty(stk))
        cout << "Stack bos!" << endl;
    else{
        cout << "Stack'in en ustundeki deger: " << stk->top->data << endl;
}}


void print(stack *stk){ //Verileri yazdirir
    if(isEmpty(stk))
        cout << "Stack bos!" << endl;
    else{
        node* iter= stk->top;
        while(iter!=NULL){
            cout << iter->data << " -> ";
            iter=iter->next;}
    cout << endl;}

}

int main()
{
    stack stk;
    int sayi, secim;
    while(true){
        cout << "1- Push (Ekle)" << endl;
        cout << "2- Pop (Cikar)" << endl;
        cout << "3- Top (En ust)" << endl;
        cout << "4- Print (Yazdir)" << endl;
        cout << "5- Cikis" << endl;
        cout << "Yapmak istediginiz islemi seciniz: ";
        cin >> secim;
        switch(secim){
        case 1:
            cout << "Sayi giriniz: "; cin >> sayi;
            push(&stk,sayi);
            break;
        case 2:
            pop(&stk);
            break;
        case 3:
            top(&stk);
            break;
        case 4:
            print(&stk);
            break;
        case 5:
            cout << "Programdan cikiliyor..." << endl;
            return 0;
        default:
            cout << "Lutfen gecerli bir islem seciniz!" << endl;
            break;}

}
    return 0;
}
