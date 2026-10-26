int __thiscall sub_4CE820(_DWORD *this)
{
  CHAR *v2; // eax
  const char *v3; // edi
  int result; // eax
  CHAR *v5; // eax
  CHAR *v6; // eax
  CHAR *v7; // eax
  CHAR *v8; // eax
  CHAR *v9; // eax

  v2 = (CHAR *)this[3596];
  if ( !v2 )
    v2 = &byte_629120;
  v3 = v2;
  result = 0;
  if ( strlen(v3) )
  {
    v5 = (CHAR *)this[3592];
    if ( !v5 )
      v5 = &byte_629120;
    sub_578600(v5);
    v6 = (CHAR *)this[3594];
    if ( !v6 )
      v6 = &byte_629120;
    sub_578600(v6);
    v7 = (CHAR *)this[3596];
    if ( !v7 )
      v7 = &byte_629120;
    sub_578600(v7);
    sub_578600(&byte_629120);
    v8 = (CHAR *)this[3599];
    if ( !v8 )
      v8 = &byte_629120;
    sub_578600(v8);
    v9 = (CHAR *)this[3601];
    if ( !v9 )
      v9 = &byte_629120;
    sub_578600(v9);
    this[1938] = this[3603];
    this[1939] = this[3604];
    this[1940] = this[3605];
    result = this[3606];
    this[1941] = result;
  }
  return result;
}
