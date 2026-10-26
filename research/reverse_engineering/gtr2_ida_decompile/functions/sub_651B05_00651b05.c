int __thiscall sub_651B05(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edx
  int v7; // ecx
  _BYTE *v8; // ebx
  int v9; // eax
  int v10; // edi
  int v11; // ecx
  double v12; // st6
  double v13; // st7
  double v14; // st7
  int v15; // edx
  int v16; // edx
  int v17; // edx
  float v19; // [esp+Ch] [ebp-54h]
  float v20; // [esp+10h] [ebp-50h]
  float v21; // [esp+14h] [ebp-4Ch]
  float v22; // [esp+1Ch] [ebp-44h]
  float v23; // [esp+20h] [ebp-40h]
  float v24; // [esp+24h] [ebp-3Ch]
  int v25; // [esp+30h] [ebp-30h]
  int v26; // [esp+34h] [ebp-2Ch]
  int v27; // [esp+3Ch] [ebp-24h]
  float v28; // [esp+4Ch] [ebp-14h]
  float v29; // [esp+4Ch] [ebp-14h]
  float v30; // [esp+4Ch] [ebp-14h]
  int v31; // [esp+50h] [ebp-10h]
  _BYTE *v32; // [esp+54h] [ebp-Ch]
  float v33; // [esp+58h] [ebp-8h]
  int v34; // [esp+5Ch] [ebp-4h]
  int v35; // [esp+5Ch] [ebp-4h]
  int v36; // [esp+68h] [ebp+8h]
  int v37; // [esp+68h] [ebp+8h]
  unsigned int v38; // [esp+6Ch] [ebp+Ch]
  float *v39; // [esp+70h] [ebp+10h]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v19 = 0.0;
  v7 = a2 * this[24];
  v20 = 0.0;
  v21 = 0.0;
  v36 = a2 & 1;
  v8 = (_BYTE *)(this[8] + a3 * this[25] + v7 + v36 * (v6 - 1));
  v32 = v8;
  v31 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v36 )
  {
    v37 = -1;
    v34 = v6 - 1;
  }
  else
  {
    v34 = 0;
    v37 = 1;
  }
  this[31] = a3;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v38 = 0;
  if ( this[26] )
  {
    v27 = 16 * v37;
    v9 = 16 * v34;
    v10 = 16 * (v34 + v37);
    v35 = 16 * (v34 - v37);
    v39 = (float *)(v9 + a4 + 8);
    do
    {
      v33 = *(float *)(v31 + 4 * (v38 & 3));
      v22 = (v19 + *(v39 - 2)) * 7.0;
      v23 = (v20 + *(v39 - 1)) * 7.0;
      v24 = (v21 + *v39) * 3.0;
      v28 = v22 + v33;
      v11 = (int)v28;
      v29 = v23 + v33;
      v25 = (int)v29;
      v30 = v24 + v33;
      v26 = (int)v30;
      if ( this[23] )
      {
        v12 = (v22 - (double)v11) * 0.14285715;
        *(float *)(this[23] + v35 + 16) = 0.1875 * v12 + *(float *)(this[23] + v35 + 16);
        *(float *)(this[23] + v9 + 16) = 0.3125 * v12 + *(float *)(this[23] + v9 + 16);
        *(float *)(this[23] + v10 + 16) = 0.0625 * v12 + *(float *)(this[23] + v10 + 16);
        v19 = v12 * 0.4375;
        v13 = 0.14285715 * (v23 - (double)v25);
        *(float *)(this[23] + v35 + 20) = 0.1875 * v13 + *(float *)(this[23] + v35 + 20);
        *(float *)(this[23] + v9 + 20) = 0.3125 * v13 + *(float *)(this[23] + v9 + 20);
        *(float *)(this[23] + v10 + 20) = 0.0625 * v13 + *(float *)(this[23] + v10 + 20);
        v8 = v32;
        v20 = v13 * 0.4375;
        v14 = (v24 - (double)v26) * 0.33333334;
        *(float *)(this[23] + v35 + 24) = 0.1875 * v14 + *(float *)(this[23] + v35 + 24);
        *(float *)(this[23] + v9 + 24) = 0.3125 * v14 + *(float *)(this[23] + v9 + 24);
        *(float *)(this[23] + v10 + 24) = 0.0625 * v14 + *(float *)(this[23] + v10 + 24);
        v21 = v14 * 0.4375;
      }
      if ( v11 >= 7 )
        v15 = 7;
      else
        v15 = v11;
      if ( v15 <= 0 )
      {
        LOBYTE(v11) = 0;
      }
      else if ( v11 >= 7 )
      {
        LOBYTE(v11) = 7;
      }
      if ( v25 >= 7 )
        v16 = 7;
      else
        v16 = v25;
      if ( v16 <= 0 )
      {
        LOBYTE(v25) = 0;
      }
      else if ( v25 >= 7 )
      {
        LOBYTE(v25) = 7;
      }
      if ( v26 >= 3 )
        v17 = 3;
      else
        v17 = (int)v30;
      if ( v17 <= 0 )
      {
        LOBYTE(v26) = 0;
      }
      else if ( v26 >= 3 )
      {
        LOBYTE(v26) = 3;
      }
      *v8 = v26 | (4 * (v25 | (8 * v11)));
      v8 += v37;
      v39 = (float *)((char *)v39 + v27);
      v35 += v27;
      v9 += v27;
      v10 += v27;
      ++v38;
      v32 = v8;
    }
    while ( v38 < this[26] );
  }
  return this[31];
}
