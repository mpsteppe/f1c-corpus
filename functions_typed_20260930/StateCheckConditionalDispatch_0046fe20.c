int __thiscall StateCheckConditionalDispatch(void *this)
{
  _DWORD *v2; // eax

  ShortComputation_fec0();
  BooleanFlagSetterVirtualCall(0);
  v2 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 13);
  if ( v2 )
    ObjectNameComparison(v2, (int)this);
  return 0;
}

