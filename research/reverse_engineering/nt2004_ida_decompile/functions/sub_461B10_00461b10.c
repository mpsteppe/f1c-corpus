int __thiscall sub_461B10(_DWORD *this)
{
  int v1; // eax
  int result; // eax
  char v3; // bl
  _UNKNOWN **v4; // eax
  float v5; // [esp+0h] [ebp-E0h]
  _BYTE v6[208]; // [esp+10h] [ebp-D0h] BYREF

  v1 = this[1680];
  if ( v1 > 0 && v1 <= 2 )
    return sub_461BC0(this, -1);
  v5 = dbl_7DA9D0;
  sub_4D0D00(4, 3, 0, 0, LODWORD(v5), 3);
  result = sub_463A40(v6, 2, -1, -1);
  v3 = result;
  if ( dword_75CBA8 != 5 )
  {
    result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 4964);
    if ( (_BYTE)result )
    {
      v4 = (_UNKNOWN **)&unk_5FFEB8;
      if ( !v3 )
        v4 = &off_5FFEB4;
      return sub_500FE0((int)&unk_7D7920, aSendingServerO, (char)v4);
    }
  }
  return result;
}
