int __thiscall sub_404850(_DWORD *this)
{
  char *v2; // eax
  const char *v3; // edi
  int result; // eax
  char *v5; // edx

  v2 = (char *)this[14];
  if ( !v2 )
    v2 = &byte_5EA438;
  v3 = v2;
  result = 0;
  if ( strlen(v3) )
  {
    v5 = (char *)this[14];
    if ( !v5 )
      v5 = &byte_5EA438;
    return StringCopyFileCheckDispatch(v5, 1);
  }
  return result;
}

