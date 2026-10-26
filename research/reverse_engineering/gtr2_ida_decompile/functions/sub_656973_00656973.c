int __thiscall sub_656973(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // cl
  int v6; // ebx
  int v7; // edx
  _WORD *v8; // edi
  int v9; // ebx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  double v13; // st6
  double v14; // st6
  double v15; // st7
  int v16; // ebx
  int v17; // ebx
  int v18; // ebx
  int v19; // ebx
  float v21; // [esp+Ch] [ebp-50h]
  float v22; // [esp+10h] [ebp-4Ch]
  float v23; // [esp+14h] [ebp-48h]
  float v24; // [esp+1Ch] [ebp-40h]
  float v25; // [esp+20h] [ebp-3Ch]
  float v26; // [esp+24h] [ebp-38h]
  int v27; // [esp+2Ch] [ebp-30h]
  int v28; // [esp+30h] [ebp-2Ch]
  int v29; // [esp+34h] [ebp-28h]
  int v30; // [esp+3Ch] [ebp-20h]
  float v31; // [esp+50h] [ebp-Ch]
  float v32; // [esp+50h] [ebp-Ch]
  float v33; // [esp+50h] [ebp-Ch]
  int v34; // [esp+54h] [ebp-8h]
  float v35; // [esp+58h] [ebp-4h]
  int v36; // [esp+64h] [ebp+8h]
  int v37; // [esp+64h] [ebp+8h]
  unsigned int v38; // [esp+64h] [ebp+8h]
  int v39; // [esp+68h] [ebp+Ch]
  float *v40; // [esp+6Ch] [ebp+10h]

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
  v36 = a2 & 1;
  v8 = (_WORD *)(this[8] + a3 * this[25] + v7 + 6 * v36 * (v6 - 1));
  v34 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v36 )
  {
    v9 = v6 - 1;
    v37 = -1;
    v10 = -1;
  }
  else
  {
    v9 = 0;
    v10 = 1;
    v37 = 1;
  }
  this[31] = a3;
  if ( this[23] )
  {
    sub_6503AF((int)this, a4);
    v10 = v37;
  }
  v38 = 0;
  if ( this[26] )
  {
    v30 = 16 * v10;
    v11 = 16 * v9;
    v12 = 16 * (v10 + v9);
    v39 = 16 * (v9 - v10);
    v40 = (float *)(16 * v9 + a4 + 8);
    do
    {
      v35 = *(float *)(v34 + 4 * (v38 & 3));
      v24 = (v21 + *(v40 - 2)) * 65535.0;
      v25 = (v22 + *(v40 - 1)) * 65535.0;
      v26 = (v23 + *v40) * 65535.0;
      v31 = v24 + v35;
      v27 = (int)v31;
      v32 = v25 + v35;
      v28 = (int)v32;
      v33 = v26 + v35;
      v29 = (int)v33;
      if ( this[23] )
      {
        v13 = (v24 - (double)v27) * 0.000015259022;
        *(float *)(this[23] + v39 + 16) = 0.1875 * v13 + *(float *)(this[23] + v39 + 16);
        *(float *)(this[23] + v11 + 16) = 0.3125 * v13 + *(float *)(this[23] + v11 + 16);
        *(float *)(this[23] + v12 + 16) = 0.0625 * v13 + *(float *)(this[23] + v12 + 16);
        v21 = v13 * 0.4375;
        v14 = (v25 - (double)v28) * 0.000015259022;
        *(float *)(this[23] + v39 + 20) = 0.1875 * v14 + *(float *)(this[23] + v39 + 20);
        *(float *)(this[23] + v11 + 20) = 0.3125 * v14 + *(float *)(this[23] + v11 + 20);
        *(float *)(this[23] + v12 + 20) = 0.0625 * v14 + *(float *)(this[23] + v12 + 20);
        v22 = v14 * 0.4375;
        v15 = 0.000015259022 * (v26 - (double)v29);
        *(float *)(this[23] + v39 + 24) = 0.1875 * v15 + *(float *)(this[23] + v39 + 24);
        *(float *)(this[23] + v11 + 24) = 0.3125 * v15 + *(float *)(this[23] + v11 + 24);
        *(float *)(this[23] + v12 + 24) = 0.0625 * v15 + *(float *)(this[23] + v12 + 24);
        v23 = v15 * 0.4375;
      }
      v16 = v27;
      if ( v27 >= 0xFFFF )
        v16 = 0xFFFF;
      if ( v16 <= 0 )
      {
        LOWORD(v27) = 0;
      }
      else if ( v27 >= 0xFFFF )
      {
        LOWORD(v27) = -1;
      }
      v17 = v28;
      if ( v28 >= 0xFFFF )
        v17 = 0xFFFF;
      if ( v17 <= 0 )
      {
        LOWORD(v28) = 0;
      }
      else if ( v28 >= 0xFFFF )
      {
        LOWORD(v28) = -1;
      }
      v18 = (int)v33;
      if ( v29 >= 0xFFFF )
        v18 = 0xFFFF;
      if ( v18 <= 0 )
      {
        LOWORD(v19) = 0;
      }
      else
      {
        v19 = (int)v33;
        if ( v29 >= 0xFFFF )
          LOWORD(v19) = -1;
      }
      v8[1] = v28;
      v8[2] = v27;
      v40 = (float *)((char *)v40 + v30);
      v39 += v30;
      *v8 = v19;
      v8 += 3 * v10;
      v11 += v30;
      v12 += v30;
      ++v38;
    }
    while ( v38 < this[26] );
  }
  return this[31];
}
