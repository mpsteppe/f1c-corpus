// f1c  0x004faf60  size=763
void __thiscall sub_4FAF60(int this)
{
  float *v2; // eax
  _DWORD *v3; // eax
  long double v4; // st4
  float *v5; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st5
  long double v9; // st7
  int v10; // eax
  int v11; // edi
  int v12; // ebp
  float *v13; // ebx
  double v14; // st7
  double v15; // st6
  long double v16; // st5
  long double v17; // st6
  float v18; // [esp+10h] [ebp-4h]

  if ( *(_DWORD *)(this + 300) < dword_5EA2CC )
  {
    v2 = *(float **)(this + 272);
    if ( v2 )
    {
      *(float *)(this + 164) = v2[37] - *(float *)(this + 148);
      *(float *)(this + 168) = v2[38] - *(float *)(this + 152);
      *(float *)(this + 172) = v2[39] - *(float *)(this + 156);
    }
    else
    {
      v3 = *(_DWORD **)(this + 268);
      if ( v3 )
      {
        *(_DWORD *)(this + 164) = v3[41];
        *(_DWORD *)(this + 168) = v3[42];
        *(_DWORD *)(this + 172) = v3[43];
      }
    }
    *(float *)(this + 80) = *(float *)(this + 44) - 1.5 + *(float *)(this + 160);
    *(float *)(this + 84) = *(float *)(this + 48) - 1.5 - *(float *)(this + 160);
    *(float *)(this + 104) = *(float *)(this + 96) + *(float *)(this + 44);
    *(float *)(this + 108) = *(float *)(this + 100) + *(float *)(this + 48);
    *(float *)(this + 60) = sqrt(
                              *(float *)(this + 164) * *(float *)(this + 164)
                            + *(float *)(this + 168) * *(float *)(this + 168)
                            + *(float *)(this + 172) * *(float *)(this + 172));
    if ( *(float *)(this + 164) != 0.0 || *(float *)(this + 168) != 0.0 || *(float *)(this + 172) != 0.0 )
    {
      v4 = sqrt(
             *(float *)(this + 164) * *(float *)(this + 164)
           + *(float *)(this + 168) * *(float *)(this + 168)
           + *(float *)(this + 172) * *(float *)(this + 172));
      *(float *)(this + 164) = 1.0 / v4 * *(float *)(this + 164);
      *(float *)(this + 168) = 1.0 / v4 * *(float *)(this + 168);
      *(float *)(this + 172) = 1.0 / v4 * *(float *)(this + 172);
    }
    v5 = *(float **)(this + 276);
    if ( v5 )
    {
      v6 = v5[37] - *(float *)(this + 148);
      v7 = v5[38] - *(float *)(this + 152);
      v8 = v5[39] - *(float *)(this + 156);
      *(float *)(this + 64) = sqrt(v8 * v8 + v7 * v7 + v6 * v6);
    }
    if ( *(float *)(this + 172) == 0.0 )
    {
      *(_DWORD *)(this + 184) = 1070141403;
    }
    else
    {
      v9 = atan2(*(float *)(this + 164) / *(float *)(this + 172), 1.0);
      *(float *)(this + 184) = v9;
      if ( *(float *)(this + 172) > 0.0 )
        *(float *)(this + 184) = v9 + 3.1415927;
    }
    v10 = *(_DWORD *)(this + 272);
    if ( v10 )
    {
      v11 = *(_DWORD *)(v10 + 272);
      if ( v11 )
      {
        v12 = 0;
        v13 = (float *)(this + 188);
        do
        {
          v14 = *(float *)(v11 + 148) - *(float *)(this + 148);
          v15 = *(float *)(v11 + 156) - *(float *)(this + 156);
          v16 = sqrt(*(float *)(this + 164) * *(float *)(this + 164) + *(float *)(this + 172) * *(float *)(this + 172))
              * sqrt(v15 * v15 + v14 * v14);
          if ( v16 == 0.0
            || (v17 = (v14 * *(float *)(this + 164) + v15 * *(float *)(this + 172)) / v16, v18 = v17, v17 >= 1.0)
            || (sub_5894A0(), *v13 = v18, v18 < 0.024110001) )
          {
            *v13 = 0.024110001;
          }
          v11 = *(_DWORD *)(v11 + 272);
          if ( !v11 )
            break;
          ++v12;
          ++v13;
        }
        while ( v12 < 4 );
      }
    }
  }
}
