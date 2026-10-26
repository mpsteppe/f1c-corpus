int sub_58D190()
{
  int result; // eax
  int v1; // ecx
  _DWORD *i; // edx

  result = -1;
  v1 = 0;
  if ( dword_7E4840 > 0 )
  {
    for ( i = (_DWORD *)dword_7E483C; *i; ++i )
    {
      if ( ++v1 >= dword_7E4840 )
        return result;
    }
    return v1;
  }
  return result;
}
