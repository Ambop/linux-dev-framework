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
#include <string.h>
#include "config_file_ops.h"

char *some_data="abc=\"123\"";
int main(int argc, char *argv[])
{
    FILE *file=fopen("test.config", "w");
    
    fwrite(some_data, 1, strlen(some_data),
                     file);
    fclose(file);

    parse_config_file("test.config", 0);

    printf("abc=%s\n", get_config_var("abc"));

    return 0;
}

