void __thiscall sub_44C710(float *this, int a2, float *Base, float a4, float a5, char a6)
{
  int v6; // ecx
  signed int v7; // esi
  float *v9; // edx
  double v10; // st7
  int i; // ebx
  double v12; // st6
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c2
  int v16; // ebp
  float v18[7]; // [esp+14h] [ebp-38h] BYREF
  float v19[7]; // [esp+30h] [ebp-1Ch] BYREF
  float v20; // [esp+50h] [ebp+4h]
  float Basea; // [esp+54h] [ebp+8h]

  v6 = a2;
  v7 = 0;
  if ( a2 )
  {
    v9 = Base + 2;
    do
    {
      v10 = -3.4028235e38;
      v20 = 3.4028235e38;
      for ( i = 0; i < 3; ++i )
      {
        v12 = a5 * *(float *)(*(_DWORD *)(v6 + 8 * i) + 12) + a4 * **(float **)(v6 + 8 * i);
        if ( v14 | v15 )
          v20 = v12;
        if ( v12 > v10 )
        {
          Basea = v12;
          v10 = Basea;
        }
      }
      *v9 = v10;
      *((_DWORD *)v9 - 2) = v6;
      *(v9 - 1) = v20;
      ++v7;
      v9 += 4;
      *(v9 - 3) = (v10 + v20) * 0.5;
      v6 = *(_DWORD *)(v6 + 28);
    }
    while ( v6 );
  }
  qsort(Base, v7, 0x10u, (_CoreCrtNonSecureSearchSortCompareFunction)sub_44C570);
  v16 = (v7 + 1) / 2;
  if ( v7 / 2 == v16 )
  {
    sub_44C5B0(this, (int)Base, v7 / 2, v7, a6);
  }
  else
  {
    sub_44C5B0(v18, (int)Base, v7 / 2, v7, 0);
    sub_44C5B0(v19, (int)Base, v16, v7, 0);
    if ( v18[6] >= (double)v19[6] )
    {
      if ( a6 )
        sub_44C5B0(this, (int)Base, v16, v7, 1);
      else
        qmemcpy(this, v19, 0x1Cu);
    }
    else if ( a6 )
    {
      sub_44C5B0(this, (int)Base, v7 / 2, v7, 1);
    }
    else
    {
      qmemcpy(this, v18, 0x1Cu);
    }
  }
}
