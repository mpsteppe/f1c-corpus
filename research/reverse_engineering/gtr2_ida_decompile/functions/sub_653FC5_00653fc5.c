int __thiscall sub_653FC5(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // ebx
  int v7; // edx
  int v8; // ebx
  int v9; // edi
  unsigned int v10; // ecx
  float *v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // edi
  int v15; // ebx
  int v16; // edx
  double v17; // st6
  double v18; // st7
  int v19; // edx
  __int16 v20; // cx
  float v22; // [esp+Ch] [ebp-4Ch]
  float v23; // [esp+18h] [ebp-40h]
  float v24; // [esp+1Ch] [ebp-3Ch]
  float v25; // [esp+28h] [ebp-30h]
  int v26; // [esp+2Ch] [ebp-2Ch]
  int v27; // [esp+38h] [ebp-20h]
  int v28; // [esp+3Ch] [ebp-1Ch]
  int v29; // [esp+4Ch] [ebp-Ch]
  int v30; // [esp+50h] [ebp-8h]
  _WORD *v31; // [esp+54h] [ebp-4h]
  int v32; // [esp+60h] [ebp+8h]
  unsigned int v33; // [esp+60h] [ebp+8h]
  int v34; // [esp+64h] [ebp+Ch]
  float v35; // [esp+64h] [ebp+Ch]
  float v36; // [esp+64h] [ebp+Ch]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v22 = 0.0;
  v7 = a2 * this[24];
  v23 = 0.0;
  v32 = a2 & 1;
  v31 = (_WORD *)(this[8] + a3 * this[25] + v7 + 2 * v32 * (v6 - 1));
  v29 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v32 )
  {
    v8 = v6 - 1;
    v34 = -1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
    v34 = 1;
  }
  this[31] = v32;
  v10 = 0;
  if ( this[26] )
  {
    v11 = (float *)a4;
    do
    {
      ++v10;
      *v11 = v11[2] * 0.072099999 + v11[1] * 0.71539998 + *v11 * 0.21250001;
      v11 += 4;
    }
    while ( v10 < this[26] );
  }
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v33 = 0;
  if ( this[26] )
  {
    v12 = v9;
    v28 = 2 * v9;
    v13 = 16 * v8;
    v14 = 16 * (v8 + v9);
    v30 = 16 * v12;
    v15 = 16 * (v8 - v34);
    do
    {
      v24 = (v22 + *(float *)(v13 + a4)) * 255.0;
      v25 = (v23 + *(float *)(v13 + a4 + 12)) * 255.0;
      v35 = v24 + *(float *)(v29 + 4 * (v33 & 3));
      v16 = (int)v35;
      v26 = v16;
      v36 = v25 + *(float *)(v29 + 4 * (v33 & 3));
      v27 = (int)v36;
      if ( this[23] )
      {
        v17 = (v24 - (double)v16) * 0.0039215689;
        *(float *)(v15 + this[23] + 16) = 0.1875 * v17 + *(float *)(v15 + this[23] + 16);
        *(float *)(v13 + this[23] + 16) = 0.3125 * v17 + *(float *)(v13 + this[23] + 16);
        *(float *)(v14 + this[23] + 16) = 0.0625 * v17 + *(float *)(v14 + this[23] + 16);
        v22 = v17 * 0.4375;
        v18 = 0.0039215689 * (v25 - (double)v27);
        *(float *)(v15 + this[23] + 28) = 0.1875 * v18 + *(float *)(v15 + this[23] + 28);
        *(float *)(v13 + this[23] + 28) = 0.3125 * v18 + *(float *)(v13 + this[23] + 28);
        *(float *)(v14 + this[23] + 28) = 0.0625 * v18 + *(float *)(v14 + this[23] + 28);
        v23 = v18 * 0.4375;
      }
      if ( v16 >= 255 )
        v16 = 255;
      if ( v16 <= 0 )
      {
        LOWORD(v26) = 0;
      }
      else if ( v26 >= 255 )
      {
        LOWORD(v26) = 255;
      }
      v19 = (int)v36;
      if ( v27 >= 255 )
        v19 = 255;
      if ( v19 <= 0 )
      {
        LOBYTE(v27) = 0;
      }
      else if ( v27 >= 255 )
      {
        LOBYTE(v27) = -1;
      }
      v13 += v30;
      v15 += v30;
      v14 += v30;
      LOBYTE(v20) = 0;
      HIBYTE(v20) = v27;
      *v31 = v26 | v20;
      v31 = (_WORD *)((char *)v31 + v28);
      ++v33;
    }
    while ( v33 < this[26] );
  }
  return this[31];
}
