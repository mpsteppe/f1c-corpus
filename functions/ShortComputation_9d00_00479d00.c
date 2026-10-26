int __thiscall ShortComputation_9d00(void *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // eax

  v2 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 14);
  if ( v2 )
    ObjectNameComparison(v2, (int)this);
  v3 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 15);
  if ( v3 )
    ObjectNameComparison(v3, (int)this);
  return 0;
}
