_DWORD *__thiscall ObjectAllocator(_DWORD *this)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)OperatorNewNhMallocWrapper(812);
  if ( v2 )
    *this = ShortComputation_bb40(v2);
  else
    *this = 0;
  return this;
}

