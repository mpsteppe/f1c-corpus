int sub_4BAA00()
{
  CHAR *v0; // eax
  CHAR *v2; // eax

  if ( !byte_76617C )
    return 0;
  if ( !dword_7655CC )
    return 0;
  v0 = sub_4AD820((_DWORD *)dword_7655CC);
  if ( !v0 )
    return 0;
  if ( sub_579060(v0, aGarage_0) )
    return 2;
  v2 = sub_4AD7F0((_DWORD *)dword_7655CC);
  if ( v2 && sub_579060(v2, aChat_0) )
    return 3;
  else
    return 1;
}
