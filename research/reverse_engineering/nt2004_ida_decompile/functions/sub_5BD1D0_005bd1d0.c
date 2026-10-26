char __fastcall sub_5BD1D0(int a1, _BYTE *a2, int a3, _DWORD *a4, _WORD *a5)
{
  __int16 v5; // ax
  _BYTE *v6; // edx

  if ( a3 >= 5 )
  {
    LOBYTE(v5) = *a2;
    v6 = a2 + 1;
    *a4 = *(_DWORD *)v6;
    if ( (v5 & 0x10) != 0 )
    {
      if ( a3 - 5 >= 2 )
      {
        v5 = *((_WORD *)v6 + 2);
        *a5 = v5;
      }
    }
    else
    {
      LOBYTE(v5) = (_BYTE)a5;
      *a5 = *(_WORD *)(a1 + 1176);
    }
  }
  return v5;
}
