int __thiscall sub_653ACD(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // edi
  int v7; // edx
  _WORD *v8; // ebx
  int v9; // edi
  int v10; // ecx
  int v11; // edx
  float *v12; // edi
  int v13; // ecx
  float *v14; // eax
  double v15; // st6
  double v16; // st5
  double v17; // st3
  double v18; // st4
  int v19; // eax
  double v20; // st7
  int v21; // edx
  __int16 v22; // dx
  float v24; // [esp+28h] [ebp-38h]
  float v25; // [esp+38h] [ebp-28h]
  int v26; // [esp+3Ch] [ebp-24h]
  int v27; // [esp+44h] [ebp-1Ch]
  int v28; // [esp+48h] [ebp-18h]
  __int16 v29; // [esp+4Ch] [ebp-14h]
  float v30; // [esp+50h] [ebp-10h]
  int v31; // [esp+54h] [ebp-Ch]
  int v32; // [esp+58h] [ebp-8h]
  float *i; // [esp+5Ch] [ebp-4h]
  int v34; // [esp+68h] [ebp+8h]
  int v35; // [esp+68h] [ebp+8h]
  float *v36; // [esp+68h] [ebp+8h]
  unsigned int v37; // [esp+6Ch] [ebp+Ch]
  unsigned int v38; // [esp+70h] [ebp+10h]
  float v39; // [esp+70h] [ebp+10h]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v24 = 0.0;
  v7 = a2 * this[24];
  v34 = a2 & 1;
  v8 = (_WORD *)(this[8] + a3 * this[25] + v7 + 2 * v34 * (v6 - 1));
  v27 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v34 )
  {
    v9 = v6 - 1;
    v35 = -1;
  }
  else
  {
    v9 = 0;
    v35 = 1;
  }
  this[31] = a3;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v37 = 0;
  if ( this[26] )
  {
    v26 = 2 * v35;
    v10 = v9 + v35;
    v31 = 16 * v35;
    v11 = 16 * (v9 - v35);
    v12 = (float *)(16 * v9 + a4 + 8);
    v13 = 16 * v10;
    v32 = -8 - a4;
    v28 = v11;
    v36 = v12;
    do
    {
      v14 = (float *)this[14];
      v29 = 0;
      v38 = 0;
      v30 = 3.4028235e38;
      for ( i = v14; ; v14 = i )
      {
        v15 = *(v12 - 1) - v14[1];
        v16 = *v12 - v14[2];
        v17 = *(v12 - 2) - *v14;
        v18 = v16 * v16 + v15 * v15 + v17 * v17;
        if ( v18 < v30 )
        {
          v30 = v18;
          v29 = v38;
        }
        ++v38;
        i += 4;
        if ( v38 >= 0x100 )
          break;
      }
      v25 = (v24 + v12[1]) * 255.0;
      v39 = v25 + *(float *)(v27 + 4 * (v37 & 3));
      v19 = (int)v39;
      if ( this[23] )
      {
        v20 = (v25 - (double)(int)v39) * 0.0039215689;
        *(float *)(this[23] + v11 + 28) = 0.1875 * v20 + *(float *)(this[23] + v11 + 28);
        *(float *)((char *)v36 + v32 + this[23] + 28) = 0.3125 * v20 + *(float *)((char *)v36 + v32 + this[23] + 28);
        *(float *)(this[23] + v13 + 28) = 0.0625 * v20 + *(float *)(this[23] + v13 + 28);
        v24 = v20 * 0.4375;
      }
      v21 = (int)v39;
      if ( v19 >= 255 )
        v21 = 255;
      if ( v21 <= 0 )
      {
        LOBYTE(v19) = 0;
      }
      else if ( v19 >= 255 )
      {
        LOBYTE(v19) = -1;
      }
      v12 = &v36[v31 / 4u];
      v13 += v31;
      LOBYTE(v22) = 0;
      HIBYTE(v22) = v19;
      v36 = (float *)((char *)v36 + v31);
      *v8 = v29 | v22;
      v11 = v31 + v28;
      v8 = (_WORD *)((char *)v8 + v26);
      ++v37;
      v28 += v31;
    }
    while ( v37 < this[26] );
  }
  return this[31];
}
