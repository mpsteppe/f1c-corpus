// f1c  0x004c29f0  size=134
int __thiscall sub_4C29F0(_DWORD *this)
{
  int result; // eax
  int v3; // edi
  float v4; // [esp+0h] [ebp-Ch]

  result = sub_42BC10();
  if ( (_BYTE)result && dword_8AB6E4 != 2 && dword_7C56A4 == 7 )
  {
    v3 = *(_DWORD *)(dword_7C54E8 + 16472);
    sub_4C2BF0(this);
    sub_4C2C40(v3);
    if ( dword_7D0990 > 0 )
    {
      v4 = (float)dword_7D01A0;
      sub_4C2DC0(v4);
    }
    sub_4C2D30(flt_7D0798);
    result = dword_7D0410;
    if ( (dword_7D0410 == 4 || dword_7D0410 == 3) && v3 == 1 )
      ++this[15];
  }
  return result;
}
