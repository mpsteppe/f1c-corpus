void sub_53CA00()
{
  _BYTE *v0; // ecx
  int v1; // ecx
  int v2; // edx
  int v3; // esi
  int v4; // ebx
  _BYTE *v5; // ecx
  int *v6; // edi
  int v7; // ecx
  int v8; // edi
  int v9; // ebx
  int *v10; // ecx
  int v11; // ecx
  _BYTE v12[4224]; // [esp+0h] [ebp-1080h] BYREF

  v0 = v12;
  do
  {
    TwoFieldInitializer(v0);
    v0 = (_BYTE *)(v1 + 132);
  }
  while ( v2 != 1 );
  v3 = 0;
  v4 = 0;
  if ( dword_8B8E30 > 0 )
  {
    v5 = v12;
    v6 = dword_8B5A38;
    do
    {
      if ( (*v6 & 0x400) == 0 )
      {
        ArithmeticComparison_c6b0(v5, v6);
        ++v3;
        v5 = (_BYTE *)(v7 + 132);
      }
      ++v4;
      v6 += 33;
    }
    while ( v4 < dword_8B8E30 );
  }
  dword_8B8E30 = v3;
  if ( v3 > 0 )
  {
    v8 = 0;
    v9 = v3;
    do
    {
      ArithmeticComparison_c6b0(&dword_8B5A38[v8], &v12[v8 * 4]);
      v8 += 33;
      --v9;
    }
    while ( v9 );
  }
  if ( v3 < 32 )
  {
    v10 = &dword_8B5A38[33 * v3];
    do
    {
      ArithmeticComparison_c6b0(v10, 0);
      v10 = (int *)(v11 + 132);
    }
    while ( (int)v10 < (int)&dword_8B6AB8 );
  }
}
