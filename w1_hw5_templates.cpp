////============================================================================
//// Name        : CourseraWhiteBeltCpp.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : //Template fpr various types for Sqr function
////============================================================================
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <limits>
//#include <map>
//#include <tuple>
//#include <cassert>
//using namespace std;
//
//template <typename tp> tp Sqr(const tp& var);
//template <typename Key,typename Value> map<Key,Value> operator*(const map<Key,Value>& lhs , const map<Key,Value>& rhs );
//template <typename tp> vector<tp> operator*(const vector<tp>& lhs , const vector<tp>& rhs );
//template <class T,class S> pair <T,S> operator*(const pair<T,S>& lhs, const pair<T,S>& rhs);
////template <class T,class S > ostream& operator<<(ostream& out , const map<T,S>& rhs );
////template <class T> ostream& operator<<(ostream& out , const vector<T>& rhs );
////template <class T,class S> ostream&  operator<<(ostream& out , const pair<T,S>& rhs);
//
//template <typename tp>
//tp Sqr(const tp& var){
//	return var*var;
//}
//template <class T,class S>
//pair <T,S> operator*(const pair<T,S>& lhs, const pair<T,S>& rhs){
//	T first=lhs.first*rhs.first;
//	S second= lhs.second*rhs.second;
//	return make_pair(first,second);
//}
//template <typename Key,typename Value>
//map<Key,Value> operator*(const map<Key,Value>& lhs , const map<Key,Value>& rhs ){
//	map<Key,Value> temp;
//	auto it_lhs = lhs.begin();
//	for(auto it=rhs.begin(); it!=rhs.end(); ++it){
//		temp[it->first] = it->second* it_lhs->second;
//		++it_lhs;
//	}
//	return temp;
//}
//template <typename tp>
//vector<tp> operator*(const vector<tp>& lhs , const vector<tp>& rhs ){
//	vector<tp> temp;
//	auto it_lhs = lhs.begin();
//	for(auto it=rhs.begin(); it!=rhs.end(); ++it){
//		temp.push_back((*it)*(*it_lhs));
//		it_lhs++;
//	}
//	return temp;
//}
////
//template <class T,class S >
//ostream& operator<<(ostream& out , const map<T,S>& rhs ){
//
//	for(auto t=rhs.begin(); t!=rhs.end(); ++t){
//		out << *t << " ";
//	}
//	return out;
//}
//template <class T>
//ostream& operator<<(ostream& out , const vector<T>& rhs ){
//
//	for(auto t=rhs.begin(); t!=rhs.end(); ++t){
//		out << *t << " " ;
//	}
//	return out;
//}
//template <class T,class S>
//ostream&  operator<<(ostream& out , const pair<T,S>& rhs){
//	out << "("<< rhs.first<<","<< rhs.second<<")";
//	return out;
//}
//
//
//void test1(){
//		vector<double> b0={5.3,4.4,3.1};
//		vector<int> b1={5,4,3};
//		map<int,int> b2={{1,2},{1,3}};//Does not work
//		map<double,double> b3={{6.6,7.0},{1.8,3.9}};//Does not work
//		pair<double,double> b4={1.5,5};
//		cout << Sqr(b0) << endl;
//		cout << Sqr(b1) << endl;
//		cout << Sqr(b2) << endl;
//		cout << Sqr(b3) << endl;
//		cout << Sqr(b4) << endl;
//}
//
//void test2(){
//		vector<int> v = {1, 2, 3};
//		cout << "vector:";
//		for (int x : Sqr(v)) {
//		  cout << ' ' << x;
//		}
//		cout << endl;
//
//		map<int, pair<int, int>> map_of_pairs = {
//		  {4, {2, 2}},
//		  {7, {4, 3}}
//		};
//		cout << "map of pairs:" << endl;
//		for (const auto& x : Sqr(map_of_pairs)) {
//		  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
//		}
//}
//
//void test3(){
//	vector<map<int, vector<double>>> it = { { {2, { 3, 4,5,6.8 }}}, { {5, {6, 7,0.01}} } };
//	for (const auto& mp : it){
//		for (const auto& itm : mp){
//			for (const auto& val : itm.second ){
//				cout << val << endl;
//			}
//		}
//	}
//
//	vector<map<int, vector<double>>>  it1 = Sqr(it);
//	for (const auto& mp : it1){
//		for (const auto& itm : mp){
//			for (const auto& val : itm.second ){
//				cout << val << endl;
//			}
//		}
//	}
//}
//
//int main(){
//
//	test3();
//	return 0;
//}


