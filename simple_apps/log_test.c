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

#include "log.h"


int main(int argc, char *argv[])
{
    init_log("abc.log", 1024*1024);
    
    SysLog("let's write something in log");
    SysLog("a=%d", 555);

    errno=110;
    ErrSysLog("some thing failed");
    return 0;
}

