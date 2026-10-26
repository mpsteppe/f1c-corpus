int __thiscall sub_4A2E90(_DWORD *this)
{
  const char *v2; // esi
  const char *v3; // eax
  const CHAR *v4; // eax

  v2 = dword_B6F6A8;
  if ( !dword_B6F6A8 )
    v2 = WindowName;
  v3 = (const char *)this[149];
  if ( !v3 )
    v3 = WindowName;
  if ( strcmp(v3, v2) )
  {
    v4 = dword_B6F6A8;
    if ( !dword_B6F6A8 )
      v4 = WindowName;
    sub_615860(v4);
    sub_48FBF0(this);
  }
  return 0;
}
