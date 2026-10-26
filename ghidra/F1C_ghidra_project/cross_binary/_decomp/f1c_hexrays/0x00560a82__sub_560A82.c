// f1c  0x00560a82  size=170
void __cdecl __spoils<ecx> sub_560A82(char *a1, int a2, char *a3, int a4, int a5, int a6, int a7)
{
  int v9; // ecx
  int v10; // ebx
  char *v11; // edi
  char *v12; // esi
  bool v13; // cc
  int v14; // ecx
  int v15; // ebx
  int v16; // edx
  int v17; // eax

  dword_5DD844 = a7 == -1;
  dword_5DD804 = a7 & 0xFFFFFF;
  v9 = a5;
  dword_5DD814 = a5;
  if ( dword_5DD844 == 1 )
  {
    v10 = a6;
    do
    {
      qmemcpy(a3, a1, 4 * v9);
      v12 = &a1[4 * v9];
      v11 = &a3[4 * v9];
      v9 = dword_5DD814;
      a1 = &v12[a2 - 4 * a5];
      a3 = &v11[a4 - 4 * a5];
      v13 = v10-- <= 1;
    }
    while ( !v13 );
  }
  else
  {
    v14 = dword_5DD804;
    do
    {
      v15 = 0;
      v16 = a5;
      do
      {
        v17 = *(_DWORD *)&a1[v15];
        if ( v17 != v14 )
          *(_DWORD *)&a3[v15] = v17;
        v15 += 4;
        v13 = v16-- <= 1;
      }
      while ( !v13 );
      a1 += a2;
      a3 += a4;
      v13 = a6-- <= 1;
    }
    while ( !v13 );
  }
}
