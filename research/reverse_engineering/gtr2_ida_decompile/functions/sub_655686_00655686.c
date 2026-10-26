int __thiscall sub_655686(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edi
  int v7; // edx
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  int v12; // edi
  int v13; // ecx
  double v14; // st6
  double v15; // st7
  int v16; // ebx
  int v17; // ebx
  float v19; // [esp+1Ch] [ebp-40h]
  float v20; // [esp+20h] [ebp-3Ch]
  float v21; // [esp+2Ch] [ebp-30h]
  float v22; // [esp+30h] [ebp-2Ch]
  int v23; // [esp+3Ch] [ebp-20h]
  int v24; // [esp+40h] [ebp-1Ch]
  float v25; // [esp+48h] [ebp-14h]
  float v26; // [esp+50h] [ebp-Ch]
  int v27; // [esp+54h] [ebp-8h]
  int *v28; // [esp+58h] [ebp-4h]
  int v29; // [esp+64h] [ebp+8h]
  unsigned int v30; // [esp+64h] [ebp+8h]
  int v31; // [esp+68h] [ebp+Ch]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v19 = 0.0;
  v7 = a2 * this[24];
  v20 = 0.0;
  v29 = a2 & 1;
  v28 = (int *)(this[8] + a3 * this[25] + v7 + 4 * v29 * (v6 - 1));
  v27 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v29 )
  {
    v8 = v6 - 1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
  }
  this[31] = v29;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v30 = 0;
  if ( this[26] )
  {
    v24 = 4 * v9;
    v10 = 16 * v8;
    v11 = 16 * (v9 + v8);
    v23 = 16 * v9;
    v31 = 16 * (v8 - v9);
    do
    {
      v21 = (v19 + *(float *)(v10 + a4)) * 32767.0;
      v22 = (v20 + *(float *)(v10 + a4 + 4)) * 32767.0;
      v26 = v21 + *(float *)(v27 + 4 * (v30 & 3));
      v12 = (int)v26;
      v25 = v22 + *(float *)(v27 + 4 * (v30 & 3));
      v13 = (int)v25;
      if ( this[23] )
      {
        v14 = (v21 - (double)(int)v26) * 0.000030518509;
        *(float *)(v31 + this[23] + 16) = 0.1875 * v14 + *(float *)(v31 + this[23] + 16);
        *(float *)(v10 + this[23] + 16) = 0.3125 * v14 + *(float *)(v10 + this[23] + 16);
        *(float *)(v11 + this[23] + 16) = 0.0625 * v14 + *(float *)(v11 + this[23] + 16);
        v19 = v14 * 0.4375;
        v15 = 0.000030518509 * (v22 - (double)(int)v25);
        *(float *)(v31 + this[23] + 20) = 0.1875 * v15 + *(float *)(v31 + this[23] + 20);
        *(float *)(v10 + this[23] + 20) = 0.3125 * v15 + *(float *)(v10 + this[23] + 20);
        *(float *)(v11 + this[23] + 20) = 0.0625 * v15 + *(float *)(v11 + this[23] + 20);
        v12 = (int)v26;
        v20 = v15 * 0.4375;
      }
      v16 = v12;
      if ( v12 >= 0x7FFF )
        v16 = 0x7FFF;
      if ( v16 <= -32767 )
      {
        LOWORD(v12) = -32767;
      }
      else if ( v12 >= 0x7FFF )
      {
        LOWORD(v12) = 0x7FFF;
      }
      v17 = (int)v25;
      if ( v13 >= 0x7FFF )
        v17 = 0x7FFF;
      if ( v17 <= -32767 )
      {
        v13 = -32767;
      }
      else if ( v13 >= 0x7FFF )
      {
        v13 = 0x7FFF;
      }
      *v28 = (unsigned __int16)v12 | (v13 << 16);
      v31 += v23;
      v10 += v23;
      v11 += v23;
      ++v30;
      v28 = (int *)((char *)v28 + v24);
    }
    while ( v30 < this[26] );
  }
  return this[31];
}
