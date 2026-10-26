void __cdecl __spoils<ecx> sub_560410(char *a1, int a2, char *a3, int a4, int a5, int a6, unsigned __int16 a7)
{
  int v9; // ebx
  unsigned int v10; // eax
  __int16 v11; // cx
  unsigned int v12; // ecx
  char *v13; // edi
  char *v14; // esi
  unsigned int v15; // ecx
  bool v16; // cc
  int v17; // ebx
  int v18; // edx
  unsigned int v19; // eax
  int v20; // edx
  unsigned int v21; // eax

  dword_5DD804 = a7;
  v9 = a6;
  v10 = 2 * a5;
  if ( a7 == 0xFFFF )
  {
    v11 = 2 * a5;
    if ( (v10 & 7) == 0 )
    {
      v12 = v10 >> 2;
      do
      {
        qmemcpy(a3, a1, 4 * v12);
        v14 = &a1[4 * v12];
        v13 = &a3[4 * v12];
        v15 = v10 & 3;
        if ( (v10 & 3) != 0 )
        {
          qmemcpy(v13, v14, v15);
          v14 += v15;
          v13 += v15;
        }
        a1 = &v14[a2 - v10];
        v12 = v10 >> 2;
        a3 = &v13[a4 - v10];
        v16 = v9-- <= 1;
      }
      while ( !v16 );
      return;
    }
  }
  else
  {
    v11 = dword_5DD804;
  }
  do
  {
    v17 = 0;
    v18 = a5;
    do
    {
      v19 = *(_DWORD *)&a1[v17];
      if ( (_WORD)v19 != v11 )
        *(_WORD *)&a3[v17] = v19;
      v16 = v18 <= 1;
      v20 = v18 - 1;
      if ( v16 )
        break;
      v21 = HIWORD(v19);
      if ( (_WORD)v21 != v11 )
        *(_WORD *)&a3[v17 + 2] = v21;
      v17 += 4;
      v16 = v20 <= 1;
      v18 = v20 - 1;
    }
    while ( !v16 );
    a1 += a2;
    a3 += a4;
    v16 = a6-- <= 1;
  }
  while ( !v16 );
}
