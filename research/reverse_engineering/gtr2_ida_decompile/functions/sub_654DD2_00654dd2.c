int __thiscall sub_654DD2(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // ebx
  int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // edi
  int v12; // ebx
  int v13; // edx
  double v14; // st6
  double v15; // st7
  double v16; // st7
  int v17; // edx
  int v18; // edx
  unsigned __int16 v19; // dx
  float v21; // [esp+Ch] [ebp-50h]
  float v22; // [esp+10h] [ebp-4Ch]
  float v23; // [esp+18h] [ebp-44h]
  float v24; // [esp+1Ch] [ebp-40h]
  float v25; // [esp+20h] [ebp-3Ch]
  float v26; // [esp+28h] [ebp-34h]
  int v27; // [esp+2Ch] [ebp-30h]
  int v28; // [esp+30h] [ebp-2Ch]
  int v29; // [esp+38h] [ebp-24h]
  int v30; // [esp+3Ch] [ebp-20h]
  int v31; // [esp+40h] [ebp-1Ch]
  int v32; // [esp+50h] [ebp-Ch]
  float v33; // [esp+54h] [ebp-8h]
  float v34; // [esp+54h] [ebp-8h]
  int *v35; // [esp+58h] [ebp-4h]
  int v36; // [esp+64h] [ebp+8h]
  unsigned int v37; // [esp+64h] [ebp+8h]
  int v38; // [esp+68h] [ebp+Ch]
  float v39; // [esp+68h] [ebp+Ch]
  float v40; // [esp+68h] [ebp+Ch]
  float *v41; // [esp+6Ch] [ebp+10h]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v21 = 0.0;
  v7 = a2 * this[24];
  v22 = 0.0;
  v23 = 0.0;
  v36 = a2 & 1;
  v35 = (int *)(this[8] + a3 * this[25] + v7 + 4 * v36 * (v6 - 1));
  v32 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v36 )
  {
    v8 = v6 - 1;
    v38 = -1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
    v38 = 1;
  }
  this[31] = v36;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v37 = 0;
  if ( this[26] )
  {
    v31 = 4 * v9;
    v30 = 16 * v9;
    v10 = 16 * v8;
    v11 = 16 * (v8 + v9);
    v12 = 16 * (v8 - v38);
    v41 = (float *)(v10 + a4 + 12);
    do
    {
      v39 = *(float *)(v32 + 4 * (v37 & 3));
      v24 = (v21 + *(v41 - 3)) * 127.0;
      v25 = (v22 + *(v41 - 2)) * 127.0;
      v26 = (v23 + *v41) * 255.0;
      v33 = v24 + v39;
      v13 = (int)v33;
      v27 = v13;
      v34 = v25 + v39;
      v28 = (int)v34;
      v40 = v26 + v39;
      v29 = (int)v40;
      if ( this[23] )
      {
        v14 = (v24 - (double)v13) * 0.0078740157;
        *(float *)(this[23] + v12 + 16) = 0.1875 * v14 + *(float *)(this[23] + v12 + 16);
        *(float *)(this[23] + v10 + 16) = 0.3125 * v14 + *(float *)(this[23] + v10 + 16);
        *(float *)(this[23] + v11 + 16) = 0.0625 * v14 + *(float *)(this[23] + v11 + 16);
        v21 = v14 * 0.4375;
        v15 = 0.0078740157 * (v25 - (double)v28);
        *(float *)(this[23] + v12 + 20) = 0.1875 * v15 + *(float *)(this[23] + v12 + 20);
        *(float *)(this[23] + v10 + 20) = 0.3125 * v15 + *(float *)(this[23] + v10 + 20);
        *(float *)(this[23] + v11 + 20) = 0.0625 * v15 + *(float *)(this[23] + v11 + 20);
        v22 = v15 * 0.4375;
        v16 = (v26 - (double)v29) * 0.0039215689;
        *(float *)(this[23] + v12 + 28) = 0.1875 * v16 + *(float *)(this[23] + v12 + 28);
        *(float *)(this[23] + v10 + 28) = 0.3125 * v16 + *(float *)(this[23] + v10 + 28);
        *(float *)(this[23] + v11 + 28) = 0.0625 * v16 + *(float *)(this[23] + v11 + 28);
        v23 = v16 * 0.4375;
      }
      if ( v13 >= 127 )
        v13 = 127;
      if ( v13 <= -127 )
      {
        LOBYTE(v27) = -127;
      }
      else if ( v27 >= 127 )
      {
        LOBYTE(v27) = 127;
      }
      v17 = (int)v34;
      if ( v28 >= 127 )
        v17 = 127;
      if ( v17 <= -127 )
      {
        LOBYTE(v28) = -127;
      }
      else if ( v28 >= 127 )
      {
        LOBYTE(v28) = 127;
      }
      v18 = (int)v40;
      if ( v29 >= 255 )
        v18 = 255;
      if ( v18 <= -255 )
      {
        LOBYTE(v29) = 1;
      }
      else if ( v29 >= 255 )
      {
        LOBYTE(v29) = -1;
      }
      HIBYTE(v19) = v29;
      LOBYTE(v19) = v28;
      *v35 = (unsigned __int8)v27 | (v19 << 8);
      v35 = (int *)((char *)v35 + v31);
      v41 = (float *)((char *)v41 + v30);
      v10 += v30;
      v12 += v30;
      v11 += v30;
      ++v37;
    }
    while ( v37 < this[26] );
  }
  return this[31];
}
