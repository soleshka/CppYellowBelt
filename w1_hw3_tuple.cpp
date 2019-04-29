////============================================================================
//// Name        : CourseraWhiteBeltCpp.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : //print elements which are above average
////============================================================================
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <limits>
//#include <map>
//using namespace std;
//
////enum class Lang {
////  DE, FR, IT
////};
////struct Region {
////  string std_name;
////  string parent_std_name;
////  map<Lang, string> names;
////  int64_t population;
////};
//
//bool operator<(const Region& lhs, const Region& rhs){
//	return (tie(lhs.std_name,lhs.parent_std_name,lhs.names,lhs.population) <
//			tie(rhs.std_name,rhs.parent_std_name,rhs.names,rhs.population));
//
//
//}
//int FindMaxRepetitionCount(const vector<Region>& regions){
//	map<Region,int> reg_to_count;
//	if (regions.size()==0) return 0; //no element exists
//	else{
//		//regions is not empty
//		for(unsigned int i=0;i<regions.size();i++){
//			if (reg_to_count.count(regions[i]) != 0 ){
//				reg_to_count[regions[i]]++;
//			}else{
//				reg_to_count[regions[i]]=1;
//			}
//		}
//		auto mx = max_element(reg_to_count.begin(), reg_to_count.end(),
//		    [](const pair<Region, int>& p1, const pair<Region, int>& p2) {
//		        return p1.second < p2.second; });
//		return mx->second ;
//	}
//}
//
//
////A better solution :
////int FindMaxRepetitionCount(const vector<Region>& regions) {
////  int result = 0;
////  map<Region, int> repetion_count;
////  for (const Region& region : regions) {
////    result = max(result, ++repetion_count[region]);
////  }
////  return result;
////}
//
//
//
////int main() {
////
////
////	cout << FindMaxRepetitionCount({
////	      {
////	          "Moscow",
////	          "Russia",
////	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
////	          89
////	      }, {
////	          "Russia",
////	          "Eurasia",
////	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
////	          89
////	      }, {
////	          "Moscow",
////	          "Russia",
////	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
////	          89
////	      }, {
////	          "Moscow",
////	          "Russia",
////	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
////	          89
////	      }, {
////	          "Russia",
////	          "Eurasia",
////	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
////	          89
////	      },
////	  }) << endl;
////
////	  cout << FindMaxRepetitionCount({
////	      {
////	          "Moscow",
////	          "Russia",
////	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
////	          89
////	      }, {
////	          "Russia",
////	          "Eurasia",
////	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
////	          89
////	      }, {
////	          "Moscow",
////	          "Russia",
////	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
////	          89
////	      }, {
////	          "Moscow",
////	          "Toulouse",
////	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
////	          89
////	      }, {
////	          "Moscow",
////	          "Russia",
////	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
////	          31
////	      },
////	  }) << endl;
////
////
////	return 0;
////}


