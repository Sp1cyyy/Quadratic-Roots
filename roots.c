#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calc_det(double a, double b, double c);
void calc_root(double a, double b, double c, double det);
int
main(int argc, char* argv[]){
    double a, b, c;
    double det;
    printf("Enter the coefficients of polynomial\n");
    printf("Where the form of the polynomial is ax^2 + bx +c\n");
    printf("Enter in form \"a\" \"b\" \"c\" (note: enter without quotation marks): ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a ==0 && b == 0 && c == 0){
        printf("Invalid Function entered, please run program again.\n");
        exit(EXIT_FAILURE);
    }
    det = calc_det(a, b, c);
    if(det<0){
        printf("The polynomial has no real roots\n");
    }
    else{
        calc_root(a, b, c, det);
    }
}
double 
calc_det(double a, double b, double c){
    double det;
    det = b*b - 4*a*c;
    return det;
}
void 
calc_root(double a, double b, double c, double det){
    double root_1, root_2;
    if(det == 0){
        root_1 = -b/2*a;
        if(root_1 == 0){
            root_1*=-1;
        } 
        printf("The polynomial has 1 real root: %0.2lf\n", root_1);
    }
    else{
        root_1 = (-b - sqrt(det))/(2*a);
        root_2 = (-b + sqrt(det))/(2*a);
        printf("The polynomial has 2 real roots: %0.2lf and %0.2lf\n", root_1, root_2);
    }
}