int __thiscall sub_4CE760(_DWORD *this)
{
  CHAR *v2; // eax
  CHAR *v3; // eax
  CHAR *v4; // eax
  CHAR *v5; // eax
  CHAR *v6; // eax
  int result; // eax

  v2 = (CHAR *)this[122];
  if ( !v2 )
    v2 = &byte_629120;
  sub_578600(v2);
  v3 = (CHAR *)this[124];
  if ( !v3 )
    v3 = &byte_629120;
  sub_578600(v3);
  v4 = (CHAR *)this[126];
  if ( !v4 )
    v4 = &byte_629120;
  sub_578600(v4);
  v5 = (CHAR *)this[1934];
  if ( !v5 )
    v5 = &byte_629120;
  sub_578600(v5);
  v6 = (CHAR *)this[1936];
  if ( !v6 )
    v6 = &byte_629120;
  sub_578600(v6);
  this[3603] = this[1938];
  this[3604] = this[1939];
  this[3605] = this[1940];
  result = this[1941];
  this[3606] = result;
  return result;
}
