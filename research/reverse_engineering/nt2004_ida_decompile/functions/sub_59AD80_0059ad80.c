int __thiscall sub_59AD80(int this)
{
  _DWORD *v2; // ebp
  int v3; // ebx
  int v4; // edi
  _DWORD *v5; // edi
  void *v6; // ebx
  int v7; // eax
  char *v8; // edi
  int v9; // ebx

  v2 = (_DWORD *)sub_598170((_DWORD *)dword_7E8E5C);
  v3 = 0;
  if ( *(int *)(this + 280) > 0 )
  {
    v4 = 0;
    do
    {
      sub_599B10(v2, *(_DWORD **)(v4 + *(_DWORD *)(this + 284) + 4));
      *(_DWORD *)(v4 + *(_DWORD *)(this + 284) + 4) = 0;
      sub_5A7DD0(v4 + *(_DWORD *)(this + 284));
      ++v3;
      v4 += 64;
    }
    while ( v3 < *(_DWORD *)(this + 280) );
  }
  v5 = *(_DWORD **)(this + 316);
  while ( v5 )
  {
    v6 = v5;
    v5 = (_DWORD *)v5[9];
    sub_5AD580(v6);
    sub_5BE8AE();
  }
  v7 = *(_DWORD *)(this + 272);
  if ( v7 )
  {
    v8 = (char *)(v7 + 56 * *(_DWORD *)(v7 - 4));
    if ( *(_DWORD *)(v7 - 4) - 1 >= 0 )
    {
      v9 = *(_DWORD *)(v7 - 4);
      do
      {
        v8 -= 56;
        nullsub_6(v8);
        --v9;
      }
      while ( v9 );
    }
    sub_5BE8AE();
    *(_DWORD *)(this + 272) = 0;
  }
  if ( *(_DWORD *)(this + 324) )
  {
    nullsub_6(*(void **)(this + 324));
    sub_5BE8AE();
    *(_DWORD *)(this + 324) = 0;
  }
  return 0;
}
