#include <iostream>
#include"myheader.h"
#include <Windows.h>
using namespace std;

void out_for_operation(){
    cout<<"Operation=1 Положить грязную посуду в машинку"<<endl<<
          "Operation=2 Положить чистую посуду в на полку"<<endl<<
          "Operation=3 Забрать посуду с полки и сделать ее грязной"<<endl<<
          "Введите операцию"<<endl;

}

int main()
{
        setlocale(LC_ALL, "");

        my_stack dirtydish;
        my_queue wash1;
        my_queue wash2 ;
        my_deque cleandish;

        int num;// число чтобы потом рандомно распределить посуду на полке
        int operation;//что сделать с посудой

        for(int i=0;i<7;i++){
            dirtydish.add(1);
            wash1.add(1);
            wash2.add(1);
        }

        out_for_operation();
        cin>>operation;

        switch(operation){

            case 1:{
            dirtydish.del();//удаляем грязную тарелку из стопки и ложим в машинку
            if(rand()%2==1)
                {wash1.add(1);}
            else{wash2.add(1);}break;
            }

            case 2:{
            if(wash1.empty() && wash2.empty())
                {cout<<"Машинки пустые";}
            else if(wash1.empty())
                {wash2.del();}
            else if(wash2.empty())
                {wash1.del();}
            else{
                if(rand()%2==1)
                    {wash1.del();}
                else{wash2.del();}
            }

            if(rand()%2==1)
                {cleandish.add_end(1);}
            else{cleandish.add_begin(1);}break;
            }

            case 3:{
            if(rand()%2==1)
                {cleandish.del_begin();}
            else{cleandish.del_end();}

            dirtydish.add(1);break;
            }
        }
	return 0;
}
