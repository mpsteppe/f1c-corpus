BOOL __cdecl sub_596A2E(DWORD dwInfoType, LPCWCH lpSrcStr, int cchSrc, LPWORD lpCharType, UINT CodePage, LCID Locale)
{
  int v6; // eax
  int v8; // eax
  unsigned int v9; // esi
  int v10; // eax
  void *v11; // esp
  int v12; // eax
  void *v13; // esp
  LCID v14; // eax
  WORD *v15; // esi
  WORD v16[6]; // [esp+0h] [ebp-38h] BYREF
  LPSTR lpMultiByteStr; // [esp+Ch] [ebp-2Ch]
  int v18; // [esp+10h] [ebp-28h]
  WORD *v19; // [esp+14h] [ebp-24h]
  BOOL StringTypeA; // [esp+18h] [ebp-20h]
  WORD CharType; // [esp+1Ch] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+20h] [ebp-18h]

  v6 = dword_8D41D0;
  if ( !dword_8D41D0 )
  {
    if ( GetStringTypeW(1u, &String2, 1, &CharType) )
    {
      v6 = 1;
    }
    else
    {
      if ( !GetStringTypeA(0, 1u, String1, 1, &CharType) )
        return 0;
      v6 = 2;
    }
    dword_8D41D0 = v6;
  }
  if ( v6 == 1 )
    return GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType);
  if ( v6 == 2 )
  {
    if ( !CodePage )
      CodePage = ::CodePage;
    v8 = WideCharToMultiByte(CodePage, 0x220u, lpSrcStr, cchSrc, 0, 0, 0, 0);
    v9 = v8;
    v18 = v8;
    if ( v8 )
    {
      ms_exc.registration.TryLevel = 0;
      v10 = v8 + 3;
      LOBYTE(v10) = v10 & 0xFC;
      v11 = alloca(v10);
      ms_exc.old_esp = (DWORD)v16;
      lpMultiByteStr = (LPSTR)v16;
      sub_58BB10((unsigned __int8 *)v16, 0, v9);
      ms_exc.registration.TryLevel = -1;
      if ( lpMultiByteStr )
      {
        if ( WideCharToMultiByte(CodePage, 0x220u, lpSrcStr, cchSrc, lpMultiByteStr, v9, 0, 0) )
        {
          v12 = 2 * v9 + 5;
          LOBYTE(v12) = v12 & 0xFC;
          v13 = alloca(v12);
          ms_exc.old_esp = (DWORD)v16;
          v19 = v16;
          ms_exc.registration.TryLevel = -1;
          if ( v16 )
          {
            v14 = Locale;
            if ( !Locale )
              v14 = dword_8D3F38;
            v15 = &v16[cchSrc];
            *v15 = -1;
            *(v15 - 1) = -1;
            StringTypeA = GetStringTypeA(v14, dwInfoType, lpMultiByteStr, v18, v16);
            if ( *(v15 - 1) != 0xFFFF && *v15 == 0xFFFF )
            {
              sub_58B130((unsigned int)lpCharType, v16, 2 * cchSrc);
              return StringTypeA;
            }
          }
        }
      }
    }
  }
  return 0;
}
