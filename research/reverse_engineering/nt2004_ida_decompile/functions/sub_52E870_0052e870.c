char __thiscall sub_52E870(int this, int a2, int a3, float a4)
{
  _DWORD *v5; // eax
  int v6; // ecx
  double v7; // st7
  double v8; // st7
  signed int v9; // edx
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // ecx
  double v13; // st7
  char v15; // bl
  int v16; // [esp+Ch] [ebp-118h]
  float v17; // [esp+10h] [ebp-114h]
  float v18; // [esp+14h] [ebp-110h]
  float v19; // [esp+14h] [ebp-110h]
  float v20; // [esp+14h] [ebp-110h]
  float v21; // [esp+18h] [ebp-10Ch]
  float v22; // [esp+18h] [ebp-10Ch]
  float v23; // [esp+18h] [ebp-10Ch]
  float v24; // [esp+1Ch] [ebp-108h]
  float v25; // [esp+1Ch] [ebp-108h]
  float v26; // [esp+1Ch] [ebp-108h]
  float v27; // [esp+20h] [ebp-104h]
  float v28[9]; // [esp+24h] [ebp-100h] BYREF
  float v29; // [esp+48h] [ebp-DCh] BYREF
  float v30; // [esp+4Ch] [ebp-D8h]
  float v31; // [esp+50h] [ebp-D4h]
  float v32; // [esp+54h] [ebp-D0h]
  float v33; // [esp+58h] [ebp-CCh]
  float v34; // [esp+5Ch] [ebp-C8h]
  float v35; // [esp+60h] [ebp-C4h]
  float v36; // [esp+64h] [ebp-C0h]
  float v37; // [esp+68h] [ebp-BCh]
  float v38; // [esp+6Ch] [ebp-B8h]
  float v39; // [esp+70h] [ebp-B4h]
  float v40; // [esp+74h] [ebp-B0h]
  float v41; // [esp+78h] [ebp-ACh] BYREF
  float v42; // [esp+7Ch] [ebp-A8h]
  float v43; // [esp+80h] [ebp-A4h]
  float v44; // [esp+84h] [ebp-A0h] BYREF
  float v45; // [esp+88h] [ebp-9Ch]
  float v46; // [esp+8Ch] [ebp-98h]
  float v47[3]; // [esp+90h] [ebp-94h] BYREF
  float v48[9]; // [esp+9Ch] [ebp-88h] BYREF
  float v49[9]; // [esp+C0h] [ebp-64h] BYREF
  float v50[4]; // [esp+E4h] [ebp-40h] BYREF
  float v51[4]; // [esp+F4h] [ebp-30h] BYREF
  float v52[4]; // [esp+104h] [ebp-20h] BYREF
  _BYTE v53[16]; // [esp+114h] [ebp-10h] BYREF

  v5 = (_DWORD *)(this + 216);
  v6 = *(_BYTE *)(this + 218) & 0x3F;
  if ( v6 )
  {
    sub_4D0D00((_DWORD *)a3, *v5 >> 28, v6, (unsigned __int16)*v5 >> 6, *v5 & 0x3F, a2, 0);
    v7 = *(float *)(this + 12) - *(float *)(this + 220);
    v27 = v7;
    if ( v7 == 0.0 )
    {
      v8 = 1.0;
      v17 = 0.0;
    }
    else
    {
      v17 = (*(float *)&a2 - *(float *)(this + 220)) / v27;
      v8 = 1.0 - v17;
    }
    v9 = (*(_DWORD *)(this + 22) & 0xFFC00000) + ((*(_DWORD *)(this + 18) >> 10) & 0x3FF000);
    v10 = *(_DWORD *)(this + 230);
    v11 = (v10 & 0xFFC00000) + ((*(_DWORD *)(this + 226) >> 10) & 0x3FF000);
    v47[0] = (double)(int)(*(_DWORD *)(this + 18) << 10) * 0.000015258789 * v17
           + (double)(int)(*(_DWORD *)(this + 226) << 10) * 0.000015258789 * v8;
    v16 = v11;
    v12 = *(_DWORD *)(this + 22) << 10;
    v47[1] = (double)v9 * 0.0000019073486 * v17 + (double)v16 * 0.0000019073486 * v8;
    v47[2] = (double)(v10 << 10) * 0.000015258789 * v8 + (double)v12 * 0.000015258789 * v17;
    sub_4CF5A0((_DWORD *)(a3 + 10), v47);
    sub_4CF950((int *)(this + 234), v50);
    v18 = (double)*(__int16 *)(this + 244) * 0.0078125;
    v21 = (double)*(__int16 *)(this + 246) * 0.0078125;
    v24 = (double)*(__int16 *)(this + 248) * 0.0078125;
    sub_4CF950((int *)(this + 26), v52);
    sub_579360(v50, v48);
    qmemcpy(v28, v48, sizeof(v28));
    v38 = v48[6] * v24 + v48[3] * v21 + v48[0] * v18;
    v39 = v48[7] * v24 + v48[4] * v21 + v48[1] * v18;
    v40 = v48[8] * v24 + v48[5] * v21 + v48[2] * v18;
    v19 = v38 * v27;
    v41 = v19;
    v22 = v39 * v27;
    v42 = v22;
    v25 = v40 * v27;
    v43 = v25;
    sub_579930(&v41, v47);
    sub_579360(v52, &v29);
    v49[0] = v28[6] * v35 + v28[3] * v32 + v29 * v28[0];
    v49[1] = v28[6] * v36 + v28[3] * v33 + v30 * v28[0];
    v49[2] = v28[6] * v37 + v28[3] * v34 + v31 * v28[0];
    v49[3] = v28[7] * v35 + v28[4] * v32 + v28[1] * v29;
    v49[4] = v28[7] * v36 + v28[4] * v33 + v28[1] * v30;
    v49[5] = v28[7] * v37 + v28[4] * v34 + v28[1] * v31;
    v49[6] = v28[2] * v29 + v28[8] * v35 + v28[5] * v32;
    v49[7] = v28[2] * v30 + v28[8] * v36 + v28[5] * v33;
    v49[8] = v28[2] * v31 + v28[8] * v37 + v28[5] * v34;
    sub_579200(v49, v53);
    sub_5794F0(v53, &v44);
    v13 = *(float *)&a2 - *(float *)(this + 220);
    qmemcpy(v28, v48, sizeof(v28));
    v20 = v38 * v13;
    v23 = v39 * v13;
    v26 = v40 * v13;
    v41 = v20;
    v42 = v23;
    v43 = v26;
    sub_579930(&v41, v47);
    v44 = v44 * v17;
    v45 = v45 * v17;
    v46 = v46 * v17;
    sub_579930(&v44, v47);
    sub_579200(v28, v51);
    sub_4CF720((_DWORD *)(a3 + 18), v51);
    *(_WORD *)(a3 + 8) = *(_WORD *)(this + 224);
    return 1;
  }
  else
  {
    v15 = sub_52DF70((void *)this, a2, (int)v5, this + 8, a3);
    if ( v15 )
      sub_52E740((float *)a3, a4);
    return v15;
  }
}
