unsigned __int8 __stdcall sub_458220(UINT uCode)
{
  unsigned __int8 result; // al
  UINT v2; // esi
  UINT v3; // eax

  if ( (byte_764710 & 1) == 0 )
  {
    byte_764710 |= 1u;
    dwhkl = GetKeyboardLayout(0);
  }
  word_764724 = 0;
  Char = 0;
  if ( !GetKeyboardState(&KeyState) )
    return 0;
  v2 = uCode;
  if ( uCode == 32825 )
    v2 = 57;
  v3 = MapVirtualKeyExA(v2, 1u, dwhkl);
  ToAsciiEx(v3, v2, &KeyState, &Char, 0, dwhkl);
  result = sub_457C70(Char, v2);
  word_764724 = result;
  return result;
}
