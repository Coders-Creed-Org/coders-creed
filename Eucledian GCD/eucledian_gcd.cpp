#include <bits/stdc++.h>
using namespace std;

#define ll long long

//EXPLANATION: https://cp-algorithms.com/algebra/euclid-algorithm.html

//recursive
ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

//iterative
ll gcd1(ll a, ll b)
{
    while(b)
    {
        a = a%b;
        swap(a,b);
    }
    return a;
}

//bitwise operator using instead of %
ll binaryGcd(ll a, ll b)
{
    if(!a || !b) return a|b;//returns whichever is non zero
    unsigned shift = __builtin_ctz(a|b);//counting number of zeros to right of rightmost set bit
    a >>= __builtin_ctz(a); //removing all zeros from the right of rightmost set bit in a
    
    do{
        b >>= __builtin_ctz(b); 
        if(a>b) swap(a,b);
        
        b -= a;
    }while(b);
    
    return a<<shift;
}

ll lcm (ll a, ll b) {
    return a / binaryGcd(a, b) * b;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	
	while(t--)
	{
	    ll a, b;
	    cin>>a>>b;
	    cout<<gcd1(a,b)<<" "<<lcm(a,b)<<endl;
	}
	
	return 0;
}
