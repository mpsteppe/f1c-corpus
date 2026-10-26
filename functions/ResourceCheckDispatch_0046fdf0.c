int __thiscall ResourceCheckDispatch(void *this)
{
  _DWORD *v2; // eax

  ShortComputation_fec0();
  BooleanFlagSetterVirtualCall(1);
  v2 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 12);
  if ( v2 )
    ObjectNameComparison(v2, (int)this);
  return 0;
}
