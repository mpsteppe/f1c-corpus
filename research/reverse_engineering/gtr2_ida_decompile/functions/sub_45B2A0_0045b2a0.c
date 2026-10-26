void __thiscall sub_45B2A0(float *this, _DWORD *a2, int a3, float a4, float a5, char a6)
{
  _DWORD *v6; // ecx
  int v7; // esi
  float *v9; // edx
  double v10; // st7
  double v11; // st6
  unsigned __int8 v13; // c0
  unsigned __int8 v14; // c2
  double v15; // st6
  unsigned __int8 v17; // c0
  unsigned __int8 v18; // c2
  double v19; // st6
  unsigned __int8 v21; // c0
  unsigned __int8 v22; // c2
  int v23; // ebp
  float v25[7]; // [esp+14h] [ebp-38h] BYREF
  float v26[7]; // [esp+30h] [ebp-1Ch] BYREF
  float v27; // [esp+50h] [ebp+4h]
  float v28; // [esp+54h] [ebp+8h]
  float v29; // [esp+54h] [ebp+8h]
  float v30; // [esp+54h] [ebp+8h]

  v6 = a2;
  v7 = 0;
  if ( a2 )
  {
    v9 = (float *)(a3 + 8);
    do
    {
      v10 = -3.4028235e38;
      v27 = 3.4028235e38;
      v11 = a5 * *(float *)(*v6 + 16) + a4 * *(float *)*v6;
      if ( v13 | v14 )
        v27 = v11;
      if ( v11 > -3.4028235e38 )
      {
        v28 = v11;
        v10 = v28;
      }
      v15 = a5 * *(float *)(v6[2] + 16) + a4 * *(float *)v6[2];
      if ( v17 | v18 )
        v27 = v15;
      if ( v15 > v10 )
      {
        v29 = v15;
        v10 = v29;
      }
      v19 = a5 * *(float *)(v6[4] + 16) + a4 * *(float *)v6[4];
      if ( v21 | v22 )
        v27 = v19;
      if ( v19 > v10 )
      {
        v30 = v19;
        v10 = v30;
      }
      *v9 = v10;
      *((_DWORD *)v9 - 2) = v6;
      *(v9 - 1) = v27;
      ++v7;
      v9 += 4;
      *(v9 - 3) = (v10 + v27) * 0.5;
      v6 = (_DWORD *)v6[7];
    }
    while ( v6 );
  }
  sub_632C60(a3, v7);
  v23 = (v7 + 1) / 2;
  if ( v7 / 2 == v23 )
  {
    sub_459D00(this, a3, v7 / 2, v7, a6);
  }
  else
  {
    sub_459D00(v25, a3, v7 / 2, v7, 0);
    sub_459D00(v26, a3, v23, v7, 0);
    if ( v25[6] >= (double)v26[6] )
    {
      if ( a6 )
        sub_459D00(this, a3, v23, v7, 1);
      else
        qmemcpy(this, v26, 0x1Cu);
    }
    else if ( a6 )
    {
      sub_459D00(this, a3, v7 / 2, v7, 1);
    }
    else
    {
      qmemcpy(this, v25, 0x1Cu);
    }
  }
}
