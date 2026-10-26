int __thiscall sub_5EA410(_DWORD *this, const char *ArgList, void **a3, char a4, int a5)
{
  void **v6; // eax
  void **v7; // esi
  _BYTE v9[16]; // [esp+10h] [ebp-10h] BYREF

  if ( a3 )
  {
    v7 = a3;
  }
  else
  {
    v6 = (void **)sub_5E0740(this, ArgList, 0);
    v7 = v6;
    if ( !v6 )
    {
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error locating mesh / mat file %s", (char)ArgList);
      return -1;
    }
    sub_5DEC60(v9, v6, 0x10u);
  }
  if ( sub_5E9E60(this, (int)this, (int)v7, a4, a5) )
    return -1;
  if ( !a3 )
    sub_5DF6E0(v7);
  return 0;
}
