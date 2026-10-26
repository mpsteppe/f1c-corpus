void __thiscall sub_4D2140(_BYTE *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  signed int v4; // edx
  signed int v5; // edx
  signed int i; // ecx
  float *v7; // eax
  double v8; // st7
  double v9; // st7
  double v10; // st6
  double v11; // st5
  double v12; // st4
  double v13; // st7
  char v14; // al
  long double v15; // st6
  signed int j; // ecx
  signed int v17; // edi
  int v18; // ebx
  char v19; // cl
  float v20; // [esp+Ch] [ebp-1D8h]
  float v21; // [esp+10h] [ebp-1D4h]
  float v22; // [esp+14h] [ebp-1D0h]
  float v23; // [esp+18h] [ebp-1CCh]
  float v24; // [esp+1Ch] [ebp-1C8h]
  float v25; // [esp+24h] [ebp-1C0h]
  float v26[12]; // [esp+28h] [ebp-1BCh] BYREF
  _DWORD v27[51]; // [esp+58h] [ebp-18Ch] BYREF
  float Base[48]; // [esp+124h] [ebp-C0h] BYREF

  v2 = (_DWORD *)sub_40C460(&dword_6291CC);
  v3 = v2;
  if ( !v2 || sub_459B90(v2) && sub_459B90(v3) != 1 )
  {
    v4 = NumOfElements;
LABEL_16:
    if ( v4 > 0 )
      memset(v26, 1u, v4);
    goto LABEL_18;
  }
  v4 = NumOfElements;
  if ( (int)NumOfElements <= dword_7680C0 )
    goto LABEL_16;
  if ( !dword_75AAC4 )
    return;
  v20 = *(float *)(dword_75AAC4 + 17604);
  v21 = *(float *)(dword_75AAC4 + 17608);
  v22 = *(float *)(dword_75AAC4 + 17612);
  sub_459BC0(v3, 0, v27);
  sub_579100(v27, v26);
  v5 = NumOfElements;
  for ( i = 0; i < v5; ++i )
  {
    v7 = (float *)dword_75AAD0[i];
    v8 = v7[4401];
    v7 += 4401;
    v9 = v8 - v20;
    v10 = v7[1] - v21;
    v11 = v7[2] - v22;
    v23 = v26[6] * v11 + v26[3] * v10 + v9 * v26[0];
    v24 = v26[7] * v11 + v26[4] * v10 + v26[1] * v9;
    v12 = v26[8] * v11 + v26[5] * v10 + v26[2] * v9;
    v13 = v12;
    if ( v12 < 0.0 )
      v13 = v12 * 0.40000001;
    v14 = this[i];
    v15 = sqrt(v24 * v24 + v23 * v23 + v13 * v13);
    *(float *)&v27[i + 3] = v15;
    if ( v14 )
      *(float *)&v27[i + 3] = v15 - 5.0;
    Base[i] = *(float *)&v27[i + 3];
  }
  qsort(Base, v5, 4u, (_CoreCrtNonSecureSearchSortCompareFunction)sub_4D1CB0);
  v4 = NumOfElements;
  v25 = Base[dword_7680C0];
  for ( j = 0; j < v4; ++j )
    *((_BYTE *)v26 + j) = *(float *)&v27[j + 3] < (double)v25;
LABEL_18:
  v17 = 0;
  if ( v4 > 0 )
  {
    v18 = this - (_BYTE *)v26;
    do
    {
      v19 = *((_BYTE *)v26 + v17);
      if ( v19 != *((_BYTE *)v26 + v17 + v18) )
      {
        *((_BYTE *)v26 + v17 + v18) = v19;
        if ( v19 )
        {
          sub_50B4E0(*(_DWORD *)(dword_75AAD0[v17] + 4760), 1);
        }
        else
        {
          sub_59ECC0(0, 0, 1, 0);
          sub_59ECC0(1, 0, 0, 0);
          sub_59EF70(0, 1, 0);
        }
        v4 = NumOfElements;
      }
      ++v17;
    }
    while ( v17 < v4 );
  }
}
