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
#if 1
#include <openssl/md5.h> /* link with -lcrypto not -lcrypt , see man 3 crypto and man 3 crypt */
#define USE_OPENSSL_MD5
#else
#include "md5.h"
#endif
#include "debug.h"

#ifdef USE_OPENSSL_MD5
void md5_test(const char *str)
{
  MD5_CTX context;
  unsigned char digest[16];
  unsigned int len = strlen (str);

  MD5_Init (&context);
  MD5_Update (&context, str, len);
  MD5_Final (digest, &context);

  print_mem(digest,16);
}
#else
void md5_test(const char *str)
{
  MD5_CTX context;
  unsigned char digest[16];
  unsigned int len = strlen (str);

  MD5Init (&context);
  MD5Update (&context, str, len);
  MD5Final (digest, &context);

  print_mem(digest,16);
}
#endif


int main(int argc, char *argv[])
{
	DBG_PRINT_S("hello");
	md5_test("abc");

	return 0;
}

