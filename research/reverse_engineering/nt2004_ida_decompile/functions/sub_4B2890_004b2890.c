int __thiscall sub_4B2890(_DWORD *this, int a2, int *a3, int a4, int a5, char a6)
{
  int v7; // ebx
  __int64 v8; // rax
  int v9; // eax
  int v10; // ebx
  int v11; // ecx
  double v12; // st7
  double v13; // st5
  int v14; // esi
  double v15; // st7
  int v16; // edi
  int v17; // eax
  int v18; // ecx
  int v20; // [esp+10h] [ebp-B4h] BYREF
  int v21; // [esp+14h] [ebp-B0h]
  int v22; // [esp+18h] [ebp-ACh] BYREF
  int v23; // [esp+1Ch] [ebp-A8h]
  int v24; // [esp+20h] [ebp-A4h]
  float v25[16]; // [esp+24h] [ebp-A0h] BYREF
  float v26[4]; // [esp+64h] [ebp-60h] BYREF
  float v27; // [esp+74h] [ebp-50h]
  int v28; // [esp+78h] [ebp-4Ch]
  float v29; // [esp+84h] [ebp-40h]
  float v30; // [esp+88h] [ebp-3Ch]
  int v31; // [esp+8Ch] [ebp-38h]
  float v32; // [esp+90h] [ebp-34h]
  float v33; // [esp+94h] [ebp-30h]
  int v34; // [esp+98h] [ebp-2Ch]
  float v35; // [esp+A4h] [ebp-20h]
  float v36; // [esp+A8h] [ebp-1Ch]
  int v37; // [esp+ACh] [ebp-18h]
  float v38; // [esp+B0h] [ebp-14h]
  float v39; // [esp+B4h] [ebp-10h]
  int v40; // [esp+B8h] [ebp-Ch]

  v22 = 0;
  v20 = 0;
  sub_5A41F0(a2, &v22, &v20, 0);
  v7 = (__int64)((double)v22 * *(float *)(a4 + 172));
  v22 = v7;
  v8 = (__int64)((double)v20 * *(float *)(a4 + 176));
  v20 = v8;
  if ( v7 > 0 && (int)v8 > 0 )
  {
    v24 = this[2];
    v9 = *a3;
    v10 = v24 - v7 / 2;
    v11 = this[3];
    v23 = *a3 + v20 + 4;
    v12 = (double)v23;
    v23 = v9 + 4;
    v13 = (double)v24;
    v21 = v10;
    v26[2] = 0.0;
    v28 = 0;
    v31 = 0;
    v34 = 0;
    v26[0] = v13 - 1.0;
    v37 = 0;
    v40 = 0;
    v26[1] = v12;
    v25[2] = 0.0;
    v25[5] = 0.0;
    v26[3] = v13;
    v25[10] = 0.0;
    v25[13] = 0.0;
    v27 = (double)(v11 - v9) * 0.94999999 + (double)(v9 + 4);
    v29 = v13 - 2.0;
    v30 = v12;
    v32 = v13;
    v33 = v27;
    v35 = v13 - 3.0;
    v36 = v12;
    v38 = v13;
    v39 = v27;
    v25[0] = v13;
    v25[1] = v12;
    v25[3] = v13;
    v25[4] = v27;
    v25[8] = v13 - 4.0;
    v25[9] = v12;
    v25[11] = v13;
    v25[12] = v27;
    sub_4AB2E0((int)v26, 3, -2002081110, dword_7E8CDC, 0);
    sub_4AB2E0((int)v25, 2, -2000962629, dword_7E8CDC, 0);
    if ( dword_766080[0] )
    {
      sub_5069D0(v10 - 4, *a3 - 4, 1, 0);
      sub_506980(v22 + 8, v20 + 8);
      sub_506B20(-1996488705);
      sub_506960(0);
    }
    v14 = (__int64)(1.0 / *(float *)(a4 + 172) * (double)v21);
    v15 = 1.0 / *(float *)(a4 + 176) * (double)*a3;
    v24 = *(_DWORD *)(a4 + 152);
    v21 = (__int64)v15;
    sub_5A3F10(-1);
    sub_5A3FF0(a2, v14, v21, dword_7E8CDC, 0);
    sub_5A3F10(v24);
    if ( a6 && dword_766084 )
    {
      v16 = v20 + 8;
      v17 = sub_4B1A80(0xFFFFFF, -1, 0.0);
      v18 = *a3 - 4;
      v21 = v17;
      sub_5069D0(v10 + v22 + 5, v18, 1, 0);
      sub_506980(v16, v16);
      sub_506B20(v21);
      sub_506960(0);
    }
    LODWORD(v8) = v20 + 8 + *a3;
    *a3 = v8;
  }
  return v8;
}
