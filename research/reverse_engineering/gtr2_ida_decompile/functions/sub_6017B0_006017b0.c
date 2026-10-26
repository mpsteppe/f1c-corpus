int __cdecl sub_6017B0(int a1, char *a2, int a3, char *a4, int a5, int a6, int a7, int a8)
{
  int v10; // ecx
  int v11; // ebx
  char *v12; // edi
  char *v13; // esi
  bool v14; // cc
  int v15; // ebx
  int v16; // edx
  int result; // eax

  v10 = a6;
  if ( a8 == -1 )
  {
    v11 = a7;
    do
    {
      qmemcpy(a4, a2, 4 * v10);
      v13 = &a2[4 * v10];
      v12 = &a4[4 * v10];
      v10 = a6;
      a2 = &v13[a3 - 4 * a6];
      a4 = &v12[a5 - 4 * a6];
      v14 = v11-- <= 1;
    }
    while ( !v14 );
  }
  do
  {
    v15 = 0;
    v16 = a6;
    do
    {
      result = *(_DWORD *)&a2[v15];
      if ( result != ((unsigned int)byte_FFFFFF & a8) )
        *(_DWORD *)&a4[v15] = result;
      v15 += 4;
      v14 = v16-- <= 1;
    }
    while ( !v14 );
    a2 += a3;
    a4 += a5;
    v14 = a7-- <= 1;
  }
  while ( !v14 );
  return result;
}
