#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

void Fusion(int *T, int a, int b, int m){
  int i,j,k=0,tp,td;
  int P[100],D[100];

  for (i=a;i<=m;i++){
    P[k]=T[i];
    k++;
  }

  tp=k;
  k=0;

  for (i=m+1;i<b;i++){
    D[k]=T[i];
    k++;
  }

  td=k;
  k=0;

  i=0;
  j=0;

  while ((i<tp) && (j<td)){
    if (P[i]<D[j]){
      T[k]=P[i];
      k++;
      i++;
    }
    else {
      T[k]=D[j];
      k++;
      j++;
    }
  }
  while (i<tp){
    T[k]=P[i];
    k++;
    i++;
  }
  while (j<td){
    T[k]=D[j];
    k++;
    j++;
  }


}

/*
int m=(a+b)/2;
cout<<"avant appel partitionnement"<<" a: "<<a<<" | b : "<<b<<" | T : "<<T<<endl;
tri_fusion_rec(T,a,m);
cout<<"apres appel partitionnement"<<" a: "<<a<<" | b : "<<b<<" | m : "<<m<<" | T : "<<T<<endl;
cout<<"appel tri_rapide à gauche"<<" a : "<<a<<" | m-1 : "<<m-1<<endl;
tri_fusion_rec(T,m+1,b);
cout<<"appel tri_rapide à droite "<<" m+1 "<<m+1<<" | b : "<<b<<endl;
Fusion(T,a,b,m);
*/

void tri_fusion_rec(int *T,int a,int b)
        {
        if (a<b)
            {
            int m=(a+b)/2;
            cout<<"appel tri_fusion: "<<" a: "<<a<<" | b : "<<m<<endl;
            tri_fusion_rec(T,a,m);
            cout<<"appel tri_fusion: "<<" a: "<<m+1<<" | b : "<<b<<endl;
            tri_fusion_rec(T,m+1,b);
            cout<<"fusion: "<<" a "<<a<<" m : "<<m<<" | b : "<<b<<endl;
            Fusion(T,a,b,m);
            }
        }


void TriFusion(int *T,int b,int a)
{
     if (b>0)
        {
            tri_fusion_rec(T,a,b-1);
        }
}


int main (){

//---------------------------------------------------
/*
cout<<"---------Test fonction Fusion----------"<<endl;
int T[100]={1,3,6,8,10,13,2,4,5,12,14};
for (int i=0;i<11;i++){
  cout<<T[i]<<",";
}
Fusion(T,0,11,5);
cout<<"Après Tri : "<<endl;
for (int i=0;i<11;i++){
  cout<<T[i]<<",";
}
cout<<endl;
cout<<"Tableau à trier : "<<endl;
*/
//-----------------------------------------------------

int b= 13, a = 0,m;
int P[100]={2,5,1,18,3,8,16,18,9,7,4,0,12};
for (int i=0;i<b;i++){
  cout<<P[i]<<",";
}
cout<<endl;


  TriFusion(P,b,a);

for (int i=0;i<b;i++){
  cout<<P[i]<<",";
}


}
