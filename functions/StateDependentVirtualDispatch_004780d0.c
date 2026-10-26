int __thiscall StateDependentVirtualDispatch(_DWORD *this)
{
  int v2; // eax

  if ( SessionStateCheck(dword_7CD25C) == 3 )
    v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 23);
  else
    v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 21);
  if ( v2 )
    this[56] = v2;
  return 0;
}
