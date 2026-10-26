char __stdcall sub_52DAB0(float a1, int a2, int a3, float a4)
{
  long double v4; // st7
  int v5; // eax
  double v6; // st7
  float *v7; // ebx
  double v8; // st7
  double v9; // st5
  long double v10; // st6
  long double v11; // st6
  double v12; // st7
  double v13; // st7
  double v14; // st6
  _WORD *v15; // eax
  int v16; // edx
  int v18; // [esp-4h] [ebp-A0h]
  float v19; // [esp+10h] [ebp-8Ch]
  float v20; // [esp+14h] [ebp-88h]
  float v21; // [esp+14h] [ebp-88h]
  float v22; // [esp+18h] [ebp-84h]
  float v23; // [esp+1Ch] [ebp-80h]
  float v24; // [esp+20h] [ebp-7Ch] BYREF
  float v25; // [esp+24h] [ebp-78h]
  float v26; // [esp+28h] [ebp-74h]
  float v27; // [esp+2Ch] [ebp-70h]
  float v28; // [esp+30h] [ebp-6Ch] BYREF
  float v29; // [esp+34h] [ebp-68h]
  float v30; // [esp+38h] [ebp-64h]
  float v31; // [esp+3Ch] [ebp-60h]
  float v32; // [esp+40h] [ebp-5Ch]
  float v33; // [esp+44h] [ebp-58h]
  float v34; // [esp+48h] [ebp-54h] BYREF
  float v35; // [esp+4Ch] [ebp-50h]
  float v36; // [esp+50h] [ebp-4Ch]
  float v37; // [esp+54h] [ebp-48h] BYREF
  float v38; // [esp+58h] [ebp-44h]
  float v39; // [esp+5Ch] [ebp-40h]
  float v40; // [esp+60h] [ebp-3Ch] BYREF
  float v41; // [esp+64h] [ebp-38h]
  float v42; // [esp+68h] [ebp-34h]
  float v43; // [esp+6Ch] [ebp-30h] BYREF
  float v44; // [esp+70h] [ebp-2Ch]
  float v45; // [esp+74h] [ebp-28h]
  char v46[36]; // [esp+78h] [ebp-24h] BYREF

  v19 = a1 - *(float *)(a2 + 4);
  if ( v19 >= -1.25 )
  {
    if ( v19 > 1.25 )
      v19 = 1.25;
  }
  else
  {
    v19 = -1.25;
  }
  v4 = fabs(v19);
  if ( v4 >= 0.25 )
  {
    v20 = -0.125;
    if ( v19 >= 0.0 )
      v20 = 0.125;
  }
  else
  {
    v20 = (2.0 - v4 * 4.0) * v19 * 0.5;
  }
  if ( v4 >= 0.5 )
  {
    v23 = -0.25;
    if ( v19 >= 0.0 )
      v23 = 0.25;
  }
  else
  {
    v23 = (2.0 - (v4 + v4)) * v19 * 0.5;
  }
  if ( v4 >= 1.3 )
  {
    v27 = -0.64999998;
    if ( v19 >= 0.0 )
      v27 = 0.64999998;
  }
  else
  {
    v27 = (2.0 - v4 * 0.76923078) * v19 * 0.5;
  }
  *(_DWORD *)a3 = *(_DWORD *)a2;
  *(_DWORD *)(a3 + 204) = *(_DWORD *)(a2 + 204);
  *(float *)(a3 + 4) = a1;
  sub_4CFBA0((_DWORD *)(a2 + 24), &v24);
  sub_4CFF40(a2 + 8, (int)&v43);
  v5 = 6326 * (*(_DWORD *)a2 & 0x3F);
  v44 = a4 * -9.8100004;
  v6 = v20 * 0.5;
  v18 = dword_6309F4[v5];
  v34 = (v43 * v6 + v24) * v19 + *(float *)(a2 + 36);
  v35 = (v44 * v6 + v25) * v19 + *(float *)(a2 + 40);
  v36 = (v45 * v6 + v26) * v19 + *(float *)(a2 + 44);
  v7 = sub_403D10(&flt_628F60, &v34, v18);
  sub_52D830(v7, (float *)(a2 + 36), &v40);
  sub_52D830(v7, &v34, &v28);
  if ( v19 == 0.0 )
  {
    v8 = 0.0;
    v31 = 0.0;
    v32 = 0.0;
  }
  else
  {
    v33 = v30 - v42;
    v9 = 1.0 / v19;
    v22 = v9;
    v28 = v9 * (v28 - v40);
    v31 = v28;
    v29 = v22 * (v29 - v41);
    v32 = v29;
    v30 = v22 * v33;
    v33 = v30;
    v8 = v30;
  }
  v10 = flt_769BEC
      - sqrt(
          ((v26 - v42) * (v26 - v42) + (v25 - v41) * (v25 - v41) + (v24 - v40) * (v24 - v40))
        / (v26 * v26 + v25 * v25 + v24 * v24 + 0.0099999998));
  if ( v10 < 0.0 )
    v10 = 0.0;
  v11 = v10 * (v19 - v20) * v19 * 0.5;
  *(float *)(a3 + 36) = v31 * v11 + v34;
  *(float *)(a3 + 40) = v32 * v11 + v35;
  *(float *)(a3 + 44) = v8 * v11 + v36;
  if ( !*((_DWORD *)v7 + 82) && !byte_7D74CB )
  {
    v12 = (*(float *)(a3 + 44) - v7[2]) * v7[13]
        + (*(float *)(a3 + 40) - v7[1]) * v7[12]
        + (*(float *)(a3 + 36) - *v7) * v7[11]
        + 0.75
        - v7[34];
    v21 = v12;
    if ( v12 > 0.0 && v7[34] < 28.5 )
    {
      v13 = v21 * v7[11];
      v14 = v21 * v7[12];
      v30 = v21 * v7[13];
      *(float *)(a3 + 36) = *(float *)(a3 + 36) - v13;
      *(float *)(a3 + 40) = *(float *)(a3 + 40) - v14;
      *(float *)(a3 + 44) = *(float *)(a3 + 44) - v30;
    }
  }
  sub_4CFD10(a2 + 24, &v37);
  v37 = v37 * v23;
  v38 = v38 * v27;
  v39 = v39 * v23;
  sub_579100(a2 + 48, v46);
  sub_579930(&v37, a3 + 48);
  v15 = (_WORD *)(a3 + 16);
  v16 = 4;
  do
  {
    *v15 = *(_WORD *)((char *)v15 + a2 - a3);
    ++v15;
    --v16;
  }
  while ( v16 );
  *(_DWORD *)(a3 + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(a3 + 28) = *(_DWORD *)(a2 + 28);
  *(_BYTE *)(a3 + 32) = *(_BYTE *)(a2 + 32);
  *(_WORD *)(a3 + 33) = *(_WORD *)(a2 + 33);
  *(_BYTE *)(a3 + 35) = *(_BYTE *)(a2 + 35);
  *(_DWORD *)(a3 + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(a3 + 12) = *(_DWORD *)(a2 + 12);
  return 1;
}
