int sub_4934C0()
{
  int result; // eax
  int v1; // ebp
  const char *v2; // ebx
  int v3; // edi
  int v4; // esi
  const char *v5; // eax
  CHAR *v6; // [esp+0h] [ebp-8h]
  size_t v7; // [esp+4h] [ebp-4h]

  result = dword_7D6A5C;
  if ( dword_7D6A5C )
  {
    v6 = *(CHAR **)dword_7D6A5C;
    if ( !*(_DWORD *)dword_7D6A5C )
      v6 = &byte_629120;
    result = NumOfElements;
    if ( (int)NumOfElements > 0 )
    {
      v1 = 0;
      v7 = NumOfElements;
      do
      {
        v2 = (const char *)(dword_76BB88 + v1 + 24992);
        v3 = 0;
        if ( dword_7D6A58 <= 0 )
        {
LABEL_12:
          if ( v6 )
            sub_4EEAE0(0);
        }
        else
        {
          v4 = 0;
          while ( 1 )
          {
            v5 = *(const char **)(v4 + dword_7D6A5C);
            if ( !v5 )
              v5 = &byte_629120;
            if ( !_strcmpi(v2, v5) )
              break;
            ++v3;
            v4 += 1232;
            if ( v3 >= dword_7D6A58 )
              goto LABEL_12;
          }
        }
        v1 += 25304;
        result = --v7;
      }
      while ( v7 );
    }
  }
  return result;
}
