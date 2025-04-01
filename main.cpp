#include <iostream>
#include <iomanip>
#include "Eigen/Eigen"
#include "function.hpp"

using namespace std;
using namespace Eigen;


int main()
{
	cout<<scientific;
	// Vettore soluzione
	Vector2d sol;
	sol << -1.0e0,-1.0e00;
	
	// Primo sistema
	Matrix2d A1; 
	A1 << 5.547001962252291e-01, -3.770900990025203e-02,
		 8.320502943378437e-01, -9.992887623566787e-01;

	Vector2d b1; 
	b1 << -5.169911863249772e-01, 1.672384680188350e-01;

	Vector2d xPALU1 = PALU(A1,b1);
	Vector2d xQR1 = QR(A1,b1);
	
	double ErrPALU1 = ErrRel(xPALU1,sol);
	double ErrQR1 = ErrRel(xQR1,sol);
	
	cout<<"La soluzione del sistema 1 ottenuta con PALU è\n"<<setprecision(1)<<"["<<xPALU1[0]<<","<<xPALU1[1]<<"]"<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è: "<<setprecision(4)<<ErrPALU1<<endl;
	cout<<"\nLa soluzione del sistema 1 ottenuta con QR è\n"<<setprecision(1)<<"["<<xQR1[0]<<","<<xQR1[1]<<"]"<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è: "<<setprecision(4)<<ErrQR1<<endl;
	
	// Secondo sistema
	Matrix2d A2; 
	A2 << 5.547001962252291e-01, -5.540607316466765e-01,
		  8.320502943378437e-01, -8.324762492991313e-01;

	Vector2d b2; 
	b2 << -6.394645785530173e-04, 4.259549612877223e-04;

	Vector2d xPALU2 = PALU(A2,b2);
	Vector2d xQR2 = QR(A2,b2);
	
	double ErrPALU2 = ErrRel(xPALU2,sol);
	double ErrQR2 = ErrRel(xQR2,sol);
	
	cout<<"\nLa soluzione del sistema 2 ottenuta con PALU è\n"<<setprecision(1)<<"["<<xPALU2[0]<<","<<xPALU2[1]<<"]"<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è: "<<setprecision(4)<<ErrPALU2<<endl;
	cout<<"\nLa soluzione del sistema 2 ottenuta con QR è\n"<<setprecision(1)<<"["<<xQR2[0]<<","<<xQR2[1]<<"]"<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è: "<<setprecision(4)<<ErrQR2<<endl;
		
	// Terzo sistema
	Matrix2d A3; 
	A3 << 5.547001962252291e-01, -5.547001955851905e-01,
		  8.320502943378437e-01, -8.320502947645361e-01;

	Vector2d b3; 
	b3 << -6.400391328043042e-10, 4.266924591433963e-10;

	Vector2d xPALU3 = PALU(A3,b3);
	Vector2d xQR3 = QR(A3,b3);
	
	double ErrPALU3 = ErrRel(xPALU3,sol);
	double ErrQR3 = ErrRel(xQR3,sol);
	
	cout<<"\nLa soluzione del sistema 3 ottenuta con PALU è\n"<<setprecision(1)<<"["<<xPALU3[0]<<","<<xPALU3[1]<<"]"<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è: "<<setprecision(4)<<ErrPALU3<<endl;
	cout<<"\nLa soluzione del sistema 3 ottenuta con QR è\n"<<setprecision(1)<<"["<<xQR3[0]<<","<<xQR3[1]<<"]"<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è: "<<setprecision(4)<<ErrQR3<<endl;	
    return 0;
}
