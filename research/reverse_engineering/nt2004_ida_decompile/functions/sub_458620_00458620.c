int __thiscall sub_458620(HCURSOR *this)
{
  int result; // eax
  char v3; // [esp+0h] [ebp-4h]

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_4, 5556) )
    sub_500FE0((int)&unk_7D7920, aEnteredHwinput_4, v3);
  sub_452190(this + 1123);
  sub_452190(this + 868);
  sub_451AC0(this + 816);
  sub_451430(this + 1);
  result = (int)*this;
  if ( *this )
  {
    result = (*(int (__stdcall **)(HCURSOR))(*(_DWORD *)result + 8))(*this);
    *this = 0;
  }
  if ( byte_769DF4 == 1 )
  {
    result = sub_526590();
    this[1734] = (HCURSOR)-1;
  }
  return result;
}
