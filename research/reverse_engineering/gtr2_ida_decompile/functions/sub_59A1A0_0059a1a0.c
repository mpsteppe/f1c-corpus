char __thiscall sub_59A1A0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  double v5; // st7
  double v7; // st7
  int i; // ebx
  int *v9; // ebx
  float v10; // ecx
  double v11; // st7
  float v12; // ebp
  double v13; // st7
  double v14; // st7
  int v15; // eax
  double v16; // st7
  double v18; // st7
  double v19; // st6
  float v20; // ecx
  float v21; // eax
  float v22; // ecx
  float v23; // edx
  float v24; // ecx
  float v25; // eax
  float v26; // [esp+0h] [ebp-108h]
  float v27; // [esp+4h] [ebp-104h]
  float v28; // [esp+4h] [ebp-104h]
  float v29; // [esp+4h] [ebp-104h]
  float v30; // [esp+4h] [ebp-104h]
  float v31; // [esp+4h] [ebp-104h]
  float v32; // [esp+18h] [ebp-F0h]
  float v33; // [esp+1Ch] [ebp-ECh]
  int v34; // [esp+20h] [ebp-E8h] BYREF
  float v35; // [esp+24h] [ebp-E4h]
  float v36; // [esp+28h] [ebp-E0h]
  float v37; // [esp+2Ch] [ebp-DCh] BYREF
  int v38; // [esp+30h] [ebp-D8h] BYREF
  float v39; // [esp+34h] [ebp-D4h]
  float v40; // [esp+38h] [ebp-D0h]
  float v41; // [esp+3Ch] [ebp-CCh] BYREF
  float v42; // [esp+40h] [ebp-C8h] BYREF
  int v43; // [esp+44h] [ebp-C4h] BYREF
  float v44; // [esp+48h] [ebp-C0h]
  float v45; // [esp+4Ch] [ebp-BCh]
  float v46; // [esp+50h] [ebp-B8h] BYREF
  float v47[3]; // [esp+54h] [ebp-B4h] BYREF
  float v48[3]; // [esp+60h] [ebp-A8h] BYREF
  float v49[3]; // [esp+6Ch] [ebp-9Ch] BYREF
  float v50[3]; // [esp+78h] [ebp-90h] BYREF
  float v51[3]; // [esp+84h] [ebp-84h] BYREF
  float v52[3]; // [esp+90h] [ebp-78h] BYREF
  float v53[3]; // [esp+9Ch] [ebp-6Ch] BYREF
  float v54[3]; // [esp+A8h] [ebp-60h] BYREF
  float v55[3]; // [esp+B4h] [ebp-54h] BYREF
  int v56[3]; // [esp+C0h] [ebp-48h] BYREF
  float v57[3]; // [esp+CCh] [ebp-3Ch] BYREF
  int v58[4]; // [esp+D8h] [ebp-30h] BYREF
  int v59[4]; // [esp+E8h] [ebp-20h] BYREF
  _BYTE v60[16]; // [esp+F8h] [ebp-10h] BYREF

  v5 = *(float *)(a3 + 4);
  v37 = *(float *)(a4 + 4);
  if ( *(float *)&a2 >= v5 )
  {
    if ( *(float *)&a2 > (double)v37 )
      *(float *)&a2 = v37;
  }
  else
  {
    *(float *)&a2 = v5;
  }
  sub_51B2A0(
    (_DWORD *)a5,
    *(_DWORD *)a3 >> 29,
    (*(_DWORD *)a3 >> 18) & 0x3F,
    (*(_DWORD *)a3 >> 8) & 0x3FF,
    (unsigned __int8)*(_DWORD *)a3,
    a2,
    0);
  v7 = *(float *)(a4 + 4) - *(float *)(a3 + 4);
  v37 = v7;
  if ( v7 > 5.0 )
  {
    if ( this[215] != -23693671 )
    {
LABEL_7:
      v32 = 0.0;
      v33 = 1.0;
      goto LABEL_8;
    }
LABEL_16:
    v32 = 1.0;
    v33 = 0.0;
    goto LABEL_8;
  }
  v18 = *(float *)(a4 + 36) - *(float *)(a3 + 36);
  v19 = *(float *)(a4 + 44) - *(float *)(a3 + 44);
  v42 = 1.0 / v37;
  if ( (v19 * v19 + v18 * v18) * v42 >= 14981.386 )
    goto LABEL_16;
  if ( v37 == 0.0 )
    goto LABEL_7;
  v32 = (*(float *)&a2 - *(float *)(a3 + 4)) * v42;
  v33 = 1.0 - v32;
  if ( v33 > 0.0 && v33 < 1.0 )
  {
    v20 = *(float *)(a3 + 44);
    v21 = *(float *)(a3 + 40);
    v43 = *(int *)(a3 + 36);
    v45 = v20;
    v44 = v21;
    sub_519E70((_DWORD *)(a3 + 24), v57);
    v22 = *(float *)(a4 + 40);
    v23 = *(float *)(a4 + 44);
    v34 = *(int *)(a4 + 36);
    v35 = v22;
    v36 = v23;
    sub_519E70((_DWORD *)(a4 + 24), (float *)v56);
    sub_599610((float *)&v43, v57, (float *)&v34, (float *)v56, v32, &v38);
    v24 = v39;
    *(float *)(a5 + 36) = *(float *)&v38;
    v25 = v40;
    *(float *)(a5 + 40) = v24;
    *(float *)(a5 + 44) = v25;
    goto LABEL_9;
  }
LABEL_8:
  *(float *)(a5 + 36) = v33 * *(float *)(a3 + 36) + v32 * *(float *)(a4 + 36);
  *(float *)(a5 + 40) = v33 * *(float *)(a3 + 40) + v32 * *(float *)(a4 + 40);
  *(float *)(a5 + 44) = v33 * *(float *)(a3 + 44) + v32 * *(float *)(a4 + 44);
LABEL_9:
  sub_614DD0(a3 + 48, v59);
  sub_614DD0(a4 + 48, v58);
  sub_615280((int)v59, (int)v58, v32);
  sub_614DB0(v60, a5 + 48);
  for ( i = 0; i < 4; ++i )
  {
    sub_519FF0((__int16 *)(a3 + 8), i, &v46, &v37);
    sub_519FF0((__int16 *)(a4 + 8), i, &v41, &v42);
    v27 = v37 * v33 + v42 * v32;
    v26 = v46 * v33 + v41 * v32;
    sub_51ABA0((_WORD *)(a5 + 8), i, v26, v27);
  }
  sub_519E70((_DWORD *)(a3 + 24), v49);
  sub_519E70((_DWORD *)(a4 + 24), v53);
  *(float *)&v38 = v53[0] * v32;
  v43 = v38;
  v39 = v53[1] * v32;
  v44 = v39;
  v40 = v53[2] * v32;
  v45 = v40;
  *(float *)&v38 = v49[0] * v33;
  v34 = v38;
  v39 = v49[1] * v33;
  v35 = v39;
  v40 = v49[2] * v33;
  v36 = v40;
  *(float *)&v38 = *(float *)&v43 + *(float *)&v38;
  LODWORD(v47[0]) = v38;
  v39 = v44 + v39;
  v47[1] = v39;
  v40 = v45 + v40;
  v47[2] = v40;
  sub_51A830((_DWORD *)(a5 + 24), v47);
  LODWORD(v37) = a3 + 8;
  sub_519FA0(a3 + 8, (int)v55);
  LODWORD(v42) = a4 + 8;
  sub_519FA0(a4 + 8, (int)v51);
  *(float *)&v34 = v51[0] * v32;
  v43 = v34;
  v35 = v51[1] * v32;
  v44 = v35;
  v36 = v51[2] * v32;
  v45 = v36;
  v9 = (int *)(a5 + 8);
  *(float *)&v34 = v55[0] * v33;
  v38 = v34;
  v35 = v55[1] * v33;
  v39 = v35;
  v36 = v55[2] * v33;
  v40 = v36;
  *(float *)&v34 = *(float *)&v43 + *(float *)&v34;
  LODWORD(v54[0]) = v34;
  v35 = v44 + v35;
  v54[1] = v35;
  v36 = v45 + v36;
  v54[2] = v36;
  sub_51AAF0(v54);
  sub_519ED0(a3 + 24, v48);
  sub_519ED0(a4 + 24, v52);
  *(float *)&v34 = v52[0] * v32;
  v43 = v34;
  v35 = v52[1] * v32;
  v44 = v35;
  v36 = v52[2] * v32;
  v45 = v36;
  *(float *)&v34 = v48[0] * v33;
  v38 = v34;
  v35 = v48[1] * v33;
  v39 = v35;
  v36 = v48[2] * v33;
  v40 = v36;
  *(float *)&v34 = *(float *)&v43 + *(float *)&v34;
  v35 = v44 + v35;
  LODWORD(v50[0]) = v34;
  v36 = v45 + v36;
  v50[2] = v36;
  v50[1] = v35;
  sub_51A940(a5 + 24, v50);
  if ( v32 <= 0.0 )
  {
    *v9 = *(_DWORD *)LODWORD(v37);
    *(_DWORD *)(a5 + 12) = *(_DWORD *)(a3 + 12);
  }
  else
  {
    v10 = v42;
    *v9 = *(_DWORD *)LODWORD(v42);
    *(_DWORD *)(a5 + 12) = *(_DWORD *)(a4 + 12);
    if ( v32 < 1.0 )
    {
      v11 = sub_51A1E0((_DWORD *)LODWORD(v10));
      v12 = v37;
      v41 = v11 * v32;
      v13 = sub_51A1E0((_DWORD *)LODWORD(v37));
      v28 = v13 * v33 + v41;
      sub_51ADC0(v9, v28);
      v41 = sub_51A190((_DWORD *)LODWORD(v42)) * v32;
      v14 = sub_51A190((_DWORD *)LODWORD(v12));
      v29 = v14 * v33 + v41;
      sub_51AD90(v9, v29);
      v41 = COERCE_FLOAT(sub_51A1D0((_DWORD *)LODWORD(v42)));
      v15 = sub_51A1D0((_DWORD *)LODWORD(v12));
      if ( v15 == LODWORD(v41) )
      {
        v41 = sub_51A170((_DWORD *)LODWORD(v42)) * v32;
        v16 = sub_51A170((_DWORD *)LODWORD(v12));
        v30 = v16 * v33 + v41;
        sub_51AD40(v9, v30);
        return 1;
      }
      if ( (*(float *)(a3 + 4) + *(float *)(a4 + 4)) * 0.5 > *(float *)&a2 )
      {
        v31 = sub_51A170((_DWORD *)LODWORD(v37));
        sub_51AD40(v9, v31);
        return 1;
      }
    }
  }
  return 1;
}
