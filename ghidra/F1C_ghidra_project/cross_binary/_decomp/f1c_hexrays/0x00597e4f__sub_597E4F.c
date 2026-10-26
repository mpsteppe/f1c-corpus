// f1c  0x00597e4f  size=286
int __cdecl sub_597E4F(LCID Locale, LCTYPE LCType, LPSTR lpLCData, int cchData, UINT CodePage)
{
  int v5; // eax
  int LocaleInfoW; // eax
  int v8; // eax
  void *v9; // esp
  int v10; // [esp-4h] [ebp-34h]
  WCHAR v11[8]; // [esp+0h] [ebp-30h] BYREF
  WCHAR *v12; // [esp+10h] [ebp-20h]
  int v13; // [esp+14h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+18h] [ebp-18h]

  v5 = dword_8D4204;
  if ( !dword_8D4204 )
  {
    if ( GetLocaleInfoW(0, 1u, 0, 0) )
    {
      v10 = 1;
    }
    else
    {
      if ( !GetLocaleInfoA(0, 1u, 0, 0) )
        return 0;
      v10 = 2;
    }
    v5 = v10;
    dword_8D4204 = v10;
  }
  if ( v5 == 2 )
    return GetLocaleInfoA(Locale, LCType, lpLCData, cchData);
  if ( v5 != 1 )
    return 0;
  if ( !CodePage )
    CodePage = ::CodePage;
  LocaleInfoW = GetLocaleInfoW(Locale, LCType, 0, 0);
  v13 = LocaleInfoW;
  if ( !LocaleInfoW )
    return 0;
  v8 = 2 * LocaleInfoW + 3;
  LOBYTE(v8) = v8 & 0xFC;
  v9 = alloca(v8);
  ms_exc.old_esp = (DWORD)v11;
  v12 = v11;
  ms_exc.registration.TryLevel = -1;
  if ( !v11 || !GetLocaleInfoW(Locale, LCType, v11, v13) )
    return 0;
  if ( cchData )
    return WideCharToMultiByte(CodePage, 0x220u, v11, -1, lpLCData, cchData, 0, 0);
  else
    return WideCharToMultiByte(CodePage, 0x220u, v11, -1, 0, 0, 0, 0);
}
