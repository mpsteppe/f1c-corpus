int __cdecl sub_59807B(
        LCID Locale,
        DWORD dwCmpFlags,
        PCNZCH lpString1,
        int cchCount1,
        PCNZCH lpString2,
        int cchCount2,
        UINT CodePage)
{
  int v7; // esi
  BYTE *LeadByte; // eax
  unsigned __int8 v10; // dl
  BYTE *i; // eax
  unsigned __int8 v12; // dl
  int v13; // eax
  int v14; // eax
  void *v15; // esp
  int v16; // eax
  int v17; // esi
  int v18; // eax
  void *v19; // esp
  WCHAR v21[8]; // [esp+0h] [ebp-4Ch] BYREF
  struct _cpinfo CPInfo; // [esp+10h] [ebp-3Ch] BYREF
  WCHAR *v23; // [esp+24h] [ebp-28h]
  LPWSTR lpWideCharStr; // [esp+28h] [ebp-24h]
  int v25; // [esp+2Ch] [ebp-20h]
  int cchWideChar; // [esp+30h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  if ( !dword_8D4208 )
  {
    if ( CompareStringW(0, 0, &String2, 1, &String2, 1) )
    {
      dword_8D4208 = 1;
    }
    else
    {
      if ( !CompareStringA(0, 0, String1, 1, String1, 1) )
        return 0;
      dword_8D4208 = 2;
    }
  }
  v7 = cchCount1;
  if ( cchCount1 > 0 )
    v7 = sub_5982F8(lpString1, cchCount1);
  if ( cchCount2 > 0 )
    cchCount2 = sub_5982F8(lpString2, cchCount2);
  if ( dword_8D4208 == 2 )
    return CompareStringA(Locale, dwCmpFlags, lpString1, v7, lpString2, cchCount2);
  if ( dword_8D4208 == 1 )
  {
    if ( !CodePage )
      CodePage = ::CodePage;
    if ( !v7 || !cchCount2 )
    {
      if ( v7 == cchCount2 )
        return 2;
      if ( cchCount2 > 1 )
        return 1;
      if ( v7 > 1 )
        return 3;
      if ( !GetCPInfo(CodePage, &CPInfo) )
        return 0;
      if ( v7 > 0 )
      {
        if ( CPInfo.MaxCharSize >= 2 )
        {
          LeadByte = CPInfo.LeadByte;
          if ( CPInfo.LeadByte[0] )
          {
            while ( 1 )
            {
              v10 = LeadByte[1];
              if ( !v10 )
                break;
              if ( (unsigned int)*lpString1 >= *LeadByte && (unsigned int)*lpString1 <= v10 )
                return 2;
              LeadByte += 2;
              if ( !*LeadByte )
                return 3;
            }
          }
        }
        return 3;
      }
      if ( cchCount2 > 0 )
      {
        if ( CPInfo.MaxCharSize >= 2 )
        {
          for ( i = CPInfo.LeadByte; *i; i += 2 )
          {
            v12 = i[1];
            if ( !v12 )
              break;
            if ( (unsigned int)*lpString2 >= *i && (unsigned int)*lpString2 <= v12 )
              return 2;
          }
        }
        return 1;
      }
    }
    v13 = MultiByteToWideChar(CodePage, 9u, lpString1, v7, 0, 0);
    cchWideChar = v13;
    if ( v13 )
    {
      v14 = 2 * v13 + 3;
      LOBYTE(v14) = v14 & 0xFC;
      v15 = alloca(v14);
      ms_exc.old_esp = (DWORD)v21;
      lpWideCharStr = v21;
      ms_exc.registration.TryLevel = -1;
      if ( v21 )
      {
        if ( MultiByteToWideChar(CodePage, 1u, lpString1, v7, lpWideCharStr, cchWideChar) )
        {
          v16 = MultiByteToWideChar(CodePage, 9u, lpString2, cchCount2, 0, 0);
          v17 = v16;
          v25 = v16;
          if ( v16 )
          {
            v18 = 2 * v16 + 3;
            LOBYTE(v18) = v18 & 0xFC;
            v19 = alloca(v18);
            ms_exc.old_esp = (DWORD)v21;
            v23 = v21;
            ms_exc.registration.TryLevel = -1;
            if ( v21 )
            {
              if ( MultiByteToWideChar(CodePage, 1u, lpString2, cchCount2, v21, v17) )
                return CompareStringW(Locale, dwCmpFlags, lpWideCharStr, cchWideChar, v21, v17);
            }
          }
        }
      }
    }
  }
  return 0;
}
