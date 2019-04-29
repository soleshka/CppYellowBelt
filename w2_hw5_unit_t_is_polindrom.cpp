////============================================================================
//// Name        : CourseraWhiteBeltCpp.cpp
//// Author      : Oleg Greenberg
//// Version     : 1
//// Copyright   : Your copyright notice
//// Description : //Unit testing for IsPalindrom function using self defined Unittesting environment
////============================================================================
//#include <iostream>
//#include <map>
//#include <set>
//#include <sstream>
//#include <stdexcept>
//#include <string>
//#include <vector>
//#include <algorithm>
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
//bool IsPalindrom(string str){
//	string str_temp = str;
//	reverse(str_temp.begin(),str_temp.end());
//	if ( !str.compare(str_temp) )
//		return true;
//	return false;
//}
//
//void TestNullString(){
//	Assert(IsPalindrom("")==true,"Null string");
//}
//void Test1CharString(){
//	Assert(IsPalindrom("a")==true,"One char string");
//}
//void TestSpacesInString(){
//	Assert(IsPalindrom("a a")==true,"Spaces in string : 'a a' ");
//	Assert(!IsPalindrom(" a a"),"Spaces in string fail: ' a a' ");
//	Assert(!IsPalindrom("a a "),"Spaces in string fail: 'a a ' ");
//
//
//}
//void TestFalseString(){
//	Assert(IsPalindrom("abca")==false,"abca did not fail");
//	Assert(IsPalindrom("ab d")==false,"'ab d' did not fail");
//	Assert(IsPalindrom(" cab d")==false,"' cab d' did not fail");
//	Assert(!IsPalindrom("wasitacaRoracatisaw"), "wasitacaRoracatisaw");
//	Assert(!IsPalindrom("bbbbbBBBB"),"'bbbbbBBBB' did not pass");
//	Assert(!IsPalindrom("_ bb A  bb _"),"'_ bb A  ab _' did not pass");
//	Assert(!IsPalindrom("AB sioisBA"), "AB sioisBA did not fail");
//	Assert(!IsPalindrom("ABsi oisBA"), "ABsi oisBA did not fail");
//	Assert(!IsPalindrom("ABA aba"), "ABA aba");
//	Assert(!IsPalindrom("ABA "), "ABA ");
//	Assert(!IsPalindrom("ABA d"), "ABA d");
//	Assert(!IsPalindrom("ABA dcdcd"), "ABA dcdcd");
//	Assert(!IsPalindrom("\tABA   "), "'\tABA   ' did not fail");
//
//	  Assert(!IsPalindrom("wasitacaRoracatisaw"), "wasitacaRoracatisaw");
//	  Assert(!IsPalindrom("wasitacAroracatisaw"), "wasitacAroracatisaw");
//	  Assert(!IsPalindrom("wasitaCaroracatisaw"), "wasitaCaroracatisaw");
//	  Assert(!IsPalindrom("wasitAcaroracatisaw"), "wasitAcaroracatisaw");
//	  Assert(!IsPalindrom("wasiTacaroracatisaw"), "wasiTacaroracatisaw");
//	  Assert(!IsPalindrom("wasItacaroracatisaw"), "wasItacaroracatisaw");
//	  Assert(!IsPalindrom("waSitacaroracatisaw"), "waSitacaroracatisaw");
//	  Assert(!IsPalindrom("wAsitacaroracatisaw"), "wAsitacaroracatisaw");
//	  Assert(!IsPalindrom("wasitacaRracatisaw"), "wasitacaRoracatisaw");
//	  Assert(!IsPalindrom("wasitacArracatisaw"), "wasitacAroracatisaw");
//	  Assert(!IsPalindrom("wasitaCarracatisaw"), "wasitaCaroracatisaw");
//	  Assert(!IsPalindrom("wasitAcarracatisaw"), "wasitAcaroracatisaw");
//	  Assert(!IsPalindrom("wasiTacarracatisaw"), "wasiTacaroracatisaw");
//	  Assert(!IsPalindrom("wasItacarracatisaw"), "wasItacaroracatisaw");
//	  Assert(!IsPalindrom("waSitacarracatisaw"), "waSitacaroracatisaw");
//	  Assert(!IsPalindrom("wAsitacarracatisaw"), "wAsitacaroracatisaw");
//
//
//
//}
//void TestTrueString(){
//	Assert(IsPalindrom("abba"),"abba did not pass");
//	Assert(IsPalindrom("    "),"'    ' did not pass");
//	Assert(IsPalindrom("bbbbb"),"'bbbbb' did not pass");
//	Assert(IsPalindrom("0 - 1 - 0"),"'0 - 1 - 0' did not pass");
//	Assert(IsPalindrom(" _bbbbb_ "),"' _bbbbb_ ' did not pass");
//	Assert(IsPalindrom("_ bb A bb _"),"'_ bb A bb _' did not pass");
//	Assert(IsPalindrom("\tABA\t"), "'\tABA\t' did not pass");
//
//	AssertEqual(IsPalindrom(""), true, "empty string");
//	AssertEqual(IsPalindrom(" "), true, "whitespace");
//	AssertEqual(IsPalindrom("A"), true, "A");
//	AssertEqual(IsPalindrom("&"), true, "&");
//	AssertEqual(IsPalindrom("1"), true, "1");
//	AssertEqual(IsPalindrom("121"), true, "121");
//	AssertEqual(IsPalindrom("@@"), true, "@@");
//	AssertEqual(IsPalindrom("!@# #@!"), true, "!@# #@!");
//	AssertEqual(IsPalindrom("madam"), true, "madam");
//	AssertEqual(IsPalindrom("baobab"), false, "baobab");
//	AssertEqual(IsPalindrom(" weew "), true, " weew ");
//	AssertEqual(IsPalindrom("f f ff f f"), true, "f f ff f f");
//	AssertEqual(IsPalindrom("f f f f f"), true, "f f f f f");
//	AssertEqual(IsPalindrom("A  L L A"), false, "A  L L A");
//	AssertEqual(IsPalindrom("mada m"), false, "mada m");
//	AssertEqual(IsPalindrom(" weew   "), false, " weew   ");
//	AssertEqual(IsPalindrom("   weew "), false, "   weew ");
//	AssertEqual(IsPalindrom("qwertyTrewq"), false, "qwertyTrewq");
//	AssertEqual(IsPalindrom("qwertytrewq"), true, "qwertytrewq");
//	AssertEqual(IsPalindrom("qwerttrewq"), true, "qwerttrewq");
//	AssertEqual(IsPalindrom("qwertytrewQ"), false, "qwertytrewQ");
//	AssertEqual(IsPalindrom("Q wer ewQ"), false, "Q wer ewQ");
//
//
//
//}
//int main() {
//  TestRunner runner;
//  runner.RunTest(TestNullString,"TestNullString");
//  runner.RunTest(Test1CharString,"Test1CharString");
//  runner.RunTest(TestSpacesInString,"TestSpacesInString");
//  runner.RunTest(TestFalseString,"TestFalseString");
//  runner.RunTest(TestTrueString,"TestTrueString");
//
//  return 0;
//}
//
//
