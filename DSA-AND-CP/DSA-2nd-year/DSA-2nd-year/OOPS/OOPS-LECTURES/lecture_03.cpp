// oops-classes and objects
// class-->extension of structures(in c)
// structures had limitations
//            -members are public
//            -no methods
// classes-->structures+more
// classes-->can have methods and properties
// classes-->can make few memvers as private &few as public
// you can declare objects along with the class declaration like this:
/*class employee{
   class definition
}harry,rohan,lovish; */
// harry.salary=8l makes no sense if salary is private
#include <bits/stdc++.h>
using namespace std;
class binary
{
private:
    string s;
    void chk_bin(void);

public:
    void read(void);
    void ones_compliment(void);
    void display(void);
};
void binary::read(void)
{
    cout << "enter a binary number" << endl;
    cin >> s;
}
void binary::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            cout << "incorrect binary format" << endl;
            exit(0);
        }
    }
}
void binary::ones_compliment(void)
{
    chk_bin();
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) ='1';
        }
        else
        {
            s.at(i) ='0';
        }
    }
}
void binary::display(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}
int main()
{
    // Nesting of member functions
    binary b;
    b.read();
    b.display();
    b.ones_compliment();
    b.display();
    return 0;
}