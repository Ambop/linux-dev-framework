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
#include <string.h>
#include "mm.h"

int print_buf(void *buf)
{
    printf("buf contents: %s\n", (char *)buf);
    return 0;
}

int main(int argc, char *argv[])
{
    MM_HANDLE hd=create_buffer_manager(128, 3);
    char *buf1, *buf2, *buf3;
    assert(MM_HANDLE_IS_VALID(hd));
    assert(3==free_buffer_num(hd));

    buf1 = alloc_buffer(hd);
    assert(2==free_buffer_num(hd));
    strcpy(buf1, "buf1");
    printf("buf1=%p : %s\n", buf1, buf1);
    
    buf2 = alloc_buffer(hd);
    assert(1==free_buffer_num(hd));
    strcpy(buf2, "buf2");
    printf("buf2=%p : %s\n", buf2, buf2);

    buf3 = alloc_buffer(hd);
    assert(0==free_buffer_num(hd));
    strcpy(buf3, "buf3");
    printf("buf3=%p : %s\n", buf3, buf3);

    for_each_buf_in_all_link(hd, print_buf);
    add_to_all_link(hd, buf3);
    add_to_all_link(hd, buf2);
    add_to_all_link(hd, buf1);
    for_each_buf_in_all_link(hd, print_buf);
    delete_from_all_link(hd, buf3);
    delete_from_all_link(hd, buf2);
    delete_from_all_link(hd, buf1);
    for_each_buf_in_all_link(hd, print_buf);

    free_buffer(hd, buf1);
    free_buffer(hd, buf2);
    free_buffer(hd, buf3);

    buf1 = alloc_buffer(hd);
    assert(2==free_buffer_num(hd));
    strcpy(buf1, "buf1");
    printf("buf1=%p : %s\n", buf1, buf1);
    
    buf2 = alloc_buffer(hd);
    assert(1==free_buffer_num(hd));
    strcpy(buf2, "buf2");
    printf("buf2=%p : %s\n", buf2, buf2);
    
    buf3 = alloc_buffer(hd);
    assert(0==free_buffer_num(hd));
    strcpy(buf3, "buf3");
    printf("buf3=%p : %s\n", buf3, buf3);
    
    return 0;
}

