int __thiscall sub_6546E5(_DWORD *this, int a2, int a3, int a4)
{
  char v5; // al
  int v6; // ebx
  int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  int v13; // ebx
  int v14; // edx
  double v15; // st6
  double v16; // st7
  int v17; // ecx
  int v18; // ecx
  __int16 v19; // cx
  char v21; // [esp-4h] [ebp-5Ch]
  float v22; // [esp+Ch] [ebp-4Ch]
  float v23; // [esp+10h] [ebp-48h]
  float v24; // [esp+1Ch] [ebp-3Ch]
  float v25; // [esp+20h] [ebp-38h]
  int v26; // [esp+2Ch] [ebp-2Ch]
  int v27; // [esp+3Ch] [ebp-1Ch]
  int v28; // [esp+4Ch] [ebp-Ch]
  int v29; // [esp+50h] [ebp-8h]
  _WORD *v30; // [esp+54h] [ebp-4h]
  int v31; // [esp+60h] [ebp+8h]
  int v32; // [esp+60h] [ebp+8h]
  int v33; // [esp+64h] [ebp+Ch]
  float v34; // [esp+64h] [ebp+Ch]
  float v35; // [esp+64h] [ebp+Ch]

  if ( this[21] )
    a4 = sub_64EB2A(this, a4);
  if ( this[4] )
    a4 = sub_650093(this, a4);
  v5 = a2;
  v6 = this[26];
  v22 = 0.0;
  v7 = a2 * this[24];
  v23 = 0.0;
  v31 = a2 & 1;
  v30 = (_WORD *)(this[8] + a3 * this[25] + v7 + 2 * v31 * (v6 - 1));
  v28 = this[13] + 4 * ((a3 & 3) + 8 * (v5 & 3));
  if ( v31 )
  {
    v8 = v6 - 1;
    v33 = -1;
    v9 = -1;
  }
  else
  {
    v8 = 0;
    v9 = 1;
    v33 = 1;
  }
  this[31] = v31;
  if ( this[23] )
    sub_6503AF((int)this, a4);
  v32 = 0;
  if ( this[26] )
  {
    v10 = v9;
    v27 = 2 * v9;
    v11 = 16 * v8;
    v12 = 16 * (v8 + v9);
    v29 = 16 * v10;
    v13 = 16 * (v8 - v33);
    while ( 1 )
    {
      v24 = (v22 + *(float *)(v11 + a4)) * 127.0;
      v25 = (v23 + *(float *)(v11 + a4 + 4)) * 127.0;
      v34 = v24 + *(float *)(v28 + 4 * (v32 & 3));
      v26 = (int)v34;
      v35 = v25 + *(float *)(v28 + 4 * (v32 & 3));
      v14 = (int)v35;
      if ( this[23] )
      {
        v15 = (v24 - (double)v26) * 0.0078740157;
        *(float *)(this[23] + v13 + 16) = 0.1875 * v15 + *(float *)(this[23] + v13 + 16);
        *(float *)(v11 + this[23] + 16) = 0.3125 * v15 + *(float *)(v11 + this[23] + 16);
        *(float *)(this[23] + v12 + 16) = 0.0625 * v15 + *(float *)(this[23] + v12 + 16);
        v22 = v15 * 0.4375;
        v16 = 0.0078740157 * (v25 - (double)(int)v35);
        *(float *)(this[23] + v13 + 20) = 0.1875 * v16 + *(float *)(this[23] + v13 + 20);
        *(float *)(v11 + this[23] + 20) = 0.3125 * v16 + *(float *)(v11 + this[23] + 20);
        *(float *)(this[23] + v12 + 20) = 0.0625 * v16 + *(float *)(this[23] + v12 + 20);
        v23 = v16 * 0.4375;
      }
      v17 = v26 >= 127 ? 127 : v26;
      if ( v17 <= -127 )
      {
        LOBYTE(v26) = -127;
      }
      else if ( v26 >= 127 )
      {
        LOBYTE(v26) = 127;
      }
      v18 = v14 >= 127 ? 127 : (int)v35;
      if ( v18 <= -127 )
        break;
      if ( v14 >= 127 )
      {
        v21 = 127;
LABEL_28:
        LOBYTE(v14) = v21;
      }
      LOBYTE(v19) = v26;
      v11 += v29;
      v13 += v29;
      v12 += v29;
      HIBYTE(v19) = v14;
      *v30 = v19;
      v30 = (_WORD *)((char *)v30 + v27);
      if ( (unsigned int)++v32 >= this[26] )
        return this[31];
    }
    v21 = -127;
    goto LABEL_28;
  }
  return this[31];
}
