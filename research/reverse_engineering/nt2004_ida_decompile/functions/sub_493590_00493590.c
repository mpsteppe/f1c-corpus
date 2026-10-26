int sub_493590()
{
  int v0; // ebp
  int v1; // ebx
  int i; // esi
  unsigned int v3; // kr04_4
  const char *v4; // eax
  int result; // eax

  v0 = dword_7D6B50;
  v1 = 0;
  if ( dword_7D6B50 <= 0 )
    return sub_4E8A30(&byte_7D6A30);
  for ( i = 0; ; i += 400 )
  {
    v3 = strlen((const char *)(i + dword_7D6B58 + 4)) + 1;
    if ( (int)(v3 - 1) > 0 )
    {
      v4 = dword_766578;
      if ( !dword_766578 )
        v4 = &byte_629120;
      result = _strnicmp((const char *)(i + dword_7D6B58 + 4), v4, v3 - 1);
      if ( !result )
        break;
    }
    if ( ++v1 >= v0 )
      return sub_4E8A30(&byte_7D6A30);
  }
  return result;
}
