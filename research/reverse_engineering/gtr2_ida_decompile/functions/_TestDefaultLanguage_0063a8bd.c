BOOL __cdecl TestDefaultLanguage(int a1, int a2)
{
  int v2; // ecx
  int v3; // esi
  BOOL result; // eax
  int v5; // [esp-8h] [ebp-84h]
  char v6[120]; // [esp+0h] [ebp-7Ch] BYREF
  int v7; // [esp+78h] [ebp-4h]

  v7 = dword_912B08;
  result = 0;
  if ( dword_FB83D8(a1 & 0x3FF | 0x400, 1, v6, 120) )
  {
    if ( a1 == LcidFromHexString(v2, v6) )
      return 1;
    if ( !a2 )
      return 1;
    v3 = sub_6354D0((int)dword_FB83D4);
    if ( GetPrimaryLen(v5, dword_FB83D4) != v3 )
      return 1;
  }
  return result;
}
