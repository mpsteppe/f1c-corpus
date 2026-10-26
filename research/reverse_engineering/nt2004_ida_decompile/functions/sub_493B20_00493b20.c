CHAR *__thiscall sub_493B20(CHAR **this)
{
  CHAR *v1; // eax
  CHAR **v2; // esi
  CHAR *result; // eax

  v1 = (CHAR *)dword_62A098;
  if ( !dword_62A098 )
    v1 = &byte_629120;
  v2 = this + 390;
  sub_578600(v1);
  sub_578560(off_6021F0[0]);
  result = *v2;
  if ( !*v2 )
    return &byte_629120;
  return result;
}
