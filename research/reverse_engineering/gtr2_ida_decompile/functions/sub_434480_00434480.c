double __thiscall sub_434480(int this, double a2)
{
  double *v3; // ebx
  int v4; // edi
  double v6; // st7
  double v7; // st6
  double v8; // st7
  double v9; // [esp+18h] [ebp-C4h]
  double v10; // [esp+18h] [ebp-C4h]
  double v11; // [esp+18h] [ebp-C4h]
  double v12; // [esp+20h] [ebp-BCh]
  double v13; // [esp+28h] [ebp-B4h]
  double v14; // [esp+30h] [ebp-ACh]
  double v15; // [esp+38h] [ebp-A4h]
  double v16; // [esp+48h] [ebp-94h]
  double v17; // [esp+48h] [ebp-94h]
  double v18; // [esp+50h] [ebp-8Ch] BYREF
  double v19; // [esp+58h] [ebp-84h]
  double v20; // [esp+60h] [ebp-7Ch] BYREF
  double v21; // [esp+68h] [ebp-74h] BYREF
  double v22; // [esp+70h] [ebp-6Ch]
  double v23; // [esp+78h] [ebp-64h] BYREF
  _BYTE v24[16]; // [esp+80h] [ebp-5Ch] BYREF
  _BYTE v25[76]; // [esp+90h] [ebp-4Ch] BYREF

  if ( !sub_560950(&dword_FAE908, &unk_FAF650) )
    return 0.0;
  v3 = (double *)sub_560800(*(_DWORD *)(this + 3012));
  if ( !v3 )
    return 0.0;
  v4 = sub_560800(*(_DWORD *)(this + 3076));
  if ( !v4 )
    return 0.0;
  v16 = (double)*(int *)(this + 3204) * *(double *)(this + 3192) + *(double *)(this + 3184);
  v22 = 1.0 - v16;
  sub_434330(this, (int)&unk_FAF5C8, (float *)&v20, (float *)&v21);
  v23 = ((double)*(int *)(this + 3332) * *(double *)(this + 3320) + *(double *)(this + 3312)) * 0.74 + dbl_FAF608;
  v19 = v23 * 9.81 - *(float *)&v21 * a2 * a2;
  v6 = v19 * v22;
  v18 = v19 * v16;
  v7 = (v19 * v22 * v3[65] + v18 * *(double *)(v4 + 1512)) * (dbl_FAF628 + 0.02500000037252903) * 1.176470588235294;
  v22 = v22 * v7;
  v17 = v7 * v16;
  v20 = (v6 - v22) * 0.5;
  v21 = (v22 + v6) * 0.5;
  if ( v20 < 0.0 )
  {
    v21 = v21 + v20;
    v20 = 0.0;
  }
  v8 = (v18 - v17) * 0.5;
  v19 = v8;
  v18 = (v17 + v18) * 0.5;
  if ( v8 < 0.0 )
  {
    v18 = v18 + v8;
    v19 = 0.0;
  }
  v14 = v3[77];
  v13 = v3[76];
  v12 = v3[75];
  sub_55F390(v24);
  sub_55F390(v25);
  v9 = sub_431AB0(&v18, v15) * v3[65] * v15;
  v10 = sub_431AB0(&v18, v14) * v3[65] * v14 + v9;
  v11 = sub_431AB0(&v23, v12) * *(double *)(v4 + 1512) * v12 + v10;
  return (sub_431AB0(&v23, v13) * *(double *)(v4 + 1512) * v13 + v11) / v17;
}
