////============================================================================
//// Name        : CourseraWhiteBeltCpp.cpp
//// Author      : Oleg Greenberg
//// Version     : 1
//// Copyright   : Your copyright notice
//// Description : //Unit testing for class Person based on hw from White belt course
////============================================================================
//#include <iostream>
//#include <map>
//#include <set>
//#include <sstream>
//#include <stdexcept>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//template <class T>
//ostream& operator << (ostream& os, const vector<T>& s) {
//  os << "{";
//  bool first = true;
//  for (const auto& x : s) {
//    if (!first) {
//      os << ", ";
//    }
//    first = false;
//    os << x;
//  }
//  return os << "}";
//}
//
//template <class T>
//ostream& operator << (ostream& os, const set<T>& s) {
//  os << "{";
//  bool first = true;
//  for (const auto& x : s) {
//    if (!first) {
//      os << ", ";
//    }
//    first = false;
//    os << x;
//  }
//  return os << "}";
//}
//
//template <class K, class V>
//ostream& operator << (ostream& os, const map<K, V>& m) {
//  os << "{";
//  bool first = true;
//  for (const auto& kv : m) {
//    if (!first) {
//      os << ", ";
//    }
//    first = false;
//    os << kv.first << ": " << kv.second;
//  }
//  return os << "}";
//}
//
//template<class T, class U>
//void AssertEqual(const T& t, const U& u, const string& hint = {}) {
//  if (t != u) {
//    ostringstream os;
//    os << "Assertion failed: " << t << " != " << u;
//    if (!hint.empty()) {
//       os << " hint: " << hint;
//    }
//    throw runtime_error(os.str());
//  }
//}
//
//void Assert(bool b, const string& hint) {
//  AssertEqual(b, true, hint);
//}
//
//class TestRunner {
//public:
//  template <class TestFunc>
//  void RunTest(TestFunc func, const string& test_name) {
//    try {
//      func();
//      cerr << test_name << " OK" << endl;
//    } catch (exception& e) {
//      ++fail_count;
//      cerr << test_name << " fail: " << e.what() << endl;
//    } catch (...) {
//      ++fail_count;
//      cerr << "Unknown exception caught" << endl;
//    }
//  }
//
//  ~TestRunner() {
//    if (fail_count > 0) {
//      cerr << fail_count << " unit tests failed. Terminate" << endl;
//      exit(1);
//    }
//  }
//
//private:
//  int fail_count = 0;
//};
//
//class Rational {
//	public:
//	  Rational(){
//		  p = 0;
//		  q = 1;
//	  }
//	  //q is always > 0   p can be negative
//	  Rational(int numerator, int denominator){
//
//		  if (denominator == 0){
//			  throw invalid_argument("Invalid argument");
//		  }
//		  int gcd = myabs(gcd_val(numerator,denominator));
//		  //1. check how is positive who is negativ
//		  if ( (numerator >= 0 && denominator >= 0)  || (numerator < 0 && denominator < 0)){
//			  p = myabs(numerator)/gcd;
//			  q = myabs(denominator)/gcd;
//		  }else{//one is less 0
//			  p = -1*myabs(numerator)/gcd;
//			  q = myabs(denominator)/gcd;
//		  }
//	  }
//
//	  int Numerator() const{
//		  return p;
//	  };
//	  int Denominator() const{
//		  return q;
//	  }
//	private:
//
//	  int p; // integer
//	  int q; // rasional
//	  int gcd_val(int a, int b) {
//	     if (b == 0)
//	        return a;
//	     return gcd_val(b, a % b);
//	  }
//	  int myabs(int a) {
//	     if (a > 0)
//	        return a;
//	     else
//	    	 return -1*a;
//	  }
//	  //int mmd;
//	};
//
//
//void TestDefultConstructor(){
//	Rational cl1;
//	AssertEqual(cl1.Numerator(),0,"Deafult Numerator");
//	AssertEqual(cl1.Denominator(),1,"Deafult Denominator");
//
//}
//void TestNonDefultConstructor(){
//	Rational cl1(5,6);
//	AssertEqual(cl1.Numerator(),5,"Non Deafult Numerator");
//	AssertEqual(cl1.Denominator(),6,"Non Deafult Denominator");
//
//	Rational cl2(2,4);
//	AssertEqual(cl2.Numerator(),1,"Non Deafult Numerator with gcd action");
//	AssertEqual(cl2.Denominator(),2,"Non Deafult Denominator with gcd action");
//
//	Rational cl3(-3,-9);
//	AssertEqual(cl3.Numerator(),1,"Non Deafult Numerator with gcd action on negative");
//	AssertEqual(cl3.Denominator(),3,"Non Deafult Denominator with gcd action on negative");
//
//}
//
//void TestNegativeConstructor(){
//	Rational cl1(5,-10);
//	AssertEqual(cl1.Numerator(),-1,"Numerator is not negative");
//	AssertEqual(cl1.Denominator(),2,"Denumerator is not postive ");
//
//	Rational cl2(-5,10);
//	AssertEqual(cl2.Numerator(),-1,"Numerator is not negative");
//	AssertEqual(cl2.Denominator(),2,"Denumerator is not postive ");
//
//	Rational cl3(-15,-25);
//	AssertEqual(cl3.Numerator(),3,"Numerator is not positive");
//	AssertEqual(cl3.Denominator(),5,"Denumerator is not postive ");
//
//}
//
//void TestNullNumerator(){
//	Rational cl1(0,-10);
//	AssertEqual(cl1.Numerator(),0,"Numerator is not equal to 0");
//	AssertEqual(cl1.Denominator(),1,"Denumerator is not equal to 1 ");
//
//
//
//}
//
//int main() {
//	TestRunner runner;
//	runner.RunTest(TestDefultConstructor,"TestDefultConstructor");
//	runner.RunTest(TestNonDefultConstructor,"TestNonDefultConstructor");
//	runner.RunTest(TestNegativeConstructor,"TestNegativeConstructor");
//	runner.RunTest(TestNullNumerator,"TestNullNumerator");
//
//
//	  return 0;
//}
