int __thiscall VTableDispatch(void *this)
{
  _DWORD *v2; // eax

  F_5FieldInit((int)this);
  v2 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 13);
  if ( v2 )
    ObjectNameComparison(v2, (int)this);
  return 0;
}
