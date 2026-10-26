int __thiscall SeasonScoring(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // edi
  int v5; // ebp
  _DWORD *v6; // eax
  unsigned __int8 *v7; // eax
  int v8; // ecx
  bool v9; // zf

  if ( dword_7D00EC == 5 )
  {
    v8 = 18624 * this[105];
    result = *(_DWORD *)(v8 + dword_7D2E48 + 16480) - 1;
    v9 = *(_DWORD *)(v8 + dword_7D2E48 + 16480) == 1;
    this[106] = result;
    if ( v9 )
      ++this[104];
  }
  else
  {
    result = dword_7D00EC - 7;
    if ( dword_7D00EC == 7 )
    {
      this[a2 + 6] = *(_DWORD *)(18624 * this[105] + dword_7D2E48 + 16480);
      v4 = 18624 * this[105] + dword_7D2E48;
      v5 = 0;
      if ( *(_DWORD *)(v4 + 16484) != 3
        && *(_DWORD *)(v4 + 16444) >= (int)CRTFtol((double)dword_8ACF8C * 0.89999998)
        && AudioChannelStop(dword_8AD3B4, aSeasonscoringi) )
      {
        v6 = (_DWORD *)NullCheckWrapper(this[a2 + 6] - 1);
        if ( v6 )
        {
          v7 = (unsigned __int8 *)DataEntryAccessor(v6);
          v5 = sub_587ECE(v7);
        }
      }
      this[a2 + 54] = v5;
      this[102] += v5;
      result = this[105];
      this[106] = result;
    }
  }
  return result;
}

