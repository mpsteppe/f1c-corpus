// f1_2002_full  0x004c51a0  size=149
char __thiscall sub_4C51A0(_DWORD *this, const char *ArgList, const char *a3)
{
  int v4; // eax
  int v5; // eax

  v4 = sub_52DAD0(ArgList, 0);
  this[1] = v4;
  if ( !v4 && sub_4CA4A0(dword_6BD838, 1, aDDevF12002Sour_2, 568) )
    sub_4CA4F0((int)dword_6BD838, "Could not find light \"%s\"", ArgList);
  v5 = sub_52DAD0(a3, 0);
  this[2] = v5;
  if ( !v5 )
  {
    LOBYTE(v5) = sub_4CA4A0(dword_6BD838, 1, aDDevF12002Sour_2, 571);
    if ( (_BYTE)v5 )
      LOBYTE(v5) = sub_4CA4F0((int)dword_6BD838, "Could not find glow \"%s\"", a3);
  }
  return v5;
}
