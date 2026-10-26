char __thiscall sub_500210(int this, int a2, int a3)
{
  unsigned int v4; // eax
  int v5; // edx
  int v6; // ecx
  double v8; // st7
  int v9; // edx
  unsigned int v10; // eax
  int v11; // ecx
  double v12; // st7
  int v13; // edx
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  __int16 v17; // ax
  double v18; // st7
  __int16 v19; // ax
  double v20; // st7
  __int16 v21; // ax
  int v23; // [esp+4h] [ebp-10h]
  int v24; // [esp+4h] [ebp-10h]
  float v25; // [esp+8h] [ebp-Ch] BYREF
  float v26; // [esp+Ch] [ebp-8h]
  float v27; // [esp+10h] [ebp-4h]
  float v28; // [esp+18h] [ebp+4h]
  float v29; // [esp+18h] [ebp+4h]
  float v30; // [esp+18h] [ebp+4h]
  float v31; // [esp+18h] [ebp+4h]
  float v32; // [esp+1Ch] [ebp+8h]

  v4 = *(_DWORD *)(this + 440);
  v5 = this + 440;
  v6 = (v4 >> 18) & 0x3F;
  if ( !v6 )
    return AudioSampleCrossFadeInterpolation((void *)this, a2, v5, this + 8, a3);
  ProgressBarEventEncode((_DWORD *)a3, v4 >> 29, v6, (v4 >> 8) & 0x3FF, (unsigned __int8)v4, a2, 0);
  v8 = *(float *)(this + 12) - *(float *)(this + 444);
  if ( v8 == 0.0 )
  {
    v28 = 0.0;
    v32 = 1.0;
  }
  else
  {
    v28 = (*(float *)&a2 - *(float *)(this + 444)) / v8;
    v32 = 1.0 - v28;
  }
  v9 = (*(_DWORD *)(this + 22) << 16) + (*(_WORD *)(this + 20) & 0xFF00);
  v10 = *(_DWORD *)(this + 22);
  v11 = (*(_DWORD *)(this + 454) << 16) + (*(_WORD *)(this + 452) & 0xFF00);
  v25 = (double)(int)(*(_DWORD *)(this + 18) << 8) * 0.000030517578 * v28
      + (double)(int)(*(_DWORD *)(this + 450) << 8) * 0.000030517578 * v32;
  v12 = (double)v9;
  v23 = (*(unsigned __int8 *)(this + 26) << 24) + ((v10 >> 8) & 0xFFFF00);
  v13 = (*(unsigned __int8 *)(this + 458) << 24) + ((*(_DWORD *)(this + 454) >> 8) & 0xFFFF00);
  v26 = v12 * 0.000030517578 * v28 + (double)v11 * 0.000030517578 * v32;
  v27 = (double)v23 * 0.000030517578 * v28 + (double)v13 * 0.000030517578 * v32;
  FloatToRGBColorConversion((_DWORD *)(a3 + 10), &v25);
  v14 = *(__int16 *)(this + 29);
  v15 = *(__int16 *)(this + 463);
  v24 = *(__int16 *)(this + 461);
  v16 = *(__int16 *)(this + 31);
  v25 = (double)*(__int16 *)(this + 459) * 0.00048828125 * v32 + (double)*(__int16 *)(this + 27) * 0.00048828125 * v28;
  v26 = (double)v24 * 0.00048828125 * v32 + (double)v14 * 0.00048828125 * v28;
  v27 = (double)v15 * 0.00048828125 * v32 + (double)v16 * 0.00048828125 * v28;
  if ( v25 <= 15.999 )
  {
    if ( v25 >= -15.999 )
    {
      v29 = v25 * 2048.0;
      v17 = (int)v29;
    }
    else
    {
      v17 = -32767;
    }
  }
  else
  {
    v17 = 0x7FFF;
  }
  v18 = v26;
  *(_WORD *)(a3 + 19) = v17;
  if ( v18 <= 15.999 )
  {
    if ( v26 >= -15.999 )
    {
      v30 = v26 * 2048.0;
      v19 = (int)v30;
    }
    else
    {
      v19 = -32767;
    }
  }
  else
  {
    v19 = 0x7FFF;
  }
  v20 = v27;
  *(_WORD *)(a3 + 21) = v19;
  if ( v20 <= 15.999 )
  {
    if ( v27 >= -15.999 )
    {
      v31 = v27 * 2048.0;
      v21 = (int)v31;
    }
    else
    {
      v21 = -32767;
    }
  }
  else
  {
    v21 = 0x7FFF;
  }
  *(_WORD *)(a3 + 23) = v21;
  *(_WORD *)(a3 + 8) = *(_WORD *)(this + 448);
  return 1;
}

