#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;

 Vector2d PALU(const Matrix2d& A, const Vector2d& b)
{
	// Fattorizzazione 
	FullPivLU<Matrix2d> lu(A);
	
	// Ottengo P
	Matrix2d P = lu.permutationP();
	
	// Ottengo L, prendo i valori della diagonale principale e quelli sopra
	Matrix2d L = Matrix2d::Identity();
	L.triangularView<StrictlyLower>() = lu.matrixLU();
	
	// Ottengo U, prima la definisco come identità per avere gli 1 sulla diagonale principale e poi copio gli altri vaolri al di sotto
	Matrix2d U = lu.matrixLU().triangularView<Upper>();
	
	// Trovo y da Ly=Pb
	Vector2d Pb = P * b;
	Vector2d y = L.triangularView<UnitLower>().solve(Pb);
	
	// Trovo x da Ux=y
	Vector2d x = U.triangularView<Upper>().solve(y);
	
	return x;
}

Vector2d QR(const Matrix2d& A, const Vector2d& b)
{
	// Fattorizzazione
	HouseholderQR<MatrixXd> qr(A);

	// Ottengo Q
	MatrixXd Q = qr.householderQ();
	
	// Ottengo R
	MatrixXd R = qr.matrixQR().triangularView<Upper>();
	
	// Trovo y da y = Q'b
	Vector2d y = Q.transpose() * b;
	
	// Trovo x da Rx = y
	Vector2d x = R.triangularView<Upper>().solve(y);
	
	return x;
}

double ErrRel(const Vector2d& x, const Vector2d& sol)
{
	return ((x - sol).norm()/sol.norm());
}
int main()
{
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
	
	cout<<"La soluzione del sistema 1 ottenuta con PALU è\n"<<xPALU1<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è "<<ErrPALU1<<endl;
	cout<<"La soluzione del sistema 1 ottenuta con QR è\n"<<xQR1<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è "<<ErrQR1<<endl;
	
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
	
	cout<<"\nLa soluzione del sistema 2 ottenuta con PALU è\n"<<xPALU2<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è "<<ErrPALU2<<endl;
	cout<<"La soluzione del sistema 2 ottenuta con QR è\n"<<xQR2<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è "<<ErrQR2<<endl;
		
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
	
	cout<<"\nLa soluzione del sistema 3 ottenuta con PALU è\n"<<xPALU3<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è "<<ErrPALU3<<endl;
	cout<<"La soluzione del sistema 3 ottenuta con QR è\n"<<xQR3<<endl;
	cout<<"L'errore relativo rispetto alla soluzione esatta è "<<ErrQR3<<endl;	
    return 0;
}
