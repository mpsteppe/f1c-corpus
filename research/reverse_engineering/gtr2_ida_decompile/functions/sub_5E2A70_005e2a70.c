int __thiscall sub_5E2A70(int this, int a2, int a3)
{
  int result; // eax

  if ( *(_DWORD *)(this + 76) )
    j__free(*(void **)(this + 76));
  *(_DWORD *)(this + 76) = operator new(4 * a3);
  for ( result = 0; result < a3; ++result )
    *(_DWORD *)(*(_DWORD *)(this + 76) + 4 * result) = *(_DWORD *)(a2 + 4 * result);
  *(_DWORD *)(this + 80) = a3;
  return result;
}
