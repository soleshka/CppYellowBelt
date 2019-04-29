////============================================================================
//// Name        : CourseraWhiteBeltCpp.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : //Class for managing Persons tasks list. As one option returns
////numb er of updated status tasks and number of old status jobs
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
//
////map<"string",TasksInfo>  : PErson to his TasksInfo map
//
//enum class TaskStatus{
//	NEW,
//	IN_PROGRESS,
//	TESTING,
//	DONE
//};
//using TasksInfo = map<TaskStatus,int>;
//
//void PrintTasksInfo(TasksInfo tasks_info) {
//  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
//      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
//      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
//      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
//
//}
//
//class TeamTasks {
//	public:
//		//get statistics if statuses of spesific person
//		//conditions : will not be called for person who does not have any tasks. therefore no checks
//		const TasksInfo& GetPersonTasksInfo(const string& person) const{
//			//using at as this is a constant function
//			return data.at(person);
//		}
//		//Add new task (with status new ) for a spesific person
//		void AddNewTask(const string& person){
//			//new task always commes with NEW status
//			data[person][TaskStatus::NEW] ++;
//		}
//		//Refresh status of nu ber of tasks of spesific person
//		//task_count is always positive
//		//if task_count is bigger then number of none finished commands then perform only the none finished
//		//commands .
//		tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
//
//			short status_indx = 0;
//			int i =0 ;
//			TasksInfo  t_new_count , t_old_count;
//			TaskStatus task_status_index = static_cast<TaskStatus>(status_indx);
//			TaskStatus task_status_index_pl1 = static_cast<TaskStatus>(status_indx+1);
//
//			//copy the spesific persons TasksInfos
//			TasksInfo persons_tasks = data[person];
//			t_old_count = data[person];
//			//no need to keep the DONE tasks in the old status
//			t_old_count.erase(TaskStatus::DONE);

//	A better way to iterate over enums
//	TaskStatus Next(TaskStatus task_status) {
//	  return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
//	}
//	 for (TaskStatus status = TaskStatus::NEW;
//	       status != TaskStatus::DONE;
//	       status = Next(status)) {
//			while (i < task_count && task_status_index !=TaskStatus::DONE){
//
//				task_status_index = static_cast<TaskStatus>(status_indx);
//				task_status_index_pl1 = static_cast<TaskStatus>(status_indx+1);
//
//				//when never entered the while loop will end with task_status_index=DONE
//				if (t_old_count.find(task_status_index) != end(t_old_count)){
//					t_old_count[task_status_index]--;
//					data[person][task_status_index]--;
//					t_new_count[task_status_index_pl1]++;
//					data[person][task_status_index_pl1]++;
//					i++;
//
//					//we emptied the current status bucket
//					if (t_old_count[task_status_index] == 0){
//						t_old_count.erase(task_status_index);
//						status_indx++;
//						//t_old_count may very from the original because of transfered tasks
//						if (data[person].at(task_status_index) == 0){
//							data[person].erase(task_status_index);
//						}
//					}
//				}else{
//					status_indx++;
//				}
//			}
//
//
//			return tie(t_new_count,t_old_count);
//		}
//	private:
//		map<string,TasksInfo> data;
//};
//
//
//void test3_5_102(){
//	TeamTasks tasks;
//	TasksInfo updated_tasks, untouched_tasks;
//	tasks.AddNewTask("Ivan");
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 1);
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 1);
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 1);
//	tasks.AddNewTask("Ivan");
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 1);
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 1);
//	tasks.AddNewTask("Ivan");
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 1);
//	tasks.AddNewTask("Ivan");
//
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 5);
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//
//
//
//}
//
//
//void CourseTesting(){
//		  TeamTasks tasks;
//		  tasks.AddNewTask("Ilia");
//		  for (int i = 0; i < 3; ++i) {
//		    tasks.AddNewTask("Ivan");
//		  }
//		  cout << "Ilia's tasks: ";
//		  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//		  cout << "Ivan's tasks: ";
//		  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//
//		  TasksInfo updated_tasks, untouched_tasks;
//
//		  tie(updated_tasks, untouched_tasks) =
//		      tasks.PerformPersonTasks("Ivan", 2);
//		  cout << "Updated Ivan's tasks: ";
//		  PrintTasksInfo(updated_tasks);
//		  cout << "Untouched Ivan's tasks: ";
//		  PrintTasksInfo(untouched_tasks);
//
//		  tie(updated_tasks, untouched_tasks) =
//		      tasks.PerformPersonTasks("Ivan", 2);
//		  cout << "Updated Ivan's tasks: ";
//		  PrintTasksInfo(updated_tasks);
//		  cout << "Untouched Ivan's tasks: ";
//		  PrintTasksInfo(untouched_tasks);
//}
//void test1Basic(){
//	 TeamTasks tasks;
//	  for (int i = 0; i < 3; ++i) {
//		tasks.AddNewTask("Ivan");
//	  }
//
//	  cout << "Ivan's tasks: ";
//	  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//
//	  TasksInfo updated_tasks, untouched_tasks;
//	  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 1);
//	  cout << "Ivans's tasks: ";
//	  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//
//	  cout << "Updated Ivan's tasks: ";
//	  PrintTasksInfo(updated_tasks);
//
//	  cout << "Untouched Ivan's tasks: ";
//	  PrintTasksInfo(untouched_tasks);
//	/*************************************************************************/
//
//	  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 1);
//	  cout << "Ivans's tasks: ";
//	  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//
//	  cout << "Updated Ivan's tasks: ";
//	  PrintTasksInfo(updated_tasks);
//
//	  cout << "Untouched Ivan's tasks: ";
//	  PrintTasksInfo(untouched_tasks);
//	/*************************************************************************/
//
//	  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 1);
//	  cout << "Ivans's tasks: ";
//	  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//
//	  cout << "Updated Ivan's tasks: ";
//	  PrintTasksInfo(updated_tasks);
//
//	  cout << "Untouched Ivan's tasks: ";
//	  PrintTasksInfo(untouched_tasks);
//}
//void PrintUntouchedUPdated(TasksInfo updated_tasks,TasksInfo untouched_tasks){
//	  cout << "Updated Ivan's tasks: ";
//	  PrintTasksInfo(updated_tasks);
//
//	  cout << "Untouched Ivan's tasks: ";
//	  PrintTasksInfo(untouched_tasks);
//	  cout << endl;
//}
//void test2Additional(){
//	TeamTasks tasks;
//	TasksInfo updated_tasks, untouched_tasks;
//	for (int i = 0; i < 5; ++i) {
//		tasks.AddNewTask("Alice");
//	}
//
//	tie(updated_tasks, untouched_tasks) =tasks.PerformPersonTasks ("Alice", 5);
//	PrintUntouchedUPdated(updated_tasks,untouched_tasks);
//
//	tie(updated_tasks, untouched_tasks) =tasks.PerformPersonTasks ("Alice", 5);
//	PrintUntouchedUPdated(updated_tasks,untouched_tasks);
//
//	tie(updated_tasks, untouched_tasks) =tasks.PerformPersonTasks ("Alice", 1);
//	PrintUntouchedUPdated(updated_tasks,untouched_tasks);
//
//	for (int i = 0; i < 5; ++i) {
//		tasks.AddNewTask ("Alice");
//	}
//
//	tie(updated_tasks, untouched_tasks) =tasks.PerformPersonTasks ("Alice", 2);
//	PrintUntouchedUPdated(updated_tasks,untouched_tasks);
//
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//	tie(updated_tasks, untouched_tasks) =tasks.PerformPersonTasks ("Alice", 4);
//	PrintUntouchedUPdated(updated_tasks,untouched_tasks);
//
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//	tie(updated_tasks, untouched_tasks) =tasks.PerformPersonTasks ("Alice", 5);
//	PrintUntouchedUPdated(updated_tasks,untouched_tasks);
//
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//	tie(updated_tasks, untouched_tasks) =tasks.PerformPersonTasks ("Alice", 10);
//	PrintUntouchedUPdated(updated_tasks,untouched_tasks);
//
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//	tie(updated_tasks, untouched_tasks) =tasks.PerformPersonTasks ("Alice", 10);
//	PrintUntouchedUPdated(updated_tasks,untouched_tasks);
//
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//	for (int i = 0; i < 1; ++i) {
//		tasks.AddNewTask ("Alice");
//	}
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//	tie(updated_tasks, untouched_tasks) =tasks.PerformPersonTasks ("Alice", 2);
//	PrintUntouchedUPdated(updated_tasks,untouched_tasks);
//
//	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//	tie(updated_tasks, untouched_tasks) =tasks.PerformPersonTasks("Bob",3);
//	PrintUntouchedUPdated(updated_tasks,untouched_tasks);
//
//}
//int main(){
//	//test1Basic();
//	//test2Additional();
//	//CourseTesting();
//
//	test3_5_102();
//
//
//	return 0;
//}
//
//
