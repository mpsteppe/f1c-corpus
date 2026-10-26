int __thiscall sub_651FDB(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edi
  int v7; // edx
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // ebx
  double v14; // st6
  double v15; // st7
  double v16; // st7
  double v17; // st7
  int v18; // edi
  int v19; // ebx
  int v20; // edi
  int v21; // ebx
  int v22; // ebx
  float v24; // [esp+Ch] [ebp-54h]
  float v25; // [esp+10h] [ebp-50h]
  float v26; // [esp+14h] [ebp-4Ch]
  float v27; // [esp+18h] [ebp-48h]
  float v28; // [esp+1Ch] [ebp-44h]
  float v29; // [esp+20h] [ebp-40h]
  float v30; // [esp+24h] [ebp-3Ch]
  float v31; // [esp+28h] [ebp-38h]
  __int16 v32; // [esp+2Ch] [ebp-34h]
  int v33; // [esp+30h] [ebp-30h]
  int v34; // [esp+34h] [ebp-2Ch]
  int v35; // [esp+38h] [ebp-28h]
  int v36; // [esp+3Ch] [ebp-24h]
  int v37; // [esp+40h] [ebp-20h]
  float v38; // [esp+54h] [ebp-Ch]
  float v39; // [esp+54h] [ebp-Ch]
  float v40; // [esp+54h] [ebp-Ch]
  int v41; // [esp+58h] [ebp-8h]
  _WORD *v42; // [esp+5Ch] [ebp-4h]
  int v43; // [esp+68h] [ebp+8h]
  unsigned int v44; // [esp+68h] [ebp+8h]
  float *v45; // [esp+6Ch] [ebp+Ch]
  float v46; // [esp+70h] [ebp+10h]
  float v47; // [esp+70h] [ebp+10h]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v24 = 0.0;
  v7 = a2 * this[24];
  v25 = 0.0;
  v26 = 0.0;
  v27 = 0.0;
  v43 = a2 & 1;
  v42 = (_WORD *)(this[8] + a3 * this[25] + v7 + 2 * v43 * (v6 - 1));
  v41 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v43 )
  {
    v8 = v6 - 1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
  }
  this[31] = v43;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v44 = 0;
  if ( this[26] )
  {
    v37 = 2 * v9;
    v36 = 16 * v9;
    v10 = 16 * v8;
    v11 = 16 * (v9 + v8);
    v12 = 16 * (v8 - v9);
    v45 = (float *)(16 * v8 + a4 + 8);
    do
    {
      v46 = *(float *)(v41 + 4 * (v44 & 3));
      v28 = (v24 + *(v45 - 2)) * 7.0;
      v29 = (v25 + *(v45 - 1)) * 7.0;
      v30 = (v26 + *v45) * 3.0;
      v31 = (v27 + v45[1]) * 255.0;
      v38 = v28 + v46;
      v13 = (int)v38;
      v32 = v13;
      v39 = v29 + v46;
      v33 = (int)v39;
      v40 = v30 + v46;
      v34 = (int)v40;
      v47 = v31 + v46;
      v35 = (int)v47;
      if ( this[23] )
      {
        v14 = (v28 - (double)v13) * 0.14285715;
        *(float *)(this[23] + v12 + 16) = 0.1875 * v14 + *(float *)(this[23] + v12 + 16);
        *(float *)(this[23] + v10 + 16) = 0.3125 * v14 + *(float *)(this[23] + v10 + 16);
        *(float *)(this[23] + v11 + 16) = 0.0625 * v14 + *(float *)(this[23] + v11 + 16);
        v24 = v14 * 0.4375;
        v15 = 0.14285715 * (v29 - (double)v33);
        *(float *)(this[23] + v12 + 20) = 0.1875 * v15 + *(float *)(this[23] + v12 + 20);
        *(float *)(this[23] + v10 + 20) = 0.3125 * v15 + *(float *)(this[23] + v10 + 20);
        *(float *)(this[23] + v11 + 20) = 0.0625 * v15 + *(float *)(this[23] + v11 + 20);
        v25 = v15 * 0.4375;
        v16 = (v30 - (double)v34) * 0.33333334;
        *(float *)(this[23] + v12 + 24) = 0.1875 * v16 + *(float *)(this[23] + v12 + 24);
        *(float *)(this[23] + v10 + 24) = 0.3125 * v16 + *(float *)(this[23] + v10 + 24);
        *(float *)(this[23] + v11 + 24) = 0.0625 * v16 + *(float *)(this[23] + v11 + 24);
        v26 = v16 * 0.4375;
        v17 = (v31 - (double)v35) * 0.0039215689;
        *(float *)(this[23] + v12 + 28) = 0.1875 * v17 + *(float *)(this[23] + v12 + 28);
        *(float *)(this[23] + v10 + 28) = 0.3125 * v17 + *(float *)(this[23] + v10 + 28);
        *(float *)(this[23] + v11 + 28) = 0.0625 * v17 + *(float *)(this[23] + v11 + 28);
        v27 = v17 * 0.4375;
      }
      if ( v13 >= 7 )
        v18 = 7;
      else
        v18 = v13;
      if ( v18 <= 0 )
      {
        v32 = 0;
      }
      else if ( v13 >= 7 )
      {
        v32 = 7;
      }
      v19 = v33;
      if ( v33 >= 7 )
        v19 = 7;
      if ( v19 <= 0 )
      {
        LOWORD(v33) = 0;
      }
      else if ( v33 >= 7 )
      {
        LOWORD(v33) = 7;
      }
      v20 = (int)v40;
      if ( v34 >= 3 )
        v20 = 3;
      if ( v20 <= 0 )
      {
        LOWORD(v34) = 0;
      }
      else if ( v34 >= 3 )
      {
        LOWORD(v34) = 3;
      }
      v21 = (int)v47;
      if ( v35 >= 255 )
        v21 = 255;
      if ( v21 <= 0 )
      {
        LOWORD(v22) = 0;
      }
      else
      {
        v22 = (int)v47;
        if ( v35 >= 255 )
          LOWORD(v22) = 255;
      }
      *v42 = v34 | (4 * (v33 | (8 * (v32 | (8 * v22)))));
      v42 = (_WORD *)((char *)v42 + v37);
      v45 = (float *)((char *)v45 + v36);
      v10 += v36;
      v12 += v36;
      v11 += v36;
      ++v44;
    }
    while ( v44 < this[26] );
  }
  return this[31];
}
