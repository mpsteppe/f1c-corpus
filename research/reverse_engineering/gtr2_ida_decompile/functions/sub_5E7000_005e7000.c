int __thiscall sub_5E7000(void *this, const char *ArgList, int a3, int a4, int a5, int a6)
{
  void **v7; // esi

  v7 = (void **)sub_5E0740(this, ArgList, 0);
  if ( v7 )
  {
    (*(void (__thiscall **)(int, void *, void *, int, int, int, int))(*(_DWORD *)dword_FB27A4 + 268))(
      dword_FB27A4,
      *v7,
      v7[2],
      a3,
      a4,
      a5,
      a6);
    sub_5DF6E0(v7);
    return 0;
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error getting stats for surface %s", (char)ArgList);
    return -1;
  }
}
