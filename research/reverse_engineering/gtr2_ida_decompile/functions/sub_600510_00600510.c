int __thiscall sub_600510(
        _DWORD *this,
        const char *ArgList,
        int a3,
        _DWORD *a4,
        float a5,
        int a6,
        const char *a7,
        int a8,
        char **a9,
        int a10)
{
  void *v11; // eax
  char *v12; // esi
  _DWORD *v14; // ecx

  v11 = operator new(0x140u);
  if ( v11 )
    v12 = (char *)sub_6002C0(v11);
  else
    v12 = 0;
  if ( sub_5FF950((int *)v12, a10, (int)this, (int)this, a3, a4, a5, a6, a7, a8, a10) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating projector %s", (char)ArgList);
    return -1;
  }
  else
  {
    sub_5FE380(v12, ArgList);
    v14 = this + 145;
    if ( (a10 & 0x200) == 0 )
      v14 = this + 141;
    sub_5FDFB0(v14, (int)v12, 1);
    if ( a9 )
      *a9 = v12;
    return 0;
  }
}
