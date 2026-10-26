int sub_47F300()
{
  int v0; // ebp
  int v1; // ebx
  int i; // esi
  unsigned int v3; // kr04_4
  char *v4; // eax
  int result; // eax

  v0 = dword_8AC488;
  v1 = 0;
  if ( dword_8AC488 <= 0 )
    return sub_4C54F0(0);
  for ( i = 0; ; i += 396 )
  {
    v3 = strlen((const char *)(i + dword_8AC490 + 4)) + 1;
    if ( (int)(v3 - 1) > 0 )
    {
      v4 = (char *)dword_7CE5D0;
      if ( !dword_7CE5D0 )
        v4 = byte_5EA438;
      result = sub_596C80(i + dword_8AC490 + 4, v4, v3 - 1);
      if ( !result )
        break;
    }
    if ( ++v1 >= v0 )
      return sub_4C54F0(0);
  }
  return result;
}
