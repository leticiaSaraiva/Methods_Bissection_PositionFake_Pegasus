#include <bits/stdc++.h>
using namespace std;


double f( double x ){
    //double y = (2*pow(x,3)) - (4*pow(x,2)) + (3*x); //exemplo PDF
    //double y = (pow(x,5)) - (3*pow(x,4)) - (3*pow(x,2)) + 2; //Item a
    //double y = sqrt(x) - (pow(5,-x)); //Item b
    //double y = (pow(x,5)) - (pow(x,4)) - (4*x) + 1; //Item c
    double y = (0.05*pow(x,3)) - (0.4*pow(x,2)) + (3*x*sin(x)); //Item d
    return y;
}

double MetodoBissecao(double a, double b, double e){
	double Xm;
	int i = 0;

	do{ 
		Xm = (a + b)/2;
		if (f(a) * f(Xm) < 0){
		b = Xm;
		}else {
		a = Xm;
		} 
		i++;
	} while ((abs(f(Xm)) > e));

	cout << "Valor de x:" << Xm << "\n";
	cout << "Iterações:" << i-1 << "\n";
    cout << "Intervalo: [" << a << "," << b << "] \n";
	return Xm;
}


double MetodoPosicaoFalsa( double a, double b, double e ){
	int i = 0;
    double c = ( a*f(b) - (b*f(a)) )/( f(b)-f(a) );
    while( abs(f(c)) > e and abs(a-b) > e ){
        if( f(a)*f(c) < 0 ){
            b = c;
        }
        else if( f(c)*f(b) < 0 ){
            a = c;
        }
        c = ( a*f(b) - (b*f(a)) )/( f(b)-f(a) );
        i++;
    }
    cout << "Iterações: " << i << "\n";
    cout << "Intervalo: [" << a << "," << b << "] \n";

    return c;
}

double MetodoPosicaoFalsaRecursivo( double a, double b, double e )
{
    double fa = f(a);
    double fb = f(b);
    double c = ( (a*fb) - (b*fa) )/( fb-fa );
    double fc = f(c);
    cout << " a : " << a << " b: " <<b <<" c: " << c << " fc: " << fc << " b-a: " << abs(b-a) << "\n";
    if( fc == 0.0 or abs(fc) < e or abs(a-b) < e ){
         return c;
    }
    if( fa*fc < 0 ){
        return MetodoPosicaoFalsaRecursivo(a,c,e);
    }

    return MetodoPosicaoFalsaRecursivo(c,b,e);
}

double MetodoPegasoRecursivo( double a, double fa, double b, double fb, double e ){
    double c = ( (a*fb) - (b*fa) )/( fb-fa );
    double fc = f(c);
    cout << " a : " << a << " b: " <<b <<" c: " << c << " fc: " << fc << " b-a: " << abs(b-a) << "\n";
    if( fc == 0.0 or abs(fc) < e or abs(a-b) < e ){
        return c;
    }
    if( fa*fc < 0 ){
        double fa2 = (fa*fb)/(fb+fc);
        return MetodoPegasoRecursivo(a,fa2,c,fc,e);
    }
    
    return MetodoPegasoRecursivo(b,fb,c,fc,e);
}

int main(){
    double a,b,e;
    
    cout << "Digite o valor 'a' do intervalo [a,b]: ";
    cin >> a;
    
    cout << "Digite o valor 'b' do intervalo [a,b]: ";
    cin >> b;
 
	cout << "Informe a precisão epsilon: ";
    cin >> e;
    
    cout.precision(10);
    
    cout << "\nMétodo da Bisseção" << "\n";
    MetodoBissecao(a,b,e);
    cout << "\nMétodo da Posição Falsa" << "\n";
    cout << "Valor de x: " << MetodoPosicaoFalsa(a,b,e) << "\n\n";
    cout << "Método de Pegaso" << "\n";
    cout << "Valor de x: " << MetodoPegasoRecursivo(a,f(a),b,f(b),e);
    
    return 0;
}
