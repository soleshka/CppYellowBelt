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
//      os << " hint: " << hint;
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
//class Person {
//	public:
//		void ChangeFirstName(int year , const string& first_name){
//			years_to_first[year] = first_name;
//		}
//		void ChangeLastName(int year , const string& last_name){
//			years_to_last[year] = last_name;
//		}
//		string GetFullName(int year){
//			//get the year if the name was changed before the given name otherwise -1
//			int first_year = FindFirstName(years_to_first , year);
//			//same for last name
//			int last_year = FindFirstName(years_to_last , year);
////			cout << "year " << year << endl;
////			cout << "first_name " << first_year << endl;
////			cout << "last_name " << last_year << endl;
//
//			if (first_year <= year && last_year <= year){//both name changes occured before the given name
//				return (years_to_first[first_year] + " " + years_to_last[last_year]);
//			}else if (first_year <= year){//only first name change occured before the given name
//				return (years_to_first[first_year] + " with unknown last name");
//			}else if (last_year <= year ){//only last name change occured before the given name
//				return (years_to_last[last_year] + " with unknown first name");
//			}else
//				return "Incognito";
//			}
//
//
//	private:
//		map<int,string> years_to_first;
//		map<int,string> years_to_last;
//
//		//returns the last year which is smaller then the given year when the name was changed
//		//if such does not exist return -1
//		int FindFirstName(const map<int,string>& mp , int year){
//			int temp_year = 999999;
//			for (const auto& yr : mp ){
//				if (yr.first > year ){
//					break;
//				}else{//must be a year which is less then compared year
//					temp_year = yr.first;
//				}
//			}
//			return temp_year;
//		}
//
//
//};
//
////
//void TestFirstNameChange(){
//	Person cl1;
//	cl1.ChangeFirstName(1990,"Daria");
//	AssertEqual(cl1.GetFullName(1990),"Daria with unknown last name","First time FIRST name change");
//}
//void TestLastNameChange(){
//	Person cl1;
//	cl1.ChangeLastName(1991,"Erkhova");
//	AssertEqual(cl1.GetFullName(1991),"Erkhova with unknown first name","First time LAST name change");
//}
//void TestFullNameChangeSameYear(){
//	Person cl1;
//	cl1.ChangeLastName(1991,"Erkhova");
//	cl1.ChangeFirstName(1991,"Daria");
//
//	AssertEqual(cl1.GetFullName(1991),"Daria Erkhova","First time Full name change");
//}
//void TestFullNameChangeConsecutiveYear(){
//	Person cl1;
//	cl1.ChangeLastName(1991,"Erkhova");
//	cl1.ChangeFirstName(1992,"Daria");
//
//	AssertEqual(cl1.GetFullName(1993),"Daria Erkhova","Consecutive Full name change");
//	AssertEqual(cl1.GetFullName(1991),"Erkhova with unknown first name","Consecutive FIRST name change");
//
//}
//void TestIncognito(){
//	Person cl1;
//	AssertEqual(cl1.GetFullName(1990),"Incognito","Incognito");
//	cl1.ChangeLastName(1991,"Erkhova");
//	cl1.ChangeFirstName(1992,"Daria");
//
//	AssertEqual(cl1.GetFullName(1990),"Incognito","Incognito");
//	AssertEqual(cl1.GetFullName(1991),"Erkhova with unknown first name","Consecutive FIRST name change");
//
//}
//void TestSeveralNameChanges(){
//	Person cl1;
//	cl1.ChangeLastName(1991,"Erkhova");
//	cl1.ChangeFirstName(1992,"Daria");
//	cl1.ChangeFirstName(1992,"Daria1");
//	cl1.ChangeLastName(2018,"Greenberg");
//
//
//
//	AssertEqual(cl1.GetFullName(1992),"Daria1 Erkhova","Second time FIRST name change");
//	AssertEqual(cl1.GetFullName(2018),"Daria1 Greenberg","Second time full name change ");
//
//}
//int main() {
//  TestRunner runner;
//  runner.RunTest(TestFirstNameChange,"TestFirstNameChange");
//  runner.RunTest(TestLastNameChange,"TestLastNameChange");
//  runner.RunTest(TestFullNameChangeSameYear,"TestFullNameChangeSameYear");
//  runner.RunTest(TestFullNameChangeConsecutiveYear,"TestFullNameChangeConsecutiveYear");
//  runner.RunTest(TestIncognito,"TestIncognito");
//  runner.RunTest(TestSeveralNameChanges,"TestSeveralNameChanges");
//
//
//
//
//  return 0;
//}
