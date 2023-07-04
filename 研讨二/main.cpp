#include"Cluster.h"
#include<iostream>
using namespace std;
	int main() 
{
	Cluster cluster(8, 4, 32); // 初始化超算集群，总共有 8 个 CPU、4 个 GPU、32 GB 内存
	cluster.submit_task({ 1, 1, 0, 4, 5 }); // 提交任务，需要 1 个 CPU、4 GB 内存，预计运行 5 秒
	cluster.submit_task({ 2, 1, 0, 4, 5 }); // 提交任务，需要 1 个 CPU、4 GB 内存，预计运行 5 秒
	cluster.submit_task({ 3, 0, 1, 4, 5 }); // 提交任务，需要 1 个 GPU、4 GB 内存，预计运行 5 秒
	cluster.submit_task({ 4, 0, 1, 4, 5 }); // 提交任务，需要 1 个 GPU、4 GB 内存，预计运行 5 秒
	cluster.submit_task({ 5, 2, 0, 8, 10 }); // 提交任务，需要 2 个 CPU、8 GB 内存，预计运行 10 秒
    cluster.submit_task({ 6, 9, 0, 1, 5 });// 提交任务，需要 9 个 CPU，1 GB 内存，预计运行 5 秒
	cluster.submit_task({ 7, 5, 3, 4, 6 });// 提交任务，需要 5 个 CPU、3 个 GPU、4 GB 内存，预计运行 6 秒
	cluster.submit_task({ 8, 0, 5, 5, 4 });// 提交任务，需要 5 个 GPU，5 GB 内存，预计运行 4秒
	cluster.display_resource_usage(); // 显示资源使用情况
	cluster.schedule(); // 调度任务
	cluster.display_resource_usage(); // 显示资源使用情况
	return 0;
}
