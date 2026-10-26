int __thiscall sub_651E1A(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // ebx
  int v7; // ecx
  _BYTE *v8; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  double v13; // st7
  int v14; // ebx
  float v16; // [esp+28h] [ebp-28h]
  float v17; // [esp+38h] [ebp-18h]
  int v18; // [esp+3Ch] [ebp-14h]
  float v19; // [esp+44h] [ebp-Ch]
  int v20; // [esp+48h] [ebp-8h]
  int v21; // [esp+4Ch] [ebp-4h]
  int v22; // [esp+58h] [ebp+8h]
  int v23; // [esp+58h] [ebp+8h]
  unsigned int v24; // [esp+5Ch] [ebp+Ch]
  float *v25; // [esp+60h] [ebp+10h]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v16 = 0.0;
  v7 = a2 * this[24];
  v22 = a2 & 1;
  v8 = (_BYTE *)(this[8] + a3 * this[25] + v7 + v22 * (v6 - 1));
  v20 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v22 )
  {
    v9 = v6 - 1;
    v23 = -1;
  }
  else
  {
    v9 = 0;
    v23 = 1;
  }
  this[31] = a3;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v24 = 0;
  if ( this[26] )
  {
    v18 = 16 * v23;
    v10 = 16 * v9;
    v11 = 16 * (v23 + v9);
    v21 = 16 * (v9 - v23);
    v25 = (float *)(16 * v9 + a4 + 12);
    do
    {
      v17 = (v16 + *v25) * 255.0;
      v19 = v17 + *(float *)(v20 + 4 * (v24 & 3));
      v12 = (int)v19;
      if ( this[23] )
      {
        v13 = (v17 - (double)(int)v19) * 0.0039215689;
        *(float *)(v21 + this[23] + 28) = 0.1875 * v13 + *(float *)(v21 + this[23] + 28);
        *(float *)(v10 + this[23] + 28) = 0.3125 * v13 + *(float *)(v10 + this[23] + 28);
        *(float *)(v11 + this[23] + 28) = 0.0625 * v13 + *(float *)(v11 + this[23] + 28);
        v12 = (int)v19;
        v16 = v13 * 0.4375;
      }
      v14 = v12;
      if ( v12 >= 255 )
        v14 = 255;
      if ( v14 <= 0 )
      {
        LOBYTE(v12) = 0;
      }
      else if ( v12 >= 255 )
      {
        LOBYTE(v12) = -1;
      }
      *v8 = v12;
      v25 = (float *)((char *)v25 + v18);
      v21 += v18;
      v8 += v23;
      v10 += v18;
      v11 += v18;
      ++v24;
    }
    while ( v24 < this[26] );
  }
  return this[31];
}
