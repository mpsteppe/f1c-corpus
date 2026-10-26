int __thiscall sub_650DE3(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edi
  int v7; // edx
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // ecx
  int v12; // ebx
  int v13; // edx
  double v14; // st6
  double v15; // st6
  double v16; // st7
  int v17; // edi
  int v18; // edi
  int v19; // edi
  float v21; // [esp+Ch] [ebp-50h]
  float v22; // [esp+10h] [ebp-4Ch]
  float v23; // [esp+14h] [ebp-48h]
  float v24; // [esp+1Ch] [ebp-40h]
  float v25; // [esp+20h] [ebp-3Ch]
  float v26; // [esp+24h] [ebp-38h]
  int v27; // [esp+30h] [ebp-2Ch]
  int v28; // [esp+34h] [ebp-28h]
  int v29; // [esp+3Ch] [ebp-20h]
  int v30; // [esp+40h] [ebp-1Ch]
  float v31; // [esp+50h] [ebp-Ch]
  float v32; // [esp+50h] [ebp-Ch]
  int v33; // [esp+54h] [ebp-8h]
  _WORD *v34; // [esp+58h] [ebp-4h]
  int v35; // [esp+64h] [ebp+8h]
  unsigned int v36; // [esp+64h] [ebp+8h]
  float v37; // [esp+68h] [ebp+Ch]
  float v38; // [esp+68h] [ebp+Ch]
  float *v39; // [esp+6Ch] [ebp+10h]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v21 = 0.0;
  v7 = a2 * this[24];
  v22 = 0.0;
  v23 = 0.0;
  v35 = a2 & 1;
  v34 = (_WORD *)(this[8] + a3 * this[25] + v7 + 2 * v35 * (v6 - 1));
  v33 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v35 )
  {
    v8 = v6 - 1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
  }
  this[31] = v35;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v36 = 0;
  if ( this[26] )
  {
    v30 = 2 * v9;
    v29 = 16 * v9;
    v10 = 16 * v8;
    v11 = 16 * (v9 + v8);
    v12 = 16 * (v8 - v9);
    v39 = (float *)(16 * v8 + a4 + 8);
    do
    {
      v37 = *(float *)(v33 + 4 * (v36 & 3));
      v24 = (v21 + *(v39 - 2)) * 31.0;
      v25 = (v22 + *(v39 - 1)) * 63.0;
      v26 = (v23 + *v39) * 31.0;
      v31 = v24 + v37;
      v13 = (int)v31;
      v32 = v25 + v37;
      v27 = (int)v32;
      v38 = v26 + v37;
      v28 = (int)v38;
      if ( this[23] )
      {
        v14 = (v24 - (double)v13) * 0.032258064;
        *(float *)(this[23] + v12 + 16) = 0.1875 * v14 + *(float *)(this[23] + v12 + 16);
        *(float *)(this[23] + v10 + 16) = 0.3125 * v14 + *(float *)(this[23] + v10 + 16);
        *(float *)(this[23] + v11 + 16) = 0.0625 * v14 + *(float *)(this[23] + v11 + 16);
        v21 = v14 * 0.4375;
        v15 = (v25 - (double)v27) * 0.015873017;
        *(float *)(this[23] + v12 + 20) = 0.1875 * v15 + *(float *)(this[23] + v12 + 20);
        *(float *)(this[23] + v10 + 20) = 0.3125 * v15 + *(float *)(this[23] + v10 + 20);
        *(float *)(this[23] + v11 + 20) = 0.0625 * v15 + *(float *)(this[23] + v11 + 20);
        v22 = v15 * 0.4375;
        v16 = 0.032258064 * (v26 - (double)v28);
        *(float *)(this[23] + v12 + 24) = 0.1875 * v16 + *(float *)(this[23] + v12 + 24);
        *(float *)(this[23] + v10 + 24) = 0.3125 * v16 + *(float *)(this[23] + v10 + 24);
        *(float *)(this[23] + v11 + 24) = 0.0625 * v16 + *(float *)(this[23] + v11 + 24);
        v23 = v16 * 0.4375;
      }
      if ( v13 >= 31 )
        v17 = 31;
      else
        v17 = v13;
      if ( v17 <= 0 )
      {
        LOWORD(v13) = 0;
      }
      else if ( v13 >= 31 )
      {
        LOWORD(v13) = 31;
      }
      v18 = (int)v32;
      if ( v27 >= 63 )
        v18 = 63;
      if ( v18 <= 0 )
      {
        LOWORD(v27) = 0;
      }
      else if ( v27 >= 63 )
      {
        LOWORD(v27) = 63;
      }
      v19 = (int)v38;
      if ( v28 >= 31 )
        v19 = 31;
      if ( v19 <= 0 )
      {
        LOWORD(v28) = 0;
      }
      else if ( v28 >= 31 )
      {
        LOWORD(v28) = 31;
      }
      *v34 = v28 | (32 * (v27 | ((_WORD)v13 << 6)));
      v39 = (float *)((char *)v39 + v29);
      v10 += v29;
      v12 += v29;
      v11 += v29;
      ++v36;
      v34 = (_WORD *)((char *)v34 + v30);
    }
    while ( v36 < this[26] );
  }
  return this[31];
}
