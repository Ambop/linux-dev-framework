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

#include "measure.h"

void f1()
{
    printf("f1 \n");
}

void f2()
{
    printf("f2 \n");
}

void test_perform()
{
    int i;
    DECLAIRE_TIME_MEASURE(f1);
    DECLAIRE_TIME_MEASURE(f2);

    INIT_TIME_MEASURE(f1);
    INIT_TIME_MEASURE(f2);

    for (i=0; i<5; i++)
    {
        TIME_MEASURE_BEGIN(f1);
        f1();
        TIME_MEASURE_END(f1);

    }

    for (i=0; i<3; i++)
    {
        TIME_MEASURE_BEGIN(f2);
        f2();
        TIME_MEASURE_END(f2);

    }


}

int main(int argc, char *argv[])
{
    init_measure(2);
    test_perform();
    report_measure();
    return 0;
}

