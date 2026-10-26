int __thiscall sub_47BE50(_DWORD *this)
{
  CHAR *v1; // eax
  CHAR *v3; // eax

  v1 = (CHAR *)dword_62A0A8;
  if ( !dword_62A0A8 )
    v1 = &byte_629120;
  sub_578600(v1);
  v3 = (CHAR *)this[42];
  if ( !v3 )
    v3 = &byte_629120;
  sub_578560(v3);
  sub_527460(&byte_629120, 1);
  return 0;
}
