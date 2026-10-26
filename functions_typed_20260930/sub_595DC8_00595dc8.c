BOOL __cdecl sub_595DC8(
        DWORD dwInfoType,
        LPCSTR lpSrcStr,
        int cchSrc,
        LPWORD lpCharType,
        UINT CodePage,
        LCID Locale,
        int a7)
{
  int v7; // eax
  LCID v8; // eax
  int v10; // eax
  unsigned int v11; // edi
  int v12; // eax
  void *v13; // esp
  int v14; // eax
  WCHAR v15[8]; // [esp+0h] [ebp-34h] BYREF
  WCHAR *v16; // [esp+10h] [ebp-24h]
  int cchWideChar; // [esp+14h] [ebp-20h]
  WORD CharType; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  v7 = dword_8D41C0;
  if ( !dword_8D41C0 )
  {
    if ( GetStringTypeW(1u, &String2, 1, &CharType) )
    {
      v7 = 1;
    }
    else
    {
      if ( !GetStringTypeA(0, 1u, String1, 1, &CharType) )
        return 0;
      v7 = 2;
    }
    dword_8D41C0 = v7;
  }
  if ( v7 != 2 )
  {
    if ( v7 == 1 )
    {
      if ( !CodePage )
        CodePage = ::CodePage;
      v10 = MultiByteToWideChar(CodePage, a7 != 0 ? 9 : 1, lpSrcStr, cchSrc, 0, 0);
      cchWideChar = v10;
      if ( v10 )
      {
        ms_exc.registration.TryLevel = 0;
        v11 = 2 * v10;
        v12 = 2 * v10 + 3;
        LOBYTE(v12) = v12 & 0xFC;
        v13 = alloca(v12);
        ms_exc.old_esp = (DWORD)v15;
        v16 = v15;
        sub_58BB10((unsigned __int8 *)v15, 0, v11);
        ms_exc.registration.TryLevel = -1;
        if ( v15 )
        {
          v14 = MultiByteToWideChar(CodePage, 1u, lpSrcStr, cchSrc, v15, cchWideChar);
          if ( v14 )
            return GetStringTypeW(dwInfoType, v15, v14, lpCharType);
        }
      }
    }
    return 0;
  }
  v8 = Locale;
  if ( !Locale )
    v8 = dword_8D3F38;
  return GetStringTypeA(v8, dwInfoType, lpSrcStr, cchSrc, lpCharType);
}

