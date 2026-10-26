int __thiscall sub_49EC60(_DWORD *this, const char *a2)
{
  const char *v3; // eax

  if ( !a2 )
    return -1;
  v3 = (const char *)this[40];
  if ( !v3 )
    v3 = &byte_629120;
  if ( strcmp(a2, v3) )
    sub_578600(a2);
  return 0;
}
