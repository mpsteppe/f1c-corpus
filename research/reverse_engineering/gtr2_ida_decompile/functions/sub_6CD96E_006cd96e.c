int __thiscall sub_6CD96E(int this)
{
  unsigned int i; // eax
  int v3; // edi
  int result; // eax

  sub_6CD3BF((_DWORD *)this, (_DWORD *)(this + 80), (unsigned int *)(this + 76));
  for ( i = 0; i < *(_DWORD *)(this + 56); ++i )
  {
    *(_DWORD *)(*(_DWORD *)(this + 48) + 4 * i) = i;
    *(_DWORD *)(*(_DWORD *)(this + 64) + 4 * i) = *(_DWORD *)(*(_DWORD *)(this + 60) + 4 * i);
  }
  sub_682274(sub_6CD318, *(int **)(this + 48), *(_DWORD *)(this + 56), this);
  v3 = 0;
  if ( !*(_DWORD *)(this + 56) )
    return 1;
  while ( 1 )
  {
    result = sub_6CD4DC(this, *(_DWORD *)(*(_DWORD *)(this + 48) + 4 * v3));
    if ( result < 0 )
      break;
    if ( !result )
      return 0;
    if ( (unsigned int)++v3 >= *(_DWORD *)(this + 56) )
      return 1;
  }
  return result;
}
