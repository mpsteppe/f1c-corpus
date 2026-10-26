LCID GetLcidFromDefault()
{
  LCID result; // eax

  LOWORD(dword_FB83B8) = dword_FB83B8 | 0x104;
  result = GetUserDefaultLCID();
  dword_FB83C0 = result;
  Locale = result;
  return result;
}
