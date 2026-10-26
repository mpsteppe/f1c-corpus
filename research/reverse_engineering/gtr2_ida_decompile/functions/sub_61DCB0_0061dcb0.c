int __thiscall sub_61DCB0(int this, int a2)
{
  int i; // eax
  int j; // eax
  int result; // eax

  if ( *(_DWORD *)(this + 48) )
    return (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 48) + 24))(*(_DWORD *)(this + 48), a2);
  for ( i = 0; i < *(_DWORD *)(this + 32); ++i )
    *(double *)(*(_DWORD *)(*(_DWORD *)(this + 40) + 4 * a2) + 8 * i) = 0.0;
  for ( j = 0; j < *(_DWORD *)(this + 32); ++j )
    *(double *)(*(_DWORD *)(*(_DWORD *)(this + 40) + 4 * j) + 8 * a2) = 0.0;
  result = *(_DWORD *)(*(_DWORD *)(this + 40) + 4 * a2);
  *(double *)(result + 8 * a2) = 1.0;
  *(double *)(*(_DWORD *)(this + 44) + 8 * a2) = 0.0;
  return result;
}
