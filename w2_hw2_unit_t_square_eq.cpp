////============================================================================
//// Name        : CourseraWhiteBeltCpp.cpp
//// Author      : Oleg Greenberg
//// Version     : 1
//// Copyright   : Your copyright notice
//// Description : //Unit testing for Ax^2+Bx+C equation. Based on self defined u nit tresting environment
////============================================================================
//
//#include <iostream>
//#include <map>
//#include <set>
//#include <sstream>
//#include <stdexcept>
//#include <string>
//#include <vector>
//
////TODO remove this begore submission
//#include<cmath>
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
//
///*Unit tests*/
//
//
//
//int GetDistinctRealRootCount(double a, double b, double c) {
////	double x1,x2,del;
////	del = b*b-4*a*c;
////
////
////	if (del >= 0 ) {
////		if (del > 0){//del > 0
////			if (a == 0){
////				x1 = -1*c/b;
////				//cout << x1;
////				return 1;
////			}else{
////				x1 = (-b + sqrt(del))/(2*a);
////				x2 = (-b - sqrt(del))/(2*a);
////				//cout << x1 << " " << x2;
////				return 2;
////			}
////		}else{//del == 0
////			if (b == 0 && c == 0){
////				x1 = 0;
////				//cout << x1;
////				return 1;
////			}else if(b == 0 && a == 0){
////				//nothing here
////			}else {
////				x1 =  -b/(2*a);
////				//cout << x1;
////				return 1;
////			}
////		}
////	}else{
////		//no roots, del < 0
////	}
////	return 0;
//}
//
////a=0,b=0 Res = 0
//void test1(){
//	Assert(GetDistinctRealRootCount(0,0,5.3)==0,"A=0,B=0");
//}
////b=0,a>0,c>0
//void test2_1(){
//	Assert(GetDistinctRealRootCount(1.2,0,2.2)==0,"b=0,a>0,c>0");
//}
////b=0,a<0,c<0
//void test2_2(){
//	Assert(GetDistinctRealRootCount(-1,0,-2)==0,"b=0,a<0,c<0");
//}
////b=0,a>0,c<0
//void test2_3(){
//	Assert(GetDistinctRealRootCount(3.5,0,-4)==2,"b=0,a>0,c<0");
//}
////b=0,a<0,c>0
//void test2_4(){
//	Assert(GetDistinctRealRootCount(-3.5,0,4)==2,"b=0,a<0,c>0");
//}
////b!=0,a=0,c=0
//void test3_1(){
//	Assert(GetDistinctRealRootCount(0,5.0,0)==1,"b!=0,a=0,c=0");
//}
////b=0,a!=0,c=0
//void test3_2(){
//	Assert(GetDistinctRealRootCount(6,0,0)==1,"b=0,a!=0,c=0");
//}
////b!=0,a!=0,c=0
//void test3_3(){
//	Assert(GetDistinctRealRootCount(6,4.2,0)==2,"b!=0,a!=0,c=0");
//	Assert(GetDistinctRealRootCount(6,-4.2,0)==2,"b<0,a>0,c=0");
//	Assert(GetDistinctRealRootCount(-6,4.2,0)==2,"b>0,a<0,c=0");
//	Assert(GetDistinctRealRootCount(-6.0,-4.2,0)==2,"b<0,a>0,c=0");
//
//}
////b!=0,a=0,c=0
//void test4_1(){
//	Assert(GetDistinctRealRootCount(0,4,0)==1,"b>0,a=0,c=0");
//	Assert(GetDistinctRealRootCount(0,-4,0)==1,"b<0,a=0,c=0");
//
//}
////b=0,a=0,c!=0
//void test4_2(){
//	Assert(GetDistinctRealRootCount(0,0,1)==0,"//b=0,a=0,c>0");
//	Assert(GetDistinctRealRootCount(0,0,-1)==0,"//b=0,a=0,c<0");
//}
////b!=0,a=0,c!=0
//void test4_3(){
//	Assert(GetDistinctRealRootCount(0,1,2)==1,"//b>0,a=0,c>0");
//	Assert(GetDistinctRealRootCount(0,-1,2)==1,"//b<0,a=0,c>0");
//	Assert(GetDistinctRealRootCount(0,1,-2)==1,"//b>0,a=0,c<0");
//	Assert(GetDistinctRealRootCount(0,-1,-2)==1,"//b<0,a=0,c<0");
//}
////b^2-4ac>0
//void test5_1(){
//	Assert(GetDistinctRealRootCount(1,3,2)==2,"b^2-4ac>0,a>0,b>0,c>0");
//	Assert(GetDistinctRealRootCount(1,-3,2)==2,"b^2-4ac>0,a>0,b<0,c>0");
//	Assert(GetDistinctRealRootCount(-1,-3,2)==2,"b^2-4ac>0,a<0,b<0,c>0");
//	Assert(GetDistinctRealRootCount(-1,-3,-2)==2,"b^2-4ac>0,a<0,b<0,c<0");
//
//}
////b^2-4ac=0
//void test6_1(){
//	Assert(GetDistinctRealRootCount(1,4,4)==1,"b^2-4ac=0");
//}
////b^2-4ac<0
//void test7_1(){
//	Assert(GetDistinctRealRootCount(1,1,2)==0,"b^2-4ac<0");
//}
//
//int main() {
//  TestRunner runner;
//  runner.RunTest(test1,"test1");
//  runner.RunTest(test2_1,"test2_1");
//  runner.RunTest(test2_2,"test2_2");
//  runner.RunTest(test2_3,"test2_3");
//  runner.RunTest(test2_4,"test2_4");
//  runner.RunTest(test3_1,"test3_1");
//  runner.RunTest(test3_2,"test3_2");
//  runner.RunTest(test3_3,"test3_3");
//  runner.RunTest(test3_3,"test4_1");
//  runner.RunTest(test3_3,"test4_2");
//  runner.RunTest(test3_3,"test4_3");
//  runner.RunTest(test5_1,"test5_1");
//  runner.RunTest(test6_1,"test6_1");
//  runner.RunTest(test7_1,"test7_1");
//
//
//
//
//
//
//
//
//  return 0;
//}
