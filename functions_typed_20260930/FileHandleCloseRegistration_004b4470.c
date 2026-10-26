char __thiscall sub_4B4470(_DWORD *this, int a2)
{
  this[1] = ResourceLookupDispatcher(a2);
  ConditionalDispatch_6bd0(this, 4);
  ConditionalDispatch_6bd0(this + 2, 2);
  return 1;
}

