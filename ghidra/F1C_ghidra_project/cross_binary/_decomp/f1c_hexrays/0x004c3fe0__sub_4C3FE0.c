// f1c  0x004c3fe0  size=150
int __stdcall sub_4C3FE0(const char *a1)
{
  unsigned int v1; // kr04_4
  int result; // eax
  int v3; // ebx
  int v4; // esi
  const char *v5; // edx
  const char *v6; // ecx

  v1 = strlen(a1) + 1;
  result = dword_8AC390;
  v3 = 0;
  if ( dword_8AC390 <= 0 )
  {
LABEL_12:
    dword_8AC38C = 0;
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = *(const char **)(v4 + dword_8AC394);
      if ( !v5 )
        v5 = byte_5EA438;
      v6 = &v5[strlen(v5)];
      if ( v6 > v5 )
      {
        while ( *v6 != 92 )
        {
          if ( --v6 <= v5 )
            goto LABEL_10;
        }
        ++v6;
      }
LABEL_10:
      result = sub_596C80(v6, a1, v1 - 1);
      if ( !result )
        break;
      result = dword_8AC390;
      ++v3;
      v4 += 1060;
      if ( v3 >= dword_8AC390 )
        goto LABEL_12;
    }
    dword_8AC38C = v3;
  }
  return result;
}
