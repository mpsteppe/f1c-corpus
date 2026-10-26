char __thiscall sub_59B530(int this)
{
  unsigned int v2; // edx
  unsigned int v3; // eax
  int v4; // ecx
  unsigned int i; // edi
  _WORD *v6; // eax
  _WORD *v7; // ebp
  unsigned int v8; // ecx
  unsigned int j; // eax

  v2 = *(_DWORD *)(this + 12);
  v3 = *(_DWORD *)(this + 20) + 1;
  if ( v3 <= v2 )
    return 1;
  v4 = *(_DWORD *)(this + 28);
  for ( i = v4 + v2; i < v3; i += v4 )
    ;
  v6 = (_WORD *)OperatorNewNhMallocWrapper(4 * i);
  v7 = v6;
  if ( v6 )
  {
    if ( (int)(i - 1) >= 0 )
    {
      v8 = i;
      do
      {
        v6[1] = 0;
        *v6 = 0;
        v6 += 2;
        --v8;
      }
      while ( v8 );
    }
    for ( j = 0; j < *(_DWORD *)(this + 20); *(_DWORD *)&v7[2 * j - 2] = *(_DWORD *)(*(_DWORD *)(this + 8) + 4 * j - 4) )
      ++j;
    FreeWrapper_7bcf(*(LPVOID *)(this + 8));
    *(_DWORD *)(this + 8) = v7;
    *(_DWORD *)(this + 12) = i;
    return 1;
  }
  return 0;
}

