LCID sub_5903C0()
{
  LCID result; // eax

  LOWORD(dword_8D3FB0) = dword_8D3FB0 | 0x104;
  result = GetUserDefaultLCID();
  dword_8D3FB4 = result;
  Locale = result;
  return result;
}
