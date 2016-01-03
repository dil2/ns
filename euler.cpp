    /*
     * C++ Program to Implement Euler Theorem
     */

  #include<iostream>
using namespace std;

// A naive method to find modulor multiplicative inverse of
// 'a' under modulo 'm'
int modInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}

// Driver Program
int main()
{
    int a, m ;
    cout<<"Enter number to find modular multiplicative inverse: ";
    cin>>a;
    cout<<"Enter Modular Value: ";
    cin>>m;
    cout << modInverse(a, m);
    return 0;
}
