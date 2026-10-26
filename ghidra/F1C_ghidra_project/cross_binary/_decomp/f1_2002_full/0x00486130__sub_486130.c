// f1_2002_full  0x00486130  size=132
int __thiscall sub_486130(_DWORD *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax

  v2 = (const char *)this[46];
  if ( !v2 )
    v2 = &byte_5C97DC;
  if ( !_strcmpi(v2, asc_5AEB70) )
    this[194] = 0;
  v3 = (const char *)this[46];
  if ( !v3 )
    v3 = &byte_5C97DC;
  if ( !_strcmpi(v3, aR_0) )
    this[194] = 1;
  v4 = (const char *)this[46];
  if ( !v4 )
    v4 = &byte_5C97DC;
  if ( !_strcmpi(v4, aC_5) )
    this[194] = 2;
  return 0;
}
