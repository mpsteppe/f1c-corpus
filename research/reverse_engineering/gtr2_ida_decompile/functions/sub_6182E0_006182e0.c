char __thiscall sub_6182E0(int this)
{
  unsigned int v2; // edx
  unsigned int v3; // eax
  int v4; // ecx
  unsigned int i; // edi
  _DWORD *v6; // eax
  _DWORD *v7; // ebp
  unsigned int j; // eax

  v2 = *(_DWORD *)(this + 12);
  v3 = *(_DWORD *)(this + 20) + 1;
  if ( v3 <= v2 )
    return 1;
  v4 = *(_DWORD *)(this + 28);
  for ( i = v4 + v2; i < v3; i += v4 )
    ;
  v6 = operator new(4 * i);
  v7 = v6;
  if ( v6 )
    sub_41D1B0((int)v6, 4, i, (int)sub_618030);
  else
    v7 = 0;
  if ( !v7 )
    return 0;
  for ( j = 0; j < *(_DWORD *)(this + 20); ++j )
    v7[j] = *(_DWORD *)(*(_DWORD *)(this + 8) + 4 * j);
  j__free(*(void **)(this + 8));
  *(_DWORD *)(this + 8) = v7;
  *(_DWORD *)(this + 12) = i;
  return 1;
}
