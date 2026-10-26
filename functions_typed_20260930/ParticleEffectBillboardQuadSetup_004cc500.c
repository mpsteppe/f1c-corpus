int __thiscall sub_4CC500(float *this, float *a2, float *a3)
{
  long double v3; // st7
  long double v4; // st7
  float v6; // [esp+10h] [ebp-24h]
  float v7; // [esp+10h] [ebp-24h]
  float v8; // [esp+10h] [ebp-24h]
  float v9; // [esp+14h] [ebp-20h]
  float v10; // [esp+14h] [ebp-20h]
  float v11; // [esp+14h] [ebp-20h]
  float v12; // [esp+18h] [ebp-1Ch]
  float v13; // [esp+18h] [ebp-1Ch]
  float v14; // [esp+18h] [ebp-1Ch]
  float v15; // [esp+1Ch] [ebp-18h]
  float v16; // [esp+20h] [ebp-14h]
  float v17; // [esp+24h] [ebp-10h]
  float v18; // [esp+28h] [ebp-Ch]
  float v19; // [esp+28h] [ebp-Ch]
  float v20; // [esp+2Ch] [ebp-8h]
  float v21; // [esp+2Ch] [ebp-8h]
  float v22; // [esp+30h] [ebp-4h]
  float v23; // [esp+30h] [ebp-4h]

  v6 = a3[1] * a2[20] - a3[2] * a2[19];
  v9 = a3[2] * a2[18] - a2[20] * *a3;
  v12 = a2[19] * *a3 - a3[1] * a2[18];
  v3 = v12 * v12 + v9 * v9 + v6 * v6;
  if ( v3 > 0.0 )
  {
    v4 = this[4] * 0.5 / sqrt(v3);
    v15 = v6 * v4;
    v16 = v9 * v4;
    v17 = v12 * v4;
  }
  else
  {
    v15 = 0.0;
    v17 = 0.0;
    v16 = this[4] * 0.5;
  }
  v18 = v15 + a2[11];
  v20 = v16 + a2[12];
  v22 = v17 + a2[13];
  PixelWriteToTextureBuffer(*(_DWORD *)a2, 1, LODWORD(v18), LODWORD(v20), LODWORD(v22), *((_DWORD *)a2 + 24));
  v7 = v18 - *a3;
  v10 = v20 - a3[1];
  v13 = v22 - a3[2];
  PixelWriteToTextureBuffer(*(_DWORD *)a2, 2, LODWORD(v7), LODWORD(v10), LODWORD(v13), *((_DWORD *)a2 + 24));
  v19 = a2[11] - v15;
  v21 = a2[12] - v16;
  v23 = a2[13] - v17;
  PixelWriteToTextureBuffer(*(_DWORD *)a2, 0, LODWORD(v19), LODWORD(v21), LODWORD(v23), *((_DWORD *)a2 + 24));
  v8 = v19 - *a3;
  v11 = v21 - a3[1];
  v14 = v23 - a3[2];
  return PixelWriteToTextureBuffer(*(_DWORD *)a2, 3, LODWORD(v8), LODWORD(v11), LODWORD(v14), *((_DWORD *)a2 + 24));
}

