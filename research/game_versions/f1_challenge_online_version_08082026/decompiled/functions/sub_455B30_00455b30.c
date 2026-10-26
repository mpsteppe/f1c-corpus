unsigned __int8 __stdcall sub_455B30(UINT uCode)
{
  unsigned __int8 result; // al
  UINT v2; // esi
  UINT v3; // eax

  if ( (byte_7CCC04 & 1) == 0 )
  {
    byte_7CCC04 |= 1u;
    dwhkl = GetKeyboardLayout(0);
  }
  word_7CCBC0 = 0;
  Char = 0;
  if ( !GetKeyboardState(&KeyState) )
    return 0;
  v2 = uCode;
  if ( uCode == 32825 )
    v2 = 57;
  v3 = MapVirtualKeyExA(v2, 1u, dwhkl);
  ToAsciiEx(v3, v2, &KeyState, &Char, 0, dwhkl);
  result = sub_455580(Char, v2);
  word_7CCBC0 = result;
  return result;
}
