int sub_476F30()
{
  int result; // eax
  char v1; // bl
  _UNKNOWN **v2; // eax
  float v3; // [esp+8h] [ebp-360h]

  v3 = dbl_FB1D18;
  sub_51B2A0(4, 3, 0, 0, LODWORD(v3), 3);
  result = sub_4745E0();
  v1 = result;
  if ( dword_B640C0 != 5 )
  {
    result = sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 4931);
    if ( (_BYTE)result )
    {
      v2 = (_UNKNOWN **)&unk_6F6718;
      if ( !v1 )
        v2 = &off_6F6714;
      return sub_561210((int)byte_FAE910, "Sending server OK request (ret=%s)", (char)v2);
    }
  }
  return result;
}
