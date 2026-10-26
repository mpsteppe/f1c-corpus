int __thiscall sub_51C210(_DWORD *this, int a2, int a3)
{
  int *v4; // edi
  int v5; // ecx
  double v6; // st7
  double v7; // st6
  long double v8; // st5
  long double v9; // st7
  long double v10; // st6
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  float v14; // ecx
  float v15; // edx
  double v16; // st7
  int v17; // eax
  int result; // eax
  float v19; // [esp+4h] [ebp-D4h]
  float v20; // [esp+4h] [ebp-D4h]
  float v21; // [esp+18h] [ebp-C0h]
  float v22; // [esp+18h] [ebp-C0h]
  float v23; // [esp+1Ch] [ebp-BCh]
  float v24; // [esp+1Ch] [ebp-BCh]
  float v25; // [esp+20h] [ebp-B8h]
  float v26; // [esp+20h] [ebp-B8h]
  float v27; // [esp+28h] [ebp-B0h] BYREF
  float v28; // [esp+2Ch] [ebp-ACh]
  float v29; // [esp+30h] [ebp-A8h]
  float v30; // [esp+34h] [ebp-A4h] BYREF
  float v31; // [esp+38h] [ebp-A0h]
  float v32; // [esp+3Ch] [ebp-9Ch]
  float v33; // [esp+40h] [ebp-98h]
  float v34; // [esp+44h] [ebp-94h]
  float v35; // [esp+48h] [ebp-90h]
  _DWORD v36[3]; // [esp+4Ch] [ebp-8Ch] BYREF
  float v37[9]; // [esp+58h] [ebp-80h] BYREF
  double v38[6]; // [esp+7Ch] [ebp-5Ch] BYREF
  int v39; // [esp+ACh] [ebp-2Ch]
  float v40[9]; // [esp+B4h] [ebp-24h] BYREF

  sub_51A270((int)this, &v27);
  sub_51A830((_DWORD *)(a2 + 24), &v27);
  v27 = 0.0;
  v28 = 0.0;
  v29 = 0.0;
  sub_51A940(a2 + 24, &v27);
  v4 = (int *)(a2 + 8);
  sub_51AAF0(&v27);
  v5 = this[1];
  v6 = (double)(int)(*this << 10) * 0.000015258789;
  v21 = v6;
  v7 = (double)(int)((v5 & 0xFFC00000) + ((*this >> 10) & 0x3FF000)) * 0.0000019073486;
  v23 = v7;
  *(float *)(a2 + 36) = v21;
  *(float *)(a2 + 40) = v23;
  v25 = (double)(v5 << 10) * 0.000015258789;
  *(float *)(a2 + 44) = v25;
  v8 = (double)((*((_BYTE *)this + 12) >> 2) & 0x3F) * 0.098174773;
  v33 = sin(v8);
  v35 = cos(v8);
  if ( v33 == 0.0 && v35 == 0.0 )
  {
    v33 = 1.0;
    v35 = 0.0;
  }
  v38[0] = v6;
  v38[1] = v7;
  v38[2] = v25;
  v39 = 0;
  v38[3] = 2.0;
  v38[4] = 9.999999933815813e36;
  if ( !sub_45D210(dbl_B68610, v38, &v30) )
  {
    v30 = 0.0;
    v31 = 1.0;
    v32 = 0.0;
  }
  v27 = v31 * v35 - v32 * 0.0;
  v28 = v32 * v33 - v30 * v35;
  v29 = v30 * 0.0 - v31 * v33;
  v9 = 1.0 / sqrt(v29 * v29 + v28 * v28 + v27 * v27);
  v10 = v27 * v9;
  v22 = v10;
  v24 = v9 * v28;
  v26 = v9 * v29;
  v27 = v32 * v24 - v26 * v31;
  v28 = v26 * v30 - v32 * v10;
  v29 = v31 * v10 - v24 * v30;
  v37[0] = v10;
  v35 = v29;
  v33 = v27;
  v34 = v28;
  v37[3] = v24;
  v37[1] = v30;
  v37[2] = v27;
  v37[6] = v26;
  v37[4] = v31;
  v37[5] = v28;
  v37[7] = v32;
  v11 = *(_DWORD *)(a2 + 48);
  v37[8] = v29;
  v12 = *(_DWORD *)(a2 + 52);
  v13 = *(_DWORD *)(a2 + 56);
  v36[0] = v11;
  v36[2] = v13;
  v36[1] = v12;
  sub_614A90(v36, v40);
  if ( v40[6] * v26 + v40[3] * v24 + v40[0] * v22 < 0.99879551 )
  {
    sub_40D5D0(v37, (int)&v27);
    v14 = v28;
    v15 = v29;
    *(float *)(a2 + 48) = v27;
    *(float *)(a2 + 52) = v14;
    *(float *)(a2 + 56) = v15;
  }
  switch ( HIBYTE(*((unsigned __int16 *)this + 6)) & 3 )
  {
    case 1:
      v16 = 0.72000003;
      break;
    case 2:
      v16 = 0.86000001;
      break;
    case 3:
      v16 = 1.0;
      break;
    default:
      v16 = 0.57999998;
      break;
  }
  v19 = v16 * 31.0;
  *v4 ^= (*v4 ^ ((unsigned __int8)sub_4015C0(v19) << 12)) & 0x1F000;
  v20 = (double)(*((_WORD *)this + 6) >> 10) * 50.0 * 7.0;
  v17 = sub_4015C0(v20);
  if ( v17 >= 0 )
  {
    if ( v17 > 0x3FFF )
      v17 = 0x3FFF;
  }
  else
  {
    v17 = 0;
  }
  result = v17 << 18;
  *v4 = result | *v4 & 0x3FFFF;
  *(_DWORD *)(a2 + 4) = a3;
  return result;
}
