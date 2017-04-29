/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef  __COMMON_H__
#define  __COMMON_H__

#include <stdio.h>
#include <getopt.h>
#include <inttypes.h>

#define    ARRAY_SIZE(array_name)    (sizeof(array_name)/sizeof(array_name[0]))
#define    MEMBER_OFFSET(type_name, member_name)    ((unsigned long)(void *)(&(((type_name *)NULL)->member_name)))

static inline void print_usage(const char *prog, const char *syntax, const struct option *opts, int nr_opt)
{
    int i;
    printf("usage:\n"
		  "\t%s %s\n\n"
		  ,prog
		  ,syntax);

	printf("full option list:\n"
		"%-32s    %-12s\n"
		,"<name>"
		,"<has arg>");

	for (i=0; i<nr_opt; i++)
		if (opts[i].name)
			printf("--%-30s    %-12s\n"
			,opts[i].name
			,(opts[i].has_arg==required_argument)?"yes":"no");
	
}


static inline void print_stats(int no_prt_zero_item, const uint64_t *items, const char *item_names[], int nr)
{

    int i;
	printf("\n");

	for (i=0; i<nr; i++)
		if (items[i] || !no_prt_zero_item)
			printf("%-32s    0x%-16"PRIx64"(%"PRIu64")\n"
			,item_names[i]
			,items[i], items[i]);

}

#endif

