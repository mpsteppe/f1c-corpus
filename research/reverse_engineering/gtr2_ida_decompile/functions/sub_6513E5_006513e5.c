int __thiscall sub_6513E5(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edi
  int v7; // edx
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // ecx
  int v12; // edi
  int v13; // edx
  double v14; // st6
  double v15; // st6
  double v16; // st7
  double v17; // st7
  int v18; // ebx
  int v19; // ebx
  int v20; // ebx
  int v21; // ebx
  float v23; // [esp+Ch] [ebp-54h]
  float v24; // [esp+10h] [ebp-50h]
  float v25; // [esp+14h] [ebp-4Ch]
  float v26; // [esp+18h] [ebp-48h]
  float v27; // [esp+1Ch] [ebp-44h]
  float v28; // [esp+20h] [ebp-40h]
  float v29; // [esp+24h] [ebp-3Ch]
  float v30; // [esp+28h] [ebp-38h]
  int v31; // [esp+2Ch] [ebp-34h]
  int v32; // [esp+30h] [ebp-30h]
  int v33; // [esp+34h] [ebp-2Ch]
  int v34; // [esp+3Ch] [ebp-24h]
  int v35; // [esp+40h] [ebp-20h]
  float v36; // [esp+54h] [ebp-Ch]
  float v37; // [esp+54h] [ebp-Ch]
  float v38; // [esp+54h] [ebp-Ch]
  int v39; // [esp+58h] [ebp-8h]
  _WORD *v40; // [esp+5Ch] [ebp-4h]
  int v41; // [esp+68h] [ebp+8h]
  unsigned int v42; // [esp+68h] [ebp+8h]
  float *v43; // [esp+6Ch] [ebp+Ch]
  float v44; // [esp+70h] [ebp+10h]
  float v45; // [esp+70h] [ebp+10h]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v23 = 0.0;
  v7 = a2 * this[24];
  v24 = 0.0;
  v25 = 0.0;
  v26 = 0.0;
  v41 = a2 & 1;
  v40 = (_WORD *)(this[8] + a3 * this[25] + v7 + 2 * v41 * (v6 - 1));
  v39 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v41 )
  {
    v8 = v6 - 1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
  }
  this[31] = v41;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v42 = 0;
  if ( this[26] )
  {
    v35 = 2 * v9;
    v10 = 16 * v8;
    v34 = 16 * v9;
    v11 = 16 * (v9 + v8);
    v12 = 16 * (v8 - v9);
    v43 = (float *)(v10 + a4 + 8);
    do
    {
      v44 = *(float *)(v39 + 4 * (v42 & 3));
      v27 = (v23 + *(v43 - 2)) * 31.0;
      v28 = (v24 + *(v43 - 1)) * 31.0;
      v29 = (v25 + *v43) * 31.0;
      v30 = v26 + v43[1];
      v36 = v27 + v44;
      v31 = (int)v36;
      v37 = v28 + v44;
      v32 = (int)v37;
      v38 = v29 + v44;
      v33 = (int)v38;
      v45 = v30 + v44;
      v13 = (int)v45;
      if ( this[23] )
      {
        v14 = (v27 - (double)v31) * 0.032258064;
        *(float *)(this[23] + v12 + 16) = 0.1875 * v14 + *(float *)(this[23] + v12 + 16);
        *(float *)(this[23] + v10 + 16) = 0.3125 * v14 + *(float *)(this[23] + v10 + 16);
        *(float *)(this[23] + v11 + 16) = 0.0625 * v14 + *(float *)(this[23] + v11 + 16);
        v23 = v14 * 0.4375;
        v15 = (v28 - (double)v32) * 0.032258064;
        *(float *)(this[23] + v12 + 20) = 0.1875 * v15 + *(float *)(this[23] + v12 + 20);
        *(float *)(this[23] + v10 + 20) = 0.3125 * v15 + *(float *)(this[23] + v10 + 20);
        *(float *)(this[23] + v11 + 20) = 0.0625 * v15 + *(float *)(this[23] + v11 + 20);
        v24 = v15 * 0.4375;
        v16 = 0.032258064 * (v29 - (double)v33);
        *(float *)(this[23] + v12 + 24) = 0.1875 * v16 + *(float *)(this[23] + v12 + 24);
        *(float *)(this[23] + v10 + 24) = 0.3125 * v16 + *(float *)(this[23] + v10 + 24);
        *(float *)(this[23] + v11 + 24) = 0.0625 * v16 + *(float *)(this[23] + v11 + 24);
        v25 = v16 * 0.4375;
        v17 = v30 - (double)(int)v45;
        *(float *)(this[23] + v12 + 28) = 0.1875 * v17 + *(float *)(this[23] + v12 + 28);
        *(float *)(this[23] + v10 + 28) = 0.3125 * v17 + *(float *)(this[23] + v10 + 28);
        *(float *)(this[23] + v11 + 28) = 0.0625 * v17 + *(float *)(this[23] + v11 + 28);
        v26 = v17 * 0.4375;
      }
      v18 = v31;
      if ( v31 >= 31 )
        v18 = 31;
      if ( v18 <= 0 )
      {
        LOWORD(v31) = 0;
      }
      else if ( v31 >= 31 )
      {
        LOWORD(v31) = 31;
      }
      v19 = v32;
      if ( v32 >= 31 )
        v19 = 31;
      if ( v19 <= 0 )
      {
        LOWORD(v32) = 0;
      }
      else if ( v32 >= 31 )
      {
        LOWORD(v32) = 31;
      }
      v20 = (int)v38;
      if ( v33 >= 31 )
        v20 = 31;
      if ( v20 <= 0 )
      {
        LOWORD(v33) = 0;
      }
      else if ( v33 >= 31 )
      {
        LOWORD(v33) = 31;
      }
      if ( v13 >= 1 )
        v21 = 1;
      else
        v21 = (int)v45;
      if ( v21 <= 0 )
      {
        LOWORD(v13) = 0;
      }
      else if ( v13 >= 1 )
      {
        LOWORD(v13) = 1;
      }
      *v40 = v33 | (32 * (v32 | (32 * (v31 | (32 * v13)))));
      v43 = (float *)((char *)v43 + v34);
      v10 += v34;
      v12 += v34;
      v11 += v34;
      ++v42;
      v40 = (_WORD *)((char *)v40 + v35);
    }
    while ( v42 < this[26] );
  }
  return this[31];
}
