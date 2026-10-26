int __thiscall sub_654253(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edx
  int v7; // ecx
  _BYTE *v8; // edi
  unsigned int v9; // ecx
  float *v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // ecx
  double v14; // st6
  double v15; // st7
  int v16; // edx
  int v17; // edx
  float v19; // [esp+Ch] [ebp-50h]
  float v20; // [esp+18h] [ebp-44h]
  float v21; // [esp+1Ch] [ebp-40h]
  float v22; // [esp+28h] [ebp-34h]
  int v23; // [esp+2Ch] [ebp-30h]
  int v24; // [esp+3Ch] [ebp-20h]
  float v25; // [esp+44h] [ebp-18h]
  float v26; // [esp+4Ch] [ebp-10h]
  int v27; // [esp+50h] [ebp-Ch]
  int v28; // [esp+54h] [ebp-8h]
  int v29; // [esp+54h] [ebp-8h]
  unsigned int v30; // [esp+58h] [ebp-4h]
  int v31; // [esp+64h] [ebp+8h]
  int v32; // [esp+64h] [ebp+8h]
  int v33; // [esp+68h] [ebp+Ch]
  int v34; // [esp+68h] [ebp+Ch]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v19 = 0.0;
  v7 = a2 * this[24];
  v20 = 0.0;
  v31 = a2 & 1;
  v8 = (_BYTE *)(this[8] + a3 * this[25] + v7 + v31 * (v6 - 1));
  v27 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v31 )
  {
    v32 = -1;
    v33 = v6 - 1;
  }
  else
  {
    v33 = 0;
    v32 = 1;
  }
  this[31] = v28;
  v9 = 0;
  if ( this[26] )
  {
    v10 = (float *)a4;
    do
    {
      ++v9;
      *v10 = v10[2] * 0.072099999 + *v10 * 0.21250001 + v10[1] * 0.71539998;
      v10 += 4;
    }
    while ( v9 < this[26] );
  }
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v30 = 0;
  if ( this[26] )
  {
    v24 = 16 * v32;
    v11 = 16 * (v33 + v32);
    v12 = 16 * v33;
    v29 = v11;
    v34 = 16 * (v33 - v32);
    do
    {
      v21 = (v19 + *(float *)(v12 + a4)) * 15.0;
      v22 = (v20 + *(float *)(v12 + a4 + 12)) * 15.0;
      v26 = v21 + *(float *)(v27 + 4 * (v30 & 3));
      v23 = (int)v26;
      v25 = v22 + *(float *)(v27 + 4 * (v30 & 3));
      v13 = (int)v25;
      if ( this[23] )
      {
        v14 = (v21 - (double)v23) * 0.06666667;
        *(float *)(this[23] + v34 + 16) = 0.1875 * v14 + *(float *)(this[23] + v34 + 16);
        *(float *)(this[23] + v12 + 16) = 0.3125 * v14 + *(float *)(this[23] + v12 + 16);
        *(float *)(this[23] + v29 + 16) = 0.0625 * v14 + *(float *)(this[23] + v29 + 16);
        v11 = v29;
        v19 = v14 * 0.4375;
        v15 = 0.06666667 * (v22 - (double)(int)v25);
        *(float *)(this[23] + v34 + 28) = 0.1875 * v15 + *(float *)(this[23] + v34 + 28);
        *(float *)(this[23] + v12 + 28) = 0.3125 * v15 + *(float *)(this[23] + v12 + 28);
        *(float *)(this[23] + v29 + 28) = 0.0625 * v15 + *(float *)(this[23] + v29 + 28);
        v20 = v15 * 0.4375;
      }
      if ( v23 >= 15 )
        v16 = 15;
      else
        v16 = (int)v26;
      if ( v16 <= 0 )
      {
        LOBYTE(v23) = 0;
      }
      else if ( v23 >= 15 )
      {
        LOBYTE(v23) = 15;
      }
      if ( v13 >= 15 )
        v17 = 15;
      else
        v17 = (int)v25;
      if ( v17 <= 0 )
      {
        LOBYTE(v13) = 0;
      }
      else if ( v13 >= 15 )
      {
        LOBYTE(v13) = 15;
      }
      *v8 = v23 | (16 * v13);
      v34 += v24;
      v8 += v32;
      v11 += v24;
      v12 += v24;
      ++v30;
      v29 = v11;
    }
    while ( v30 < this[26] );
  }
  return this[31];
}
