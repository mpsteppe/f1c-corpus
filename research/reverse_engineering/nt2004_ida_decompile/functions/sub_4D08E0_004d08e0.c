int __thiscall sub_4D08E0(int this, int a2, int a3)
{
  double v4; // st7
  long double v5; // st7
  int v6; // ecx
  long double v7; // st7
  int v8; // edx
  int v9; // eax
  int result; // eax
  float v11; // [esp+0h] [ebp-D0h]
  float v12; // [esp+0h] [ebp-D0h]
  float v13; // [esp+14h] [ebp-BCh]
  float v14; // [esp+14h] [ebp-BCh]
  float v15; // [esp+18h] [ebp-B8h]
  float v16; // [esp+1Ch] [ebp-B4h]
  float v17; // [esp+1Ch] [ebp-B4h]
  float v18; // [esp+20h] [ebp-B0h]
  float v19; // [esp+20h] [ebp-B0h]
  float v20; // [esp+20h] [ebp-B0h]
  float v21; // [esp+24h] [ebp-ACh]
  float v22; // [esp+24h] [ebp-ACh]
  float v23; // [esp+24h] [ebp-ACh]
  float v24; // [esp+28h] [ebp-A8h]
  float v25; // [esp+28h] [ebp-A8h]
  float v26; // [esp+28h] [ebp-A8h]
  int v27; // [esp+2Ch] [ebp-A4h]
  float v28; // [esp+30h] [ebp-A0h] BYREF
  float v29; // [esp+34h] [ebp-9Ch]
  float v30; // [esp+38h] [ebp-98h]
  float v31; // [esp+3Ch] [ebp-94h] BYREF
  float v32; // [esp+40h] [ebp-90h]
  float v33; // [esp+44h] [ebp-8Ch]
  _DWORD v34[3]; // [esp+48h] [ebp-88h] BYREF
  double v35[3]; // [esp+54h] [ebp-7Ch] BYREF
  int v36; // [esp+6Ch] [ebp-64h]
  int v37; // [esp+70h] [ebp-60h]
  int v38; // [esp+74h] [ebp-5Ch]
  int v39; // [esp+78h] [ebp-58h]
  int v40; // [esp+84h] [ebp-4Ch]
  float v41[13]; // [esp+88h] [ebp-48h] BYREF
  float v42; // [esp+BCh] [ebp-14h]

  sub_4D0670(this, &v31);
  sub_4CFA90((int *)(a2 + 24), &v31);
  v31 = 0.0;
  v32 = 0.0;
  v33 = 0.0;
  sub_4CFC00(a2 + 24, &v31);
  sub_4CFE90(a2 + 8, &v31);
  v18 = (double)(int)(*(_DWORD *)this << 10) * 0.000015258789;
  v4 = (double)(int)((*(_DWORD *)(this + 4) & 0xFFC00000) + ((*(_DWORD *)this >> 10) & 0x3FF000));
  v27 = *(_DWORD *)(this + 4) << 10;
  *(float *)(a2 + 36) = v18;
  v21 = v4 * 0.0000019073486;
  *(float *)(a2 + 40) = v21;
  v24 = (double)v27 * 0.000015258789;
  *(float *)(a2 + 44) = v24;
  v5 = (double)((*(_BYTE *)(this + 12) >> 2) & 0x3F) * 0.098174773;
  v13 = sin(v5);
  v16 = cos(v5);
  if ( v13 == 0.0 && v16 == 0.0 )
  {
    v13 = 1.0;
    v16 = 0.0;
  }
  v35[0] = v18;
  v35[1] = v21;
  v35[2] = v24;
  v36 = 0;
  v37 = 0x40000000;
  v38 = 0x40000000;
  v39 = 1201543096;
  v40 = 0;
  if ( !sub_44E990(dbl_760B48, v35, &v28) )
  {
    v28 = 0.0;
    v29 = 1.0;
    v30 = 0.0;
  }
  v19 = v29 * v16 - v30 * 0.0;
  v22 = v30 * v13 - v28 * v16;
  v42 = v29;
  v25 = v28 * 0.0 - v29 * v13;
  v6 = *(_DWORD *)(a2 + 48);
  v7 = 1.0 / sqrt(v25 * v25 + v22 * v22 + v19 * v19);
  v14 = v19 * v7;
  v15 = v22 * v7;
  v17 = v7 * v25;
  v31 = v30 * v15 - v17 * v29;
  v32 = v17 * v28 - v30 * v14;
  v33 = v29 * v14 - v15 * v28;
  v8 = *(_DWORD *)(a2 + 52);
  v9 = *(_DWORD *)(a2 + 56);
  v34[0] = v6;
  v34[1] = v8;
  v34[2] = v9;
  sub_579100(v34, v41);
  if ( v41[6] * v17 + v41[3] * v15 + v41[0] * v14 < 0.99879551 )
  {
    v20 = -asin(v32);
    if ( fabs(v32) == 1.0 )
    {
      v26 = 0.0;
      v23 = atan2(-v17, v14);
    }
    else
    {
      v23 = atan2(v31, v33);
      v26 = atan2(v15, v42);
    }
    *(float *)(a2 + 48) = v20;
    *(float *)(a2 + 52) = v23;
    *(float *)(a2 + 56) = v26;
  }
  v11 = sub_4D0790((_BYTE *)this);
  sub_4D0340((_DWORD *)(a2 + 8), v11);
  v12 = (double)(*(_WORD *)(this + 12) >> 10) * 50.0;
  sub_4D02B0((int *)(a2 + 8), v12);
  result = a3;
  *(_DWORD *)(a2 + 4) = a3;
  return result;
}
