int __thiscall sub_6CD9DB(int this, int a2)
{
  unsigned int v2; // ebx
  int v4; // ecx
  void *v5; // eax
  void *v6; // eax
  int v7; // edi
  void *v8; // eax
  void *v9; // eax
  int v10; // ecx
  int v11; // edi
  unsigned int v12; // edx
  int v13; // eax
  void *v14; // eax
  void *v15; // eax
  void *v16; // eax
  void *v17; // eax
  int v18; // edi
  void *v19; // eax
  void *v20; // eax
  void *v21; // eax
  void *v22; // eax
  int v23; // edi
  int v24; // ecx
  int v25; // eax
  int v26; // edi
  void *v27; // eax
  void *v28; // eax
  void *v29; // eax
  int result; // eax
  unsigned int k; // eax
  size_t v32; // [esp-4h] [ebp-18h]
  size_t Size; // [esp+Ch] [ebp-8h]
  size_t Sizea; // [esp+Ch] [ebp-8h]
  int Sizeb; // [esp+Ch] [ebp-8h]
  size_t Sizec; // [esp+Ch] [ebp-8h]
  size_t Sized; // [esp+Ch] [ebp-8h]
  size_t Sizee; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]
  unsigned int j; // [esp+10h] [ebp-4h]

  v2 = 0;
  v4 = *(_DWORD *)(this + 4);
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  *(_DWORD *)(this + 44) = 0;
  *(_DWORD *)(this + 48) = 0;
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 56) = *(_DWORD *)(v4 + 12);
  sub_686074(v4);
  v5 = operator new(4 * *(_DWORD *)(this + 56));
  *(_DWORD *)(this + 8) = v5;
  if ( !v5 )
    goto LABEL_48;
  v6 = operator new(4 * *(_DWORD *)(this + 56));
  *(_DWORD *)(this + 28) = v6;
  if ( !v6 )
    goto LABEL_48;
  memset(*(void **)(this + 8), 0, 4 * *(_DWORD *)(this + 56));
  memset(*(void **)(this + 28), 0, 4 * *(_DWORD *)(this + 56));
  for ( i = 0; i < *(_DWORD *)(this + 56); ++i )
  {
    v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 4) + 24) + 4 * i);
    if ( (*(_WORD *)(v7 + 2) & 0xFFF0) != 0 )
    {
      for ( Size = 0; Size < *(_DWORD *)(v7 + 12); ++Size )
        sub_6CD265((_DWORD *)this, i, *(_DWORD *)(*(_DWORD *)(v7 + 16) + 4 * Size));
      for ( Sizea = 0; Sizea < *(_DWORD *)(v7 + 4); ++Sizea )
        sub_6CD1F0((_DWORD *)this, i, *(_DWORD *)(*(_DWORD *)(v7 + 8) + 4 * Sizea));
    }
  }
  v8 = operator new(4 * *(_DWORD *)(this + 56));
  *(_DWORD *)(this + 12) = v8;
  if ( !v8 )
    goto LABEL_48;
  v9 = operator new(4 * *(_DWORD *)(this + 56));
  *(_DWORD *)(this + 32) = v9;
  if ( !v9 )
    goto LABEL_48;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  if ( *(_DWORD *)(this + 56) )
  {
    do
    {
      v13 = 4 * v12;
      *(_DWORD *)(v13 + *(_DWORD *)(this + 12)) = v10;
      v10 += *(_DWORD *)(4 * v12 + *(_DWORD *)(this + 8));
      *(_DWORD *)(v13 + *(_DWORD *)(this + 32)) = v11;
      v11 += *(_DWORD *)(4 * v12++ + *(_DWORD *)(this + 28));
    }
    while ( v12 < *(_DWORD *)(this + 56) );
    v2 = 0;
  }
  Sizeb = 4 * v10;
  v14 = operator new(4 * v10);
  *(_DWORD *)(this + 16) = v14;
  if ( !v14 )
    goto LABEL_48;
  v15 = operator new(Sizeb);
  *(_DWORD *)(this + 20) = v15;
  if ( !v15 )
    goto LABEL_48;
  v16 = operator new(Sizeb);
  *(_DWORD *)(this + 24) = v16;
  if ( !v16 )
    goto LABEL_48;
  v17 = operator new(4 * v11);
  *(_DWORD *)(this + 36) = v17;
  if ( !v17 )
    goto LABEL_48;
  memset(*(void **)(this + 8), 0, 4 * *(_DWORD *)(this + 56));
  memset(*(void **)(this + 28), 0, 4 * *(_DWORD *)(this + 56));
  for ( j = 0; j < *(_DWORD *)(this + 56); ++j )
  {
    v18 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 4) + 24) + 4 * j);
    if ( (*(_WORD *)(v18 + 2) & 0xFFF0) != 0 )
    {
      for ( Sizec = 0; Sizec < *(_DWORD *)(v18 + 4); ++Sizec )
        sub_6CD1F0((_DWORD *)this, j, *(_DWORD *)(*(_DWORD *)(v18 + 8) + 4 * Sizec));
      for ( Sized = 0; Sized < *(_DWORD *)(v18 + 12); ++Sized )
        sub_6CD265((_DWORD *)this, j, *(_DWORD *)(*(_DWORD *)(v18 + 16) + 4 * Sized));
    }
  }
  for ( Sizee = 0; Sizee < *(_DWORD *)(this + 56); ++Sizee )
  {
    sub_6CD379(
      (int *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(4 * Sizee + *(_DWORD *)(this + 12))),
      (unsigned int *)(4 * Sizee + *(_DWORD *)(this + 8)));
    sub_6CD379(
      (int *)(*(_DWORD *)(this + 36) + 4 * *(_DWORD *)(4 * Sizee + *(_DWORD *)(this + 32))),
      (unsigned int *)(4 * Sizee + *(_DWORD *)(this + 28)));
  }
  v19 = operator new(4 * *(_DWORD *)(this + 56));
  *(_DWORD *)(this + 60) = v19;
  if ( !v19 )
    goto LABEL_48;
  v20 = operator new(4 * *(_DWORD *)(this + 56));
  *(_DWORD *)(this + 64) = v20;
  if ( !v20 )
    goto LABEL_48;
  v21 = operator new(4 * *(_DWORD *)(this + 56));
  *(_DWORD *)(this + 68) = v21;
  if ( !v21 )
    goto LABEL_48;
  v22 = operator new(4 * *(_DWORD *)(this + 56));
  *(_DWORD *)(this + 52) = v22;
  if ( !v22 )
    goto LABEL_48;
  if ( *(_DWORD *)(this + 56) )
  {
    do
    {
      v23 = 4 * v2;
      v24 = *(_DWORD *)(4 * v2 + *(_DWORD *)(*(_DWORD *)(this + 4) + 24));
      *(_DWORD *)(v23 + *(_DWORD *)(this + 60)) = v2;
      *(_DWORD *)(v23 + *(_DWORD *)(this + 68)) = v24;
      *(_DWORD *)(v24 + 36) = -1;
      if ( (*(_WORD *)(v24 + 2) & 0xFFF0) == 0 || (v25 = sub_680F76((_DWORD *)v24)) != 0 )
        v25 = 1;
      ++v2;
      *(_DWORD *)(v23 + *(_DWORD *)(this + 52)) = v25;
    }
    while ( v2 < *(_DWORD *)(this + 56) );
  }
  v26 = 0;
  v32 = 4 * *(_DWORD *)(this + 56);
  *(_DWORD *)(this + 72) = 0;
  v27 = operator new(v32);
  *(_DWORD *)(this + 40) = v27;
  if ( !v27
    || (v28 = operator new(4 * *(_DWORD *)(this + 56)), (*(_DWORD *)(this + 44) = v28) == 0)
    || (v29 = operator new(4 * *(_DWORD *)(this + 56)), (*(_DWORD *)(this + 48) = v29) == 0) )
  {
LABEL_48:
    v26 = -2147024882;
    goto LABEL_49;
  }
  if ( !a2 )
  {
LABEL_49:
    j__free(*(void **)(this + 8));
    j__free(*(void **)(this + 12));
    j__free(*(void **)(this + 16));
    j__free(*(void **)(this + 20));
    j__free(*(void **)(this + 24));
    j__free(*(void **)(this + 28));
    j__free(*(void **)(this + 32));
    j__free(*(void **)(this + 36));
    j__free(*(void **)(this + 40));
    j__free(*(void **)(this + 44));
    j__free(*(void **)(this + 48));
    j__free(*(void **)(this + 52));
    j__free(*(void **)(this + 60));
    j__free(*(void **)(this + 64));
    j__free(*(void **)(this + 68));
    return v26;
  }
  while ( 1 )
  {
    result = sub_6CD96E(this);
    if ( result < 0 )
      return result;
    if ( result == 1 )
    {
      for ( k = 0; k < *(_DWORD *)(this + 56); ++k )
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 4) + 24) + 4 * k) = *(_DWORD *)(*(_DWORD *)(this + 68)
                                                                                 + 4
                                                                                 * *(_DWORD *)(*(_DWORD *)(this + 60)
                                                                                             + 4 * k));
      goto LABEL_49;
    }
  }
}
