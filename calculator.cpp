#include <iostream>
using namespace std;
double factorial(int n){ //writing factorial function for using it in taylor series expansion
    double result =1;
    for(int i=2;i<=n;i++)
        result *= i;
    return result;      
    }
    double power(double base , int exp){//writing power function for using it in taylor series expansion(I was having doubts so i took some external help)
        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }
        return result;
    }
    double sin(double x){//sin function using taylor series formula
        double result=0;
        for(int i=0;i<10;i++)
        {
            int sign= (i%2==0)?1:-1;
            result =result +sign* power(x,2*i+1)/factorial(2*i+1);
        }
        return result;
    }
    double cos(double x) {//cos function using taylor series formula
        double result = 0;
        for (int i = 0; i < 10; i++) {
            int sign = (i % 2 == 0) ? 1 : -1;
            result += sign * power(x, 2 * i) / factorial(2 * i);
        }
        return result;
    }
    
    double tan(double x){
        return sin(x)/cos(x);
    }
    double logarithm(double x)//Logarithm function using taylor series formula
    {
        if(x<=0)
        {
            cout<<"Logarithm is undefined for zero and negative numbers. Please enter a number greater than zero."<<endl;
        }
        else{
            double result =0;
            for (int i = 1; i < 10; i++) {
            result += (power(x - 1, i) * (i % 2 == 0 ? -1 : 1)) / i;
            }
            return result;
        }
        return 0;
       //using the first 10 terms in sin , cos , tan and logarithm functions for approximation
    } 
    void  quadratic(double a , double b , double c)//for solving quadratic equations ax^2+bx+c
    {
        double discriminant = (b*b)-4*a*c;
        if(discriminant>0)
        {
            double r1 = (-b + power(discriminant, 0.5)) / (2 * a);
            double r2 = (-b - power(discriminant, 0.5)) / (2 * a);
            cout<<"The roots of the given quadratic equation are real and different"<<endl;
            cout<<"The roots are "<<r1<<"and "<<r2<<endl;
            
        }
        else if(discriminant==0)
        {
            double r=  -b/(2*a);
            cout<<"The roots of the given quadratic equation are real and same"<<endl;
            cout<<"The root of the equation is "<<r<<endl;

        }
        else{
            cout<<"The roots of the given equation are not real ";
        }
       
    }
int main()
{
    char operation;
    cout<<"Enter your operator"<<endl;
    cout<<"+ for addition"<<endl;
    cout<<"- for subtraction"<<endl;
    cout<<"/ for division"<<endl;
    cout<<"* for multiplication"<<endl;
    cout<<"l for logarithm "<<endl;
    cout<<"s for sin"<<endl;
    cout<<"c for cos"<<endl;
    cout<<"t for tan"<<endl;
    cout<<"q for solving a quadratic equation"<<endl;
    cin>> operation;
    double num1;
    double num2;
    double num3;
    if(operation=='+')
    {
        
        cout<<"Enter two numbers";
        cin>>num1>>num2;
        cout<<"The sum of these two numbers is "<<num1+num2<<endl;
    }
    else if(operation=='-')
    {
        cout<<"Enter two numbers";
        cin>>num1>>num2;
        cout<<"The difference of these two numbers is "<<num1-num2<<endl;
    }
    else if(operation =='*')
    {
        cout<<"Enter two numbers";
        cin>>num1>>num2;
        cout<<"The product of these two numbers is "<<num1*num2<<endl;
    }
    else if(operation=='/')
    {
        cout<<"Enter two numbers";
        cin>>num1>>num2;
        if(num2==0)
        {
            cout<<"The operation cannot be performed because division by zero is undefined";
        }
        else{
            cout<<num1<<" divided by "<<num2<<" is "<<num1/num2<<endl;
        }
    }
    else if(operation=='l')
    {
        cout<<"Enter a number ";
        
        cin>>num1;
        if(num1<=0)
        {
            cout<<"Invalid input";
        }
        else {
            double log = logarithm(num1);
            cout<<"Logarithm of "<<num1<<" is "<<log<<endl; 
        }
        

    } 
    else if(operation=='s')
    {
        cout<<"Enter an angle in radians";
        cin>>num1;
        double ans= sin(num1);
        cout<<"Sine of "<<num1<<" is "<<ans<<endl;
    }
    else if(operation=='c')
    {
        cout<<"Enter an angle in radians";
        cin>>num1;
        double ans1= cos(num1);
        cout<<"Cosine of "<<num1<<" is "<<ans1<<endl;
    }
    else if(operation =='t')
    {
        cout<<"Enter an angle in radians";
        cin>>num1;
        double ans2=tan(num1);
        cout<<"Tangent of "<<num1<<" is "<<ans2<<endl;
    }
    else if(operation=='q')
    {
        cout<<"Enter a,b,c in the quadratic equation ax^2+bx+c";
        cin>>num1>>num2>>num3;
        quadratic(num1 , num2 , num3);
    }
    return 0;
}







    

    



