// f1c  0x00459070  size=702
_DWORD *__thiscall sub_459070(int this, float *a2, float *a3, int a4)
{
  long double v5; // st7
  int v6; // eax
  float v7; // ecx
  float v8; // edx
  bool v9; // zf
  float *v10; // eax
  int v11; // ecx
  float *v12; // eax
  int v13; // ecx
  double v14; // st7
  double v15; // st6
  double v16; // st7
  double v17; // st6
  float *v18; // eax
  float v19; // eax
  float v20; // ecx
  float v21; // edx
  float v22; // eax
  float *v24; // eax
  float v25; // ecx
  float v26; // edx
  float v27; // eax
  double v28; // st5
  double v29; // st7
  double v30; // st6
  float v31; // [esp+4h] [ebp-24h] BYREF
  float v32; // [esp+8h] [ebp-20h]
  float v33; // [esp+Ch] [ebp-1Ch]
  float v34; // [esp+10h] [ebp-18h]
  float v35; // [esp+14h] [ebp-14h]
  float v36; // [esp+18h] [ebp-10h]
  float v37; // [esp+24h] [ebp-4h]
  float v38; // [esp+2Ch] [ebp+4h]
  int v39; // [esp+34h] [ebp+Ch]
  float v40; // [esp+34h] [ebp+Ch]

  v5 = *(float *)(this + 168);
  v6 = this + 12;
  v7 = *(float *)(this + 12);
  v8 = *(float *)(v6 + 4);
  v36 = *(float *)(v6 + 8);
  v9 = (*(_BYTE *)(this + 116) & 2) == 0;
  v34 = v7;
  v35 = v8;
  if ( !v9 )
  {
    if ( !*(_BYTE *)(this + 204) )
    {
      v10 = (float *)sub_4582C0(this + 176, 0.0);
      v39 = *(_DWORD *)(this + 184);
      v34 = *v10 * -1.0;
      v35 = v10[1] * -1.0;
      v36 = v10[2] * -1.0;
      v12 = (float *)sub_4582C0(v11, *(float *)&v39);
      v14 = *v12 * -1.0;
      v15 = v12[1] * -1.0;
      v37 = v12[2] * -1.0;
      v31 = v34 - *a2;
      v32 = v35 - a2[1];
      v33 = v36 - a2[2];
      v34 = v14 - *a2;
      v16 = v15 - a2[1];
      v17 = v37 - a2[2];
      if ( v17 * v17 + v16 * v16 + v34 * v34 < v33 * v33 + v32 * v32 + v31 * v31 )
      {
        v19 = *(float *)(this + 184);
        *(_DWORD *)(this + 172) = -1082130432;
        v18 = (float *)sub_4582C0(v13, v19);
      }
      else
      {
        *(_DWORD *)(this + 172) = 1065353216;
        v18 = (float *)sub_4582C0(v13, 0.0);
      }
      v20 = *v18;
      v21 = v18[1];
      v22 = v18[2];
      v31 = v20;
      v32 = v21;
      v33 = v22;
      sub_456110((_DWORD *)this, &v31);
      v31 = 0.0;
      v32 = 0.0;
      v33 = 0.0;
      return sub_456150((_DWORD *)this, &v31);
    }
    v5 = sqrt(*a3 * *a3 + a3[1] * a3[1] + a3[2] * a3[2]) * *(float *)(this + 168);
  }
  v38 = v5 * *(float *)(this + 172) * *(float *)&a4 + *(float *)(this + 188);
  v24 = (float *)sub_4582C0(this + 176, v38);
  v25 = *v24;
  v26 = v24[1];
  v27 = v24[2];
  v31 = v25;
  v32 = v26;
  v33 = v27;
  sub_456110((_DWORD *)this, &v31);
  if ( *(float *)&a4 <= 0.0 )
  {
    v29 = 0.0;
    v33 = 0.0;
    v30 = 0.0;
  }
  else
  {
    v37 = v33 - v36;
    v28 = 1.0 / *(float *)&a4;
    v40 = v28;
    v34 = v28 * (v31 - v34);
    v31 = v34;
    v35 = v40 * (v32 - v35);
    v32 = v35;
    v36 = v40 * v37;
    v29 = v34;
    v33 = v36;
    v30 = v35;
  }
  v31 = v29 * -1.0;
  v32 = v30 * -1.0;
  v33 = v33 * -1.0;
  return sub_456150((_DWORD *)this, &v31);
}
