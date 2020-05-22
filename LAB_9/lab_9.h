#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Heap
{
    int* mas;//сами элементы
    int d;//размерность кучи(д куча)
    int size;
    void swap(int i,int j)  // меняет местами ключи вершин
    {
        int buf=mas[i];
        mas[i]=mas[j];
        mas[j]=buf;
    }
    void shiftUp(int i)  //используется для восстановления инварианта при уменьшении ключа
    {
        while(i>0)
        {
            if (mas[i]<mas[(int)floor((i-1)/d)])  //округление floor (int к какому типу)
            {
                swap(i,(int)floor((i-1)/d));//свап 2ч элементов кучи с восстановлением свойств
            }
            i--;
        }
    }
    void shiftDown(int i)  //используется для восстановления инварианта при увеличении ключа
    {
        while(i*d+1<size-1)
        {
            //Минимальный сын (левый) слева внизу
            int min=mas[i*d+1];
            int j=i*d+1; //индекс мин сына
            for (int r=2;r<=d;r++)
            {
                if (mas[i*d+r]<min)  //если элемент кучи меньше заданного минамального
                {
                    min=mas[i*d+r];// делаем его минимальным
                    j=i*d+r;//
                }
            }
            if(mas[i]>mas[j] && j<size)  //если элемент заданного массива больше, чем элемент массива
            {
                swap(i,j);//меняем их местами
            }
            i=j;
        }
    }
    void setHeap(int* mas1)  //строим кучу, передаем массив сохраняя всойства д кучи
    {
        for(int i=0;i<size;i++)
        {
            mas[i]=mas1[i];
            shiftUp(i);
        }
    }
public:
    Heap(int* mas,int d,int size)//конструктор
    {
        this->d=d;
        this->size=size;
        this->mas=new int[size];
        setHeap(mas);//строим кучу
    }
    ~Heap(){};
    void out() //вывод
    {
        int dep=depth(d,size);//уровни
        int j=1;
        if(d==3)
        {
            for(int i=0;i<=dep;i++)
                cout << "------";
            cout << "-----------------";
            cout<<mas[0]<<endl;
        }
        else
        {
            for(int i=0;i<=dep;i++)
                cout << "-----";
            cout<< "-" <<mas[0]<<endl;
        }
        for(int i=1;i<=dep;i++)
        {
            int count=0;
            for (;count!=pow(d,i);j++)
            {
                if (j<size)
                {
                    if(count==0)
                        for (int z=0;z<=dep*(dep-i);z++)
                            cout<<"--";
                    if (d==3 && (mas[j]==mas[1] || mas[j]==mas[2] || mas[j]==mas[3]))
                    {
                        cout<<"--"<<mas[j]<<"------------";
                    }
                    else
                        cout<<mas[j];

                }
                for (int z=0;z<=dep*(dep-i);z++)
                    cout<<"--";
                count++;
            }
            cout<<endl;
        }
    }
    int depth(int d,int m)//считаем уровни кучи
    {
        int length=0;
        for (int i=0;i<m;i++)
        {
            if (pow(d,i)<=m)
                length++;
        }
        return length;
    }
    void insert(int x) //вставка  элемента
    {
        mas[size]=x;
        shiftUp(size);
        size++;
    }
    void delete_min()//удаляем минималиный элемент
    {
        swap(0,size-1);
        size--;
        shiftDown(0);
    }
};
