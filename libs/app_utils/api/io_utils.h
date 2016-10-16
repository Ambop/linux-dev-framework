/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef  __IO_UTILS_H__
#define  __IO_UTILS_H__

#include <unistd.h>

int fd_readable(int fd, int sec, int usec);
int fd_writeable(int fd, int sec, int usec);
int set_fd_nonblock(int fd);
int write_reliable(int fd, const void *buf, size_t count);
int write_certain_bytes(int fd, const void *buf, size_t count);
int read_reliable(int fd, void *buf, size_t count);
int read_certain_bytes(int fd, void *buf, size_t count);
int printf_to_fd(int fd, const char *fmt, ...);
int get_temp_file(char *path);

#endif

