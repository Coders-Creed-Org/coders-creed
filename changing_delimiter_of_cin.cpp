#include <bits/stdc++.h>
using namespace std;

//This is a sample program to take a line as input and print the length of the biggest word. '
//The words are separated by single spaces, so we will have to remove single space as delimiter(since it is by default delimiter of cin)


struct colon_is_space : std::ctype<char> {
colon_is_space() : std::ctype<char>(get_table()) {}
static mask const* get_table()
{
static mask rc[table_size];
rc[':'] = std::ctype_base::space;
rc['\n'] = std::ctype_base::space;  //any custom delimiter can be set here
return &rc[0];
}
};




int main(){

cin.imbue(locale(cin.getloc(), new colon_is_space));  //this is the function that we have to use

int n;
cin>>n;
char ar[n+1];
// cin.getline(ar,n+1);
// cin.ignore();
for(int i = 0;i<n+1;i++)
cin>>ar[i];

// for(auto i:ar)
// cout<<i;

int maxi=INT_MIN,len=0;

for(int i=0;i<n+1;i++){

if(ar[i]==' '|| ar[i]=='\0'){
maxi = max(maxi,len);
len=0;
}
else{
len++;
}
}
cout<<max(maxi,len)<<endl;
return 0;}