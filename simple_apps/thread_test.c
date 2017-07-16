/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#include <stdio.h>
#include "sys_utils.h"
#include "signal_utils.h"
#include "debug.h"

static char thread_para[]="hello, hehe";


static void *thread_func(void *arg)
{
    int dest_cpu;
	char buf[16];
    DBG_PRINT("%s", thread_para);
	while (1)
	{
	    fgets(buf, sizeof(buf), stdin);
		dest_cpu=atoi(buf);
		DBG_PRINT("input=%s; dest_cpu=%d", buf, dest_cpu);
		bind_cur_thread_to_cpu(dest_cpu);
	}

	return NULL;
}

int main(int argc, char *argv[])
{
    int ret, dest_cpu=0;
	pthread_t the_thread;
	char buf[16];

	if (argc > 1)
		dest_cpu=atoi(argv[1]);
	bind_cur_thread_to_cpu(dest_cpu);
	
	DBG_PRINT("input dest cpu idx for new thread:");
	fgets(buf, sizeof(buf), stdin);
	dest_cpu=atoi(buf);
	DBG_PRINT("input=%s; dest_cpu=%d", buf, dest_cpu);



	ret=create_thread_full(&the_thread, thread_func, thread_para, dest_cpu, dest_cpu, SCHED_FIFO, 30);
	DBG_PRINT("==ret=%d", ret);
	if (ret)
		ERR_DBG_PRINT_QUIT("==");
	
	pthread_join(the_thread, NULL);

    return 0;
}

