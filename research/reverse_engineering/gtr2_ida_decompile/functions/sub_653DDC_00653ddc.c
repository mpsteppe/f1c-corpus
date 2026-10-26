int __thiscall sub_653DDC(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edi
  _BYTE *v7; // edi
  int v8; // ebx
  unsigned int v9; // ecx
  float *v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  double v14; // st7
  int v15; // ebx
  float v17; // [esp+1Ch] [ebp-34h]
  float v18; // [esp+2Ch] [ebp-24h]
  int v19; // [esp+3Ch] [ebp-14h]
  float v20; // [esp+44h] [ebp-Ch]
  int v21; // [esp+48h] [ebp-8h]
  int v22; // [esp+4Ch] [ebp-4h]
  int v23; // [esp+58h] [ebp+8h]
  int v24; // [esp+58h] [ebp+8h]
  unsigned int v25; // [esp+5Ch] [ebp+Ch]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v17 = 0.0;
  v6 = a2 * this[24];
  v23 = a2 & 1;
  v7 = (_BYTE *)(this[8] + v23 * (this[26] - 1) + a3 * this[25] + v6);
  v21 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v23 )
  {
    v8 = this[26] - 1;
    v24 = -1;
  }
  else
  {
    v8 = 0;
    v24 = 1;
  }
  this[31] = a3;
  v9 = 0;
  if ( this[26] )
  {
    v10 = (float *)a4;
    do
    {
      ++v9;
      *v10 = v10[2] * 0.072099999 + v10[1] * 0.71539998 + *v10 * 0.21250001;
      v10 += 4;
    }
    while ( v9 < this[26] );
  }
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v25 = 0;
  if ( this[26] )
  {
    v11 = 16 * v8;
    v12 = 16 * (v8 + v24);
    v19 = 16 * v24;
    v22 = 16 * (v8 - v24);
    do
    {
      v18 = (v17 + *(float *)(v11 + a4)) * 255.0;
      v20 = v18 + *(float *)(v21 + 4 * (v25 & 3));
      v13 = (int)v20;
      if ( this[23] )
      {
        v14 = (v18 - (double)(int)v20) * 0.0039215689;
        *(float *)(v22 + this[23] + 16) = 0.1875 * v14 + *(float *)(v22 + this[23] + 16);
        *(float *)(v11 + this[23] + 16) = 0.3125 * v14 + *(float *)(v11 + this[23] + 16);
        *(float *)(v12 + this[23] + 16) = 0.0625 * v14 + *(float *)(v12 + this[23] + 16);
        v13 = (int)v20;
        v17 = v14 * 0.4375;
      }
      v15 = v13;
      if ( v13 >= 255 )
        v15 = 255;
      if ( v15 <= 0 )
      {
        LOBYTE(v13) = 0;
      }
      else if ( v13 >= 255 )
      {
        LOBYTE(v13) = -1;
      }
      *v7 = v13;
      v22 += v19;
      v7 += v24;
      v11 += v19;
      v12 += v19;
      ++v25;
    }
    while ( v25 < this[26] );
  }
  return this[31];
}
