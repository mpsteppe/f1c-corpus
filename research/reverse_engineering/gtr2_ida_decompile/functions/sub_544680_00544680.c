int __thiscall sub_544680(int this, float *a2, float a3)
{
  int result; // eax
  double v5; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  int v10; // ecx
  int v11; // edx
  int v12; // esi
  int v13; // edx
  int v14; // esi
  double v15; // st7
  int v16; // ebx
  double v17; // st7
  float v18; // [esp+0h] [ebp-1Ch]
  float v19; // [esp+4h] [ebp-18h]
  int v20; // [esp+14h] [ebp-8h]
  float v21; // [esp+18h] [ebp-4h]
  float v22; // [esp+20h] [ebp+4h]
  float v23; // [esp+24h] [ebp+8h]
  float v24; // [esp+24h] [ebp+8h]

  result = *(_DWORD *)(this + 96);
  if ( result > 0 )
  {
    v5 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
    *a2 = v5 + v5 + *a2;
    v7 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
    a2[2] = v7 + v7 + a2[2];
    v8 = dword_BE1204 == 2 ? sub_5210A0(&dword_BE120C) : dbl_FB1D18;
    v22 = v8;
    sub_544540((float *)this);
    v23 = sqrt(a3);
    if ( dword_BE1204 == 2 )
      v9 = sub_5210D0(&dword_BE120C) == 5 ? 0.0 : sub_5210C0(&dword_BE120C);
    else
      v9 = dbl_FB1D10;
    v19 = (double)*(int *)(this + 96) * v9 * v23 * 2.5263157;
    result = sub_4015C0(v19) >> *(_DWORD *)(this + 8);
    v24 = v23 * 0.80000001;
    if ( result > 0 )
    {
      v20 = result;
      do
      {
        v10 = *(_DWORD *)(this + 104);
        v11 = *(_DWORD *)(this + 96);
        *(_DWORD *)(this + 104) = v10 + 1;
        if ( v10 + 1 >= v11 )
          *(_DWORD *)(this + 104) = 0;
        v12 = *(_DWORD *)(this + 100);
        v13 = *(_DWORD *)(v12 + 108 * v10 + 4);
        v14 = 108 * v10 + v12;
        if ( v13 < 0 )
        {
          *(_DWORD *)(v14 + 4) = *(_DWORD *)(this + 108);
          *(_DWORD *)(*(_DWORD *)(this + 112) + 4 * (*(_DWORD *)(this + 108))++) = 108 * v10 + *(_DWORD *)(this + 100);
          sub_5FCAC0(v10);
        }
        *(float *)(v14 + 8) = v22;
        v21 = v22 + 0.39583334;
        *(float *)(v14 + 12) = v21;
        v15 = flt_BE1FD8[2 * (((_BYTE)dword_BE2720 + 1) & 0x7F)];
        dword_BE2720 = ((_BYTE)dword_BE2720 + 1) & 0x7F;
        *(float *)(v14 + 44) = v15 + *a2;
        *(float *)(v14 + 48) = a2[1] + 8.0;
        v16 = 40 * *(_DWORD *)(v14 + 84) + 12459352;
        *(float *)(v14 + 52) = flt_BE1FDC[2 * dword_BE2720] + a2[2];
        *(_DWORD *)(v14 + 56) = 0;
        v17 = v24 * *(float *)(v14 + 40);
        *(_DWORD *)(v14 + 60) = *(_DWORD *)(v16 + 12);
        *(_DWORD *)(v14 + 64) = 0;
        v18 = v17;
        *(_DWORD *)(v14 + 96) = &off_16C9990[0][0x1000000 * sub_4015C0(v18)];
        result = sub_542790(v14, (float *)(v16 + 16), (float *)(v16 + 28));
        --v20;
      }
      while ( v20 );
    }
  }
  return result;
}
