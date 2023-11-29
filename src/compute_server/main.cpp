#include "flow_compute_server.hpp"

int main(){
	
	pid_t main_process_ID = getpid();
	std::cout << "我是 main_process 進程: " << main_process_ID << std::endl ;


	pid_t rece_process_ID = fork();	//產生接收進程

	if (rece_process_ID == -1) {
		std::cerr << "rece_process fork 失敗" << std::endl;
		return 1;
	}
	else if (rece_process_ID == 0) {
		std::cout << "我是 rece_process 進程: " << getpid() << std::endl ;
		return 0;
	}
	else {
		pid_t comp_process_ID = fork();	//產生運算進程
		if (comp_process_ID == -1) {
			std::cerr << "comp_process fork 失敗" << std::endl;
			return 1;
		}
		else if (comp_process_ID == 0) {
			std::cout << "我是 comp_process 進程: " << getpid() << std::endl ;
			return 0;
		}
		else {
			pid_t send_process_ID = fork();	//產生發送進程
			if (send_process_ID == -1) {
				std::cerr << "send_process fork 失敗" << std::endl;
				return 1;
			}
			else if (send_process_ID == 0) {
				std::cout << "我是 send_process 進程: " << getpid() << std::endl ;
				return 0;
			}
		}
	}
	return 0;


}

