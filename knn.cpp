#include <bits/stdc++.h>
// #include<iostream>
// #include<cmath>
// #include<vector>
using namespace std;
class movie{
public:
int action;
int comedy;
char category;
movie(int action,int comedy , char category){
this-> action= action;
this-> comedy= comedy;
this-> category = category;
}
};
class closeness{
public:
float distance;
char category;
closeness(int action , int comedy, movie mknown){
distance = sqrt(pow(action - mknown.action ,2) + pow(comedy -
mknown.comedy, 2));
category = mknown.category;
}
};
int find_centroid(vector<movie> v , char m_type , char return_type){
int count;
pair<int, int> p;
p.first=0;
p.second =0;
for(int i=0; i< v.size(); i++){
if(v[i].category== m_type){
p.first += v[i].action;
p.second += v[i].comedy;
count++;
}
}
if (return_type=='x'){
return p.first/ count;
}
else{
return p.second/ count;
}

}

int main(){
vector<movie> movies;
vector<closeness> distance;
movie m1(100, 5, 'A');
movie m2(20, 90, 'C');
movie m3(95, 15, 'A');
movie m4(25, 110, 'C');
movies.push_back(m1);
movies.push_back(m2);
movies.push_back(m3);
movies.push_back(m4);
int n=1;
do{
if(n==1){
int action;
int comedy;
cout<<"Enter Action"<<endl;
cin>> action;
cout<<"Enter Comedy"<<endl;
cin>> comedy;
for (int i=0 ; i< movies.size(); i++){
closeness c(action , comedy , movies[i]);
distance.push_back(c);
}
int min= INT_MAX, max =INT_MIN; char cat_min , cat_max;
for (int i=0; i< distance.size(); i++){
if(distance[i].distance< min){
min = distance[i].distance;
cat_min = distance[i].category;
}
if(distance[i].distance> max){
max = distance[i].distance;
cat_max = distance[i].category;
}
}
if (cat_min != cat_max){
char category = cat_min;
cout<<category<<endl;
movie m(action, comedy , category);
movies.push_back(m);
}
else{
int centroid_c_x= find_centroid(movies , 'C', 'x');
int centroid_c_y= find_centroid(movies , 'C', 'y');

int centroid_a_x= find_centroid(movies , 'A', 'x');
int centroid_a_y= find_centroid(movies , 'A', 'y');
int distance1 = sqrt(pow(action - centroid_c_x ,2) + pow(comedy -

centroid_c_x, 2));

int distance2 = sqrt(pow(action - centroid_a_x ,2) + pow(comedy -

centroid_a_x, 2));

if(distance1< distance2){
cout<< "C"<<endl;
movie m(action , comedy, 'C');
movies.push_back(m);
}
else{
cout<< "A"<<endl;
movie m(action , comedy, 'A');
movies.push_back(m);
}

}
cout<<"DO YOU WANT TO ADD MORE DATA (1/0)"<<endl;
cin>> n;
}
else
return 0;
}while(n==1);
return 0;
}