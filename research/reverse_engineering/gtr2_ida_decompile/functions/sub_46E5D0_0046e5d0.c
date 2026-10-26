int __thiscall sub_46E5D0(int this, float *a2, int a3, float *a4, int a5, float a6)
{
  int *v7; // ebx
  int v8; // eax
  int v9; // ecx
  float v10; // edx
  int v11; // eax
  float v12; // eax
  float v13; // ecx
  double v14; // st7
  double v15; // st6
  long double v16; // st5
  long double v17; // st4
  double v19; // st5
  unsigned __int8 v20; // c0
  unsigned __int8 v21; // c3
  double v22; // st5
  long double v23; // st7
  long double v24; // st7
  char v25; // al
  float v26; // edx
  int v27; // ecx
  float v28; // edi
  double v29; // st7
  int v31; // [esp+10h] [ebp-30h]
  float v32; // [esp+14h] [ebp-2Ch]
  float v33; // [esp+18h] [ebp-28h]
  int v34; // [esp+1Ch] [ebp-24h] BYREF
  float v35; // [esp+20h] [ebp-20h]
  int v36; // [esp+24h] [ebp-1Ch]
  int v37; // [esp+28h] [ebp-18h] BYREF
  float v38; // [esp+2Ch] [ebp-14h]
  int v39; // [esp+30h] [ebp-10h]
  int v40; // [esp+34h] [ebp-Ch] BYREF
  float v41; // [esp+38h] [ebp-8h]
  float v42; // [esp+3Ch] [ebp-4h]
  float v43; // [esp+44h] [ebp+4h]
  float v44; // [esp+44h] [ebp+4h]
  int v45; // [esp+4Ch] [ebp+Ch]

  v7 = (int *)(this + 24);
  v8 = this + 24;
  v9 = *(_DWORD *)(this + 24);
  v10 = *(float *)(v8 + 4);
  v39 = *(_DWORD *)(v8 + 8);
  v11 = *(_DWORD *)(this + 180);
  v37 = v9;
  v38 = v10;
  if ( v11 )
    sub_46CF80(this, a2, a4, a6);
  v12 = *(float *)(this + 16);
  v13 = *(float *)(this + 20);
  *(float *)&v40 = *(float *)(this + 12) + *a2;
  v31 = v40;
  v41 = v12 + a2[1];
  v32 = v41;
  LOBYTE(v12) = *(_BYTE *)(this + 116);
  v42 = v13 + a2[2];
  v33 = v42;
  if ( (LOBYTE(v12) & 1) != 0 )
  {
    v14 = *(float *)(this + 48);
    v15 = *(float *)(this + 52);
    v16 = 35.0 / sqrt(v42 * v42 + *(float *)&v40 * *(float *)&v40 + v41 * v41);
    if ( v16 >= 0.1 )
    {
      if ( v16 > 1.0 )
        v16 = 1.0;
    }
    else
    {
      v16 = 0.1;
    }
    if ( *(_BYTE *)(this + 164) )
      *(float *)(this + 216) = v16;
    v17 = fabs(v16 - *(float *)(this + 216));
    *(float *)&v45 = v17;
    v43 = a6 * 0.25;
    if ( v17 < 0.02 )
      v43 = v43 * 0.5;
    v19 = v43;
    if ( v20 | v21 )
    {
      v22 = -v19;
      v44 = -*(float *)&v45;
      if ( v22 <= v44 )
        v22 = v44;
    }
    else if ( v19 >= *(float *)&v45 )
    {
      v22 = *(float *)&v45;
    }
    else
    {
      v22 = v43;
    }
    *(float *)(this + 216) = v22 + *(float *)(this + 216);
    *(float *)(this + 56) = v14 * *(float *)(this + 216);
    *(float *)(this + 60) = v15 * *(float *)(this + 216);
  }
  v23 = v33 * v33 + *(float *)&v31 * *(float *)&v31 + v32 * v32;
  if ( v23 > 0.0 )
  {
    v24 = 1.0 / sqrt(v23);
    *(float *)&v31 = *(float *)&v31 * v24;
    v32 = v32 * v24;
    v33 = v24 * v33;
  }
  *(float *)&v34 = asin(v32);
  if ( *(float *)&v31 == 0.0 && v33 == 0.0 )
    v35 = 0.0;
  else
    v35 = 3.1415927 - atan2(-*(float *)&v31, -v33);
  v25 = *(_BYTE *)(this + 164);
  v26 = v35;
  v27 = v34;
  v36 = 0;
  v28 = 0.0;
  if ( v25 )
  {
    *(_BYTE *)(this + 164) = 0;
    v37 = v27;
    v38 = v26;
    v39 = 0;
  }
  if ( *(float *)(this + 168) > 0.0 )
  {
    sub_46C8D0((float *)this, (float *)&v34, (float *)&v37, &v40, a6, *(float *)(this + 168));
    v27 = v40;
    v26 = v41;
    v28 = v42;
  }
  v29 = *(float *)(this + 228);
  *v7 = v27;
  *((float *)v7 + 1) = v26;
  *((float *)v7 + 2) = v28;
  if ( v29 > 0.0 )
    *(float *)(this + 228) = *(float *)(this + 228) - a6;
  return 0;
}
