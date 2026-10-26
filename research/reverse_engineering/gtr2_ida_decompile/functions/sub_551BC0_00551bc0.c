int __thiscall sub_551BC0(_DWORD *this)
{
  int result; // eax
  int v3; // esi
  double v4; // st7
  int v5; // edx
  int v6; // [esp+0h] [ebp-14h]
  float v7; // [esp+10h] [ebp-4h]

  if ( (unsigned __int8)sub_4735A0() )
  {
    if ( dbl_FB1D18 < 120.0 )
    {
      result = dword_757C10 - this[62];
      if ( dword_757C10 != this[62] )
        return result;
    }
    v7 = 2.5;
  }
  else
  {
    v7 = 3.0;
  }
  v3 = off_9034A4;
  if ( dword_82F4A0 < 1023 )
  {
    ++dword_82F4A0;
    off_9034A4 += 848;
  }
  *(float *)&v6 = dbl_FB1D18;
  sub_51B2A0((_DWORD *)v3, 4, 18, 8, 255, v6, 3);
  *(float *)(v3 + 8) = dbl_FB1D18 + v7;
  v4 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
  v5 = *(_DWORD *)(v3 + 8);
  *(float *)(v3 + 12) = dbl_FB1D18 + v7 + v4 + v4 + 5.0;
  this[752] = v5;
  result = *(_DWORD *)(v3 + 12);
  this[753] = result;
  return result;
}
