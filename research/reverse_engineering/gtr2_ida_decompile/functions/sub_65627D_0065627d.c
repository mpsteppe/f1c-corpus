int __thiscall sub_65627D(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // ebx
  int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  double v13; // st6
  double v14; // st7
  int v15; // eax
  int v16; // eax
  float v18; // [esp+1Ch] [ebp-44h]
  float v19; // [esp+20h] [ebp-40h]
  float v20; // [esp+2Ch] [ebp-34h]
  float v21; // [esp+30h] [ebp-30h]
  int v22; // [esp+3Ch] [ebp-24h]
  int v23; // [esp+40h] [ebp-20h]
  float v24; // [esp+48h] [ebp-18h]
  float v25; // [esp+50h] [ebp-10h]
  int v26; // [esp+54h] [ebp-Ch]
  _WORD *v27; // [esp+58h] [ebp-8h]
  unsigned int v28; // [esp+5Ch] [ebp-4h]
  int v29; // [esp+68h] [ebp+8h]
  int v30; // [esp+68h] [ebp+8h]
  int v31; // [esp+68h] [ebp+8h]
  int v32; // [esp+6Ch] [ebp+Ch]

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
  v27 = (_WORD *)(this[8] + a3 * this[25] + v7 + 2 * v29 * (v6 - 1));
  v26 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v29 )
  {
    v8 = v6 - 1;
    v30 = -1;
  }
  else
  {
    v8 = 0;
    v30 = 1;
  }
  this[31] = a3;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v28 = 0;
  if ( this[26] )
  {
    v23 = 2 * v30;
    v22 = 16 * v30;
    v9 = 16 * v8;
    v32 = 16 * (v30 + v8);
    v31 = 16 * (v8 - v30);
    do
    {
      sub_5A9859();
      v10 = v28 & 3;
      v20 = (v18 + *(float *)(v9 + a4)) * 127.0;
      v21 = (v19 + *(float *)(v9 + a4 + 4)) * 127.0;
      v25 = v20 + *(float *)(v26 + 4 * v10);
      v11 = (int)v25;
      v24 = v21 + *(float *)(v26 + 4 * v10);
      v12 = (int)v24;
      if ( this[23] )
      {
        v13 = (v20 - (double)(int)v25) * 0.0078740157;
        *(float *)(this[23] + v31 + 16) = 0.1875 * v13 + *(float *)(this[23] + v31 + 16);
        *(float *)(v9 + this[23] + 16) = 0.3125 * v13 + *(float *)(v9 + this[23] + 16);
        *(float *)(this[23] + v32 + 16) = 0.0625 * v13 + *(float *)(this[23] + v32 + 16);
        v18 = v13 * 0.4375;
        v14 = 0.0078740157 * (v21 - (double)(int)v24);
        *(float *)(this[23] + v31 + 20) = 0.1875 * v14 + *(float *)(this[23] + v31 + 20);
        *(float *)(v9 + this[23] + 20) = 0.3125 * v14 + *(float *)(v9 + this[23] + 20);
        *(float *)(this[23] + v32 + 20) = 0.0625 * v14 + *(float *)(this[23] + v32 + 20);
        v19 = v14 * 0.4375;
      }
      v15 = (int)v25;
      if ( v11 >= 127 )
        v15 = 127;
      if ( v15 <= -127 )
      {
        LOBYTE(v11) = -127;
      }
      else if ( v11 >= 127 )
      {
        LOBYTE(v11) = 127;
      }
      v16 = (int)v24;
      if ( v12 >= 127 )
        v16 = 127;
      if ( v16 <= -127 )
      {
        LOBYTE(v12) = -127;
      }
      else if ( v12 >= 127 )
      {
        LOBYTE(v12) = 127;
      }
      BYTE1(v11) = v12;
      *v27 = v11;
      v27 = (_WORD *)((char *)v27 + v23);
      v31 += v22;
      v32 += v22;
      v9 += v22;
      ++v28;
    }
    while ( v28 < this[26] );
  }
  return this[31];
}
