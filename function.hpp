 #pragma once
 
 #include "Eigen/Eigen"
 
 using namespace std;
 using namespace Eigen;
 
 Vector2d PALU(const Matrix2d& A, const Vector2d& b)
{
	// Fattorizzazione 
	FullPivLU<Matrix2d> lu(A);
	
	Vector2d x = lu.solve(b);
	
	return x;
}

Vector2d QR(const Matrix2d& A, const Vector2d& b)
{
	// Fattorizzazione
	HouseholderQR<MatrixXd> qr(A);
	
	Vector2d x = qr.solve(b);
	
	return x;
}

double ErrRel(const Vector2d& x, const Vector2d& sol)
{
	return ((x - sol).norm()/sol.norm());
}
