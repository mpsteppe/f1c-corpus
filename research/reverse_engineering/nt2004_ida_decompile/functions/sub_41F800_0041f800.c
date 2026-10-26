void __thiscall sub_41F800(int this, float a2, int a3, float a4, float a5, int a6, float a7)
{
  int v7; // edx
  long double v8; // st7
  int v9; // edi
  float *v10; // eax
  float *v11; // esi
  double v12; // st6
  double v13; // st6
  double v14; // st5
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c3
  double v18; // st5
  double v19; // st6
  unsigned __int8 v21; // c0
  unsigned __int8 v22; // c3
  double v23; // st6
  float v24; // [esp+0h] [ebp-3Ch]
  float v25; // [esp+0h] [ebp-3Ch]
  float v26; // [esp+0h] [ebp-3Ch]
  float v27; // [esp+8h] [ebp-34h]
  float v28; // [esp+8h] [ebp-34h]
  float v29; // [esp+Ch] [ebp-30h]
  float v30; // [esp+14h] [ebp-28h]
  float v31; // [esp+18h] [ebp-24h]
  float v32; // [esp+2Ch] [ebp-10h]
  float v33; // [esp+38h] [ebp-4h]
  float v34; // [esp+40h] [ebp+4h]
  float v35; // [esp+48h] [ebp+Ch]

  v7 = 0;
  v8 = 1.0 / sqrt(a4 * a4 + a2 * a2);
  v34 = a2 * v8;
  v35 = v8 * a4;
  if ( *(float *)(this + 92) >= 36.0 )
  {
    *(_BYTE *)(this + 1) = 0;
    v9 = 1;
  }
  else
  {
    *(_BYTE *)(this + 1) = 1;
    v9 = 3;
  }
  do
  {
    v10 = *(float **)(this + 4);
    v29 = v10[4401];
    v30 = v10[4403];
    v11 = (float *)(this + 12 * v7 + 8);
    if ( v7 == 1 )
    {
      v32 = v10[5971] * 2.5;
      v29 = v10[5969] * 2.5 + v29;
      v12 = v32 + v30;
    }
    else if ( v7 == 2 )
    {
      v33 = v10[5971] * 2.5;
      v29 = v29 - v10[5969] * 2.5;
      v12 = v30 - v33;
    }
    else
    {
      v12 = v30;
    }
    v31 = v29 - a5;
    v13 = v12 - a7;
    v14 = v35 * v13 + v31 * v34;
    v24 = v34 * v14;
    v27 = v35 * v14;
    v18 = sqrt(v27 * v27 + v24 * v24);
    if ( v16 | v17 )
      v18 = -v18;
    *(float *)(this + 12 * v7 + 16) = v18;
    v25 = -v35;
    v19 = v13 * v34 - v31 * v35;
    v26 = v25 * v19;
    v28 = v34 * v19;
    v23 = sqrt(v28 * v28 + v26 * v26);
    if ( !(v21 | v22) )
      v23 = -v23;
    ++v7;
    *v11 = v23;
  }
  while ( v7 < v9 );
}
