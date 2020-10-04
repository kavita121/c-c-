//Sieve of eratosthenes

#include<bits/stdc++.h>
#define ll long long

using namespace std;

void eratosthenes(vector<int> &prime)
{
    int i, j;
    for(i=2; i<=sqrt(prime.size()); i++)
    {
        if(prime[i] == 1)
        {
            for(j=2; i*j<=prime.size(); j++)
            {
                prime[j*i] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    n++;
    vector<int> prime(n,1);
    eratosthenes(prime);
    for(int i=2; i<n; i++)
        if(prime[i] == 1)
            cout<<i<<" ";
    return 0;
}
