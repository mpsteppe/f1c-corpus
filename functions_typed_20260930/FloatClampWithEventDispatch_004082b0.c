void __thiscall sub_4082B0(float *this)
{
  int v2; // eax
  int v3; // eax
  double v4; // st7
  double v5; // st7
  int v6; // [esp-Ch] [ebp-18h]
  int v7; // [esp-8h] [ebp-14h]
  int v8; // [esp-8h] [ebp-14h]
  float v9; // [esp+4h] [ebp-8h]
  float v10; // [esp+8h] [ebp-4h]

  v9 = flt_5BE8F8 * *this * this[4];
  v10 = this[4] - v9;
  if ( *this == 0.0 )
  {
    if ( *((_BYTE *)this + 21) )
    {
      ConditionalBranchByFlag(1);
      *((_BYTE *)this + 21) = 0;
    }
  }
  else
  {
    if ( dword_8AD2A0 != -1 )
    {
      ConditionalBranchByFlag(0);
      *((_BYTE *)this + 21) = 1;
    }
    v7 = CRTFtol(v9);
    v2 = CRTFtol(this[3]);
    F_2DSurfaceBlitFill(dword_8B8DC8, 0, 0, v2, v7, 0);
    v8 = CRTFtol(this[4] - v10 + 1.0);
    v6 = CRTFtol(this[3]);
    v3 = CRTFtol(v10);
    F_2DSurfaceBlitFill(dword_8B8DC8, 0, v3, v6, v8, 0);
  }
  if ( *this >= (double)this[1] )
  {
    if ( *this > (double)this[1] )
    {
      v5 = *this - dbl_8AFE90 * this[2];
      *this = v5;
      if ( v5 < this[1] )
        *this = this[1];
    }
  }
  else
  {
    v4 = dbl_8AFE90 * this[2] + *this;
    *this = v4;
    if ( v4 > this[1] )
      *this = this[1];
  }
}

