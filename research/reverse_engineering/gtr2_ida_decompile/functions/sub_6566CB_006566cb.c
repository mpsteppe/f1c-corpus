int __thiscall sub_6566CB(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edi
  int v7; // edx
  int *v8; // ebx
  int v9; // edi
  unsigned int v10; // ecx
  float *v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  double v15; // st6
  double v16; // st7
  int v17; // edi
  int v18; // edi
  float v20; // [esp+Ch] [ebp-50h]
  float v21; // [esp+18h] [ebp-44h]
  float v22; // [esp+1Ch] [ebp-40h]
  float v23; // [esp+28h] [ebp-34h]
  int v24; // [esp+2Ch] [ebp-30h]
  int v25; // [esp+3Ch] [ebp-20h]
  int v26; // [esp+40h] [ebp-1Ch]
  float v27; // [esp+48h] [ebp-14h]
  int v28; // [esp+50h] [ebp-Ch]
  float v29; // [esp+54h] [ebp-8h]
  int *v30; // [esp+58h] [ebp-4h]
  int v31; // [esp+64h] [ebp+8h]
  unsigned int v32; // [esp+64h] [ebp+8h]
  int v33; // [esp+68h] [ebp+Ch]
  int v34; // [esp+68h] [ebp+Ch]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v20 = 0.0;
  v7 = a2 * this[24];
  v21 = 0.0;
  v31 = a2 & 1;
  v8 = (int *)(this[8] + a3 * this[25] + v7 + 4 * v31 * (v6 - 1));
  v30 = v8;
  v28 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v31 )
  {
    v9 = v6 - 1;
    v33 = -1;
  }
  else
  {
    v9 = 0;
    v33 = 1;
  }
  v10 = 0;
  this[31] = v31;
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
  v32 = 0;
  if ( this[26] )
  {
    v26 = 4 * v33;
    v12 = 16 * v9;
    v13 = 16 * (v9 + v33);
    v25 = 16 * v33;
    v34 = 16 * (v9 - v33);
    do
    {
      v22 = (v20 + *(float *)(v12 + a4)) * 65535.0;
      v23 = (v21 + *(float *)(v12 + a4 + 12)) * 65535.0;
      v29 = v22 + *(float *)(v28 + 4 * (v32 & 3));
      v24 = (int)v29;
      v27 = v23 + *(float *)(v28 + 4 * (v32 & 3));
      v14 = (int)v27;
      if ( this[23] )
      {
        v15 = (v22 - (double)v24) * 0.000015259022;
        *(float *)(v34 + this[23] + 16) = 0.1875 * v15 + *(float *)(v34 + this[23] + 16);
        *(float *)(v12 + this[23] + 16) = 0.3125 * v15 + *(float *)(v12 + this[23] + 16);
        *(float *)(v13 + this[23] + 16) = 0.0625 * v15 + *(float *)(v13 + this[23] + 16);
        v8 = v30;
        v20 = v15 * 0.4375;
        v16 = 0.000015259022 * (v23 - (double)(int)v27);
        *(float *)(v34 + this[23] + 28) = 0.1875 * v16 + *(float *)(v34 + this[23] + 28);
        *(float *)(v12 + this[23] + 28) = 0.3125 * v16 + *(float *)(v12 + this[23] + 28);
        *(float *)(v13 + this[23] + 28) = 0.0625 * v16 + *(float *)(v13 + this[23] + 28);
        v21 = v16 * 0.4375;
      }
      v17 = (int)v29;
      if ( v24 >= 0xFFFF )
        v17 = 0xFFFF;
      if ( v17 <= 0 )
      {
        v24 = 0;
      }
      else if ( v24 >= 0xFFFF )
      {
        v24 = 0xFFFF;
      }
      v18 = (int)v27;
      if ( v14 >= 0xFFFF )
        v18 = 0xFFFF;
      if ( v18 <= 0 )
      {
        v14 = 0;
      }
      else if ( v14 >= 0xFFFF )
      {
        v14 = 0xFFFF;
      }
      *v8 = v24 | (v14 << 16);
      v8 = (int *)((char *)v8 + v26);
      v34 += v25;
      v12 += v25;
      v13 += v25;
      ++v32;
      v30 = v8;
    }
    while ( v32 < this[26] );
  }
  return this[31];
}
