int __thiscall sub_5574B0(int this)
{
  _DWORD *v2; // ebx
  int v3; // ebp
  int v4; // edi
  int v5; // ecx
  int v6; // ecx
  void *v7; // ebp
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  void *v11; // ebp
  int v12; // edi
  int v13; // ebx
  void *v14; // esi

  v2 = (_DWORD *)sub_545F40((_DWORD *)dword_8B8F28);
  v3 = 0;
  if ( *(int *)(this + 76) > 0 )
  {
    v4 = 0;
    do
    {
      if ( *(_DWORD *)(v4 + *(_DWORD *)(this + 80) + 4) )
      {
        sub_547710(v2, *(_DWORD **)(v4 + *(_DWORD *)(this + 80) + 4));
        *(_DWORD *)(v4 + *(_DWORD *)(this + 80) + 4) = 0;
      }
      if ( (*(_BYTE *)(this + 32) & 8) != 0 )
        sub_540CB0(dword_8B78A0, v4 + *(_DWORD *)(this + 80));
      if ( *(_DWORD *)(v4 + *(_DWORD *)(this + 80) + 20) )
        sub_587BCF(*(LPVOID *)(v4 + *(_DWORD *)(this + 80) + 20));
      v5 = *(_DWORD *)(this + 80);
      if ( *(_DWORD *)(v4 + v5 + 12) )
        sub_587BCF(*(LPVOID *)(v4 + v5 + 12));
      ++v3;
      v4 += 64;
    }
    while ( v3 < *(_DWORD *)(this + 76) );
  }
  sub_557630(this);
  v6 = *(_DWORD *)(this + 80);
  if ( v6 )
  {
    v7 = (void *)(v6 - 4);
    v8 = v6 + (*(_DWORD *)(v6 - 4) << 6);
    if ( *(_DWORD *)(v6 - 4) - 1 >= 0 )
    {
      v9 = *(_DWORD *)(v6 - 4);
      do
      {
        v8 -= 64;
        nullsub_3();
        --v9;
      }
      while ( v9 );
    }
    sub_587BCF(v7);
  }
  v10 = *(_DWORD *)(this + 52);
  if ( v10 )
  {
    v11 = (void *)(v10 - 4);
    v12 = v10 + (*(_DWORD *)(v10 - 4) << 7);
    if ( *(_DWORD *)(v10 - 4) - 1 >= 0 )
    {
      v13 = *(_DWORD *)(v10 - 4);
      do
      {
        v12 -= 128;
        sub_5573F0();
        --v13;
      }
      while ( v13 );
    }
    sub_587BCF(v11);
  }
  if ( *(_DWORD *)(this + 64) )
    sub_587BCF(*(LPVOID *)(this + 64));
  if ( *(_DWORD *)(this + 60) )
    sub_587BCF(*(LPVOID *)(this + 60));
  if ( *(_DWORD *)(this + 68) )
    sub_587BCF(*(LPVOID *)(this + 68));
  v14 = *(void **)(this + 72);
  if ( v14 )
    sub_587BCF(v14);
  return 0;
}
