char __thiscall sub_458E00(int this, float *a2, float *a3, float *a4, float a5, int a6)
{
  double v7; // st7
  float *v8; // ebx
  long double v9; // st7
  long double v10; // st7
  int v11; // edx
  float *v12; // edi
  long double v13; // st4
  long double v14; // st7
  double v15; // st7
  float v16; // edx
  float v17; // eax
  double v18; // st7
  double v19; // st6
  float *v20; // esi
  double v21; // st7
  double v22; // st6
  double v23; // st7
  double v24; // st6
  int v26; // [esp+Ch] [ebp-3Ch] BYREF
  float v27; // [esp+10h] [ebp-38h]
  float v28; // [esp+14h] [ebp-34h]
  float v29; // [esp+18h] [ebp-30h] BYREF
  float v30; // [esp+1Ch] [ebp-2Ch]
  float v31; // [esp+20h] [ebp-28h]
  float v32[9]; // [esp+24h] [ebp-24h] BYREF

  if ( *(_BYTE *)(this + 116) )
  {
    v27 = 1000.0;
    *(_BYTE *)(this + 116) = 0;
  }
  else
  {
    v27 = a5;
  }
  v28 = *(float *)(this + 136) * 12.56637061435917;
  v7 = *(float *)(this + 32) + *a3;
  v8 = (float *)(this + 160);
  v30 = *(float *)(this + 36) + a3[1];
  *(float *)&v26 = v7 - *(float *)(this + 160);
  sub_458D90((float *)&v26, -3.141592653589793, 3.141592653589793, 6.283185307179586);
  v9 = *(float *)&v26 * v28 * v27;
  if ( fabs(*(float *)&v26) < fabs(v9) )
    v9 = *(float *)&v26;
  *v8 = v9 + *v8;
  sub_458D90((float *)(this + 160), -3.141592653589793, 3.141592653589793, 6.283185307179586);
  *(float *)&v26 = v30 - *(float *)(this + 164);
  sub_458D90((float *)&v26, -3.141592653589793, 3.141592653589793, 6.283185307179586);
  v10 = *(float *)&v26 * v28 * v27;
  if ( fabs(*(float *)&v26) < fabs(v10) )
    v10 = *(float *)&v26;
  *(float *)(this + 164) = v10 + *(float *)(this + 164);
  sub_458D90((float *)(this + 164), -3.141592653589793, 3.141592653589793, 6.283185307179586);
  *(_DWORD *)(this + 168) = v11;
  v12 = (float *)(this + 148);
  sub_579560(v11, v11);
  v13 = *v12 * *v12 + *(float *)(this + 152) * *(float *)(this + 152) + *(float *)(this + 156) * *(float *)(this + 156);
  if ( v13 > 0.0 )
  {
    v14 = 1.0 / sqrt(v13);
    *v12 = v14 * *v12;
    *(float *)(this + 152) = v14 * *(float *)(this + 152);
    *(float *)(this + 156) = v14 * *(float *)(this + 156);
  }
  v15 = -*(float *)(this + 144);
  *v12 = v15 * *v12;
  *(float *)(this + 152) = v15 * *(float *)(this + 152);
  *(float *)(this + 156) = v15 * *(float *)(this + 156);
  v16 = a3[1];
  v17 = a3[2];
  v29 = *a3;
  v30 = v16;
  v31 = v17;
  sub_579100(&v29, v32);
  v18 = v32[1] * *(float *)(this + 24);
  v19 = v32[2] * *(float *)(this + 28);
  v20 = (float *)(this + 44);
  v21 = v18 + v19 + v32[0] * *(v20 - 6);
  v22 = v32[3] * *(v20 - 6) + v32[4] * *(v20 - 5) + v32[5] * *(v20 - 4);
  v31 = v32[6] * *(v20 - 6) + v32[7] * *(v20 - 5) + v32[8] * *(v20 - 4);
  v29 = v21 + *a2;
  v23 = v22 + a2[1];
  v24 = v31 + a2[2];
  *v12 = v29 + *v12;
  v12[1] = v23 + v12[1];
  v12[2] = v24 + v12[2];
  *v20 = *a4;
  v20[1] = a4[1];
  v20[2] = a4[2];
  return 1;
}
