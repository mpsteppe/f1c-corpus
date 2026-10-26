int __thiscall sub_650421(_DWORD *this, int a2, int a3, int a4)
{
  int v6; // ebx
  char *v7; // edi
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  double v12; // st6
  double v13; // st6
  double v14; // st7
  int v15; // ebx
  char v16; // dl
  int v17; // ebx
  int v18; // ebx
  float v20; // [esp+Ch] [ebp-50h]
  float v21; // [esp+10h] [ebp-4Ch]
  float v22; // [esp+14h] [ebp-48h]
  float v23; // [esp+1Ch] [ebp-40h]
  float v24; // [esp+20h] [ebp-3Ch]
  float v25; // [esp+24h] [ebp-38h]
  int v26; // [esp+2Ch] [ebp-30h]
  int v27; // [esp+30h] [ebp-2Ch]
  int v28; // [esp+34h] [ebp-28h]
  int v29; // [esp+3Ch] [ebp-20h]
  int v30; // [esp+40h] [ebp-1Ch]
  float v31; // [esp+50h] [ebp-Ch]
  float v32; // [esp+50h] [ebp-Ch]
  float v33; // [esp+50h] [ebp-Ch]
  int v34; // [esp+54h] [ebp-8h]
  float v35; // [esp+58h] [ebp-4h]
  int v36; // [esp+64h] [ebp+8h]
  int v37; // [esp+64h] [ebp+8h]
  unsigned int v38; // [esp+64h] [ebp+8h]
  int v39; // [esp+68h] [ebp+Ch]
  float *v40; // [esp+6Ch] [ebp+10h]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v6 = this[26];
  v20 = 0.0;
  v36 = a2 & 1;
  v21 = 0.0;
  v22 = 0.0;
  v7 = (char *)(this[8] + a3 * this[25] + a2 * this[24] + 3 * v36 * (v6 - 1));
  v34 = this[13] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  if ( v36 )
  {
    v8 = v6 - 1;
    v37 = -1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
    v37 = 1;
  }
  this[31] = a3;
  if ( this[23] )
  {
    sub_6503AF((int)this, a4);
    v9 = v37;
  }
  v38 = 0;
  if ( this[26] )
  {
    v30 = 3 * v9;
    v29 = 16 * v9;
    v10 = 16 * v8;
    v11 = 16 * (v9 + v8);
    v39 = 16 * (v8 - v9);
    v40 = (float *)(16 * v8 + a4 + 8);
    do
    {
      v35 = *(float *)(v34 + 4 * (v38 & 3));
      v23 = (v20 + *(v40 - 2)) * 255.0;
      v24 = (v21 + *(v40 - 1)) * 255.0;
      v25 = (v22 + *v40) * 255.0;
      v31 = v23 + v35;
      v26 = (int)v31;
      v32 = v24 + v35;
      v27 = (int)v32;
      v33 = v25 + v35;
      v28 = (int)v33;
      if ( this[23] )
      {
        v12 = (v23 - (double)v26) * 0.0039215689;
        *(float *)(this[23] + v39 + 16) = 0.1875 * v12 + *(float *)(this[23] + v39 + 16);
        *(float *)(this[23] + v10 + 16) = 0.3125 * v12 + *(float *)(this[23] + v10 + 16);
        *(float *)(this[23] + v11 + 16) = 0.0625 * v12 + *(float *)(this[23] + v11 + 16);
        v20 = v12 * 0.4375;
        v13 = (v24 - (double)v27) * 0.0039215689;
        *(float *)(this[23] + v39 + 20) = 0.1875 * v13 + *(float *)(this[23] + v39 + 20);
        *(float *)(this[23] + v10 + 20) = 0.3125 * v13 + *(float *)(this[23] + v10 + 20);
        *(float *)(this[23] + v11 + 20) = 0.0625 * v13 + *(float *)(this[23] + v11 + 20);
        v21 = v13 * 0.4375;
        v14 = 0.0039215689 * (v25 - (double)v28);
        *(float *)(this[23] + v39 + 24) = 0.1875 * v14 + *(float *)(this[23] + v39 + 24);
        *(float *)(this[23] + v10 + 24) = 0.3125 * v14 + *(float *)(this[23] + v10 + 24);
        *(float *)(this[23] + v11 + 24) = 0.0625 * v14 + *(float *)(this[23] + v11 + 24);
        v22 = v14 * 0.4375;
      }
      v15 = v26;
      v16 = -1;
      if ( v26 >= 255 )
        v15 = 255;
      if ( v15 <= 0 )
      {
        LOBYTE(v26) = 0;
      }
      else if ( v26 >= 255 )
      {
        LOBYTE(v26) = -1;
      }
      v17 = v27;
      if ( v27 >= 255 )
        v17 = 255;
      if ( v17 <= 0 )
      {
        LOBYTE(v27) = 0;
      }
      else if ( v27 >= 255 )
      {
        LOBYTE(v27) = -1;
      }
      v18 = (int)v33;
      if ( v28 >= 255 )
        v18 = 255;
      if ( v18 <= 0 )
      {
        v16 = 0;
      }
      else if ( v28 < 255 )
      {
        v16 = (int)v33;
      }
      *v7 = v16;
      v7[1] = v27;
      v7[2] = v26;
      v40 = (float *)((char *)v40 + v29);
      v39 += v29;
      v7 += v30;
      v10 += v29;
      v11 += v29;
      ++v38;
    }
    while ( v38 < this[26] );
  }
  return this[31];
}
