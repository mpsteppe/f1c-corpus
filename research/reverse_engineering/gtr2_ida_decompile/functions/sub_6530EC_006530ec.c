int __thiscall sub_6530EC(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edi
  int v7; // edx
  int *v8; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  double v13; // st6
  double v14; // st7
  int v15; // edi
  int v16; // edi
  float v18; // [esp+Ch] [ebp-50h]
  float v19; // [esp+10h] [ebp-4Ch]
  float v20; // [esp+1Ch] [ebp-40h]
  float v21; // [esp+20h] [ebp-3Ch]
  int v22; // [esp+2Ch] [ebp-30h]
  int v23; // [esp+3Ch] [ebp-20h]
  int v24; // [esp+40h] [ebp-1Ch]
  float v25; // [esp+48h] [ebp-14h]
  int v26; // [esp+50h] [ebp-Ch]
  float v27; // [esp+54h] [ebp-8h]
  int *v28; // [esp+58h] [ebp-4h]
  int v29; // [esp+64h] [ebp+8h]
  unsigned int v30; // [esp+64h] [ebp+8h]
  int v31; // [esp+68h] [ebp+Ch]
  int v32; // [esp+68h] [ebp+Ch]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v18 = 0.0;
  v7 = a2 * this[24];
  v19 = 0.0;
  v29 = a2 & 1;
  v8 = (int *)(this[8] + a3 * this[25] + v7 + 4 * v29 * (v6 - 1));
  v28 = v8;
  v26 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v29 )
  {
    v9 = v6 - 1;
    v31 = -1;
  }
  else
  {
    v9 = 0;
    v31 = 1;
  }
  this[31] = v29;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v30 = 0;
  if ( this[26] )
  {
    v24 = 4 * v31;
    v10 = 16 * v9;
    v11 = 16 * (v9 + v31);
    v23 = 16 * v31;
    v32 = 16 * (v9 - v31);
    do
    {
      v20 = (v18 + *(float *)(v10 + a4)) * 65535.0;
      v21 = (v19 + *(float *)(v10 + a4 + 4)) * 65535.0;
      v27 = v20 + *(float *)(v26 + 4 * (v30 & 3));
      v22 = (int)v27;
      v25 = v21 + *(float *)(v26 + 4 * (v30 & 3));
      v12 = (int)v25;
      if ( this[23] )
      {
        v13 = (v20 - (double)v22) * 0.000015259022;
        *(float *)(v32 + this[23] + 16) = 0.1875 * v13 + *(float *)(v32 + this[23] + 16);
        *(float *)(v10 + this[23] + 16) = 0.3125 * v13 + *(float *)(v10 + this[23] + 16);
        *(float *)(v11 + this[23] + 16) = 0.0625 * v13 + *(float *)(v11 + this[23] + 16);
        v8 = v28;
        v18 = v13 * 0.4375;
        v14 = 0.000015259022 * (v21 - (double)(int)v25);
        *(float *)(v32 + this[23] + 20) = 0.1875 * v14 + *(float *)(v32 + this[23] + 20);
        *(float *)(v10 + this[23] + 20) = 0.3125 * v14 + *(float *)(v10 + this[23] + 20);
        *(float *)(v11 + this[23] + 20) = 0.0625 * v14 + *(float *)(v11 + this[23] + 20);
        v19 = v14 * 0.4375;
      }
      v15 = (int)v27;
      if ( v22 >= 0xFFFF )
        v15 = 0xFFFF;
      if ( v15 <= 0 )
      {
        v22 = 0;
      }
      else if ( v22 >= 0xFFFF )
      {
        v22 = 0xFFFF;
      }
      v16 = (int)v25;
      if ( v12 >= 0xFFFF )
        v16 = 0xFFFF;
      if ( v16 <= 0 )
      {
        v12 = 0;
      }
      else if ( v12 >= 0xFFFF )
      {
        v12 = 0xFFFF;
      }
      *v8 = v22 | (v12 << 16);
      v8 = (int *)((char *)v8 + v24);
      v32 += v23;
      v10 += v23;
      v11 += v23;
      ++v30;
      v28 = v8;
    }
    while ( v30 < this[26] );
  }
  return this[31];
}
