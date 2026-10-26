int __thiscall sub_653716(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edi
  int v7; // edx
  int v8; // edi
  int v9; // ebx
  int v10; // ecx
  int v11; // edx
  int v12; // edi
  int v13; // ebx
  double v14; // st6
  double v15; // st6
  double v16; // st6
  double v17; // st7
  int v18; // edx
  int v19; // edx
  int v20; // edx
  int v21; // edx
  float v23; // [esp+Ch] [ebp-5Ch]
  float v24; // [esp+10h] [ebp-58h]
  float v25; // [esp+14h] [ebp-54h]
  float v26; // [esp+18h] [ebp-50h]
  float v27; // [esp+1Ch] [ebp-4Ch]
  float v28; // [esp+20h] [ebp-48h]
  float v29; // [esp+24h] [ebp-44h]
  float v30; // [esp+28h] [ebp-40h]
  int v31; // [esp+2Ch] [ebp-3Ch]
  int v32; // [esp+30h] [ebp-38h]
  int v33; // [esp+34h] [ebp-34h]
  int v34; // [esp+38h] [ebp-30h]
  int v35; // [esp+3Ch] [ebp-2Ch]
  int v36; // [esp+40h] [ebp-28h]
  float v37; // [esp+54h] [ebp-14h]
  float v38; // [esp+54h] [ebp-14h]
  float v39; // [esp+54h] [ebp-14h]
  int v40; // [esp+58h] [ebp-10h]
  int v41; // [esp+5Ch] [ebp-Ch]
  int v42; // [esp+60h] [ebp-8h]
  _QWORD *v43; // [esp+64h] [ebp-4h]
  int v44; // [esp+70h] [ebp+8h]
  unsigned int v45; // [esp+70h] [ebp+8h]
  float *v46; // [esp+74h] [ebp+Ch]
  float v47; // [esp+78h] [ebp+10h]
  float v48; // [esp+78h] [ebp+10h]

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
  v44 = a2 & 1;
  v43 = (_QWORD *)(this[8] + a3 * this[25] + v7 + 8 * v44 * (v6 - 1));
  v40 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v44 )
  {
    v8 = v6 - 1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
  }
  this[31] = v44;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v45 = 0;
  if ( this[26] )
  {
    v36 = 8 * v9;
    v35 = 16 * v9;
    v10 = 16 * v8;
    v11 = 16 * (v9 + v8);
    v12 = 16 * (v8 - v9);
    v41 = v11;
    v42 = v12;
    v46 = (float *)(v10 + a4 + 8);
    do
    {
      v47 = *(float *)(v40 + 4 * (v45 & 3));
      v27 = (v23 + *(v46 - 2)) * 65535.0;
      v28 = (v24 + *(v46 - 1)) * 65535.0;
      v29 = (v25 + *v46) * 65535.0;
      v30 = (v26 + v46[1]) * 65535.0;
      v37 = v27 + v47;
      v13 = (int)v37;
      v31 = v13;
      v38 = v28 + v47;
      v32 = (int)v38;
      v39 = v29 + v47;
      v33 = (int)v39;
      v48 = v30 + v47;
      v34 = (int)v48;
      if ( this[23] )
      {
        v14 = (v27 - (double)v13) * 0.000015259022;
        *(float *)(this[23] + v12 + 16) = 0.1875 * v14 + *(float *)(this[23] + v12 + 16);
        *(float *)(this[23] + v10 + 16) = 0.3125 * v14 + *(float *)(this[23] + v10 + 16);
        *(float *)(this[23] + v11 + 16) = 0.0625 * v14 + *(float *)(this[23] + v11 + 16);
        v23 = v14 * 0.4375;
        v15 = (v28 - (double)v32) * 0.000015259022;
        *(float *)(this[23] + v12 + 20) = 0.1875 * v15 + *(float *)(this[23] + v12 + 20);
        *(float *)(this[23] + v10 + 20) = 0.3125 * v15 + *(float *)(this[23] + v10 + 20);
        *(float *)(this[23] + v11 + 20) = 0.0625 * v15 + *(float *)(this[23] + v11 + 20);
        v24 = v15 * 0.4375;
        v16 = (v29 - (double)v33) * 0.000015259022;
        *(float *)(this[23] + v12 + 24) = 0.1875 * v16 + *(float *)(this[23] + v12 + 24);
        *(float *)(this[23] + v10 + 24) = 0.3125 * v16 + *(float *)(this[23] + v10 + 24);
        *(float *)(this[23] + v11 + 24) = 0.0625 * v16 + *(float *)(this[23] + v11 + 24);
        v25 = v16 * 0.4375;
        v17 = 0.000015259022 * (v30 - (double)v34);
        *(float *)(this[23] + v12 + 28) = 0.1875 * v17 + *(float *)(this[23] + v12 + 28);
        *(float *)(this[23] + v10 + 28) = 0.3125 * v17 + *(float *)(this[23] + v10 + 28);
        *(float *)(this[23] + v11 + 28) = 0.0625 * v17 + *(float *)(this[23] + v11 + 28);
        v26 = v17 * 0.4375;
      }
      v18 = v13;
      if ( v13 >= 0xFFFF )
        v18 = 0xFFFF;
      if ( v18 <= 0 )
      {
        v31 = 0;
      }
      else if ( v13 >= 0xFFFF )
      {
        v31 = 0xFFFF;
      }
      v19 = v32;
      if ( v32 >= 0xFFFF )
        v19 = 0xFFFF;
      if ( v19 <= 0 )
      {
        v32 = 0;
      }
      else if ( v32 >= 0xFFFF )
      {
        v32 = 0xFFFF;
      }
      v20 = (int)v39;
      if ( v33 >= 0xFFFF )
        v20 = 0xFFFF;
      if ( v20 <= 0 )
      {
        v33 = 0;
      }
      else if ( v33 >= 0xFFFF )
      {
        v33 = 0xFFFF;
      }
      v21 = (int)v48;
      if ( v34 >= 0xFFFF )
        v21 = 0xFFFF;
      if ( v21 <= 0 )
      {
        v34 = 0;
      }
      else if ( v34 >= 0xFFFF )
      {
        v34 = 0xFFFF;
      }
      *v43 = __PAIR64__(
               (v31 >> 31) | (unsigned int)((v32 | ((v33 | (unsigned __int64)((__int64)v34 << 16)) << 16)) >> 16),
               v31 | ((v32 | ((v33 | (unsigned int)(v34 << 16)) << 16)) << 16));
      v43 = (_QWORD *)((char *)v43 + v36);
      v46 = (float *)((char *)v46 + v35);
      v12 = v35 + v42;
      v11 = v35 + v41;
      v10 += v35;
      ++v45;
      v42 += v35;
      v41 += v35;
    }
    while ( v45 < this[26] );
  }
  return this[31];
}
