// f1c  0x0047f230  size=193
int sub_47F230()
{
  int result; // eax
  int v1; // ebp
  int v2; // ebx
  int v3; // edi
  int v4; // esi
  char *v5; // eax
  char *v6; // [esp+0h] [ebp-8h]
  int v7; // [esp+4h] [ebp-4h]

  result = dword_8AC394;
  if ( dword_8AC394 )
  {
    v6 = *(char **)dword_8AC394;
    if ( !*(_DWORD *)dword_8AC394 )
      v6 = byte_5EA438;
    result = dword_5C329C;
    if ( dword_5C329C > 0 )
    {
      v1 = 0;
      v7 = dword_5C329C;
      do
      {
        v2 = dword_7D2E48 + v1 + 18196;
        v3 = 0;
        if ( dword_8AC390 <= 0 )
        {
LABEL_12:
          if ( v6 )
            sub_4C78F0(0);
        }
        else
        {
          v4 = 0;
          while ( 1 )
          {
            v5 = *(char **)(v4 + dword_8AC394);
            if ( !v5 )
              v5 = byte_5EA438;
            if ( !sub_588410(v2, v5) )
              break;
            ++v3;
            v4 += 1060;
            if ( v3 >= dword_8AC390 )
              goto LABEL_12;
          }
        }
        v1 += 18624;
        result = --v7;
      }
      while ( v7 );
    }
  }
  return result;
}
