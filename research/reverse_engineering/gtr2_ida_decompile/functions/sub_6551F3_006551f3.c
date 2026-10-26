int __thiscall sub_6551F3(_DWORD *this, int a2, int a3, int a4)
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
  double v16; // st6
  double v17; // st7
  int v18; // ebx
  int v19; // ebx
  int v20; // ebx
  int v21; // ebx
  int v22; // ebx
  char v24; // [esp-4h] [ebp-64h]
  int v25; // [esp-4h] [ebp-64h]
  float v26; // [esp+Ch] [ebp-54h]
  float v27; // [esp+10h] [ebp-50h]
  float v28; // [esp+14h] [ebp-4Ch]
  float v29; // [esp+18h] [ebp-48h]
  float v30; // [esp+1Ch] [ebp-44h]
  float v31; // [esp+20h] [ebp-40h]
  float v32; // [esp+24h] [ebp-3Ch]
  float v33; // [esp+28h] [ebp-38h]
  int v34; // [esp+2Ch] [ebp-34h]
  int v35; // [esp+30h] [ebp-30h]
  int v36; // [esp+38h] [ebp-28h]
  int v37; // [esp+3Ch] [ebp-24h]
  int v38; // [esp+40h] [ebp-20h]
  float v39; // [esp+54h] [ebp-Ch]
  float v40; // [esp+54h] [ebp-Ch]
  float v41; // [esp+54h] [ebp-Ch]
  int v42; // [esp+58h] [ebp-8h]
  int *v43; // [esp+5Ch] [ebp-4h]
  int v44; // [esp+68h] [ebp+8h]
  unsigned int v45; // [esp+68h] [ebp+8h]
  float *v46; // [esp+6Ch] [ebp+Ch]
  float v47; // [esp+70h] [ebp+10h]
  float v48; // [esp+70h] [ebp+10h]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v26 = 0.0;
  v7 = a2 * this[24];
  v27 = 0.0;
  v28 = 0.0;
  v29 = 0.0;
  v44 = a2 & 1;
  v43 = (int *)(this[8] + a3 * this[25] + v7 + 4 * v44 * (v6 - 1));
  v42 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
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
    v38 = 4 * v9;
    v10 = 16 * v8;
    v37 = 16 * v9;
    v11 = 16 * (v9 + v8);
    v12 = 16 * (v8 - v9);
    v46 = (float *)(v10 + a4 + 8);
    do
    {
      v47 = *(float *)(v42 + 4 * (v45 & 3));
      v30 = (v26 + *(v46 - 2)) * 127.0;
      v31 = (v27 + *(v46 - 1)) * 127.0;
      v32 = (v28 + *v46) * 127.0;
      v33 = (v29 + v46[1]) * 127.0;
      v39 = v30 + v47;
      v34 = (int)v39;
      v40 = v31 + v47;
      v35 = (int)v40;
      v41 = v32 + v47;
      v13 = (int)v41;
      v48 = v33 + v47;
      v36 = (int)v48;
      if ( this[23] )
      {
        v14 = (v30 - (double)v34) * 0.0078740157;
        *(float *)(this[23] + v12 + 16) = 0.1875 * v14 + *(float *)(this[23] + v12 + 16);
        *(float *)(this[23] + v10 + 16) = 0.3125 * v14 + *(float *)(this[23] + v10 + 16);
        *(float *)(this[23] + v11 + 16) = 0.0625 * v14 + *(float *)(this[23] + v11 + 16);
        v26 = v14 * 0.4375;
        v15 = (v31 - (double)v35) * 0.0078740157;
        *(float *)(this[23] + v12 + 20) = 0.1875 * v15 + *(float *)(this[23] + v12 + 20);
        *(float *)(this[23] + v10 + 20) = 0.3125 * v15 + *(float *)(this[23] + v10 + 20);
        *(float *)(this[23] + v11 + 20) = 0.0625 * v15 + *(float *)(this[23] + v11 + 20);
        v27 = v15 * 0.4375;
        v16 = (v32 - (double)(int)v41) * 0.0078740157;
        *(float *)(this[23] + v12 + 24) = 0.1875 * v16 + *(float *)(this[23] + v12 + 24);
        *(float *)(this[23] + v10 + 24) = 0.3125 * v16 + *(float *)(this[23] + v10 + 24);
        *(float *)(this[23] + v11 + 24) = 0.0625 * v16 + *(float *)(this[23] + v11 + 24);
        v28 = v16 * 0.4375;
        v17 = 0.0078740157 * (v33 - (double)v36);
        *(float *)(this[23] + v12 + 28) = 0.1875 * v17 + *(float *)(this[23] + v12 + 28);
        *(float *)(this[23] + v10 + 28) = 0.3125 * v17 + *(float *)(this[23] + v10 + 28);
        *(float *)(this[23] + v11 + 28) = 0.0625 * v17 + *(float *)(this[23] + v11 + 28);
        v29 = v17 * 0.4375;
      }
      v18 = v34;
      if ( v34 >= 127 )
        v18 = 127;
      if ( v18 <= -127 )
      {
        LOBYTE(v34) = -127;
      }
      else if ( v34 >= 127 )
      {
        LOBYTE(v34) = 127;
      }
      v19 = v35;
      if ( v35 >= 127 )
        v19 = 127;
      if ( v19 <= -127 )
      {
        LOBYTE(v35) = -127;
      }
      else if ( v35 >= 127 )
      {
        LOBYTE(v35) = 127;
      }
      if ( v13 >= 127 )
        v20 = 127;
      else
        v20 = (int)v41;
      if ( v20 <= -127 )
      {
        v24 = -127;
      }
      else
      {
        if ( v13 < 127 )
          goto LABEL_34;
        v24 = 127;
      }
      LOBYTE(v13) = v24;
LABEL_34:
      v21 = (int)v48;
      if ( v36 >= 127 )
        v21 = 127;
      if ( v21 <= -127 )
      {
        v25 = -127;
        goto LABEL_40;
      }
      v22 = (int)v48;
      if ( v36 >= 127 )
      {
        v25 = 127;
LABEL_40:
        v22 = v25;
      }
      *v43 = (unsigned __int8)v34 | (((unsigned __int8)v35 | (((v22 << 8) | (unsigned __int8)v13) << 8)) << 8);
      v46 = (float *)((char *)v46 + v37);
      v10 += v37;
      v12 += v37;
      v11 += v37;
      ++v45;
      v43 = (int *)((char *)v43 + v38);
    }
    while ( v45 < this[26] );
  }
  return this[31];
}
