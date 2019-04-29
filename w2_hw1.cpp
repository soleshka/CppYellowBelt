////============================================================================
//// Name        : CourseraWhiteBeltCpp.cpp
//// Author      : Oleg Greenberg
//// Version     : 1
//// Copyright   : Your copyright notice
//// Description : //Another variation of  buses and stops DB . With operation overloading and testing
////============================================================================
//
//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//#include <sstream> //TODO remove before submission
//using namespace std;
//
//
//enum class QueryType {
//  NewBus,
//  BusesForStop,
//  StopsForBus,
//  AllBuses
//};
//
//struct Query {
//  QueryType type;
//  string bus;
//  string stop;
//  vector<string> stops;
//};
//
//istream& operator >> (istream& is, Query& q) {
//	string operation_code	;
//	q = {};   //as a reference is always used in main program
//	is >> operation_code;
//
//		if (operation_code == "NEW_BUS") 		{ q.type = QueryType::NewBus;}
//		else if (operation_code =="BUSES_FOR_STOP") 	{q.type = QueryType::BusesForStop;}
//		else if (operation_code =="STOPS_FOR_BUS")   {q.type = QueryType::StopsForBus;}
//		else if (operation_code == "ALL_BUSES" 	)	{q.type = QueryType::AllBuses;}
//		else {
//			throw runtime_error("No known operation code"+ operation_code);
//		}
//
//	if (operation_code == "NEW_BUS") {
//
//      string bus;
//      is >> q.bus;
//      int stop_count;
//      is >> stop_count;
//      q.stops.resize(stop_count);
//      for (string& stop : q.stops) {
//        is >> stop;
//      }
//
//    } else if (operation_code == "BUSES_FOR_STOP") {
//    	is >> q.stop;
//    } else if (operation_code == "STOPS_FOR_BUS") {
//      	is >> q.bus;
//    }
//
//	//cout  << endl << "Retrieved command: " << operation_code <<" "<< q.bus << " " << q.stop <<endl ;
//
////	for (auto item : q.stops){
////		cout << item << " ";
////	}
//	return is;
//}
//
//struct BusesForStopResponse {
//	vector<string> items;
//	string respond = "";
//};
//
//ostream& operator << (ostream& os, const BusesForStopResponse& r) {
//	 if (r.items.size() == 0) {
//		 os << r.respond;
//	 } else {
//		 for (const string& el : r.items) {
//			 os << el << " ";
//		 }
//	 }
//  return os;
//}
//
//struct StopsForBusResponse {
//	vector<string> items;
//	string respond = "";
//};
//
//ostream& operator << (ostream& os, const StopsForBusResponse& r) {
//	 if (r.items.size() == 0) {
//		 	 os << r.respond;
//	 } else {
//		 string temp_str = "";
//		 bool first = false;
//		 for (const auto& el : r.items) {
//			 if (first) {
//				 temp_str +="\n" + el ;
//			 }else{
//				 first = true;
//				 temp_str +=el ;
//			 }
//		 }
//
//		 os << temp_str;
//	}
//
//  return os;
//}
//
//struct AllBusesResponse {
//
//	vector<string> items;
//	string respond ;
//};
//
//ostream& operator << (ostream& os, const AllBusesResponse& r) {
//
//	if (r.items.size() == 0) {
//		 	 os << r.respond;
//	 }else {
//		 for (const string& el : r.items) {
//			 os << el;
//		 }
//	 }
//  return os;
//}
//
//
//class BusManager {
//public:
//  void AddBus(const string& bus, const vector<string>& stops) {
//	  for (const string& stop : stops) {
//		  stops_to_buses[stop].push_back(bus);
//		  buses_to_stops[bus].push_back(stop);
//      }
//  }
//
//  BusesForStopResponse GetBusesForStop(const string& stop) const {
//	  BusesForStopResponse return_resp;
//	  if (stops_to_buses.count(stop) == 0) {
//		  return_resp.respond = "No stop";
//      } else {
//    	  return_resp.items = stops_to_buses.at(stop);
//      }
//	  return return_resp;
//  }
//
//  StopsForBusResponse GetStopsForBus(const string& bus) const {
//	  StopsForBusResponse return_resp = {{},""};
//	  string temp = "";
//	  if (buses_to_stops.count(bus) == 0) {
//	  		  return_resp.respond = "No bus";
//	  } else {
//		  try{
//		  for (const string& stop : buses_to_stops.at(bus)) {
//			   temp = "Stop " + stop + ": ";
//			   if (stops_to_buses.at(stop).size() == 1) {
//				   temp += "no interchange";
//			   } else {
//				 for (const string& other_bus : stops_to_buses.at(stop)) {
//				   if (bus != other_bus) {
//					   temp += other_bus + " ";
//				   }
//				 }
//			   }
//			   //temp +="\n";
//			   return_resp.items.push_back(temp);
//			 }
//		  }catch(exception& ex){
//			  cout << "Here we go: " << ex.what();
//		  }
//	  }
//
//	  return return_resp;
//  }
//
// AllBusesResponse GetAllBuses() const {
//	  AllBusesResponse return_resp;
//	  string temp;
//	  	 if (buses_to_stops.empty()) {
//	  		return_resp.respond = "No buses";
//		  } else {
//			for (const auto& bus_item : buses_to_stops) {
//				temp = "";
//				temp = "Bus " + bus_item.first + ": ";
//				for (const string& stop : bus_item.second) {
//					temp += stop + " ";
//				}
//				temp +="\n";
//				return_resp.items.push_back(temp);
//			}
//		  }
//	  	 return return_resp;
//  }
//private:
//  map<string, vector<string>> buses_to_stops, stops_to_buses;
//};
//
//
//void testing_main( istringstream& istr,int query_count){
//	  Query q;
//	  BusManager bm;
//	  for (int i = 0; i < query_count; ++i) {
//	    istr >> q;
//	    switch (q.type) {
//	    case QueryType::NewBus:
//	      bm.AddBus(q.bus, q.stops);
//	      break;
//	    case QueryType::BusesForStop:
//	      cout << bm.GetBusesForStop(q.stop) << endl;
//	      break;
//	    case QueryType::StopsForBus:
//	      cout << bm.GetStopsForBus(q.bus) << endl;
//	      break;
//	    case QueryType::AllBuses:
//	      cout << bm.GetAllBuses() << endl;
//	      break;
//	    }
//	  }
//}
//
//void test1_istream(){
//	istringstream istr("NEW_BUS 32 3 A B C\nNEW_BUS 32K 6 D E F A G E\nALL_BUSES\nBUSES_FOR_STOP A\nSTOPS_FOR_BUS 272\n");
//	Query q;
//	//cout << istr.str();
//	for (int i = 0; i < 5; ++i) {
//		istr >> q;
//	}
//}
//
//void test2(){
//	  Query q;
//	  istringstream istr("NEW_BUS 32 3 A B C\nNEW_BUS 32K 6 D E F A G E\nALL_BUSES\nSTOPS_FOR_BUS 32\nBUSES_FOR_STOP A\n");
//	  testing_main(istr,5);
//}
//
//void test3(){
//	  //istringstream istr("ALL_BUSES\nBUSES_FOR_STOP Marushkino\nSTOPS_FOR_BUS 32K\n");
//	  istringstream istr("ALL_BUSES\n"
//			  	  	  	 "BUSES_FOR_STOP Marushkino\n"
//			  	  	  	 "STOPS_FOR_BUS 32K\n"
//			  	  	  	 "NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo\n"
//			  	  	  	 "NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo\n"
//			  	  	  	 "BUSES_FOR_STOP Vnukovo\n"
//			  	  	  	 "NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo\n"
//			  	  	  	 "NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo\n"
//			  	  	  	 "STOPS_FOR_BUS 272\n"
//			  	  	  	 "ALL_BUSES\n");
//	  testing_main(istr,10);
//}
//
//int main() {
//	//test1_istream();
//	//test2();
//	//test3();
//  int query_count;
//  Query q;
//
//  cin >> query_count;
//
//  BusManager bm;
//  for (int i = 0; i < query_count; ++i) {
//    cin >> q;
//    switch (q.type) {
//    case QueryType::NewBus:
//      bm.AddBus(q.bus, q.stops);
//      break;
//    case QueryType::BusesForStop:
//      cout << bm.GetBusesForStop(q.stop) << endl;
//      break;
//    case QueryType::StopsForBus:
//      cout << bm.GetStopsForBus(q.bus) << endl;
//      break;
//    case QueryType::AllBuses:
//      cout << bm.GetAllBuses() << endl;
//      break;
//    }
//  }
//
//  return 0;
//}
