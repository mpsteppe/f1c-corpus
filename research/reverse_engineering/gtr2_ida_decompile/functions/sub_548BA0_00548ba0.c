int __thiscall sub_548BA0(int this)
{
  double v2; // st7
  double v3; // st7
  int result; // eax
  int v5; // ebx
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  long double v9; // st7
  int v10; // eax
  float *v11; // ebp
  int j; // ebx
  float v13; // ecx
  long double v14; // st7
  float v15; // edx
  float v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  float v20; // [esp+0h] [ebp-64h]
  float v21; // [esp+1Ch] [ebp-48h]
  float v22; // [esp+20h] [ebp-44h]
  int i; // [esp+24h] [ebp-40h]
  float v24; // [esp+28h] [ebp-3Ch]
  float *v25; // [esp+28h] [ebp-3Ch]
  float v26; // [esp+2Ch] [ebp-38h]
  int v27; // [esp+30h] [ebp-34h] BYREF
  float v28; // [esp+34h] [ebp-30h]
  int v29; // [esp+38h] [ebp-2Ch]
  float v30; // [esp+3Ch] [ebp-28h]
  float v31; // [esp+40h] [ebp-24h]
  int v32; // [esp+44h] [ebp-20h]
  float v33; // [esp+48h] [ebp-1Ch]
  int v34; // [esp+4Ch] [ebp-18h]
  float v35; // [esp+50h] [ebp-14h]
  int v36; // [esp+54h] [ebp-10h]
  float v37; // [esp+58h] [ebp-Ch]
  float v38; // [esp+5Ch] [ebp-8h]
  int v39; // [esp+60h] [ebp-4h]

  sub_544540((float *)this);
  if ( dword_BE1204 == 2 )
    v2 = sub_5210A0(&dword_BE120C);
  else
    v2 = dbl_FB1D18;
  v21 = v2;
  if ( dword_BE1204 == 2 )
  {
    if ( sub_5210D0(&dword_BE120C) == 5 )
    {
      v22 = 0.0;
      goto LABEL_10;
    }
    v3 = sub_5210C0(&dword_BE120C);
  }
  else
  {
    v3 = dbl_FB1D10;
  }
  v22 = v3;
LABEL_10:
  result = *(_DWORD *)(this + 108);
  v5 = 0;
  for ( i = 0; v5 < result; i = v5 )
  {
    v6 = *(_DWORD *)(this + 112);
    v7 = *(_DWORD *)(v6 + 4 * v5);
    if ( v21 > (double)*(float *)(v7 + 12) || v21 < (double)*(float *)(v7 + 8) )
    {
      v18 = *(_DWORD *)(this + 108) - 1;
      *(_DWORD *)(this + 108) = v18;
      *(_DWORD *)(v6 + 4 * *(_DWORD *)(v7 + 4)) = *(_DWORD *)(v6 + 4 * v18);
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 112) + 4 * *(_DWORD *)(v7 + 4)) + 4) = *(_DWORD *)(v7 + 4);
      v19 = *(_DWORD *)v7;
      *(_DWORD *)(v7 + 4) = -1;
      sub_5FCB20(v19);
      --v5;
    }
    else
    {
      v24 = v22 * *(float *)(v7 + 60) + *(float *)(v7 + 48);
      *(float *)(v7 + 48) = v24;
      if ( (dword_B71440 & 3) != 0 )
      {
        v26 = *(float *)(v7 + 60) * 0.03125;
        if ( dword_B71440 == 1 )
        {
          if ( dword_91E07C )
          {
            v28 = *((float *)dword_91E07C + 698);
            v8 = *((_DWORD *)dword_91E07C + 699);
            v9 = v28 - *(float *)(v7 + 44);
            v30 = *((float *)dword_91E07C + 700);
            v29 = v8;
            if ( fabs(v9) < 4.0 && fabs(v30 - *(float *)(v7 + 52)) < 4.0 )
            {
              v10 = *(_DWORD *)(v7 + 44);
              v35 = v24 - v26;
              v34 = v10;
              v36 = *(_DWORD *)(v7 + 52);
              sub_544170();
            }
          }
        }
        else
        {
          v11 = (float *)(v7 + 44);
          v20 = *(float *)(v7 + 44) + *(float *)(v7 + 52);
          v25 = sub_5432C0(&flt_BE23D8, v20, 5.6568542, &v27);
          for ( j = 0; j < v27; ++j )
          {
            v13 = v25[j];
            v31 = *(float *)(LODWORD(v13) + 2776);
            v14 = v31 - *v11;
            v15 = *(float *)(LODWORD(v13) + 2784);
            v32 = *(_DWORD *)(LODWORD(v13) + 2780);
            v33 = v15;
            if ( fabs(v14) < 4.0
              && fabs(v33 - *(float *)(v7 + 52)) < 4.0
              && ((dword_B71488 & 1) != 0 || *(_DWORD *)(LODWORD(v13) + 4) != dword_91E078) )
            {
              v16 = *v11;
              v17 = *(_DWORD *)(v7 + 52);
              v38 = *(float *)(v7 + 48) - v26;
              v37 = v16;
              v39 = v17;
              sub_544170();
            }
          }
          v5 = i;
        }
      }
      sub_542790(v7, (float *)(40 * *(_DWORD *)(v7 + 84) + 12459368), (float *)(40 * *(_DWORD *)(v7 + 84) + 12459380));
    }
    result = *(_DWORD *)(this + 108);
    ++v5;
  }
  return result;
}
