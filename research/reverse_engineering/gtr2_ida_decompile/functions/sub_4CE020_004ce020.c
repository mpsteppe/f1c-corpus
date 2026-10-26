int __thiscall sub_4CE020(_DWORD *this, const char *a2)
{
  const char *v3; // eax

  if ( !a2 )
    return -1;
  v3 = (const char *)this[40];
  if ( !v3 )
    v3 = WindowName;
  if ( strcmp(a2, v3) )
    sub_615860(a2);
  return 0;
}
