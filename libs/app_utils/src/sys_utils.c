/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */


#define _GNU_SOURCE 
#include <pthread.h>
#include <sched.h>
#include "sys_utils.h"
#include "misc_utils.h"

int set_thread_cpu_range(pthread_t thread, int cpu_idx_begin, int cpu_idx_end)
{
    int i;
    cpu_set_t set;
    
    CPU_ZERO(&set);
    for (i=cpu_idx_begin;i<=cpu_idx_end;i++)
    {
        CPU_SET(i, &set);
    }
    

   return pthread_setaffinity_np(thread, sizeof(set), &set);
}

int set_cur_thread_cpu_range(int cpu_idx_begin, int cpu_idx_end)
{
   return set_thread_cpu_range(pthread_self(), cpu_idx_begin, cpu_idx_end);
}

int bind_cur_thread_to_cpu(int cpu_idx)
{
    return set_cur_thread_cpu_range(cpu_idx, cpu_idx);
}

uint64_t get_cpu_freq()
{
    uint64_t t1, t2;
    t1 = rdtsc();
    nano_sleep(1,0);
    t2 = rdtsc();
    return ((t2-t1)/1000000)*1000000;
}

