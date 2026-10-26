int __thiscall sub_5E73C0(_DWORD *this, const char *ArgList, void **a3, int a4, int a5)
{
  int v6; // ebx
  void **v7; // esi

  if ( !ArgList || !byte_FB231D )
    return 0;
  v6 = a5;
  if ( !a5 )
    v6 = *this & 0xF;
  if ( a3 )
  {
    v7 = a3;
  }
  else
  {
    v7 = (void **)sub_5E0740(this, ArgList, 0);
    if ( !v7 )
    {
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error locating bitmap file %s", (char)ArgList);
      return -1;
    }
  }
  if ( !(*(int (__thiscall **)(int, void *, void *, _DWORD *, int, int))(*(_DWORD *)dword_FB27A4 + 260))(
          dword_FB27A4,
          *v7,
          v7[2],
          this,
          v6,
          a4) )
  {
    if ( !a3 )
      sub_5DF6E0(v7);
    return 0;
  }
  if ( !a3 )
    sub_5DF6E0(v7);
  sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error loading bitmap file %s", (char)ArgList);
  return -1;
}
