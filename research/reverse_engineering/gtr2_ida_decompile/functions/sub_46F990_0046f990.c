double __usercall sub_46F990@<st0>(int a1@<ecx>, float a2@<edi>, float a3@<esi>)
{
  unsigned int v4; // eax
  double v5; // st7
  int v6; // ebp
  float v7; // eax
  double v8; // st7
  long double v9; // st7
  char v10; // al
  int v11; // eax
  int v12; // edx
  double v13; // st7
  _DWORD v15[4]; // [esp+0h] [ebp-E0h] BYREF
  char *v16; // [esp+10h] [ebp-D0h]
  float v17; // [esp+14h] [ebp-CCh] BYREF
  float v18; // [esp+18h] [ebp-C8h] BYREF
  char *v19; // [esp+1Ch] [ebp-C4h]
  float v20; // [esp+20h] [ebp-C0h]
  float v21; // [esp+24h] [ebp-BCh]
  float v22; // [esp+28h] [ebp-B8h] BYREF
  float v23; // [esp+2Ch] [ebp-B4h] BYREF
  float v24; // [esp+30h] [ebp-B0h]
  float v25; // [esp+34h] [ebp-ACh]
  float v26; // [esp+38h] [ebp-A8h] BYREF
  float v27; // [esp+3Ch] [ebp-A4h]
  float v28; // [esp+40h] [ebp-A0h] BYREF
  float v29; // [esp+44h] [ebp-9Ch]
  float v30; // [esp+48h] [ebp-98h]
  float v31; // [esp+4Ch] [ebp-94h]
  float v32; // [esp+50h] [ebp-90h]
  float v33; // [esp+54h] [ebp-8Ch]
  float v34; // [esp+58h] [ebp-88h]
  _BYTE v35[4]; // [esp+5Ch] [ebp-84h] BYREF
  int v36; // [esp+60h] [ebp-80h] BYREF
  int v37; // [esp+64h] [ebp-7Ch] BYREF
  int v38[30]; // [esp+68h] [ebp-78h] BYREF

  if ( *(_BYTE *)(a1 + 1512) && !sub_5F2C00(*(_DWORD *)(a1 + 1508), (int)v38, 4, 1) )
  {
    v4 = v38[0];
    if ( v38[0] > *(_DWORD *)(a1 + 1552) )
      *(_DWORD *)(a1 + 1552) = v38[0];
    v38[0] = v4;
    v5 = (double)v4 / (double)*(unsigned int *)(a1 + 1552);
    if ( v5 >= 1.0 )
      flt_B6C558 = 1.0;
    else
      flt_B6C558 = v5;
    *(_BYTE *)(a1 + 1512) = 0;
  }
  v23 = a3;
  v22 = a2;
  *(float *)&v6 = COERCE_FLOAT(sub_410A80(&dword_91BF20));
  sub_5E4D90(v6, v35, &v36, &v37);
  v26 = *(float *)(a1 + 1516);
  v32 = v32 * -1.0;
  v7 = *(float *)(a1 + 1520);
  v28 = *(float *)(a1 + 1524);
  v24 = v7;
  v33 = v33 * -1.0;
  v34 = v34 * -1.0;
  v26 = -v26;
  v23 = v26;
  v28 = -v28;
  v25 = v28;
  v29 = v32 + v26;
  v26 = v29;
  v30 = v7 + v33;
  v27 = v30;
  v31 = v34 + v28;
  v8 = v28;
  v28 = v31;
  qmemcpy(v38, (const void *)(v6 + 344), 0x6Cu);
  v9 = 1.0 / sqrt(v8 * v25 + v24 * v24 + v23 * v23);
  v18 = COERCE_FLOAT(&v36);
  v17 = COERCE_FLOAT(&v26);
  *(float *)(a1 + 1488) = *(float *)&v38[11] * (v25 * v9)
                        + *(float *)&v38[7] * (v7 * v9)
                        + *(float *)&v38[3] * (v23 * v9);
  sub_5E4E30(LODWORD(v17), LODWORD(v18));
  v10 = *(_BYTE *)(a1 + 1512);
  *(float *)(a1 + 1528) = (float)v36;
  *(float *)(a1 + 1532) = (float)v37;
  if ( !v10 )
  {
    v11 = *(_DWORD *)dword_FB27A4;
    v20 = 0.0;
    (*(void (__thiscall **)(int))(v11 + 208))(dword_FB27A4);
    sub_5F2C70(*(_DWORD *)(a1 + 1508));
    v19 = byte_FFFFFF;
    v18 = COERCE_FLOAT(&v28);
    v22 = v25 - flt_759E2C;
    v17 = COERCE_FLOAT(&v22);
    v29 = v26;
    v23 = v26;
    v28 = flt_759E2C + v25;
    v16 = (char *)dword_FB2790;
    v30 = v27;
    v24 = v27;
    v12 = *(_DWORD *)dword_FB27A4;
    v15[3] = v6;
    (*(void (__thiscall **)(int))(v12 + 500))(dword_FB27A4);
    v23 = 0.0;
    v17 = 0.0;
    v18 = v21 - flt_759E2C;
    v24 = v21 + flt_759E2C;
    v25 = v22;
    v19 = (char *)LODWORD(v22);
    (*(void (__thiscall **)(int, int, void *, float *, float *, char *))(*(_DWORD *)dword_FB27A4 + 500))(
      dword_FB27A4,
      v6,
      dword_FB2790,
      &v17,
      &v23,
      byte_FFFFFF);
    v18 = *(float *)&v6;
    v15[0] = v6;
    *(float *)&v15[2] = v17 - flt_759E2C;
    v19 = v16;
    v15[1] = v16;
    v20 = v17 + flt_759E2C;
    (*(void (__thiscall **)(int, int, void *, _DWORD *, float *, char *))(*(_DWORD *)dword_FB27A4 + 500))(
      dword_FB27A4,
      v6,
      dword_FB2790,
      v15,
      &v18,
      byte_FFFFFF);
    sub_5F2CE0(*(_DWORD *)(a1 + 1508));
    (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_FB27A4 + 208))(dword_FB27A4, 15);
    *(_BYTE *)(a1 + 1512) = 1;
  }
  v13 = (*(float *)(a1 + 1568) - *(float *)(a1 + 1560)) / (*(float *)(a1 + 1556) - *(float *)(a1 + 1560));
  if ( v13 < 0.0 )
    return 0.0 * flt_B6C558;
  if ( v13 > 1.0 )
    v13 = 1.0;
  return v13 * flt_B6C558;
}
