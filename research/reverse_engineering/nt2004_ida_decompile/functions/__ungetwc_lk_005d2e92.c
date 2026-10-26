__int16 __cdecl _ungetwc_lk(wchar_t MbCh, _DWORD *a2)
{
  wchar_t v2; // bx
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // eax
  char *v6; // ecx
  int v7; // eax
  int v9; // eax

  v2 = MbCh;
  if ( MbCh == 0xFFFF )
    return -1;
  v3 = a2;
  v4 = a2[3];
  if ( (v4 & 1) == 0 && ((v4 & 0x80u) == 0 || (v4 & 2) != 0) )
    return -1;
  if ( !a2[2] )
    _getbuf(a2);
  v5 = v3[3];
  if ( (v5 & 0x40) != 0
    || (v3[4] == -1 ? (v6 = (char *)&unk_625A00) : (v6 = (char *)(dword_8003E0[(int)v3[4] >> 5] + 36 * (v3[4] & 0x1F))),
        v6[4] >= 0) )
  {
    if ( *v3 == v3[2] )
    {
      if ( v3[1] )
        return -1;
      *v3 += 2;
    }
    v3[1] += 2;
    LOBYTE(v5) = v5 & 0xEE | 1;
    *v3 -= 2;
    v3[3] = v5;
    *(_WORD *)*v3 = v2;
    return *(_WORD *)*v3;
  }
  else
  {
    v7 = wctomb((char *)&MbCh, v2);
    if ( v7 == -1 )
    {
      *_errno() = 42;
      return -1;
    }
    if ( *v3 == v3[2] )
    {
      if ( v3[1] )
        return -1;
      *v3 += v7;
    }
    if ( v7 != 1 )
      *(_BYTE *)--*v3 = HIBYTE(MbCh);
    *(_BYTE *)--*v3 = MbCh;
    v3[1] += v7;
    v9 = v3[3];
    LOBYTE(v9) = v9 & 0xEE | 1;
    v3[3] = v9;
    return v2;
  }
}
