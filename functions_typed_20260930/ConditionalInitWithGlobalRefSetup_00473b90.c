int __thiscall ConditionalInitWithGlobalRefSetup(_DWORD *this)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 11);
  if ( v2 )
    ObjectNameComparison(v2, (int)this);
  this[200] = &byte_7D0474;
  this[199] = 278;
  return 0;
}

