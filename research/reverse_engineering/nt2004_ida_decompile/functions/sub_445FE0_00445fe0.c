int __thiscall sub_445FE0(char *this)
{
  char *v1; // esi
  char *v2; // ebx
  int v3; // ebp
  int v4; // ecx
  int v5; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st7
  double v9; // st5
  double v10; // st7
  double v11; // st7
  double v12; // st6
  double v13; // st7
  double v14; // st6
  double v15; // st5
  double v16; // st4
  double v17; // st5
  bool v18; // zf
  int v19; // eax
  double v20; // st4
  double v21; // st6
  double v22; // st7
  char v23; // al
  double v24; // st7
  double v25; // st7
  char v26; // al
  double v27; // st7
  double v28; // st7
  double *v29; // ebp
  char *v30; // ebx
  double v31; // st7
  int result; // eax
  int v33; // [esp+20h] [ebp-C0h]
  double v34; // [esp+20h] [ebp-C0h]
  double v35; // [esp+20h] [ebp-C0h]
  int v36; // [esp+20h] [ebp-C0h]
  double v37; // [esp+28h] [ebp-B8h]
  double v38; // [esp+28h] [ebp-B8h]
  double v39; // [esp+28h] [ebp-B8h]
  char *v41; // [esp+34h] [ebp-ACh]
  double v42[3]; // [esp+38h] [ebp-A8h] BYREF
  double v43[3]; // [esp+50h] [ebp-90h] BYREF
  double v44[3]; // [esp+68h] [ebp-78h] BYREF
  char v45; // [esp+80h] [ebp-60h] BYREF
  char v46; // [esp+90h] [ebp-50h] BYREF

  v1 = this;
  v41 = &v45;
  v2 = this + 1056;
  v33 = 4;
  do
  {
    if ( !v2[124] )
    {
      v3 = *((_DWORD *)v2 - 9);
      if ( !v3 )
        v3 = *((_DWORD *)v1 + 1423);
      sub_438520((double *)(v3 + 28), (double *)v2 - 4, (double *)v2 - 1);
      v4 = *((_DWORD *)v1 + 1541);
      v42[0] = *((double *)v2 - 1) + *(double *)(v3 + 4);
      v42[1] = *(double *)(v3 + 12) + *(double *)v2;
      v42[2] = *(double *)(v3 + 20) + *((double *)v2 + 1);
      sub_438520((double *)(v4 + 28), (double *)v2 + 2, (double *)v2 + 5);
      v5 = *((_DWORD *)v1 + 1541);
      v6 = *(double *)(v5 + 4) + *((double *)v2 + 5);
      v7 = *(double *)(v5 + 12) + *((double *)v2 + 6);
      v44[2] = *(double *)(v5 + 20) + *((double *)v2 + 7);
      v42[0] = v42[0] - v6;
      v8 = v42[1] - v7;
      v37 = sqrt((v42[2] - v44[2]) * (v42[2] - v44[2]) + v8 * v8 + v42[0] * v42[0]);
      v42[0] = v42[0] * (1.0 / v37);
      v9 = v8;
      v10 = 1.0 / v37;
      v42[1] = v9 * v10;
      v42[2] = (v42[2] - v44[2]) * v10;
      qmemcpy(v41, v42, 0x18u);
      v11 = *(double *)(v3 + 132) * *((double *)v2 + 1) - *(double *)(v3 + 140) * *(double *)v2;
      v12 = *(double *)(v3 + 140) * *((double *)v2 - 1) - *(double *)(v3 + 124) * *((double *)v2 + 1);
      v43[2] = *(double *)v2 * *(double *)(v3 + 124) - *(double *)(v3 + 132) * *((double *)v2 - 1);
      v43[0] = v11 + *(double *)(v3 + 100);
      v13 = v12 + *(double *)(v3 + 108);
      v14 = v43[2] + *(double *)(v3 + 116);
      v15 = *(double *)(v5 + 132) * *((double *)v2 + 7) - *(double *)(v5 + 140) * *((double *)v2 + 6);
      v16 = *(double *)(v5 + 140) * *((double *)v2 + 5) - *((double *)v2 + 7) * *(double *)(v5 + 124);
      v44[2] = *((double *)v2 + 6) * *(double *)(v5 + 124) - *(double *)(v5 + 132) * *((double *)v2 + 5);
      v44[0] = v15 + *(double *)(v5 + 100);
      v17 = v16 + *(double *)(v5 + 108);
      v44[2] = v44[2] + *(double *)(v5 + 116);
      v43[0] = v43[0] - v44[0];
      v43[1] = v13 - v17;
      sub_43AA30((double *)(v2 - 388), v37, v42[2] * (v14 - v44[2]) + v42[1] * v43[1] + v43[0] * v42[0]);
      v1 = this;
    }
    v2 += 1256;
    v18 = v33 == 1;
    v41 += 24;
    --v33;
  }
  while ( !v18 );
  if ( *(_DWORD *)dword_766AA4 )
  {
    v19 = *((_DWORD *)v1 + 1541);
    v20 = *(double *)(v19 + 100) * *(double *)(v19 + 100)
        + *(double *)(v19 + 108) * *(double *)(v19 + 108)
        + *(double *)(v19 + 116) * *(double *)(v19 + 116);
    v21 = v20 * *((double *)v1 + 717);
    *((double *)v1 + 148) = v21 + *((double *)v1 + 148);
    *((double *)v1 + 305) = v21 + *((double *)v1 + 305);
    v22 = v20 * *((double *)v1 + 718);
    *((double *)v1 + 462) = v22 + *((double *)v1 + 462);
    *((double *)v1 + 619) = v22 + *((double *)v1 + 619);
  }
  if ( !v1[1180] && !v1[2436] )
  {
    v23 = v1[5760];
    v24 = (*(double *)(v1 + 1156) - *(double *)(v1 + 1172) - (*(double *)(v1 + 2412) - *(double *)(v1 + 2428)))
        * *((double *)v1 + 715);
    v38 = v24 + *((double *)v1 + 148);
    *((double *)v1 + 148) = v38;
    v34 = *((double *)v1 + 305) - v24;
    *((double *)v1 + 305) = v34;
    if ( v23 )
    {
      v25 = sub_438EA0(
              (double *)(v1 + 5764),
              (*(double *)(v1 + 2412) + *(double *)(v1 + 1156)) * 0.5,
              (*(double *)(v1 + 2420) + *(double *)(v1 + 1164)) * 0.5)
          * 0.5;
      *((double *)v1 + 148) = v38 + v25;
      *((double *)v1 + 305) = v34 + v25;
    }
  }
  if ( !v1[3692] && !v1[4948] )
  {
    v26 = v1[5760];
    v27 = (*(double *)(v1 + 3668) - *(double *)(v1 + 3684) - (*(double *)(v1 + 4924) - *(double *)(v1 + 4940)))
        * *((double *)v1 + 716);
    v39 = v27 + *((double *)v1 + 462);
    *((double *)v1 + 462) = v39;
    v35 = *((double *)v1 + 619) - v27;
    *((double *)v1 + 619) = v35;
    if ( v26 )
    {
      v28 = sub_438EA0(
              (double *)(v1 + 5884),
              (*(double *)(v1 + 4924) + *(double *)(v1 + 3668)) * 0.5,
              (*(double *)(v1 + 4932) + *(double *)(v1 + 3676)) * 0.5)
          * 0.5;
      *((double *)v1 + 462) = v39 + v28;
      *((double *)v1 + 619) = v35 + v28;
    }
  }
  v29 = (double *)&v46;
  v30 = v1 + 1020;
  v36 = 4;
  do
  {
    if ( !v30[160] )
    {
      v31 = *(double *)(v30 + 164);
      v43[0] = v31 * *(v29 - 2);
      v43[1] = v31 * *(v29 - 1);
      v43[2] = v31 * *v29;
      qmemcpy(v44, v43, sizeof(v44));
      sub_57C860(v30 + 28, v44);
      sub_57C900(v30 + 76, v44);
    }
    v30 += 1256;
    v29 += 3;
    result = --v36;
  }
  while ( v36 );
  return result;
}
