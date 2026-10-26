int __thiscall sub_4A2340(_DWORD *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax

  v2 = (const char *)this[42];
  if ( !v2 )
    v2 = &byte_629120;
  if ( !_strcmpi(v2, asc_6087A8) )
    this[206] = 0;
  v3 = (const char *)this[42];
  if ( !v3 )
    v3 = &byte_629120;
  if ( !_strcmpi(v3, aR) )
    this[206] = 1;
  v4 = (const char *)this[42];
  if ( !v4 )
    v4 = &byte_629120;
  if ( !_strcmpi(v4, aC_3) )
    this[206] = 2;
  return 0;
}
