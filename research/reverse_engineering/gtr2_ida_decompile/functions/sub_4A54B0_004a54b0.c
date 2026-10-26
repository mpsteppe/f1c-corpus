int __thiscall sub_4A54B0(_DWORD *this)
{
  int v1; // eax
  const CHAR *v2; // eax

  v1 = sub_4DDFF0(this[12]);
  if ( v1 )
  {
    v2 = *(const CHAR **)(v1 + 176);
    if ( !v2 )
      v2 = WindowName;
    sub_4CE020(v2);
    return 0;
  }
  else
  {
    sub_4CE020(WindowName);
    return 0;
  }
}
