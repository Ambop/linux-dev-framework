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
#include "timer_utils.h"
#include "debug.h"
static void    hehe(int sig_no, siginfo_t *pt_siginfo, void *p_ucontext)
{
    DBG_PRINT("==");
    
}

int main(int argc, char *argv[])
{
    timer_t  timerid;
    create_posix_timer(&timerid, hehe, 1, 0);

    while (1) sleep(5);
    return 0;
}

