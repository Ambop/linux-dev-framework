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
#include "misc_utils.h"
#include "log.h"
#include "debug.h"
char aaa[100];
int main(int argc, char *argv[])
{
    unsigned long vir, phy;
    init_log("abc.log", 1024*1024);
        
    vir = (unsigned long)(void *)aaa;
    mem_addr_vir2phy(vir, &phy);
    DBG_PRINT("vir=0x%lx(%lu)", vir, vir);
    DBG_PRINT("phy=0x%lx(%lu)", phy, phy);
    return 0;
}

