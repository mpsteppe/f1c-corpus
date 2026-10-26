int __cdecl sub_551F81(float *a1, unsigned __int16 *a2)
{
  unsigned __int16 v3; // si
  unsigned int v4; // edi
  double v5; // st7
  double v6; // st5
  double v7; // st5
  double v8; // st5
  unsigned int v9; // ebx
  int v11; // ecx
  int v12; // edx
  float *v13; // edi
  float v15; // [esp+Ch] [ebp-58h] BYREF
  float v16; // [esp+10h] [ebp-54h]
  float v17; // [esp+14h] [ebp-50h]
  float v18; // [esp+18h] [ebp-4Ch]
  float v19; // [esp+1Ch] [ebp-48h] BYREF
  float v20; // [esp+20h] [ebp-44h]
  float v21; // [esp+24h] [ebp-40h]
  float v22; // [esp+28h] [ebp-3Ch]
  float v23; // [esp+2Ch] [ebp-38h]
  float v24; // [esp+30h] [ebp-34h]
  float v25; // [esp+34h] [ebp-30h]
  float v26; // [esp+38h] [ebp-2Ch]
  float v27; // [esp+3Ch] [ebp-28h]
  float v28; // [esp+40h] [ebp-24h]
  float v29; // [esp+44h] [ebp-20h]
  float v30; // [esp+48h] [ebp-1Ch]
  float v31; // [esp+4Ch] [ebp-18h]
  float v32; // [esp+50h] [ebp-14h]
  float v33; // [esp+54h] [ebp-10h]
  float v34; // [esp+58h] [ebp-Ch]
  float v35; // [esp+5Ch] [ebp-8h]
  float v36; // [esp+60h] [ebp-4h]
  float v37; // [esp+70h] [ebp+Ch]

  v3 = *a2;
  sub_550CF6(&v15, *a2);
  v4 = a2[1];
  sub_550CF6(&v19, v4);
  if ( v3 > (unsigned __int16)v4 )
  {
    v5 = v19 - v15;
    v23 = v5 * 0.33333334 + v15;
    v6 = v20 - v16;
    v37 = v6;
    v24 = v6 * 0.33333334 + v16;
    v7 = v21 - v17;
    v36 = v7;
    v25 = v7 * 0.33333334 + v17;
    v8 = v22 - v18;
    v35 = v8;
    v26 = v8 * 0.33333334 + v18;
    v27 = v5 * 0.66666669 + v15;
    v28 = v37 * 0.66666669 + v16;
    v29 = v36 * 0.66666669 + v17;
    v30 = v35 * 0.66666669 + v18;
  }
  else
  {
    v23 = (v19 - v15) * 0.5 + v15;
    v24 = (v20 - v16) * 0.5 + v16;
    v25 = (v21 - v17) * 0.5 + v17;
    v26 = (v22 - v18) * 0.5 + v18;
    v31 = 0.0;
    v32 = 0.0;
    v33 = 0.0;
    v34 = 0.0;
    v27 = 0.0;
    v28 = 0.0;
    v29 = 0.0;
    v30 = 0.0;
  }
  v9 = *((_DWORD *)a2 + 1);
  v11 = 16;
  do
  {
    v12 = 16 * (v9 & 3);
    *a1 = *(float *)((char *)&v15 + v12);
    a1[1] = *(float *)((char *)&v15 + v12 + 4);
    a1[2] = *(float *)((char *)&v17 + v12);
    v13 = a1 + 3;
    a1 += 4;
    v9 >>= 2;
    --v11;
    *v13 = *(float *)((char *)&v18 + v12);
  }
  while ( v11 );
  return 0;
}
