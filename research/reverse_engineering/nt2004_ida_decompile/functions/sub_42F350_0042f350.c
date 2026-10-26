int sub_42F350()
{
  int result; // eax
  CHAR *v1; // eax
  int v2; // ebp
  int i; // esi
  _BYTE *v4; // ecx
  CHAR *v5; // ecx
  CHAR *v6; // eax
  int v7; // [esp+0h] [ebp-14h]

  result = dword_75AACC;
  if ( dword_75AACC )
  {
    v1 = dword_766B44;
    if ( !dword_766B44 )
      v1 = &byte_629120;
    sub_578600(v1);
    v7 = *(_DWORD *)(dword_75AACC + 25252);
    sub_4EE280(dword_75AACC);
    v2 = dword_7D6A58;
    for ( i = 0; i < v2; ++i )
    {
      sub_4EEAE0(i);
      sub_4EE0B0((void *)dword_75AACC, 1);
      sub_4EE160(0.0);
      v4 = (_BYTE *)(dword_75AACC + 24992 + strlen((const char *)(dword_75AACC + 24992)));
      if ( (unsigned int)v4 > dword_75AACC + 24992 )
      {
        while ( *v4 != 92 )
        {
          if ( (unsigned int)--v4 <= dword_75AACC + 24992 )
            goto LABEL_10;
        }
        ++v4;
      }
LABEL_10:
      sub_578600(v4);
      v5 = &byte_629120 + strlen(&byte_629120);
      if ( v5 > &byte_629120 )
      {
        while ( *v5 != 46 )
        {
          if ( --v5 <= &byte_629120 )
            goto LABEL_15;
        }
        *v5 = 0;
      }
LABEL_15:
      sub_578560(word_5FC804);
      v6 = dword_766594;
      if ( !dword_766594 )
        v6 = &byte_629120;
      sub_578560(v6);
      sub_578560(aSpt);
      sub_578600(&byte_629120);
      sub_4FD8A0(&dword_7D78FC);
      sub_4FE670(&dword_7D78FC);
      sub_4EE280(dword_75AACC);
    }
    sub_4EEAE0(v7);
    sub_4EE0B0((void *)dword_75AACC, 1);
    sub_4EE160(0.0);
    sub_578600(&byte_629120);
    return 0;
  }
  return result;
}
