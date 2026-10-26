int __thiscall sub_5FE050(void *this, const char *ArgList, int a3, int a4)
{
  void *v6; // eax
  int v7; // esi

  if ( sub_5FDEA0(ArgList) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Actor %s already exsits", (char)ArgList);
    return -1;
  }
  else
  {
    v6 = operator new(0x28u);
    v7 = (int)v6;
    if ( v6 )
    {
      sub_5D9010(v6);
      *(_BYTE *)v7 = 0;
      *(_DWORD *)(v7 + 32) = 0;
      *(_DWORD *)(v7 + 36) = 0;
    }
    else
    {
      v7 = 0;
    }
    strcpy((char *)v7, ArgList);
    *(_DWORD *)(v7 + 36) = a4;
    *(_DWORD *)(v7 + 32) = a3;
    sub_5FDFB0(&dword_FB288C, v7, 1);
    return 0;
  }
}
