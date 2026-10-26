int __thiscall sub_4CF4E0(_DWORD *this)
{
  const char *v2; // esi
  const char *v3; // eax
  const CHAR *v4; // eax

  v2 = dword_75ACF4;
  if ( !dword_75ACF4 )
    v2 = WindowName;
  v3 = (const char *)this[42];
  if ( !v3 )
    v3 = WindowName;
  if ( strcmp(v3, v2) )
  {
    v4 = (const CHAR *)this[42];
    if ( !v4 )
      v4 = WindowName;
    sub_615860(v4);
    (*(void (__thiscall **)(_DWORD *))(*this + 164))(this);
  }
  return 0;
}
