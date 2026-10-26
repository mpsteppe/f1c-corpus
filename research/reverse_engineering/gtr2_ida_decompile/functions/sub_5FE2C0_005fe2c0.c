int __thiscall sub_5FE2C0(_DWORD *this, int a2, const char *ArgList, const char *a4)
{
  const char *v5; // edi
  const char *v7; // eax
  int v8; // eax

  v5 = sub_5FDEA0(ArgList);
  if ( v5 )
  {
    v7 = sub_5FDF20(a4);
    if ( v7 )
    {
      v8 = sub_5FE1F0(this, (int)v5, (int)v7);
      sub_5FDFB0((_DWORD *)(a2 + 552), v8, 0);
      return 0;
    }
    else
    {
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Could not find response %s", (char)a4);
      return -1;
    }
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Could not find actor %s", (char)ArgList);
    return -1;
  }
}
