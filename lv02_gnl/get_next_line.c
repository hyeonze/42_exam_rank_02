#include "get_next_line.h"

int     ft_strlen(char *s)
{
    int ret;

    ret = 0;
    if (!s)
        return (0);
    while (s[ret])
        ret++;
    return (ret);
}


char    *ft_strjoin(char *remains, char *buf)
{
    int     i;
    int     j;
    char    *arr;

    i = 0;
    j = 0;
    if (!(arr = (char*)malloc(ft_strlen(remains) + ft_strlen(buf) + 1)));
    if (remains)
    {
        while (remains[i])
        {
            arr[i] = remains[i];
            i++;
        }
    }
    while (buf[j])
    {
        arr[i] = buf[j];
        i++;
        j++;
    }
    arr[i] = '\0';
    free(remains);
    return(arr);
}

char    *push_line(char *remains)
{
    int     i;
    char    *arr;

    i = 0;
    while (remains[i] && remains[i] != '\n') // reamins[i]가 존재하고, 개행아니면 i++(끝이나 개행까지 인덱스밀기)
        i++;
    if (!(arr = (char*)malloc(i + 1))) // arr에 i+1만큼 메모리 할당, 실패시 null반환
        return (NULL);
    i = 0;
    while (remains[i] && remains[i] != '\n') // reamins[i]가 존재하고, 개행아니면
    {
        arr[i] = remains[i]; // arr[i]에 remains[i]저장
        i++;
    }
    arr[i] = '\0'; // arr마지막에 '\0'
    return (arr); // arr반환
}

char    *cut_next_line(char *remains)
{
    int     i;
    int     j;
    char    *arr;

    i = 0;
    j = 0;
    while (remains[i] && remains[i] != '\n') // remains[i] null이거나 개행일때 까지 인덱스 밀기
        i++;
    if (remains[i] == '\0') // reamins[i]가 null인 경우(개행없음)
    {
        free(remains); // reamins해제
        return (NULL); // NULL반환
    }
    if (!(arr = (char*)malloc(ft_strlen(remains) - i + 1))) // arr에 개행후 길이만큼 메모리 할당
        return (NULL);
    i++;
    while (remains[i]) // reamins 끝날 때 까지 array에 복사
    {
        arr[j] = remains[i];
        i++;
        j++;
    }
    arr[j] = '\0'; // arr마지막 칸 null
    free(remains); // reamins해제
    return (arr); // array반환
}

int     get_next_line(char **line)
{
    int            count;
    char           buf[2];
    static char    *remains;

    if (!line) // 라인이 없을 경우 -1반환
        return (-1);
    count = 1;
    while (count != 0 && buf[0] != '\n')
    {
        if ((count = read(0, buf, 1)) == -1) // fd로 BUFFER_SIZE만큼 읽어 buffer에 저장, count에 바이트수 저장
            return (-1); // 읽기에 실패할 경우 -1반환
        buf[count] = '\0'; // buffer마지막 자리에 null
        remains = ft_strjoin(remains, buf); // remains에 읽은 것 이어붙이기
    }
    *line = push_line(remains); // line에 reamins 복사(개행 포함돼있으면 개행까지만)
    remains = cut_next_line(remains); // remains에 개행 포함돼있을 경우 개행 후만 reamins에 저장
    return (count == 0 ? 0 : 1); // 파일끝이면 0반환, 끝아니면 1반환
}