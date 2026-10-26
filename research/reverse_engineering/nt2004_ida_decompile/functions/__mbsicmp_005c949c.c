int __cdecl _mbsicmp(const unsigned __int8 *Str1, const unsigned __int8 *Str2)
{
  const unsigned __int8 *v3; // esi
  const unsigned __int8 *v4; // ecx
  unsigned __int16 v5; // ax
  char *v6; // ecx
  unsigned __int16 v7; // di
  int v8; // eax
  unsigned __int16 v9; // ax
  char *v10; // esi
  unsigned __int16 v11; // si
  int v12; // eax
  const CHAR *v13; // [esp+Ch] [ebp-Ch]
  const CHAR *lpSrcStr; // [esp+10h] [ebp-8h]
  CHAR DestStr; // [esp+14h] [ebp-4h] BYREF
  unsigned __int8 v16; // [esp+15h] [ebp-3h]
  char *String1; // [esp+20h] [ebp+8h]
  char *String2; // [esp+24h] [ebp+Ch]

  if ( !dword_80019C )
    return _strcmpi((const char *)Str1, (const char *)Str2);
  _lock(25);
  v3 = Str2;
  v4 = Str1;
  v13 = (const CHAR *)(Str2 - 1);
  lpSrcStr = (const CHAR *)(Str1 - 1);
  while ( 1 )
  {
    v5 = *v4;
    v6 = (char *)(v4 + 1);
    ++lpSrcStr;
    String1 = v6;
    if ( (byte_8002A1[(unsigned __int8)v5] & 4) != 0 )
    {
      if ( *v6 )
      {
        v8 = __crtLCMapStringA(dword_8003A4, 0x200u, lpSrcStr, 2, &DestStr, 2, dword_800180, 1);
        if ( v8 == 1 )
        {
          v7 = (unsigned __int8)DestStr;
        }
        else
        {
          if ( v8 != 2 )
            goto LABEL_28;
          v7 = v16 + ((unsigned __int8)DestStr << 8);
        }
        ++String1;
        ++lpSrcStr;
      }
      else
      {
        v7 = 0;
      }
    }
    else if ( (byte_8002A1[v5] & 0x10) == 0x10 )
    {
      v7 = (unsigned __int8)byte_8001A0[v5];
    }
    else
    {
      v7 = v5;
    }
    v9 = *v3;
    v10 = (char *)(v3 + 1);
    ++v13;
    String2 = v10;
    if ( (byte_8002A1[(unsigned __int8)v9] & 4) != 0 )
    {
      if ( *v10 )
      {
        v12 = __crtLCMapStringA(dword_8003A4, 0x200u, v13, 2, &DestStr, 2, dword_800180, 1);
        if ( v12 == 1 )
        {
          v11 = (unsigned __int8)DestStr;
        }
        else
        {
          if ( v12 != 2 )
          {
LABEL_28:
            _unlock(25);
            return 0x7FFFFFFF;
          }
          v11 = v16 + ((unsigned __int8)DestStr << 8);
        }
        ++String2;
        ++v13;
      }
      else
      {
        v11 = 0;
      }
    }
    else
    {
      v11 = v9;
      if ( (byte_8002A1[v9] & 0x10) == 0x10 )
        v11 = (unsigned __int8)byte_8001A0[v9];
    }
    if ( v7 != v11 )
    {
      _unlock(25);
      return v11 < v7 ? 1 : -1;
    }
    if ( !v7 )
      break;
    v3 = (const unsigned __int8 *)String2;
    v4 = (const unsigned __int8 *)String1;
  }
  _unlock(25);
  return 0;
}
