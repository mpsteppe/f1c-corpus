// f1c  0x00597d3c  size=275
int __cdecl sub_597D3C(LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData, UINT CodePage)
{
  int v5; // eax
  int LocaleInfoA; // eax
  int v8; // eax
  void *v9; // esp
  int v10; // [esp-4h] [ebp-34h]
  CHAR v11[16]; // [esp+0h] [ebp-30h] BYREF
  CHAR *v12; // [esp+10h] [ebp-20h]
  int v13; // [esp+14h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+18h] [ebp-18h]

  v5 = dword_8D4200;
  if ( !dword_8D4200 )
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
    dword_8D4200 = v10;
  }
  if ( v5 == 1 )
    return GetLocaleInfoW(Locale, LCType, lpLCData, cchData);
  if ( v5 != 2 )
    return 0;
  if ( !CodePage )
    CodePage = ::CodePage;
  LocaleInfoA = GetLocaleInfoA(Locale, LCType, 0, 0);
  v13 = LocaleInfoA;
  if ( !LocaleInfoA )
    return 0;
  v8 = LocaleInfoA + 3;
  LOBYTE(v8) = v8 & 0xFC;
  v9 = alloca(v8);
  ms_exc.old_esp = (DWORD)v11;
  v12 = v11;
  ms_exc.registration.TryLevel = -1;
  if ( !v11 || !GetLocaleInfoA(Locale, LCType, v11, v13) )
    return 0;
  if ( cchData )
    return MultiByteToWideChar(CodePage, 1u, v11, -1, lpLCData, cchData);
  else
    return MultiByteToWideChar(CodePage, 1u, v11, -1, 0, 0);
}
