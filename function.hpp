 #pragma once
 
 #include "Eigen/Eigen"
 
 using namespace std;
 using namespace Eigen;
 
 Vector2d PALU(const Matrix2d& A, const Vector2d& b)
{
	// Fattorizzazione 
	FullPivLU<Matrix2d> lu(A);
	
	// Ottengo P
	Matrix2d P = lu.permutationP();
	
	// Ottengo L, prima la definisco come identità per avere gli 1 sulla diagonale principale e poi copio gli altri vaolri al di sotto
	Matrix2d L = Matrix2d::Identity();
	L.triangularView<StrictlyLower>() = lu.matrixLU();
	
	// Ottengo U, prendo i valori della diagonale principale e quelli sopra
	Matrix2d U = lu.matrixLU().triangularView<Upper>();
	
	// Trovo y da Ly=Pb
	Vector2d Pb = P * b;
	Vector2d y = L.triangularView<Lower>().solve(Pb);

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
