int __thiscall sub_54FDA0(int this, int a2, int a3)
{
  int result; // eax

  if ( *(_DWORD *)(this + 76) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 76));
  *(_DWORD *)(this + 76) = OperatorNewNhMallocWrapper(4 * a3);
  for ( result = 0; result < a3; ++result )
    *(_DWORD *)(*(_DWORD *)(this + 76) + 4 * result) = *(_DWORD *)(a2 + 4 * result);
  *(_DWORD *)(this + 80) = a3;
  return result;
}

