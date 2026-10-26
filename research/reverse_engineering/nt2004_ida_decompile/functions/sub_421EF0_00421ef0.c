void __thiscall sub_421EF0(int this)
{
  int v2; // eax
  float *v3; // eax
  double v4; // st7
  long double v5; // st7
  double v6; // st7
  double v7; // st7
  long double v8; // st6
  long double v9; // st7
  float *v10; // ecx
  double v11; // st7
  int v12; // [esp+0h] [ebp-24h]
  int v13; // [esp+4h] [ebp-20h]
  long double v14; // [esp+Ch] [ebp-18h] BYREF
  float v15; // [esp+14h] [ebp-10h]
  long double v16; // [esp+18h] [ebp-Ch]
  float v17; // [esp+20h] [ebp-4h]

  v2 = *(_DWORD *)(this + 24020);
  *(_BYTE *)(this + 76) = 1;
  if ( v2 == 1 )
  {
    v3 = *(float **)(this + 23432);
    *(float *)&v14 = v3[54] * v3[13] - v3[55] * v3[12];
    *((float *)&v14 + 1) = v3[55] * v3[11] - v3[53] * v3[13];
    v4 = v3[53] * v3[12] - v3[54] * v3[11];
    v16 = v14;
    v15 = v4;
    v17 = v15;
    sub_5795E0(&v14);
    v5 = *((float *)&v14 + 1) - *(float *)(this + 17620);
    if ( fabs(v5) >= 3.141592653589793 )
    {
      if ( v5 >= 0.0 )
        v5 = v5 - 6.283185307179586;
      else
        v5 = v5 + 6.283185307179586;
    }
    if ( fabs(v5) < 0.5 )
      sub_42C0F0(0);
    if ( *(float *)(this + 23788) < (double)*(float *)(this + 23852)
      || (fabs(*(float *)(this + 23728) - sub_42B090(*(_DWORD *)(this + 24020), 0)) < 1.5 || !*(_BYTE *)(this + 24208))
      && ((v6 = *(float *)(this + 23764), *(_DWORD *)(this + 23748) = 1065353216,
                                          *(_DWORD *)(this + 23740) = 0,
                                          v6 < 4.0)
       || *(float *)(this + 18352) > 0.89999998 && *(float *)(this + 18600) > 0.89999998) )
    {
      sub_42C0F0(4);
    }
    *(_DWORD *)(this + 23740) = 1065353216;
  }
  else
  {
    v7 = *(float *)(this + 17620);
    v14 = atan2(-*(float *)(this + 17628), -*(float *)(this + 17636));
    if ( *(float *)(this + 23764) < 4.0
      || *(float *)(this + 18352) > 0.89999998 && *(float *)(this + 18600) > 0.89999998 )
    {
      v8 = v14 - v7;
      if ( fabs(v14 - v7) >= 3.141592653589793 )
      {
        if ( v8 >= 0.0 )
          v8 = v8 - 6.283185307179586;
        else
          v8 = v8 + 6.283185307179586;
      }
      if ( fabs(v8) <= 1.5 )
      {
        sub_42C0F0(2);
      }
      else
      {
        v9 = *(float *)(*(_DWORD *)(this + 23432) + 260) - v7;
        if ( fabs(v9) >= 3.141592653589793 )
        {
          if ( v9 >= 0.0 )
            v9 = v9 - 6.283185307179586;
          else
            v9 = v9 + 6.283185307179586;
        }
        if ( fabs(v9) > 1.5 )
        {
          *(float *)(this + 23788) = *(float *)(this + 23852) + 3.0;
          sub_42C0F0(1);
        }
      }
    }
    *(_DWORD *)(this + 23748) = 1065353216;
    *(_DWORD *)(this + 23740) = 0;
  }
  if ( *(_BYTE *)(this + 24208) )
  {
    v10 = *(float **)(this + 23432);
    if ( *(float *)(this + 17636) * v10[55] + *(float *)(this + 17632) * v10[54] + *(float *)(this + 17628) * v10[53] >= flt_628F78 )
      v11 = *(float *)(this + 17636) * v10[55] + *(float *)(this + 17632) * v10[54] + *(float *)(this + 17628) * v10[53];
    else
      v11 = flt_628F78;
    *(float *)(this + 23760) = v11;
    if ( v11 < *(float *)(this + 24720) )
    {
      *(float *)&v13 = *(float *)(this + 23728) + 3.0;
      *(float *)&v12 = *(float *)(this + 23728) - 3.0;
      sub_529AC0(this + 23760, 0.25, v12, v13);
    }
  }
}
