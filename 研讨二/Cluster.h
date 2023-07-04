#pragma once
//超算集群系统
#include<iostream>
#include"LinkedQueue.h"
#include<iomanip>
using namespace std;
class Cluster {
	private:
		LinkedQueue<Task> waiting_queue; // 等待队列
		LinkedQueue<Task> running_queue; // 运行队列
		LinkedQueue<Task> finished_queue; // 已完成队列
		int cpu_total; // CPU 总数
		int gpu_total; // GPU 总数
		int memory_total; // 内存总大小
		int cpu_used; // CPU 已使用数
		int gpu_used; // GPU 已使用数
		int memory_used; // 内存已使用大小
		int id_counter; // 任务 ID 计数器
		int* _cpu;  //cpu指针数组
		int* _gpu;  //gpu指针数组
		int* _memory; //内存指针数组
public:
	Cluster(int _cpu_total, int _gpu_total, int _memory_total);
	void submit_task(Task task);
	void schedule();
	void display_resource_usage();
};

Cluster::Cluster(int _cpu_total, int _gpu_total, int _memory_total)
	: cpu_total(_cpu_total), gpu_total(_gpu_total), memory_total(_memory_total),
	cpu_used(0), gpu_used(0), memory_used(0), id_counter(0) 
	{
		_cpu=new int[cpu_total];
		for(int i=0;i<cpu_total;i++) _cpu[i]=0;
		_gpu=new int[gpu_total];
		for(int i=0;i<gpu_total;i++) _gpu[i]=0;
		_memory=new int[memory_total];
		for(int i=0;i<memory_total;i++) _memory[i]=0;
	}
// 提交任务
void Cluster::submit_task(Task task) {
	task.id = ++id_counter;
	waiting_queue.push(task);
	cout << "任务 ID 为 " << task.id << " 的任务已提交" << endl;
}

// 调度任务
void Cluster::schedule() {
	// 遍历等待队列，如果有足够的资源就将任务放入运行队列
	int n=waiting_queue.size();
	while(n!=0){
	while (!waiting_queue.empty()&&n>0) {
		Task task = waiting_queue.front();
		if (cpu_used + task.cpu <= cpu_total && gpu_used + task.gpu <= gpu_total &&
			memory_used + task.memory <= memory_total) {
			// 更新可用资源数量
			int a=cpu_used,b=gpu_used,c=memory_used;
			for(int i=0;i<task.cpu;i++) {_cpu[a]=task.id;a++;}
			for(int i=0;i<task.gpu;i++) {_gpu[b]=task.id;b++;}
			for(int i=0;i<task.memory;i++) {_memory[c]=task.id;c++;}
			// 将任务从等待队列移到运行队列
			cpu_used += task.cpu;
			gpu_used += task.gpu;
			memory_used += task.memory;
			waiting_queue.pop();
			running_queue.push(task);
			cout << "任务 ID 为 " << task.id << " 的任务已加入运行队列" << endl;
			n--;
			display_resource_usage();
		}
		else {
			// 如果资源不足，将任务移至等待队列尾部
			task = waiting_queue.front();
			if(task.cpu>cpu_total||task.gpu>gpu_total||task.memory>memory_total)
			{cout<<"任务 ID 为 "<<task.id<<"的任务所需资源超过总资源"<<",将从等待队列中移除此任务。"<<endl;
				waiting_queue.pop();
				system("pause");
				continue;
			}
			waiting_queue.pop();
			waiting_queue.push(task);
			cout << "任务 ID 为 " << task.id << " 的任务因资源不足被移至等待队列尾部" << endl; 
			n--;
		}
	}
  int a=0,b=0,c=0;
	while (!running_queue.empty()) {
		Task task = running_queue.front();
	for(int i=0;i<task.cpu;i++) {_cpu[a]=0;a++;}
	for(int i=0;i<task.gpu;i++) {_gpu[b]=0;b++;}
	for(int i=0;i<task.memory;i++) {_memory[c]=0;c++;}
		running_queue.pop();
		finished_queue.push(task);
		// 更新可用资源数量
		cpu_used -= task.cpu;
		gpu_used -= task.gpu;
		memory_used -= task.memory;
		cout << "任务 ID 为 " << task.id << " 的任务已完成" << endl;
		display_resource_usage();
	}
	n=waiting_queue.size();
	}
}
// 显示资源使用情况
void Cluster::display_resource_usage() {
	cout << "CPU 使用情况：" << cpu_used << "/" << cpu_total << " 个" << endl;
	cout << "GPU 使用情况：" << gpu_used << "/" << gpu_total << " 个" << endl;
	cout << "内存使用情况：" << memory_used << "/" << memory_total << " GB" << endl;
	int a=cpu_total,b=gpu_total,c=memory_total;
	int n=(a>b)?((a>c)?a:c):((b>c)?b:c);
	for(;n>0;n--)
	{
	if(a>0) {if(_cpu[cpu_total-a]==0) cout<<"CPU"<<cpu_total-a<<":"<<left<<setw(12)<<"空闲";else cout<<"CPU"<<cpu_total-a<<":"<<"任务"<<_cpu[cpu_total-a]<<left<<setw(7)<<"使用";a--;}
	else cout<<right<<setw(17)<<setfill(' ')<<" ";
    if(b>0) {if(_gpu[gpu_total-b]==0) cout<<"GPU"<<gpu_total-b<<":"<<left<<setw(12)<<"空闲";else cout<<"GPU"<<gpu_total-b<<":"<<"任务"<<_gpu[gpu_total-b]<<left<<setw(7)<<"使用";b--;}
	else cout<<right<<setw(17)<<setfill(' ')<<" ";
	if(c>0) {if(_memory[memory_total-c]==0) cout<<"MEMORY"<<memory_total-c<<":"<<left<<setw(12)<<"空闲";else cout<<"MEMORY"<<memory_total-c<<":"<<"任务"<<_memory[memory_total-c]<<left<<setw(7)<<"使用";c--;}
	cout<<endl;
	}
}
