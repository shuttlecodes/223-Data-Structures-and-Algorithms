//Open Problem2_v1
//Add a variable that counts how may time a function is called through the class

/*  C++ program to Count number of times a function is called  */

#include<iostream>
using namespace std;
class square
{
   private:
        int n,r; //private int
        float n1,r1; //private float
        int count=0;

    public:
        void input(); //public member functions
        void calc();
        void display();
        int getCount();
                
};
 void square::input()
{
        cout<<"Enter an integer:";
        cin>>n;
        cout<<"Enter a float no.:";
        cin>>n1;
        count++;
        
}
 void square::calc()
{
        r=n*n;
        r1=n1*n1;
        count++;
}
void square::display()
{
        cout<<"Square of integer:"<<r;
        cout<<"\nSquare of float:"<<r1<<endl;
        count++;
}

int square::getCount(){
    return count;
}

int main()
{
        square s;
        s.input();
        s.calc();
        s.display();

        cout << "A function is called " << s.getCount() << "times.";
        
}