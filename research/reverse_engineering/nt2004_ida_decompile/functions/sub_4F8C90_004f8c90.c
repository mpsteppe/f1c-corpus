BOOL __thiscall sub_4F8C90(_DWORD *this, int ArgList, int a3)
{
  int v4; // eax
  int v5; // eax

  v4 = sub_5975F0(ArgList, 0);
  this[1] = v4;
  if ( !v4 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_21, 1063) )
    sub_500FE0((int)&unk_7D7920, aCouldNotFindLi, ArgList);
  v5 = sub_5975F0(a3, 0);
  this[2] = v5;
  if ( !v5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_21, 1066) )
    sub_500FE0((int)&unk_7D7920, aCouldNotFindGl, a3);
  return this[1] != 0;
}
