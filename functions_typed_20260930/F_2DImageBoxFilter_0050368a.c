int __cdecl sub_50368A(unsigned int *a1, unsigned int a2, int a3, int a4, int a5, int a6)
{
  int v6; // eax
  unsigned int v7; // edi
  _DWORD *v8; // esi
  unsigned int v9; // ebx
  unsigned int *v10; // eax
  bool v11; // zf
  unsigned int v13; // [esp+4h] [ebp-18h]
  unsigned int v14; // [esp+Ch] [ebp-10h]
  unsigned int *v15; // [esp+18h] [ebp-4h]
  unsigned int v16; // [esp+30h] [ebp+14h]

  v6 = a5;
  v7 = a2;
  v13 = a2 + a5 * a4;
  if ( a2 < v13 )
  {
    v16 = a2 + 4 * a3;
    do
    {
      v15 = a1;
      if ( v7 < v16 )
      {
        v8 = (_DWORD *)(v7 + 4);
        v14 = ((v16 - v7 - 1) >> 3) + 1;
        do
        {
          v9 = ((*(_DWORD *)((char *)v8 + v6) & 0xFF00)
              + (*(_DWORD *)((char *)v8 + v6 - 4) & 0xFF00)
              + (*(v8 - 1) & 0xFF00)
              + (*v8 & 0xFF00)
              + 512)
             & 0x3FC00
             | ((*(_DWORD *)((char *)v8 + v6) & 0xFF00FF)
              + (*(_DWORD *)((char *)v8 + v6 - 4) & 0xFF00FF)
              + (*(v8 - 1) & 0xFF00FF)
              + (*v8 & 0xFF00FF)
              + 131074)
             & 0x3FC03FC;
          v10 = v15++;
          v8 += 2;
          v11 = v14-- == 1;
          *v10 = v9 >> 2;
          v6 = a5;
        }
        while ( !v11 );
        v7 = a2;
      }
      a1 = (unsigned int *)((char *)a1 + a6);
      v16 += 2 * v6;
      v7 += 2 * v6;
      a2 = v7;
    }
    while ( v7 < v13 );
  }
  return 0;
}

