////============================================================================
//// Name        : CourseraWhiteBeltCpp.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : //Implementation of Matrix class with simple unit testing
//
//
//
//#include <iostream>
//#include <sstream>
//#include <vector>
//#include <exception>
//using namespace std;
//
//
//
//class Matrix{
//	public:
//		//default constructor, creates empty mtrx
//		Matrix(){
//			mtrx = {};
//		}
//		//parametrized constructor , creates a new num_rows/num_col matrix with default values 0
//		Matrix(int num_rows, int num_cols){
//			//function parameters check
//			CheckNegativeSize(num_rows,num_cols);
//			//check for various versions of strange cases of empty matrix
//			if ((num_rows == 0 && num_cols != 0) || (num_rows != 0 && num_cols == 0 )){
//				mtrx = {};
//			}else{
//				mtrx.assign(num_rows, vector<int>(num_cols));
//			}
//		}
//
//		//resize the matrix acording to new num_row/num_col parameters
//		void Reset(int num_rows, int num_cols){
//			//function parameters check
//			CheckNegativeSize(num_rows,num_cols);
//			mtrx.assign(num_rows, vector<int>(num_cols));
//		}
//		//return matrix reference at location num_row/num_col . Constant method
//		int At(int num_row, int num_col) const{
//			//function parameters check
//			//CheckMatrixSize(num_row,num_col);/// no need as at throughs this error him self
//			return mtrx.at(num_row).at(num_col);
//		}
//		//return matrix value at location num_row/num_col . Non constant method
//		int& At(int num_row, int num_col) {
//			//num_col , num_row  in [0,size-1]
//			//function parameters check
//			return mtrx.at(num_row).at(num_col);
//		}
//		//return number of rows
//		int GetNumRows() const{
//			return mtrx.size();
//		}
//		//return number of columns
//		//basing that matrix columns have same size
//		int GetNumColumns() const{
//			if (GetNumRows() !=0)//not an empty matrix
//				return mtrx[0].size();
//			else
//				return 0;
//		}
//
//	private:
//		vector<vector<int>> mtrx;
//		//exception check for row/col size
//		void CheckNegativeSize(int num_row,int num_col) const{
//			//num_col , num_row  in [0,size-1]
//			if (num_row < 0 or num_col < 0 ){
//				throw out_of_range("out_of_range");
//			}
//		}
//		void CheckMatrixSize(const int& num_row,const int& num_col) const{
//			//num_col , num_row  in [0,size-1]
//			if (num_row >= GetNumRows() or num_col >= GetNumColumns() or num_row < 0 or num_col < 0){
//				throw out_of_range("out_of_range");
//			}
//		}
//};
//
//
////operators for Matric class//
////input stream in format :
////num_of_rows num_of_cols <array values>
//istream& operator>>(istream& stream , Matrix& matrx){
//	int rows,cols,val ;
//
//	//read the matrix sizes : rows,cols
//	stream >> rows >> cols;
//
//	//read the matrix values
//	matrx.Reset(rows,cols);
//	for(int i=0;i<rows;i++){
//		for(int j=0;j<cols;j++){
//			//val = matrx.At(i,j);
//			stream >> val;
//			//matrx.InsertAt(i,j,val);
//			matrx.At(i,j) = val;
//		}
//	}
//	return stream;
//}
//
////output stream in format:
//////num_of_rows num_of_cols
////<array values>
//ostream& operator<<(ostream& stream , const Matrix& matrx){
//	int rows = matrx.GetNumRows();
//	int cols = matrx.GetNumColumns();
//
//	//read the matrix sizes : rows,cols
//	stream << rows << " " << cols << endl;
//
//	//read the matrix values
//	for(int i=0;i<rows;i++){
//		for(int j=0;j<cols;j++){
//		      if (j > 0) {
//		        stream << " ";
//		      }
//		      stream << matrx.At(i,j);
//		}
//		stream << endl;
//	}
//
//	return stream;
//}
//
////comparison operator
//bool operator==(const Matrix& m_lhs, const Matrix& m_rhs){
//	if (m_lhs.GetNumColumns() != m_rhs.GetNumColumns() ||
//			m_lhs.GetNumRows() != m_rhs.GetNumRows()){
//		return false ;
//	}else{
//		for (int i=0;i<m_lhs.GetNumRows();i++){
//			for (int j=0;j<m_lhs.GetNumColumns();j++){
//				if (m_lhs.At(i,j) != m_rhs.At(i,j)){
//					return false;
//				}
//			}
//		}
//	}
//	return true;
//}
//
////addition operator
//Matrix operator+(const Matrix& m_lhs, const Matrix& m_rhs){
//	int num_cols = m_lhs.GetNumColumns();
//	int num_rows = m_lhs.GetNumRows();
//	Matrix m_temp(num_rows,num_cols);
//	if (num_cols != m_rhs.GetNumColumns() ||
//			num_rows != m_rhs.GetNumRows()){
//		throw invalid_argument("invalid_argument") ;
//	}else{
//		//go over elemnts and add to new matrix
//		for (int i=0;i< num_rows;i++){
//			for (int j=0;j<num_cols;j++){
//				//temp_m.InsertAt(i,j,m_lhs.At(i,j) + m_rhs.At(i,j));
//				m_temp.At(i,j) = m_lhs.At(i,j) + m_rhs.At(i,j);
//			}
//		}
//	}
//	return m_temp;
//}
//
////Simple unit testing
//
//void to_cout(const Matrix& one , const Matrix& two){
//	  try {
//		  cout << one.At(1,1);
//		  cout << one + two << endl;
//	  }catch(exception& e){
//		  cout << e.what();
//	  }
//}
//void test1(){
//		  Matrix one(3,5);
//		  Matrix two(3,5);
//		  istringstream stream("3 5 6 4 -1 9 8 12 1 2 9 -5 -4 0 12 8 6 3 5 5 1 0 -8 23 14 5 -6 6 9 8 0 5 4 1");
//		  stream >> one >> two ;
//		  to_cout(one,two);
//
//}
//void test2(){
//		  Matrix one(1,1);
//		  Matrix two(1,1);
//		  istringstream stream("1 1 1 1 1 1");
//		  stream >> one >> two ;
//		  to_cout(one,two);
//
//}
//void test3(){
//	Matrix one;
//	Matrix two;
//	to_cout(one,two);
//}
//void test4(){
//		  Matrix one(2,1);
//		  Matrix two(1,1);
//		  istringstream stream("2 1 1 1 1 1 1");
//		  stream >> one >> two ;
//		  to_cout(one,two);
//
//}
//void test5(){
//		  Matrix one(1,0);
//		  Matrix two(1,0);
//		  to_cout(one,two);
//
//}
//int main() {
//
//
//	test1();
//	test2();
//	test3();
//	test4();
//	test5();
//
//
//
//
//
//
//
//
//
//
//
//
//      return 0;
//
//}
//
