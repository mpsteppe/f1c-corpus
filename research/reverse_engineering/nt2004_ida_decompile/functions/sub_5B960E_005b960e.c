void __cdecl __spoils<ecx> sub_5B960E(char *a1, int a2, char *a3, int a4, int a5, int a6, int a7)
{
  unsigned int v10; // ecx
  char *v11; // edi
  char *v12; // esi
  bool v13; // cc
  int v14; // eax
  int v15; // edx
  _BYTE *v16; // esi
  int v17; // [esp+14h] [ebp+Ch]
  int v18; // [esp+1Ch] [ebp+14h]

  dword_61D434 = a7 & 0xFFFFFF;
  dword_61D444 = 3 * a5;
  v17 = a2 - 3 * a5;
  v18 = a4 - 3 * a5;
  if ( (a7 & 0xFFFFFF) == 0xFFFFFF )
  {
    v10 = dword_61D444;
    do
    {
      qmemcpy(a3, a1, v10);
      v12 = &a1[v10];
      v11 = &a3[v10];
      v10 = dword_61D444;
      a1 = &v12[v17];
      a3 = &v11[v18];
      v13 = a6-- <= 1;
    }
    while ( !v13 );
  }
  else
  {
    do
    {
      HIWORD(v14) = 0;
      v15 = a5;
      do
      {
        LOWORD(v14) = *(_WORD *)a1;
        v16 = a1 + 2;
        v14 <<= 16;
        LOBYTE(v14) = *v16;
        a1 = v16 + 1;
        if ( v14 != dword_61D434 )
          *(_DWORD *)a3 = v14;
        a3 += 3;
        v13 = v15-- <= 1;
      }
      while ( !v13 );
      a1 += v17;
      a3 += v18;
      v13 = a6-- <= 1;
    }
    while ( !v13 );
  }
}
