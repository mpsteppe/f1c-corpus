// f1c  0x00430750  size=766
double __thiscall sub_430750(int this, double a2)
{
  double *v4; // esi
  double v5; // st7
  double v6; // st6
  double v7; // st7
  double v8; // st7
  double v9; // st6
  double v10; // st7
  double v11; // st5
  double v12; // st6
  double v13; // st4
  double v14; // st5
  double v15; // st4
  double v16; // [esp+8h] [ebp-80h] BYREF
  double v17; // [esp+10h] [ebp-78h] BYREF
  double v18; // [esp+18h] [ebp-70h]
  double v19; // [esp+20h] [ebp-68h]
  double v20; // [esp+28h] [ebp-60h]
  double v21; // [esp+30h] [ebp-58h]
  double v22; // [esp+38h] [ebp-50h]
  double v23; // [esp+40h] [ebp-48h]
  double v24; // [esp+48h] [ebp-40h]
  double v25; // [esp+50h] [ebp-38h]
  double v26; // [esp+58h] [ebp-30h]
  double v27; // [esp+60h] [ebp-28h]
  double v28; // [esp+68h] [ebp-20h]
  double v29; // [esp+70h] [ebp-18h]
  double v30; // [esp+78h] [ebp-10h]
  double v31; // [esp+80h] [ebp-8h]

  if ( !sub_4D7880(&unk_8ADB88) )
    return 0.0;
  v4 = (double *)sub_4D7570(*(_DWORD *)(this + 3012));
  if ( !v4 )
    return 0.0;
  v20 = (double)*(int *)(this + 3140) * *(double *)(this + 3128) + *(double *)(this + 3120);
  v18 = 1.0 - v20;
  sub_430600(this, (int)&dword_8ADB00, (float *)&v17, (float *)&v16);
  v21 = ((double)*(int *)(this + 3268) * *(double *)(this + 3256) + *(double *)(this + 3248)) * 0.75 + dbl_8ADB40;
  v19 = v21 * 9.81 - *(float *)&v16 * a2 * a2;
  v5 = v19 * v18;
  v16 = v19 * v20;
  v6 = (v16 * v4[44] + v19 * v18 * v4[3]) * (dbl_8ADB60 + 0.02500000037252903) * 1.176470588235294;
  v19 = v18 * v6;
  v20 = v6 * v20;
  v17 = (v5 - v19) * 0.5;
  v18 = (v19 + v5) * 0.5;
  if ( v17 < 0.0 )
  {
    v7 = v18 + v17;
    v17 = 0.0;
    v18 = v7;
  }
  v8 = (v16 - v20) * 0.5;
  v19 = v8;
  v16 = (v20 + v16) * 0.5;
  if ( v8 < 0.0 )
  {
    v19 = 0.0;
    v16 = v16 + v8;
  }
  sub_4D5C70(v4[13], v4[14], v4[15]);
  sub_4D5C70(v4[54], v4[55], v4[56]);
  if ( v17 <= v26 )
    v9 = v17;
  else
    v9 = v26;
  v10 = v17 * ((((v22 * v9 + v23) * v9 + v24) * v9 + v25) * v4[3]);
  if ( v18 <= v26 )
    v11 = v18;
  else
    v11 = v26;
  v12 = v18 * ((((v22 * v11 + v23) * v11 + v24) * v11 + v25) * v4[3]);
  if ( v19 <= v31 )
    v13 = v19;
  else
    v13 = v31;
  v14 = v19 * ((((v27 * v13 + v28) * v13 + v29) * v13 + v30) * v4[44]);
  if ( v16 <= v31 )
    v15 = v16;
  else
    v15 = v31;
  return (v10 + (((v27 * v15 + v28) * v15 + v29) * v15 + v30) * v4[44] * v16 + v14 + v12) / v21;
}
