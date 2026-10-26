void __thiscall sub_614F40(float *this, float *a2)
{
  long double v2; // st4
  long double v3; // st7
  long double v4; // st6
  long double v5; // rt0
  long double v6; // st7
  int v7; // eax
  char *v8; // edx
  long double v9; // st7
  double v10; // st5
  int v11; // eax
  double v12; // st4
  char *v13; // edx
  double v14; // st3
  float v15; // [esp+0h] [ebp-54h]
  float v16; // [esp+4h] [ebp-50h]
  float v17; // [esp+8h] [ebp-4Ch]
  float v18; // [esp+Ch] [ebp-48h]
  float v19; // [esp+10h] [ebp-44h]
  float v20; // [esp+14h] [ebp-40h]
  float v21; // [esp+18h] [ebp-3Ch]
  float v22; // [esp+1Ch] [ebp-38h]
  float v23; // [esp+20h] [ebp-34h]
  float v24; // [esp+24h] [ebp-30h]
  float v25; // [esp+28h] [ebp-2Ch]
  float v26; // [esp+30h] [ebp-24h]
  float v27; // [esp+34h] [ebp-20h]
  float v28; // [esp+38h] [ebp-1Ch]
  float v29; // [esp+3Ch] [ebp-18h]
  float v30; // [esp+40h] [ebp-14h]
  float v31; // [esp+44h] [ebp-10h]
  float v32; // [esp+48h] [ebp-Ch]
  float v33; // [esp+58h] [ebp+4h]

  v2 = *a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2];
  if ( v2 > 0.0 )
  {
    v3 = sqrt(v2);
    v24 = -1.0 / v3 * *a2;
    v25 = -1.0 / v3 * a2[1];
    v4 = -1.0 / v3 * a2[2];
    v5 = sin(v3);
    v33 = cos(v3);
    v15 = 1.0 - v33;
    v22 = v24 * v5;
    v21 = v25 * v5;
    v18 = v5 * v4;
    v17 = v25 * v24 * v15;
    v20 = v24 * v4 * v15;
    v6 = v4 * v25 * v15;
    v31 = v22 + v6;
    v7 = 0;
    v8 = (char *)(this + 2);
    v9 = v6 - v22;
    do
    {
      v10 = this[v7];
      v11 = v7 + 1;
      v12 = this[v11];
      v13 = v8 + 4;
      v14 = *((float *)v13 - 1);
      v7 = v11 + 2;
      v8 = v13 + 8;
      v16 = v24 * v24;
      v26 = (1.0 - v16) * v33 + v16;
      v29 = v17 - v18;
      v32 = v20 + v21;
      this[v7 - 3] = v32 * v14 + v12 * v29 + v10 * v26;
      v27 = v17 + v18;
      v19 = v25 * v25;
      v30 = (1.0 - v19) * v33 + v19;
      this[v7 - 2] = v14 * v9 + v12 * v30 + v10 * v27;
      v28 = v20 - v21;
      v23 = v4 * v4;
      this[v7 - 1] = v14 * ((1.0 - v23) * v33 + v23) + v12 * v31 + v10 * v28;
    }
    while ( v7 < 9 );
  }
}
