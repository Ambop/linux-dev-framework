/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef  __STRING_UTILS_H__
#define  __STRING_UTILS_H__

#include <string.h>
#include   "defs.h"

int str_trim(char *output, char * input);
int str_trim_len(char *output, char * input, int len);
int str_trim_all_len(char *output, char * input, int len);
int str_trim_all(char *output, char * input);
int str_replace_substr(char *output, char *input, char *from, char *to);
void trim_new_line(char *str);
#endif

