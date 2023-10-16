/// update_1.1 : can now calculate complex roots for quadratic equations
#include <stdio.h>
#include <stdlib.h>  /// for library function {system("cls"),}
#include <math.h>    /// for library function {sqrt(), sin(), asin() etc.}

/// Macros
#define PI 3.141592653589793


/// Global Variables
int choice;
char ch;
double n;

/// Structure
struct developer_info{
    int serial;
    char developer_name[1005], developer_id[1005],developer_section[1005];
};

/// File for calculation history
FILE *calculation_history;

/// list of all functions prototype
void show_name(char *name);                 /// show name
void about_developers();                    /// about developers
void main_menu();                           /// show main menu
void basic_menu();                          /// show basic menu
void scientific_menu();                     /// show scientific menu
void logarithm();                           /// show logarithm sub menu
void trigonometry();                        /// show trigonometry sub menu
void solve_equation();                      /// show solve equation sub menu
void quadratic_equation();                  /// function for solving quadratic equation
void simultaneous_equation();               /// function for solving simultaneous equation
void advance_calculations();                /// show advance calculation sub menu
double addition(double sum, double n);      /// function for addition
double subtraction(double sub, double n);   /// function for subtraction
double multiplication(double n1, double n2);/// function for multiplication
double division(double n1, double n2);      /// function for division
double percentage(double n1, double n2);    /// function for determining percentage
double square(double n);                    /// function for calculating square
double sq_root(double n);                   /// function for calculating square root
double __log(double n);                     /// function for calculating log
double __ln(double n);                      /// function for calculating ln
double __sin(double n);                     /// function for calculating sin
double __cos(double n);                     /// function for calculating cos
double __tan(double n);                     /// function for calculating tan
double __asin(double n);                    /// function for calculating sin inverse
double __acos(double n);                    /// function for calculating cos inverse
double __atan(double n);                    /// function for calculating tan inverse
long long int factorial(int n);             /// function for calculating factorial
long long int permutation(int n, int r);    /// function for calculating nPr
long long int combination(int n, int r);    /// function for calculating nCr
double celsius_to_farenheit(double t);      /// function for calculating farenheit temperature
double farenheit_to_celsius(double t);      /// function for calculating celsius temperature


/// start of execution from main function

int main()
{

    calculation_history = fopen("calculation_history.txt","a+");

    if(calculation_history == NULL){
        printf("\n\t\t\t\t\tError Opening File.\n");
        return 0;
    }

    main_menu();

    fclose(calculation_history);

    return 0;
}


/// show name
void show_name(char *name){

    int len=strlen(name),space=(41-len)/2;
    printf("\n\n\t\t\t\t|***************************************|\n");
    printf("\t\t\t\t|");
    for(int i=1;i<=space-1;i++){
        printf(" ");
    }
    printf("%s",name);
    if(len%2==0) ++space;
    for(int i=1;i<=space;i++){
        if(i==space) printf("|\n");
        else printf(" ");

    }
    printf("\t\t\t\t|***************************************|\n");

}

/// show main menu
void main_menu()
{
    /// Local Variables

    show_name("CALCULATOR");
    printf("\n\t\t\t\t1. Basic Calculator\n");
    printf("\n\t\t\t\t2. Scientific Calculator\n");
    printf("\n\t\t\t\t3. About Developers\n");
    printf("\n\t\t\t\t-----------------------------------------\n\n");
    printf("\t\t\t\tChoose what you want(1-3): ");
    scanf("%d", &choice);

    switch(choice){
        case 1:{
            system("cls");
            basic_menu();
            break;
        }
        case 2:{
            system("cls");
            scientific_menu();
            break;
        }
        case 3:{
            system("cls");
            about_developers();
            break;
        }
        default:{
            printf("\n\n\t\t\t\tInvalid Choice!!!\n");
            printf("\n\t\t\t\tPress enter to choose again....");
            fflush(stdin);
            getchar();
            system("cls");
            main_menu();
        }

    }

}

/// about developers
void about_developers(){
    struct developer_info info[3]={
        {1,"Mohammad Tasnim Ahmed","0242310005101524","64_C"},
        {2,"S. M. Mahbub Rahman","0242310005101943","64_C"},
        {3,"Sabbir Sharif","0242310005101832","64_C"}
    };
    show_name("ABOUT DEVELOPERS");
    for(int i=0;i<3;i++){
        printf("\n\t\t\t\t%02d.\n\t\t\t\tName : %s\n\t\t\t\tID : %s\n\t\t\t\tSection : %s\n\t\t\t\tDept. of Computer Science & Enginerring\n\t\t\t\tDaffodil International University\n",info[i].serial,info[i].developer_name,info[i].developer_id,info[i].developer_section);
    }
    printf("\n\n\t\t\t\tPress enter to go main menu....");
    fflush(stdin);
    getchar();
    system("cls");
    main_menu();
}


/// show basic menu
void basic_menu()
{
    /// Local Variables
    int n;

    show_name("BASIC MENU");

    printf("\n\t\t\t\tChoose Operation: \n\n");
    printf("\t\t\t\t1. Addition\n\n");
    printf("\t\t\t\t2. Subtraction\n\n");
    printf("\t\t\t\t3. Multiplication\n\n");
    printf("\t\t\t\t4. Division\n\n");
    printf("\t\t\t\t5. Percentage\n\n");
    printf("\t\t\t\t0. Go to main menu\n\n");
    printf("\t\t\t\tYour choice(0-5): ");

    scanf("%d", &choice);

    switch (choice)
    {

        case 0:
        {
            system("cls");
            main_menu();
        }

        case 1:
        {
            system("cls");
            show_name("ADDITION");
            printf("\n\t\t\t\tEnter Values (1+2+3+4=): \n");
            double sum=0,x;
            printf("\n\t\t\t\t");
            while(1){
                scanf("%lf %c",&x,&ch);
                 if(ch=='+') sum=addition(sum,x);
                 else if(ch=='='){
                    sum=addition(sum,x);
                    break;
                 }
            }
            printf("\n\t\t\t\tThe Summation is = %.6lf\n\n", sum);
            fflush(stdin);
            do{
                printf("\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    basic_menu();
                }
                else{
                    system("cls");
                    main_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        case 2:
        {
            system("cls");
            show_name("SUBTRACTION");
            printf("\n\t\t\t\tEnter Values (1-2-3-4=): \n");
            double sub=0,x,flag=0;
            printf("\n\t\t\t\t");
            while(1){
                 scanf("%lf %c",&x,&ch);
                 if(!flag){
                    sub=x;
                    flag=1;
                    continue;
                 }
                 if(ch=='-') sub=subtraction(sub,x);
                 else if(ch=='='){
                    sub=subtraction(sub,x);
                    break;
                 }
            }
            printf("\n\t\t\t\tThe subtraction is = %.6lf\n\n", sub);
            fflush(stdin);
            do{
                printf("\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    basic_menu();
                }
                else{
                    system("cls");
                    main_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        case 3:
        {
            system("cls");
            show_name("MULTIPLICATION");
            double n1, n2;
            printf("\n\t\t\t\tEnter first value: ");
            scanf("%lf", &n1);
            printf("\n\t\t\t\tEnter second value: ");
            scanf("%lf", &n2);
            double result = multiplication(n1, n2);

            printf("\n\t\t\t\t%.2lf X %.2lf = %lf\n\n",n1,n2,result);
            fprintf(calculation_history,"%.2lf X %.2lf = %lf\n\n",n1,n2,result);
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    basic_menu();
                }
                else{
                    system("cls");
                    main_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        case 4:
        {
            system("cls");
            show_name("DIVISON");
            double n1, n2;
            printf("\n\t\t\t\tEnter first value: ");
            scanf("%lf", &n1);
            printf("\n\t\t\t\tEnter second value: ");
            scanf("%lf", &n2);
            if(n2==0){
                printf("\n\t\t\t\tInvalid!!!:(\n");
            }
            else{
                double result = division(n1, n2);
                printf("\n\t\t\t\t%.2lf / %.2lf = %lf\n\n",n1,n2,result);
                fprintf(calculation_history,"%.2lf / %.2lf = %lf\n\n",n1,n2,result);
                fflush(calculation_history);
            }
            fflush(stdin);
            do{
                printf("\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    basic_menu();
                }
                else{
                    system("cls");
                    main_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        case 5:
        {
            system("cls");
            show_name("PERCENTAGE");
            double n1, n2;
            printf("\n\t\t\t\tEnter a value: ");
            scanf("%lf", &n1);
            printf("\n\t\t\t\tEnter precentage value: ");
            scanf("%lf", &n2);
            double result = percentage(n1, n2);
            printf("\n\t\t\t\t%.2lf %% %.2lf = %lf\n\n",n1,n2,result);
            fprintf(calculation_history,"%.2lf %% %.2lf = %lf\n\n",n1,n2,result);
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    basic_menu();
                }
                else{
                    system("cls");
                    main_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        default:
            {
            printf("\n\n\t\t\t\tInvalid Choice!!!\n");
            printf("\n\t\t\t\tPress enter to choose again....");
            fflush(stdin);
            getchar();
            system("cls");
            basic_menu();
        }

    }
}


/// show scientific menu
void scientific_menu()
{
    show_name("SCIENTIFIC MENU");

    printf("\n\t\t\t\tChoose Operation: \n\n");
    printf("\t\t\t\t1. Square\n\n");
    printf("\t\t\t\t2. Square Root\n\n");
    printf("\t\t\t\t3. Logarithm\n\n");
    printf("\t\t\t\t4. Trigonometry\n\n");
    printf("\t\t\t\t5. Equation Solver\n\n");
    printf("\t\t\t\t6. Advance Calculations\n\n");
    printf("\t\t\t\t0. Go to main menu\n\n");
    printf("\t\t\t\tYour choice(0-6): ");

    scanf("%d", &choice);

    switch (choice)
    {

        case 0:{
            system("cls");
            main_menu();
            break;
        }
        case 1:{
            system("cls");
            show_name("SQUARE");
            double n;
            printf("\n\t\t\t\tEnter a value: ");
            scanf("%lf", &n);
            if(n - (int)n == 0){
             printf("\n\t\t\t\tThe Square of %.0lf = %.0lf\n", n, square(n));
             fprintf(calculation_history,"The Square of %.0lf = %.0lf\n", n, square(n));
             fflush(calculation_history);
            }
            else{
                printf("\n\t\t\t\tThe Square of %.6lf = %.6lf\n", n, square(n));
                fprintf(calculation_history,"The Square of %.6lf = %.6lf\n", n, square(n));
                fflush(calculation_history);
            }
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    scientific_menu();
                }
                else if(tolower(ch)=='n'){
                    system("cls");
                    main_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        case 2:{
            system("cls");
            show_name("SQUARE-ROOT");
            printf("\n\t\t\t\tEnter a value: ");
            scanf("%lf", &n);
            printf("\n\t\t\t\tThe Square root of %.6lf = %.6lf\n", n, sq_root(n));
            fprintf(calculation_history,"The Square root of %.6lf = %.6lf\n", n, sq_root(n));
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    scientific_menu();
                }
                else if(tolower(ch)=='n'){
                    system("cls");
                    main_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        case 3:{
            logarithm();
            break;
        }
        case 4:{
            trigonometry();
            break;
        }
        case  5:{
            solve_equation();
            break;
        }
        case  6:{
            advance_calculations();
            break;
        }
        default:
            {
            printf("\n\n\t\t\t\tInvalid Choice!!!\n");
            printf("\n\t\t\t\tPress enter to choose again....");
            fflush(stdin);
            getchar();
            system("cls");
            scientific_menu();
        }

    }

}

/// show logarithm sub menu
void logarithm(){
    system("cls");
    show_name("LOGARITHM");
    printf("\n\t\t\t\tChoose Operation: \n\n");
    printf("\t\t\t\t1. Log (Base 10)\n\n");
    printf("\t\t\t\t2. ln (Base e)\n\n");
    printf("\t\t\t\t0. Go to previous menu\n\n");
    printf("\t\t\t\tYour choice(0-2): ");

    scanf("%d",&choice);

    switch(choice){
        case 0:{
            system("cls");
            scientific_menu();
        }
        case 1:{
            system("cls");
            show_name("LOG BASE-10");
            double n;
            printf("\n\t\t\t\tEnter a value: ");
            scanf("%lf",&n);
            double res = __log(n);
            printf("\n\t\t\t\tThe result for log(%.6lf) = %.6lf\n",n,res);
            fprintf(calculation_history,"The result for log(%.6lf) = %.6lf\n",n,res);
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    logarithm();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        case 2:{
            system("cls");
            show_name("LN BASE-E");
            double n;
            printf("\n\t\t\t\tEnter a value: ");
            scanf("%lf",&n);
            double res = __ln(n);
            printf("\n\t\t\t\tThe result for ln(%.6lf) = %.6lf\n",n,res);
            fprintf(calculation_history,"\n\t\t\t\tThe result for ln(%.6lf) = %.6lf\n",n,res);
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    logarithm();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        default:
            printf("\n\n\t\t\t\tInvalid Choice!!!\n");
            printf("\n\t\t\t\tPress enter to choose again....");
            fflush(stdin);
            getchar();
            system("cls");
            logarithm();
    }

}

/// show trigonometry sub menu
void trigonometry(){
    system("cls");
    show_name("TRIGONOMETRY");
    printf("\n\t\t\t\tChoose Operation: \n\n");
    printf("\t\t\t\t1. sin\t\t\t5. tan\n\n");
    printf("\t\t\t\t2. cosec\t\t6. cot\n\n");
    printf("\t\t\t\t3. cos\t\t\t7. asin\n\n");
    printf("\t\t\t\t4. sec\t\t\t8. acos\n\n");
    printf("\t\t\t\t\t   9. atan\n\n");
    printf("\t\t\t\t0. Go to previous menu\n\n");
    printf("\t\t\t\tYour choice(0-9): ");

    scanf("%d",&choice);

    switch(choice){
        case 0:{
            system("cls");
            scientific_menu();
        }
        case 1:{
            system("cls");
            show_name("SIN");
            double n;
            printf("\n\t\t\t\tEnter an angel(degree): ");
            scanf("%lf",&n);
            double rad = (PI*n)/180.0;
            double res = __sin(rad);
            printf("\n\t\t\t\tThe result for sin(%.6lf) = %.6lf\n",n,res);
            fprintf(calculation_history,"The result for sin(%.6lf) = %.6lf\n",n,res);
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    trigonometry();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        case 2:{
            system("cls");
            show_name("COSEC");
            double n;
            printf("\n\t\t\t\tEnter an angel(degree): ");
            scanf("%lf",&n);
            double rad = (PI*n)/180.0;
            double res = 1 / __sin(rad);
            printf("\n\t\t\t\tThe result for cosec(%.6lf) = %.6lf\n",n,res);
            fprintf(calculation_history,"The result for cosec(%.6lf) = %.6lf\n",n,res);
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    trigonometry();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        case 3:{
            system("cls");
            show_name("COS");
            double n;
            printf("\n\t\t\t\tEnter an angel(degree): ");
            scanf("%lf",&n);
            double rad = (PI*n)/180.0;
            double res = __cos(rad);
            printf("\n\t\t\t\tThe result for cos(%.6lf) = %.6lf\n",n,res);
            fprintf(calculation_history,"The result for cos(%.6lf) = %.6lf\n",n,res);
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    trigonometry();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        case 4:{
            system("cls");
            show_name("SEC");
            double n;
            printf("\n\t\t\t\tEnter an angel(degree): ");
            scanf("%lf",&n);
            double rad = (PI*n)/180.0;
            double res = 1 / __cos(rad);
            printf("\n\t\t\t\tThe result for sec(%.6lf) = %.6lf\n",n,res);
            fprintf(calculation_history,"\n\t\t\t\tThe result for sec(%.6lf) = %.6lf\n",n,res);
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    trigonometry();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        case 5:{
            system("cls");
            show_name("TAN");
            double n;
            printf("\n\t\t\t\tEnter an angel(degree): ");
            scanf("%lf",&n);
            if((int)n % 90 == 0){
                printf("\n\t\t\t\tInvalid!!!:(\n");
            }
            else{
                double rad = (PI*n)/180.0;
                double res = __tan(rad);
                printf("\n\t\t\t\tThe result for tan(%.6lf) = %.6lf\n",n,res);
                fprintf(calculation_history,"The result for tan(%.6lf) = %.6lf\n",n,res);
                fflush(calculation_history);
            }
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    trigonometry();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        case 6:{
            system("cls");
            show_name("COTANGENT");
            double n;
            printf("\n\t\t\t\tEnter an angel(degree): ");
            scanf("%lf",&n);
            if(__sin(n) == 0){
                printf("\n\t\t\t\tInvalid!!!\n");
            }
            else{
                double rad = (PI*n)/180.0;
                double res = 1 / __tan(rad);
                printf("\n\t\t\t\tThe result for cot(%.6lf) = %.6lf\n",n,res);
                fprintf(calculation_history,"The result for cot(%.6lf) = %.6lf\n",n,res);
                fflush(calculation_history);
            }
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    trigonometry();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        case 7:{
            system("cls");
            show_name("SINE INVERSE");
            double n;
            printf("\n\t\t\t\tEnter the value: ");
            scanf("%lf",&n);
            if(n>=-1 && n<=1){
                double res = __asin(n)*180/PI;
                printf("\n\n\t\t\t\tInverse of sin(%.2lf) = %.2lf degree\n",n,res);
                fprintf(calculation_history,"\n\n\t\t\t\tInverse of sin(%.2lf) = %.2lf degree\n",n,res);
                fflush(calculation_history);
            }
            else{
                printf("\n\n\t\t\t\tInvalid Input. Range of sin [-1, +1]\n");
            }
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    trigonometry();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
        }
        case 8:{
            system("cls");
            show_name("COS INVERSE");
            double n;
            printf("\n\t\t\t\tEnter the value: ");
            scanf("%lf",&n);
            if(n>=-1 && n<=1){
                double res = __acos(n)*180/PI;
                printf("\n\n\t\t\t\tInverse of cos(%.2lf) = %.2lf degree\n",n,res);
                fprintf(calculation_history,"Inverse of cos(%.2lf) = %.2lf degree\n",n,res);
                fflush(calculation_history);
            }
            else{
                printf("\n\n\t\t\t\tInvalid Input. Range of cos [-1, +1]\n");
            }
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    trigonometry();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        case 9:{
            system("cls");
            show_name("TAN INVERSE");
            double n;
            printf("\n\t\t\t\tEnter the value: ");
            scanf("%lf",&n);
            double res = __atan(n)*180/PI;
            printf("\n\n\t\t\t\tInverse of tan(%.2lf) = %.2lf degree\n",n,res);
            fprintf(calculation_history,"Inverse of tan(%.2lf) = %.2lf degree\n",n,res);
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    trigonometry();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }
        default:
            printf("\n\n\t\t\t\tInvalid Choice!!!\n");
            printf("\n\t\t\t\tPress enter to choose again....");
            fflush(stdin);
            getchar();
            system("cls");
            scientific_menu();
    }

}

/// function for equation solving
void solve_equation(){
    system("cls");
    show_name("EQUATION SOLVER");

    printf("\n\t\t\t\tChoose Operation: \n\n");
    printf("\t\t\t\t1. Simultaneous  Equation (ax+by+c = 0)\n\n");
    printf("\t\t\t\t2. Quadratic Equation (ax^2+bx+c = 0)\n\n");
    printf("\t\t\t\t0. Go to previous menu\n\n");
    printf("\t\t\t\tYour choice(0-2): ");

    scanf("%d",&choice);

    switch(choice){
        case 0:{
            system("cls");
            scientific_menu();
            break;
        }

        case 1:{
            system("cls");
            show_name("SIMULTANEOUS EQUATION");
            double a1, b1, c1, a2, c2, b2, x, y;
            printf("\n\t\t\t\tCoefficient of x, y, constant for eqn_1: ");
            scanf("%lf %lf %lf", &a1, &b1, &c1);
            printf("\n\t\t\t\tCoefficient of x, y, constant for eqn_2: ");
            scanf("%lf %lf %lf", &a2, &b2, &c2);
            if(a1*b2 - a2*b1 == 0){
                printf("\n\n\t\t\tSolution Not Possible!!!!");
            }
            else{
                simultaneous_equation(a1, b1, c1, a2, b2, c2, &x, &y);
                printf("\n\n\t\t\t\tx = %.2lf and y = %.2lf\n", x, y);
                fprintf(calculation_history,"x = %.2lf and y = %.2lf\n\n", x, y);
                fflush(calculation_history);
            }
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    solve_equation();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        case 2:{
            system("cls");
            show_name("QUADRATRIC EQUATION");
            double a,b,c;
            printf("\n\t\t\t\tEnter co-efficient of x^2: ");
            scanf("%lf",&a);
            printf("\n\t\t\t\tEnter co-efficient of x: ");
            scanf("%lf",&b);
            printf("\n\t\t\t\tEnter constant: ");
            scanf("%lf",&c);
            if(a==0){
                printf("\n\n\t\t\t\tMATH ERROR!!!!\n");
            }
            else{
                int complex_roots=0;
                double x1,x2,rp,ip;
                quadratic_equation(a,b,c,&x1,&x2,&rp,&ip,&complex_roots);
                if(complex_roots){
                    printf("\n\n\t\t\t\tx1 = %.2lf+%.2lfi  and  x2 = %.2lf-%.2lfi \n",rp,ip,rp,ip);
                }
                else{
                    printf("\n\n\t\t\t\tx1 = %.2lf and x2 = %.2lf\n",x1,x2);
                    fprintf(calculation_history,"x1 = %.2lf  and  x2 = %.2lf\n",x1,x2);
                    fflush(calculation_history);
                }
            }
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    solve_equation();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        default:
            {
            printf("\n\n\t\t\t\tInvalid Choice!!!\n");
            printf("\n\t\t\t\tPress enter to choose again....");
            fflush(stdin);
            getchar();
            system("cls");
            solve_equation();
        }
    }


}


/// function for advance calculations
void advance_calculations()
{
    system("cls");
    show_name("ADVANCE CALCULATIONS");

    printf("\n\t\t\t\tChoose Operation: \n\n");
    printf("\t\t\t\t1. Factorial\n\n");
    printf("\t\t\t\t2. nPr\n\n");
    printf("\t\t\t\t3. nCr\n\n");
    printf("\t\t\t\t4. Celsius to Farenheit\n\n");
    printf("\t\t\t\t5. Farenheit to Celsius\n\n");
    printf("\t\t\t\t0. Go to previous menu\n\n");
    printf("\t\t\t\tYour choice(0-5): ");

    scanf("%d",&choice);

    switch(choice){
        case 0:{
            system("cls");
            scientific_menu();
            break;
        }
        case 1:{
            system("cls");
            show_name("FACTORIAL");
            int f;
            printf("\n\t\t\t\tEnter a value: ");
            scanf("%d", &f);
            if(f > 19){
                printf("\n\n\t\t\t\tMemory Limit Exceeded!!!!");
            }
            else{
                long long int ans = factorial(f);
                printf("\n\t\t\t\tFactorial of %d is : %lld", f, ans);
                fprintf(calculation_history,"Factorial of %d is : %lld", f, ans);
                fflush(calculation_history);
            }
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    advance_calculations();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        case 2:{
            system("cls");
            show_name("PERMUTATION");
            int n, r;
            printf("\n\t\t\t\tEnter the value of n: ");
            scanf("%d", &n);
            printf("\n\t\t\t\tEnter the value of r: ");
            scanf("%d", &r);
            if(n > 19 || r > 19){
                printf("\n\n\t\t\t\tMemory Limit Exceeded!!!!");
            }
            else if(r > n){
                printf("\n\n\t\t\t\tMATH ERROR!!!!");
            }
            else{
                long long int ans = permutation(n, r);
                printf("\n\t\t\t\t%d P %d is : %lld", n, r, ans);
                fprintf(calculation_history,"\n\t\t\t\t%d P %d is : %lld", n, r, ans);
                fflush(calculation_history);
            }
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    advance_calculations();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        case 3:{
            system("cls");
            show_name("COMBINATION");
            int n, r;
            printf("\n\t\t\t\tEnter the value of n: ");
            scanf("%d", &n);
            printf("\n\t\t\t\tEnter the value of r: ");
            scanf("%d", &r);
            if(n > 19 || r > 19){
                printf("\n\n\t\t\t\tMemory Limit Exceeded!!!!");
            }
            else if(r > n){
                printf("\n\n\t\t\t\tMATH ERROR!!!!");
            }
            else{
                long long int ans = combination(n, r);
                printf("\n\t\t\t\t%d C %d is : %lld", n, r, ans);
                fprintf(calculation_history,"\n\t\t\t\t%d C %d is : %lld", n, r, ans);
                fflush(calculation_history);
            }
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    advance_calculations();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        case 4:{
            system("cls");
            show_name("CELSIUS TO FARENHEIT");
            double t;
            printf("\n\t\t\t\tEnter the temperature in Celsius: ");
            scanf("%lf", &t);
            double ans = celsius_to_farenheit(t);
            printf("\n\t\t\t\t%.2f%c Celsius = %.2f%c Farenheit\n", t, 248, ans, 248);
            fprintf(calculation_history,"%.2f%c Celsius = %.2f%c Farenheit\n", t, 248, ans, 248);
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    advance_calculations();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        case 5:{
            system("cls");
            show_name("FARENHEIT TO CELSIUS");
            double t;
            printf("\n\t\t\t\tEnter the temperature in Farenheit: ");
            scanf("%lf", &t);
            double ans = farenheit_to_celsius(t);
            printf("\n\t\t\t\t%.2f%c Farenheit = %.2f%c Celsius\n", t, 248, ans, 248);
            fprintf(calculation_history,"%.2f%c Farenheit = %.2f%c Celsius\n", t, 248, ans, 248);
            fflush(calculation_history);
            fflush(stdin);
            do{
                printf("\n\n\t\t\t\tWould you like to calculate agian...?(y/n): ");
                ch = getchar();
                fflush(stdin);
                if(tolower(ch)=='y'){
                    system("cls");
                    advance_calculations();
                }
                else{
                    system("cls");
                    scientific_menu();
                }
            }while(tolower(ch)!='y');
            break;
        }

        default:
            {
            printf("\n\n\t\t\t\tInvalid Choice!!!\n");
            printf("\n\t\t\t\tPress enter to choose again....");
            fflush(stdin);
            getchar();
            system("cls");
            solve_equation();
        }
    }
}

/// function for summation
double addition(double sum, double n)
{
    return sum+n;
}

/// function for subtraction
double subtraction(double sub, double n)
{
    return sub-n;
}

/// function for multiplication
double multiplication(double n1, double n2)
{
    return n1*n2;
}

/// function for division
double division(double n1, double n2)
{
    return n1 / n2;
}

/// function for determining percentage
double percentage(double n1, double n2)
{
    return (n1 * n2) / 100;
}

/// function for calculating square
double square(double n)
{
    return n*n;
}

/// function for calculating square root
double sq_root(double n)
{
    return sqrt(n);
}

/// function for calculating log
double __log(double n)
{
    return log10(n);
}

/// function for calculating ln
double __ln(double n)
{
    return log(n);
}

/// function for calculating sin
double __sin(double n)
{
    return sin(n);
}

/// function for calculating cos
double __cos(double n)
{
    return cos(n);
}

/// function for calculating tan
double __tan(double n)
{
    return tan(n);
}

/// function for calculating sin inverse
double __asin(double n){
    return asin(n);
}

/// function for calculating cos inverse
double __acos(double n){
    return acos(n);
}

/// function for calculating tan inverse
double __atan(double n){
    return atan(n);
}

/// function for calculating simultaneous equation
void simultaneous_equation(double a1, double b1, double c1, double a2, double b2, double c2, double *x, double *y){
    *x = (b1*c2 - b2*c1) / (a1*b2 - a2*b1);
    *y = (a2*c1 - a1*c2) / (a1*b2 - a2*b1);
}

/// function for calculating quadratic equation
void quadratic_equation(double a, double b, double c, double *x1,double *x2, double *rp, double *ip, int *complex_roots){

    double d = b*b - 4*a*c;
    if(d<0){
        *complex_roots = 1;
        d = fabs(d);
        *rp = -b/(2*a);
        *ip = sqrt(d) / (2*a);
    }
    else{
        *x1 = (-b + sqrt(d)) / (2*a);
        *x2 = (-b - sqrt(d)) / (2*a);
    }
}

/// function for calculating factorial;
long long int factorial(int n){
    long long int fact = 1;
    if(n == 0)  return 1;
    else{
        for(int i = 1; i <= n; i++){
            fact *= i;
        }
        return fact;
    }
}

/// function for calculating nPr
long long int permutation(int n, int r){
    long long int numerator = factorial(n);
    long long int denominator = factorial(n-r);
    return numerator / denominator;
}

/// function for calculating nCr
long long int combination(int n, int r){
    return permutation(n, r) / factorial(r);
}

/// function for calculating farenheit temperature
double celsius_to_farenheit(double t){
    return ((9 / (double)5) * t + 32);
}

/// function for calculating celsius temperature
double farenheit_to_celsius(double t){
    return ((5 / (double)9) * (t - 32));
}
