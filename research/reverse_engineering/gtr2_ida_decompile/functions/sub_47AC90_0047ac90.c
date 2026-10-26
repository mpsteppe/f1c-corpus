char __thiscall sub_47AC90(float *this, int a2, int a3, int a4)
{
  int v4; // esi
  _DWORD *v7; // esi
  _DWORD *v8; // edi
  int *v9; // esi
  int v10; // ebp
  double v11; // st7
  double v12; // st7
  float *v13; // edx
  int v14; // eax
  int v15; // ecx
  bool v16; // cc
  double v17; // st7
  double v18; // st6
  int v19; // edi
  double v20; // st5
  double v21; // st7
  int v22; // esi
  double v23; // st7
  int v24; // [esp+14h] [ebp-2Ch] BYREF
  int *v25; // [esp+18h] [ebp-28h] BYREF
  int v26; // [esp+1Ch] [ebp-24h]
  _WORD v27[16]; // [esp+20h] [ebp-20h] BYREF

  v4 = a2;
  if ( sub_479D00(*(_DWORD **)this, a2) != -1 )
    return off_16C957C(a2, a3, a4);
  if ( v4 == sub_59B580(*(_DWORD *)(dword_B6CBA8 + 113316)) )
  {
    *(_DWORD *)a3 = 0;
    return 1;
  }
  v24 = v4;
  v7 = *(_DWORD **)this;
  v8 = (_DWORD *)(*(_DWORD *)this + 113304);
  sub_4796F0(v8, &v25, &v24);
  v9 = (int *)v7[28327];
  if ( v25 == v9 )
    goto LABEL_13;
  v10 = *((unsigned __int8 *)this + *((unsigned __int8 *)v25 + 16) + 1692);
  v26 = v10;
  if ( !v10 )
    goto LABEL_13;
  v24 = 0;
  sub_4796F0(v8, &v25, &a2);
  if ( v25 != v9 )
    v24 = *((unsigned __int8 *)v25 + 16);
  if ( this[v24 + 2191] > 0.0 )
  {
    *(float *)a3 = this[v24 + 2191];
    return 1;
  }
  LOBYTE(a2) = v10 == 16;
  if ( (_BYTE)a4 )
  {
    if ( v10 != 16 )
    {
LABEL_13:
      *(_DWORD *)a3 = 1092615143;
      return 0;
    }
  }
  qmemcpy(v27, &this[8 * v24 + 527], sizeof(v27));
  sub_632C60(v27, v10);
  v11 = (double)v26 * 0.33399999;
  if ( v11 < 1.0 )
    v11 = 1.0;
  a4 = (unsigned __int64)v11;
  v12 = 1.0 / (double)a4;
  v13 = (float *)a3;
  v14 = (v10 - a4) / 2;
  v15 = v14 + a4;
  v16 = a4 < 4;
  *(_DWORD *)a3 = 0;
  *(float *)&a4 = v12;
  if ( !v16 )
  {
    v17 = *v13;
    do
    {
      a3 = (__int16)v27[v14 + 3];
      v18 = (double)a3;
      a3 = (__int16)v27[v14 + 2];
      v19 = (__int16)v27[v14 + 1];
      v14 += 4;
      v20 = (double)a3;
      a3 = v19;
      a3 = *((__int16 *)&v25 + v14);
      v17 = v17
          + v18 * 0.001 * *(float *)&a4
          + v20 * 0.001 * *(float *)&a4
          + (double)v19 * 0.001 * *(float *)&a4
          + (double)a3 * 0.001 * *(float *)&a4;
    }
    while ( v14 < v15 - 3 );
    *v13 = v17;
  }
  if ( v14 < v15 )
  {
    v21 = *v13;
    do
    {
      a3 = (__int16)v27[v14++];
      v21 = v21 + (double)a3 * 0.001 * *(float *)&a4;
    }
    while ( v14 < v15 );
    *v13 = v21;
  }
  if ( (_BYTE)a2 )
  {
    v22 = v24;
    this[v24 + 2191] = *v13;
    v23 = this[6];
    if ( v23 < *v13 )
    {
      *((_WORD *)this + v22 + 4798) = (unsigned __int8)(unsigned __int64)((v23 - *v13) * 999.99994 + 0.5);
      return a2;
    }
    *((_WORD *)this + v22 + 4798) = 0;
  }
  return a2;
}
