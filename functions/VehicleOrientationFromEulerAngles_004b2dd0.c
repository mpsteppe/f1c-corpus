int __thiscall sub_4B2DD0(char *this, int a2, int a3)
{
  int v4; // edx
  float *v5; // edi
  int v6; // ecx
  int v7; // eax
  long double v8; // st7
  int v9; // eax
  long double v10; // st7
  double v11; // st7
  unsigned int v12; // eax
  double v13; // st7
  double v14; // st6
  float v15; // edx
  int result; // eax
  float v17; // [esp+0h] [ebp-84h]
  float v18; // [esp+0h] [ebp-84h]
  int v19; // [esp+10h] [ebp-74h]
  int v20; // [esp+10h] [ebp-74h]
  float v21; // [esp+14h] [ebp-70h] BYREF
  float v22; // [esp+18h] [ebp-6Ch]
  float v23; // [esp+1Ch] [ebp-68h]
  float v24; // [esp+20h] [ebp-64h] BYREF
  float v25; // [esp+24h] [ebp-60h]
  float v26; // [esp+28h] [ebp-5Ch]
  float v27; // [esp+2Ch] [ebp-58h]
  float v28; // [esp+30h] [ebp-54h]
  float v29; // [esp+34h] [ebp-50h]
  float v30[2]; // [esp+38h] [ebp-4Ch] BYREF
  float v31; // [esp+40h] [ebp-44h]
  float v32; // [esp+44h] [ebp-40h] BYREF
  float v33; // [esp+48h] [ebp-3Ch]
  float v34; // [esp+4Ch] [ebp-38h]
  double v35[3]; // [esp+50h] [ebp-34h] BYREF
  int v36; // [esp+68h] [ebp-1Ch]
  int v37; // [esp+6Ch] [ebp-18h]
  int v38; // [esp+70h] [ebp-14h]
  int v39; // [esp+74h] [ebp-10h]
  int v40; // [esp+80h] [ebp-4h]

  v4 = *(__int16 *)(this + 13);
  v19 = *(__int16 *)(this + 11);
  v5 = (float *)(a2 + 8);
  v21 = (double)*(__int16 *)(this + 9) * 0.015625;
  v22 = (double)v19 * 0.015625;
  v23 = (double)v4 * 0.015625;
  UtilityFunction_2480((_WORD *)(a2 + 8), &v21);
  v30[0] = 0.0;
  v30[1] = 0.0;
  v31 = 0.0;
  FloatToFixedConversionWithClamp(a2 + 8, v30);
  FloatToShortClampedConversion((_WORD *)(a2 + 8), v30);
  if ( v21 != 0.0 || v22 != 0.0 || v23 != 0.0 )
  {
    v20 = *(_DWORD *)this << 8;
    v6 = (*((_DWORD *)this + 1) << 16) + (*((_WORD *)this + 1) & 0xFF00);
    v7 = (*((_DWORD *)this + 1) >> 8) & 0xFFFF00;
    v36 = 0;
    v37 = 0x40000000;
    v38 = 0x40000000;
    v39 = 1201543096;
    v40 = 0;
    v8 = 1.0 / sqrt(v22 * v22 + v23 * v23 + v21 * v21);
    v22 = v22 * v8;
    v23 = v23 * v8;
    v21 = v21 * v8 * -1.0;
    v22 = v22 * -1.0;
    v23 = v23 * -1.0;
    v9 = ((unsigned __int8)this[8] << 24) + v7;
    v35[0] = (double)v20 * 0.000030517578;
    v35[1] = (double)v6 * 0.000030517578;
    v35[2] = (double)v9 * 0.000030517578;
    if ( !CollisionNormalFromFeature(dbl_7C9360, v35, &v24) )
    {
      v24 = 0.0;
      v25 = 1.0;
      v26 = 0.0;
    }
    v27 = v23 * v25 - v22 * v26;
    v28 = v21 * v26 - v23 * v24;
    v29 = v22 * v24 - v21 * v25;
    v10 = 1.0 / sqrt(v29 * v29 + v28 * v28 + v27 * v27);
    v21 = v27 * v10;
    v22 = v28 * v10;
    v23 = v10 * v29;
    v27 = v26 * v22 - v23 * v25;
    v28 = v23 * v24 - v26 * v21;
    v29 = v25 * v21 - v22 * v24;
    v11 = v28;
    FloatConvertWrapper();
    v32 = -v11;
    if ( fabs(v28) == 1.0 )
    {
      v34 = 0.0;
      v33 = atan2(-v23, v21);
    }
    else
    {
      v33 = atan2(v27, v29);
      v34 = atan2(v22, v25);
    }
    FloatToInt16SaturationPack(&v32);
  }
  v12 = *((_DWORD *)this + 1);
  v13 = (double)(int)(*(_DWORD *)this << 8) * 0.000030517578;
  v14 = (double)(int)((v12 << 16) + (*((_WORD *)this + 1) & 0xFF00)) * 0.000030517578;
  v31 = (double)(int)(((unsigned __int8)this[8] << 24) + ((v12 >> 8) & 0xFFFF00)) * 0.000030517578;
  v15 = v31;
  *v5 = v13;
  *(float *)(a2 + 16) = v15;
  *(float *)(a2 + 12) = v14;
  v17 = TernarySelectByBitfield((int)this);
  BitfieldInsert(v5, v17);
  v18 = sub_4B2C50((int)this);
  FloatToBitfieldPack(v5, v18);
  result = a3;
  *(_DWORD *)(a2 + 4) = a3;
  return result;
}
