int __thiscall sub_5AF360(int this)
{
  _DWORD *v2; // ebx
  int v3; // ebp
  int v4; // edi
  int v5; // ecx
  char *v6; // edi
  int v7; // ebx
  int v8; // eax
  char *v9; // edi
  int v10; // ebx

  v2 = (_DWORD *)sub_598170((_DWORD *)dword_7E8E5C);
  v3 = 0;
  if ( *(int *)(this + 76) > 0 )
  {
    v4 = 0;
    do
    {
      if ( *(_DWORD *)(v4 + *(_DWORD *)(this + 80) + 4) )
      {
        sub_599B10(v2, *(_DWORD **)(v4 + *(_DWORD *)(this + 80) + 4));
        *(_DWORD *)(v4 + *(_DWORD *)(this + 80) + 4) = 0;
      }
      if ( (*(_BYTE *)(this + 32) & 8) != 0 )
        sub_5A7DD0(dword_7E6B48, (_DWORD *)(v4 + *(_DWORD *)(this + 80)));
      if ( *(_DWORD *)(v4 + *(_DWORD *)(this + 80) + 20) )
        sub_5BE8AE();
      if ( *(_DWORD *)(v4 + *(_DWORD *)(this + 80) + 12) )
        sub_5BE8AE();
      ++v3;
      v4 += 64;
    }
    while ( v3 < *(_DWORD *)(this + 76) );
  }
  sub_5AF4E0(this);
  v5 = *(_DWORD *)(this + 80);
  if ( v5 )
  {
    v6 = (char *)(v5 + (*(_DWORD *)(v5 - 4) << 6));
    if ( *(_DWORD *)(v5 - 4) - 1 >= 0 )
    {
      v7 = *(_DWORD *)(v5 - 4);
      do
      {
        v6 -= 64;
        nullsub_6(v6);
        --v7;
      }
      while ( v7 );
    }
    sub_5BE8AE();
  }
  v8 = *(_DWORD *)(this + 52);
  if ( v8 )
  {
    v9 = (char *)(v8 + (*(_DWORD *)(v8 - 4) << 7));
    if ( *(_DWORD *)(v8 - 4) - 1 >= 0 )
    {
      v10 = *(_DWORD *)(v8 - 4);
      do
      {
        v9 -= 128;
        sub_5AF2B0(v9);
        --v10;
      }
      while ( v10 );
    }
    sub_5BE8AE();
  }
  if ( *(_DWORD *)(this + 64) )
    sub_5BE8AE();
  if ( *(_DWORD *)(this + 60) )
    sub_5BE8AE();
  if ( *(_DWORD *)(this + 68) )
    sub_5BE8AE();
  if ( *(_DWORD *)(this + 72) )
    sub_5BE8AE();
  return 0;
}
