void __fastcall sub_6155E0(int a1, int a2, double a3, int a4, int a5)
{
  int v5; // edi
  double *v6; // ebx
  int v7; // edx
  unsigned int v8; // esi
  double *v9; // edi
  int v10; // edx
  double *v11; // esi
  int v12; // ebp
  int v13; // [esp+0h] [ebp-4h]
  int v14; // [esp+10h] [ebp+Ch]

  v13 = a2;
  v5 = a4;
  if ( a5 - a4 + 1 >= 4 )
  {
    v6 = (double *)(a2 + 8 * a4 + 24);
    v7 = a2 - a1;
    v8 = ((unsigned int)(a5 - a4 - 3) >> 2) + 1;
    v9 = (double *)(a1 + 8 * a4 + 8);
    v14 = a4 + 4 * v8;
    do
    {
      if ( *(v6 - 3) != 0.0 )
        *(v9 - 1) = a3 * *(v6 - 3) + *(v9 - 1);
      if ( *(double *)((char *)v9 + v7) != 0.0 )
        *v9 = a3 * *(double *)((char *)v9 + v7) + *v9;
      if ( *(v6 - 1) != 0.0 )
        v9[1] = a3 * *(v6 - 1) + v9[1];
      if ( *v6 != 0.0 )
        v9[2] = a3 * *v6 + v9[2];
      v9 += 4;
      v6 += 4;
      --v8;
    }
    while ( v8 );
    v5 = v14;
    a2 = v13;
  }
  if ( v5 <= a5 )
  {
    v10 = a2 - a1;
    v11 = (double *)(a1 + 8 * v5);
    v12 = a5 - v5 + 1;
    do
    {
      if ( *(double *)((char *)v11 + v10) != 0.0 )
        *v11 = a3 * *(double *)((char *)v11 + v10) + *v11;
      ++v11;
      --v12;
    }
    while ( v12 );
  }
}
