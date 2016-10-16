/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#ifndef __P2P_H_
#define __P2P_H_
#include <stdint.h>

#define    P2P_MSG_CODE_BEGIN       (100)

#define    MSG_P2P_CONN_REQ                (P2P_MSG_CODE_BEGIN+1)
#define    MSG_P2P_CONN_RESP_DST_OFFLINE   (P2P_MSG_CODE_BEGIN+2)
#define    MSG_P2P_CONN_RESP_OK            (P2P_MSG_CODE_BEGIN+3)


typedef struct
{
    uint32_t    msg_id;
    char        usr_src[32];
    char        usr_dst[32];
    char        pass_word[32];
} __attribute__ ((packed)) t_P2P_CONN_REQ;


typedef struct
{
    uint32_t    msg_id;
    char        usr_src[32];
    char        usr_dst[32];

    char         usr_src_ip[40];
    uint16_t     usr_src_port;
    char         usr_dst_ip[40];
    uint16_t     usr_dst_port;
} __attribute__ ((packed)) t_P2P_CONN_RPLY;

#endif

