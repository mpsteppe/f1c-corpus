int __thiscall sub_65D5D6(int this, unsigned int a2, unsigned int *a3)
{
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // esi
  int v9; // edx
  void *v10; // eax
  int v11; // eax
  int v12; // eax
  void *v13; // edi
  unsigned int i; // edx
  int v15; // ecx
  int v17; // [esp+Ch] [ebp-Ch]
  void *v18; // [esp+10h] [ebp-8h]
  unsigned int v19; // [esp+14h] [ebp-4h]

  v4 = *(_DWORD *)(this + 20);
  v5 = v4;
  v6 = 0;
  v7 = v4 >> 1;
  v17 = 0;
  v19 = v4 >> 1;
  if ( !v4 )
    goto LABEL_8;
  do
  {
    v8 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v7);
    if ( a2 <= v8 )
    {
      if ( a2 >= v8 )
        break;
      v5 = v7;
    }
    else
    {
      v6 = v7 + 1;
    }
    v7 = (v5 + v6) >> 1;
    v19 = v7;
  }
  while ( v6 < v5 );
  if ( v6 >= v5 )
  {
LABEL_8:
    if ( v4 == (v4 & -v4) )
    {
      if ( v4 )
        v9 = 2 * v4;
      else
        v9 = 1;
      v10 = operator new(4 * v9);
      v18 = v10;
      if ( !v10
        || ((qmemcpy(v10, *(const void **)(this + 28), 4 * *(_DWORD *)(this + 20)),
             j__free(*(void **)(this + 28)),
             *(_DWORD *)(this + 28) = v18,
             (v11 = *(_DWORD *)(this + 20)) == 0)
          ? (v12 = 1)
          : (v12 = 2 * v11),
            (v13 = operator new(4 * v12)) == 0) )
      {
        v17 = -2147024882;
        goto LABEL_25;
      }
      qmemcpy(v13, *(const void **)(this + 24), 4 * *(_DWORD *)(this + 20));
      j__free(*(void **)(this + 24));
      *(_DWORD *)(this + 24) = v13;
      v7 = v19;
    }
    for ( i = *(_DWORD *)(this + 20); ; --i )
    {
      v15 = *(_DWORD *)(this + 24);
      if ( i <= v7 )
        break;
      *(_DWORD *)(v15 + 4 * i) = *(_DWORD *)(v15 + 4 * i - 4);
      *(_DWORD *)(*(_DWORD *)(this + 28) + 4 * i) = *(_DWORD *)(*(_DWORD *)(this + 28) + 4 * i - 4);
    }
    *(_DWORD *)(v15 + 4 * v7) = a2;
    *(_DWORD *)(*(_DWORD *)(this + 28) + 4 * v7) = 1;
    ++*(_DWORD *)(this + 20);
  }
  if ( a3 )
    *a3 = v7;
LABEL_25:
  j__free(0);
  return v17;
}
