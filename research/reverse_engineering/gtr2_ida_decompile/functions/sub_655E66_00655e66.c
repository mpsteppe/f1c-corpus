int __thiscall sub_655E66(_DWORD *this, int a2, int a3, int a4)
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
  int v18; // edi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  unsigned __int64 v22; // rt0
  float v24; // [esp+Ch] [ebp-5Ch]
  float v25; // [esp+10h] [ebp-58h]
  float v26; // [esp+14h] [ebp-54h]
  float v27; // [esp+18h] [ebp-50h]
  float v28; // [esp+1Ch] [ebp-4Ch]
  float v29; // [esp+20h] [ebp-48h]
  float v30; // [esp+24h] [ebp-44h]
  float v31; // [esp+28h] [ebp-40h]
  unsigned __int16 v32; // [esp+2Ch] [ebp-3Ch]
  int v33; // [esp+30h] [ebp-38h]
  int v34; // [esp+34h] [ebp-34h]
  int v35; // [esp+38h] [ebp-30h]
  int v36; // [esp+3Ch] [ebp-2Ch]
  int v37; // [esp+40h] [ebp-28h]
  float v38; // [esp+54h] [ebp-14h]
  float v39; // [esp+54h] [ebp-14h]
  float v40; // [esp+54h] [ebp-14h]
  int v41; // [esp+58h] [ebp-10h]
  int v42; // [esp+5Ch] [ebp-Ch]
  int v43; // [esp+60h] [ebp-8h]
  int *v44; // [esp+64h] [ebp-4h]
  int v45; // [esp+70h] [ebp+8h]
  unsigned int v46; // [esp+70h] [ebp+8h]
  float *v47; // [esp+74h] [ebp+Ch]
  float v48; // [esp+78h] [ebp+10h]
  float v49; // [esp+78h] [ebp+10h]

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
  v27 = 0.0;
  v45 = a2 & 1;
  v44 = (int *)(this[8] + a3 * this[25] + v7 + 8 * v45 * (v6 - 1));
  v41 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v45 )
  {
    v8 = v6 - 1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
  }
  this[31] = v45;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v46 = 0;
  if ( this[26] )
  {
    v37 = 8 * v9;
    v36 = 16 * v9;
    v10 = 16 * v8;
    v11 = 16 * (v9 + v8);
    v12 = 16 * (v8 - v9);
    v42 = v11;
    v43 = v12;
    v47 = (float *)(v10 + a4 + 8);
    do
    {
      v48 = *(float *)(v41 + 4 * (v46 & 3));
      v28 = (v24 + *(v47 - 2)) * 32767.0;
      v29 = (v25 + *(v47 - 1)) * 32767.0;
      v30 = (v26 + *v47) * 32767.0;
      v31 = (v27 + v47[1]) * 32767.0;
      v38 = v28 + v48;
      v13 = (int)v38;
      v32 = v13;
      v39 = v29 + v48;
      v33 = (int)v39;
      v40 = v30 + v48;
      v34 = (int)v40;
      v49 = v31 + v48;
      v35 = (int)v49;
      if ( this[23] )
      {
        v14 = (v28 - (double)v13) * 0.000030518509;
        *(float *)(this[23] + v12 + 16) = 0.1875 * v14 + *(float *)(this[23] + v12 + 16);
        *(float *)(this[23] + v10 + 16) = 0.3125 * v14 + *(float *)(this[23] + v10 + 16);
        *(float *)(this[23] + v11 + 16) = 0.0625 * v14 + *(float *)(this[23] + v11 + 16);
        v24 = v14 * 0.4375;
        v15 = (v29 - (double)v33) * 0.000030518509;
        *(float *)(this[23] + v12 + 20) = 0.1875 * v15 + *(float *)(this[23] + v12 + 20);
        *(float *)(this[23] + v10 + 20) = 0.3125 * v15 + *(float *)(this[23] + v10 + 20);
        *(float *)(this[23] + v11 + 20) = 0.0625 * v15 + *(float *)(this[23] + v11 + 20);
        v25 = v15 * 0.4375;
        v16 = (v30 - (double)v34) * 0.000030518509;
        *(float *)(this[23] + v12 + 24) = 0.1875 * v16 + *(float *)(this[23] + v12 + 24);
        *(float *)(this[23] + v10 + 24) = 0.3125 * v16 + *(float *)(this[23] + v10 + 24);
        *(float *)(this[23] + v11 + 24) = 0.0625 * v16 + *(float *)(this[23] + v11 + 24);
        v26 = v16 * 0.4375;
        v17 = 0.000030518509 * (v31 - (double)v35);
        *(float *)(this[23] + v12 + 28) = 0.1875 * v17 + *(float *)(this[23] + v12 + 28);
        *(float *)(this[23] + v10 + 28) = 0.3125 * v17 + *(float *)(this[23] + v10 + 28);
        *(float *)(this[23] + v11 + 28) = 0.0625 * v17 + *(float *)(this[23] + v11 + 28);
        v27 = v17 * 0.4375;
      }
      v18 = v13;
      if ( v13 >= 0x7FFF )
        v18 = 0x7FFF;
      if ( v18 <= -32767 )
      {
        v32 = -32767;
      }
      else if ( v13 >= 0x7FFF )
      {
        v32 = 0x7FFF;
      }
      v19 = v33;
      if ( v33 >= 0x7FFF )
        v19 = 0x7FFF;
      if ( v19 <= -32767 )
      {
        LOWORD(v33) = -32767;
      }
      else if ( v33 >= 0x7FFF )
      {
        LOWORD(v33) = 0x7FFF;
      }
      v20 = (int)v40;
      if ( v34 >= 0x7FFF )
        v20 = 0x7FFF;
      if ( v20 <= -32767 )
      {
        LOWORD(v34) = -32767;
      }
      else if ( v34 >= 0x7FFF )
      {
        LOWORD(v34) = 0x7FFF;
      }
      v21 = (int)v49;
      if ( v35 >= 0x7FFF )
        v21 = 0x7FFF;
      if ( v21 <= -32767 )
      {
        v35 = -32767;
      }
      else if ( v35 >= 0x7FFF )
      {
        v35 = 0x7FFF;
      }
      v22 = (unsigned __int16)v34 | (unsigned __int64)(unsigned int)(v35 << 16);
      HIDWORD(v22) = v22 >> 16;
      LODWORD(v22) = (unsigned __int16)v33 | ((_DWORD)v22 << 16);
      v44[1] = v22 >> 16;
      *v44 = v32 | ((_DWORD)v22 << 16);
      v44 = (int *)((char *)v44 + v37);
      v47 = (float *)((char *)v47 + v36);
      v12 = v36 + v43;
      v11 = v36 + v42;
      v10 += v36;
      ++v46;
      v43 += v36;
      v42 += v36;
    }
    while ( v46 < this[26] );
  }
  return this[31];
}
