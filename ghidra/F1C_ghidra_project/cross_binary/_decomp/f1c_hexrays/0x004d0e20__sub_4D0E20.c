// f1c  0x004d0e20  size=149
int __thiscall sub_4D0E20(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int result; // eax

  v4 = sub_5453A0(a2, 0);
  this[1] = v4;
  if ( !v4 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_3, 642) )
    sub_4D7AA0(&unk_8AD25C, aCouldNotFindLi);
  result = sub_5453A0(a3, 0);
  this[2] = result;
  if ( !result )
  {
    result = sub_4D7A50(1, aDDevF119992002_3, 645);
    if ( (_BYTE)result )
      return sub_4D7AA0(&unk_8AD25C, aCouldNotFindGl);
  }
  return result;
}
