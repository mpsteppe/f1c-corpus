int __stdcall sub_4E76F0(char *String2)
{
  unsigned int v1; // kr04_4
  int result; // eax
  int v3; // edi
  int v4; // esi

  v1 = strlen(String2) + 1;
  result = dword_7D6A58;
  v3 = 0;
  if ( dword_7D6A58 <= 0 )
  {
LABEL_5:
    dword_7D6A54 = 0;
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      result = _strnicmp((const char *)(v4 + dword_7D6A5C + 136), String2, v1 - 1);
      if ( !result )
        break;
      result = dword_7D6A58;
      ++v3;
      v4 += 1232;
      if ( v3 >= dword_7D6A58 )
        goto LABEL_5;
    }
    dword_7D6A54 = v3;
  }
  return result;
}
