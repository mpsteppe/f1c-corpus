int __thiscall sub_4AF450(_DWORD *this)
{
  _DWORD *v2; // ebp
  int result; // eax
  const char *v4; // edx
  char *v5; // eax

  v2 = (_DWORD *)this[12];
  result = 0;
  if ( v2 )
  {
    v4 = (const char *)this[19];
    if ( !v4 )
      v4 = &byte_629120;
    if ( strcmp(v4, &byte_629120) )
    {
      v5 = (char *)this[19];
      if ( !v5 )
        v5 = &byte_629120;
      return sub_4AD490(v2, v5);
    }
  }
  return result;
}
