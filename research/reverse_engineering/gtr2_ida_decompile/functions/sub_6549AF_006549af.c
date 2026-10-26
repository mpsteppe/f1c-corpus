int __thiscall sub_6549AF(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // ebx
  int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // edi
  int v12; // ebx
  int v13; // ecx
  int v14; // edx
  double v15; // st6
  double v16; // st7
  double v17; // st7
  int v18; // ebx
  int v19; // ebx
  int v20; // ebx
  char v22; // [esp-4h] [ebp-64h]
  __int16 v23; // [esp-4h] [ebp-64h]
  float v24; // [esp+Ch] [ebp-54h]
  float v25; // [esp+10h] [ebp-50h]
  float v26; // [esp+18h] [ebp-48h]
  float v27; // [esp+1Ch] [ebp-44h]
  float v28; // [esp+20h] [ebp-40h]
  float v29; // [esp+28h] [ebp-38h]
  int v30; // [esp+2Ch] [ebp-34h]
  int v31; // [esp+3Ch] [ebp-24h]
  int v32; // [esp+40h] [ebp-20h]
  float v33; // [esp+50h] [ebp-10h]
  float v34; // [esp+50h] [ebp-10h]
  int v35; // [esp+54h] [ebp-Ch]
  int v36; // [esp+58h] [ebp-8h]
  _WORD *v37; // [esp+5Ch] [ebp-4h]
  int v38; // [esp+68h] [ebp+8h]
  unsigned int v39; // [esp+68h] [ebp+8h]
  int v40; // [esp+6Ch] [ebp+Ch]
  float v41; // [esp+6Ch] [ebp+Ch]
  float v42; // [esp+6Ch] [ebp+Ch]
  float *v43; // [esp+70h] [ebp+10h]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v24 = 0.0;
  v7 = a2 * this[24];
  v25 = 0.0;
  v26 = 0.0;
  v38 = a2 & 1;
  v37 = (_WORD *)(this[8] + a3 * this[25] + v7 + 2 * v38 * (v6 - 1));
  v35 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v38 )
  {
    v8 = v6 - 1;
    v40 = -1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
    v40 = 1;
  }
  this[31] = v38;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v39 = 0;
  if ( this[26] )
  {
    v32 = 2 * v9;
    v31 = 16 * v9;
    v10 = 16 * v8;
    v11 = 16 * (v8 + v9);
    v12 = 16 * (v8 - v40);
    v36 = v12;
    v43 = (float *)(v10 + a4 + 12);
    do
    {
      v41 = *(float *)(v35 + 4 * (v39 & 3));
      v27 = (v24 + *(v43 - 3)) * 15.0;
      v28 = (v25 + *(v43 - 2)) * 15.0;
      v29 = (v26 + *v43) * 63.0;
      v33 = v27 + v41;
      v30 = (int)v33;
      v34 = v28 + v41;
      v13 = (int)v34;
      v42 = v29 + v41;
      v14 = (int)v42;
      if ( this[23] )
      {
        v15 = (v27 - (double)v30) * 0.06666667;
        *(float *)(this[23] + v12 + 16) = 0.1875 * v15 + *(float *)(this[23] + v12 + 16);
        *(float *)(this[23] + v10 + 16) = 0.3125 * v15 + *(float *)(this[23] + v10 + 16);
        *(float *)(this[23] + v11 + 16) = 0.0625 * v15 + *(float *)(this[23] + v11 + 16);
        v24 = v15 * 0.4375;
        v16 = 0.06666667 * (v28 - (double)(int)v34);
        *(float *)(this[23] + v12 + 20) = 0.1875 * v16 + *(float *)(this[23] + v12 + 20);
        *(float *)(this[23] + v10 + 20) = 0.3125 * v16 + *(float *)(this[23] + v10 + 20);
        *(float *)(this[23] + v11 + 20) = 0.0625 * v16 + *(float *)(this[23] + v11 + 20);
        v25 = v16 * 0.4375;
        v17 = (v29 - (double)(int)v42) * 0.015873017;
        *(float *)(this[23] + v12 + 28) = 0.1875 * v17 + *(float *)(this[23] + v12 + 28);
        *(float *)(this[23] + v10 + 28) = 0.3125 * v17 + *(float *)(this[23] + v10 + 28);
        *(float *)(this[23] + v11 + 28) = 0.0625 * v17 + *(float *)(this[23] + v11 + 28);
        v14 = (int)v42;
        v26 = v17 * 0.4375;
      }
      v18 = v30;
      if ( v30 >= 15 )
        v18 = 15;
      if ( v18 <= -15 )
      {
        LOBYTE(v30) = -15;
      }
      else if ( v30 >= 15 )
      {
        LOBYTE(v30) = 15;
      }
      if ( v13 >= 15 )
        v19 = 15;
      else
        v19 = (int)v34;
      if ( v19 <= -15 )
      {
        v22 = -15;
      }
      else
      {
        if ( v13 < 15 )
          goto LABEL_28;
        v22 = 15;
      }
      LOBYTE(v13) = v22;
LABEL_28:
      if ( v14 >= 63 )
        v20 = 63;
      else
        v20 = v14;
      if ( v20 <= -63 )
      {
        v23 = -63;
        goto LABEL_35;
      }
      if ( v14 >= 63 )
      {
        v23 = 63;
LABEL_35:
        LOWORD(v14) = v23;
      }
      *v37 = v30 & 0x1F | (32 * ((32 * v14) | v13 & 0x1F));
      v37 = (_WORD *)((char *)v37 + v32);
      v43 = (float *)((char *)v43 + v31);
      v12 = v31 + v36;
      v10 += v31;
      v11 += v31;
      ++v39;
      v36 += v31;
    }
    while ( v39 < this[26] );
  }
  return this[31];
}
