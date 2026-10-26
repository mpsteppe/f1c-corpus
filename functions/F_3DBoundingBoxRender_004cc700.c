int __stdcall sub_4CC700(float *a1, float *a2, float *a3)
{
  float v5; // [esp+10h] [ebp-18h]
  float v6; // [esp+10h] [ebp-18h]
  float v7; // [esp+14h] [ebp-14h]
  float v8; // [esp+14h] [ebp-14h]
  float v9; // [esp+18h] [ebp-10h]
  float v10; // [esp+18h] [ebp-10h]
  float v11; // [esp+1Ch] [ebp-Ch]
  float v12; // [esp+1Ch] [ebp-Ch]
  float v13; // [esp+20h] [ebp-8h]
  float v14; // [esp+20h] [ebp-8h]
  float v15; // [esp+24h] [ebp-4h]
  float v16; // [esp+24h] [ebp-4h]

  v11 = *a3 + a1[11];
  v13 = a1[12] + a3[1];
  v15 = a1[13] + a3[2];
  PixelWriteToTextureBuffer(*(_DWORD *)a1, 1, LODWORD(v11), LODWORD(v13), LODWORD(v15), *((_DWORD *)a1 + 24));
  v5 = v11 - *a2;
  v7 = v13 - a2[1];
  v9 = v15 - a2[2];
  PixelWriteToTextureBuffer(*(_DWORD *)a1, 2, LODWORD(v5), LODWORD(v7), LODWORD(v9), *((_DWORD *)a1 + 24));
  v12 = a1[11] - *a3;
  v14 = a1[12] - a3[1];
  v16 = a1[13] - a3[2];
  PixelWriteToTextureBuffer(*(_DWORD *)a1, 0, LODWORD(v12), LODWORD(v14), LODWORD(v16), *((_DWORD *)a1 + 24));
  v6 = v12 - *a2;
  v8 = v14 - a2[1];
  v10 = v16 - a2[2];
  return PixelWriteToTextureBuffer(*(_DWORD *)a1, 3, LODWORD(v6), LODWORD(v8), LODWORD(v10), *((_DWORD *)a1 + 24));
}
