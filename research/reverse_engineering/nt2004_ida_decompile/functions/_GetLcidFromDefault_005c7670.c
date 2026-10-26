LCID GetLcidFromDefault()
{
  LCID result; // eax

  LOWORD(dword_7FF260) = dword_7FF260 | 0x104;
  result = GetUserDefaultLCID();
  dword_7FF264 = result;
  Locale = result;
  return result;
}
