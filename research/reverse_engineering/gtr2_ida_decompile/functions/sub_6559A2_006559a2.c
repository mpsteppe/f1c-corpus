int __thiscall sub_6559A2(_DWORD *this, int a2, int a3, int a4)
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
  int v22; // ebx
  int v24; // [esp-4h] [ebp-64h]
  float v25; // [esp+Ch] [ebp-54h]
  float v26; // [esp+10h] [ebp-50h]
  float v27; // [esp+14h] [ebp-4Ch]
  float v28; // [esp+18h] [ebp-48h]
  float v29; // [esp+1Ch] [ebp-44h]
  float v30; // [esp+20h] [ebp-40h]
  float v31; // [esp+24h] [ebp-3Ch]
  float v32; // [esp+28h] [ebp-38h]
  int v33; // [esp+2Ch] [ebp-34h]
  int v34; // [esp+30h] [ebp-30h]
  int v35; // [esp+38h] [ebp-28h]
  int v36; // [esp+3Ch] [ebp-24h]
  int v37; // [esp+40h] [ebp-20h]
  float v38; // [esp+54h] [ebp-Ch]
  float v39; // [esp+54h] [ebp-Ch]
  float v40; // [esp+54h] [ebp-Ch]
  int v41; // [esp+58h] [ebp-8h]
  int *v42; // [esp+5Ch] [ebp-4h]
  int v43; // [esp+68h] [ebp+8h]
  unsigned int v44; // [esp+68h] [ebp+8h]
  float *v45; // [esp+6Ch] [ebp+Ch]
  float v46; // [esp+70h] [ebp+10h]
  float v47; // [esp+70h] [ebp+10h]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v25 = 0.0;
  v7 = a2 * this[24];
  v26 = 0.0;
  v27 = 0.0;
  v28 = 0.0;
  v43 = a2 & 1;
  v42 = (int *)(this[8] + a3 * this[25] + v7 + 4 * v43 * (v6 - 1));
  v41 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v43 )
  {
    v8 = v6 - 1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
  }
  this[31] = v43;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v44 = 0;
  if ( this[26] )
  {
    v37 = 4 * v9;
    v10 = 16 * v8;
    v36 = 16 * v9;
    v11 = 16 * (v9 + v8);
    v12 = 16 * (v8 - v9);
    v45 = (float *)(v10 + a4 + 8);
    while ( 1 )
    {
      v46 = *(float *)(v41 + 4 * (v44 & 3));
      v29 = (v25 + *(v45 - 2)) * 511.0;
      v30 = (v26 + *(v45 - 1)) * 511.0;
      v31 = (v27 + *v45) * 511.0;
      v32 = (v28 + v45[1]) * 3.0;
      v38 = v29 + v46;
      v33 = (int)v38;
      v39 = v30 + v46;
      v34 = (int)v39;
      v40 = v31 + v46;
      v13 = (int)v40;
      v47 = v32 + v46;
      v35 = (int)v47;
      if ( this[23] )
      {
        v14 = (v29 - (double)v33) * 0.0019569471;
        *(float *)(this[23] + v12 + 16) = 0.1875 * v14 + *(float *)(this[23] + v12 + 16);
        *(float *)(this[23] + v10 + 16) = 0.3125 * v14 + *(float *)(this[23] + v10 + 16);
        *(float *)(this[23] + v11 + 16) = 0.0625 * v14 + *(float *)(this[23] + v11 + 16);
        v25 = v14 * 0.4375;
        v15 = (v30 - (double)v34) * 0.0019569471;
        *(float *)(this[23] + v12 + 20) = 0.1875 * v15 + *(float *)(this[23] + v12 + 20);
        *(float *)(this[23] + v10 + 20) = 0.3125 * v15 + *(float *)(this[23] + v10 + 20);
        *(float *)(this[23] + v11 + 20) = 0.0625 * v15 + *(float *)(this[23] + v11 + 20);
        v26 = v15 * 0.4375;
        v16 = 0.0019569471 * (v31 - (double)(int)v40);
        *(float *)(this[23] + v12 + 24) = 0.1875 * v16 + *(float *)(this[23] + v12 + 24);
        *(float *)(this[23] + v10 + 24) = 0.3125 * v16 + *(float *)(this[23] + v10 + 24);
        *(float *)(this[23] + v11 + 24) = 0.0625 * v16 + *(float *)(this[23] + v11 + 24);
        v27 = v16 * 0.4375;
        v17 = (v32 - (double)v35) * 0.33333334;
        *(float *)(this[23] + v12 + 28) = 0.1875 * v17 + *(float *)(this[23] + v12 + 28);
        *(float *)(this[23] + v10 + 28) = 0.3125 * v17 + *(float *)(this[23] + v10 + 28);
        *(float *)(this[23] + v11 + 28) = 0.0625 * v17 + *(float *)(this[23] + v11 + 28);
        v28 = v17 * 0.4375;
      }
      v18 = v33;
      if ( v33 >= 511 )
        v18 = 511;
      if ( v18 <= -511 )
      {
        LOWORD(v33) = -511;
      }
      else if ( v33 >= 511 )
      {
        LOWORD(v33) = 511;
      }
      v19 = v34;
      if ( v34 >= 511 )
        v19 = 511;
      if ( v19 <= -511 )
      {
        LOWORD(v34) = -511;
      }
      else if ( v34 >= 511 )
      {
        LOWORD(v34) = 511;
      }
      v20 = (int)v40;
      if ( v13 >= 511 )
        v20 = 511;
      if ( v20 <= -511 )
      {
        LOWORD(v13) = -511;
      }
      else if ( v13 >= 511 )
      {
        LOWORD(v13) = 511;
      }
      v21 = (int)v47;
      if ( v35 >= 3 )
        v21 = 3;
      if ( v21 <= -3 )
        break;
      v22 = (int)v47;
      if ( v35 >= 3 )
      {
        v24 = 3;
LABEL_38:
        v22 = v24;
      }
      *v42 = v33 & 0x3FF | ((v34 & 0x3FF | (((v22 << 10) | v13 & 0x3FF) << 10)) << 10);
      v45 = (float *)((char *)v45 + v36);
      v10 += v36;
      v12 += v36;
      v11 += v36;
      ++v44;
      v42 = (int *)((char *)v42 + v37);
      if ( v44 >= this[26] )
        return this[31];
    }
    v24 = -3;
    goto LABEL_38;
  }
  return this[31];
}
