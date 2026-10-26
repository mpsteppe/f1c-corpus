char __thiscall sub_52DF70(void *this, int a2, int a3, int a4, int a5)
{
  double v6; // st7
  int i; // ebx
  unsigned int *v8; // ebx
  float v9; // ecx
  double v10; // st7
  float v11; // ebp
  double v12; // st7
  double v13; // st7
  int v14; // eax
  double v15; // st7
  double v17; // st7
  double v18; // st6
  float v19; // ecx
  float v20; // edx
  float v21; // edx
  float v22; // eax
  float v23; // edx
  float v24; // ecx
  float v25; // [esp+0h] [ebp-108h]
  float v26; // [esp+4h] [ebp-104h]
  float v27; // [esp+4h] [ebp-104h]
  float v28; // [esp+4h] [ebp-104h]
  float v29; // [esp+4h] [ebp-104h]
  float v30; // [esp+4h] [ebp-104h]
  float v31; // [esp+18h] [ebp-F0h]
  float v32; // [esp+1Ch] [ebp-ECh]
  float v33; // [esp+20h] [ebp-E8h] BYREF
  float v34; // [esp+24h] [ebp-E4h] BYREF
  float v35; // [esp+28h] [ebp-E0h] BYREF
  int v36; // [esp+2Ch] [ebp-DCh] BYREF
  float v37; // [esp+30h] [ebp-D8h]
  float v38; // [esp+34h] [ebp-D4h]
  int v39; // [esp+38h] [ebp-D0h] BYREF
  float v40; // [esp+3Ch] [ebp-CCh]
  float v41; // [esp+40h] [ebp-C8h]
  float v42[2]; // [esp+44h] [ebp-C4h] BYREF
  float v43; // [esp+4Ch] [ebp-BCh]
  float v44; // [esp+50h] [ebp-B8h] BYREF
  float v45[3]; // [esp+54h] [ebp-B4h] BYREF
  float v46[3]; // [esp+60h] [ebp-A8h] BYREF
  float v47[3]; // [esp+6Ch] [ebp-9Ch] BYREF
  float v48[3]; // [esp+78h] [ebp-90h] BYREF
  float v49[3]; // [esp+84h] [ebp-84h] BYREF
  float v50[3]; // [esp+90h] [ebp-78h] BYREF
  float v51[3]; // [esp+9Ch] [ebp-6Ch] BYREF
  float v52[3]; // [esp+A8h] [ebp-60h] BYREF
  float v53[3]; // [esp+B4h] [ebp-54h] BYREF
  float v54[3]; // [esp+C0h] [ebp-48h] BYREF
  int v55[3]; // [esp+CCh] [ebp-3Ch] BYREF
  int v56[4]; // [esp+D8h] [ebp-30h] BYREF
  int v57[4]; // [esp+E8h] [ebp-20h] BYREF
  _BYTE v58[16]; // [esp+F8h] [ebp-10h] BYREF

  v33 = *(float *)(a4 + 4);
  if ( *(float *)&a2 >= (double)*(float *)(a3 + 4) )
  {
    if ( *(float *)&a2 > (double)v33 )
      *(float *)&a2 = v33;
  }
  else
  {
    a2 = *(int *)(a3 + 4);
  }
  sub_4D0D00(
    (_DWORD *)a5,
    *(_DWORD *)a3 >> 28,
    *(_BYTE *)(a3 + 2) & 0x3F,
    (unsigned __int16)*(_DWORD *)a3 >> 6,
    *(_DWORD *)a3 & 0x3F,
    a2,
    0);
  v6 = *(float *)(a4 + 4) - *(float *)(a3 + 4);
  v33 = v6;
  if ( v6 > 5.0 )
  {
    if ( (unsigned __int8)sub_52E830(this) )
    {
LABEL_7:
      v31 = 0.0;
      v32 = 1.0;
      goto LABEL_8;
    }
LABEL_16:
    v31 = 1.0;
    v32 = 0.0;
    goto LABEL_8;
  }
  v17 = *(float *)(a4 + 36) - *(float *)(a3 + 36);
  v18 = *(float *)(a4 + 44) - *(float *)(a3 + 44);
  v35 = 1.0 / v33;
  if ( (v18 * v18 + v17 * v17) * v35 >= 14981.386 )
    goto LABEL_16;
  if ( v33 == 0.0 )
    goto LABEL_7;
  v31 = (*(float *)&a2 - *(float *)(a3 + 4)) * v35;
  v32 = 1.0 - v31;
  if ( v32 > 0.0 && v32 < 1.0 )
  {
    v19 = *(float *)(a3 + 40);
    v20 = *(float *)(a3 + 44);
    v50[0] = *(float *)(a3 + 36);
    v50[1] = v19;
    v50[2] = v20;
    sub_4CFBA0((_DWORD *)(a3 + 24), v42);
    v21 = *(float *)(a4 + 40);
    v22 = *(float *)(a4 + 44);
    v36 = *(int *)(a4 + 36);
    v37 = v21;
    v38 = v22;
    sub_4CFBA0((_DWORD *)(a4 + 24), (float *)v55);
    sub_52D550(v50, v42, (float *)&v36, (float *)v55, v31, &v39);
    v23 = v40;
    *(_DWORD *)(a5 + 36) = v39;
    v24 = v41;
    *(float *)(a5 + 40) = v23;
    *(float *)(a5 + 44) = v24;
    goto LABEL_9;
  }
LABEL_8:
  *(float *)(a5 + 36) = v32 * *(float *)(a3 + 36) + v31 * *(float *)(a4 + 36);
  *(float *)(a5 + 40) = v32 * *(float *)(a3 + 40) + v31 * *(float *)(a4 + 40);
  *(float *)(a5 + 44) = v32 * *(float *)(a3 + 44) + v31 * *(float *)(a4 + 44);
LABEL_9:
  sub_579450(a3 + 48, v56);
  sub_579450(a4 + 48, v57);
  sub_579D90((int)v56, (int)v57, v31);
  sub_579430(v58, a5 + 48);
  for ( i = 0; i < 4; ++i )
  {
    sub_4D0130((__int16 *)(a3 + 8), i, &v44, &v33);
    sub_4D0130((__int16 *)(a4 + 8), i, &v34, &v35);
    v26 = v33 * v32 + v35 * v31;
    v25 = v44 * v32 + v34 * v31;
    sub_4CFF90((_WORD *)(a5 + 8), i, v25, v26);
  }
  sub_4CFBA0((_DWORD *)(a3 + 24), v47);
  sub_4CFBA0((_DWORD *)(a4 + 24), v51);
  v43 = v51[2] * v31;
  v40 = v47[1] * v32;
  v41 = v47[2] * v32;
  *(float *)&v36 = v47[0] * v32 + v51[0] * v31;
  LODWORD(v45[0]) = v36;
  v37 = v40 + v51[1] * v31;
  v45[1] = v37;
  v38 = v41 + v43;
  v45[2] = v38;
  sub_4CFA90((int *)(a5 + 24), v45);
  LODWORD(v33) = a3 + 8;
  sub_4CFF40(a3 + 8, (int)v52);
  LODWORD(v35) = a4 + 8;
  sub_4CFF40(a4 + 8, (int)v49);
  v43 = v49[2] * v31;
  v40 = v52[1] * v32;
  v41 = v52[2] * v32;
  *(float *)&v36 = v52[0] * v32 + v49[0] * v31;
  LODWORD(v54[0]) = v36;
  v37 = v40 + v49[1] * v31;
  v38 = v41 + v43;
  v54[1] = v37;
  v8 = (unsigned int *)(a5 + 8);
  v54[2] = v38;
  sub_4CFE90(a5 + 8, v54);
  sub_4CFD10(a3 + 24, v46);
  sub_4CFD10(a4 + 24, v53);
  v43 = v53[2] * v31;
  v40 = v46[1] * v32;
  v41 = v46[2] * v32;
  *(float *)&v36 = v46[0] * v32 + v53[0] * v31;
  LODWORD(v48[0]) = v36;
  v37 = v40 + v53[1] * v31;
  v48[1] = v37;
  v38 = v41 + v43;
  v48[2] = v38;
  sub_4CFC00(a5 + 24, v48);
  if ( v31 <= 0.0 )
  {
    *v8 = *(_DWORD *)LODWORD(v33);
    *(_DWORD *)(a5 + 12) = *(_DWORD *)(a3 + 12);
  }
  else
  {
    v9 = v35;
    *v8 = *(_DWORD *)LODWORD(v35);
    *(_DWORD *)(a5 + 12) = *(_DWORD *)(a4 + 12);
    if ( v31 < 1.0 )
    {
      v10 = sub_4D03F0((_DWORD *)LODWORD(v9));
      v11 = v33;
      v34 = v10 * v31;
      v12 = sub_4D03F0((_DWORD *)LODWORD(v33));
      v27 = v12 * v32 + v34;
      sub_4D03C0(v8, v27);
      v34 = sub_4D0370((_WORD *)LODWORD(v35)) * v31;
      v13 = sub_4D0370((_WORD *)LODWORD(v11));
      v28 = v13 * v32 + v34;
      sub_4D0340(v8, v28);
      v34 = COERCE_FLOAT(sub_4D03B0((_DWORD *)LODWORD(v35)));
      v14 = sub_4D03B0((_DWORD *)LODWORD(v11));
      if ( v14 == LODWORD(v34) )
      {
        v34 = sub_4D0310((_DWORD *)LODWORD(v35)) * v31;
        v15 = sub_4D0310((_DWORD *)LODWORD(v11));
        v29 = v15 * v32 + v34;
        sub_4D02B0((int *)v8, v29);
        return 1;
      }
      if ( (*(float *)(a3 + 4) + *(float *)(a4 + 4)) * 0.5 > *(float *)&a2 )
      {
        v30 = sub_4D0310((_DWORD *)LODWORD(v33));
        sub_4D02B0((int *)v8, v30);
        return 1;
      }
    }
  }
  return 1;
}
