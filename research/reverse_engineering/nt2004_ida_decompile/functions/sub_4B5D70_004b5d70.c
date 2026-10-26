void __stdcall sub_4B5D70(int a1, int a2, int a3, int a4, int a5)
{
  double v5; // st7
  int v6; // ecx
  float v7; // [esp+14h] [ebp+4h]

  if ( *(_DWORD *)(dword_75AAD0[dword_75AAC0] + 25248) == *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248) )
  {
    v5 = (*((double *)&unk_75EFCC + 157 * a1) - 0.6875) * 3.2;
    v7 = v5;
    if ( v5 >= 0.0 )
    {
      if ( v7 > 1.0 )
        v7 = 1.0;
    }
    else
    {
      v7 = 0.0;
    }
    sub_59FFB0(a2, a3, a4, a5, -16777216);
    if ( v7 > 0.0 )
    {
      v6 = -65536;
      if ( v7 <= 0.80000001 )
      {
        if ( v7 > 0.5 )
          v6 = -256;
      }
      else
      {
        v6 = -16711936;
      }
      sub_59FFB0(a2, a3, (__int64)((double)a4 * v7), a5, v6);
    }
  }
  else
  {
    sub_59FFB0(a2, a3, a4, a5, -16711936);
  }
}
