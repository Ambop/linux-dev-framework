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
#include <errno.h>
#include <assert.h>
#include "debug.h"
#include "pc_queue.h"


int main(int argc, char *argv[])
{
    int a[] = {0,1,2,3,4};
    int value, i;
    t_pc_que *pt_q = create_pc_que(16);
    assert(pt_q);
    for (i=0;i<5;i++)
    assert(0==pc_que_enq_try(pt_q, &a[i], 0, NULL));
for (i=0;i<5;i++)
{
    value = *(int *)pc_que_outq_try(pt_q, NULL, NULL);
    assert(i==value);
    DBG_PRINT("value=%d", value);
}
    return 0;
}

