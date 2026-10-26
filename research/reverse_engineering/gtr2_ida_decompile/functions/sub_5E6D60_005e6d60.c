int __thiscall sub_5E6D60(void *this, const char *ArgList, int a3, int a4, int a5, int a6, int a7)
{
  void **v8; // esi

  v8 = (void **)sub_5E0740(this, ArgList, 0);
  if ( v8 )
  {
    (*(void (__thiscall **)(int, void *, void *, int, int, int, int))(*(_DWORD *)dword_FB27A4 + 268))(
      dword_FB27A4,
      *v8,
      v8[2],
      a3,
      a4,
      a5,
      a6);
    sub_5DF6E0(v8);
    return 0;
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error getting stats for surface %s", (char)ArgList);
    return -1;
  }
}
