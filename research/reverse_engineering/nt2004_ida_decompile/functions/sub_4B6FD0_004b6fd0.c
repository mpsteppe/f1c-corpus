void __stdcall sub_4B6FD0(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // esi
  double v6; // st7
  int v7; // ecx

  v5 = dword_75AAC4;
  if ( *(_BYTE *)(304 * a1 + dword_75AAC4 + 2296) )
  {
    if ( v5 == (sub_42DBA0() ? dword_75AACC : 0) )
    {
      v6 = (*((double *)&unk_75EFCC + 157 * a1) - 0.6875) * 3.2;
      if ( v6 < 0.0 )
        return;
      if ( v6 <= 1.0 )
      {
        if ( v6 <= 0.0 )
          return;
      }
      else
      {
        v6 = 1.0;
      }
      v7 = -65536;
      if ( v6 <= 0.80000001 )
      {
        if ( v6 > 0.5 )
          v7 = -256;
      }
      else
      {
        v7 = -16711936;
      }
      sub_59FFB0(a2, a3, (__int64)((double)a4 * v6), a5, v7);
    }
    else
    {
      sub_59FFB0(a2, a3, a4, a5, -16711936);
    }
  }
}
