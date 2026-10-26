int __thiscall PollingStateChangeDetection(_DWORD **this)
{
  int *v2; // eax
  int *v3; // edi
  int v4; // eax
  _DWORD *v5; // edx
  int v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // edx

  v2 = (int *)(*(int (__thiscall **)(_DWORD *, int))(*this[16] + 28))(this[16], 3);
  v3 = v2;
  if ( v2 && this[71] != (_DWORD *)GuardedAccessor(v2) )
  {
    v4 = GuardedAccessor(v3);
    v5 = *this;
    this[71] = (_DWORD *)v4;
    ((void (__thiscall *)(_DWORD **))v5[40])(this);
  }
  v6 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 18);
  if ( v6 )
  {
    v7 = *(_DWORD **)(v6 + 372);
    if ( this[72] != v7 )
    {
      v8 = *this;
      this[72] = v7;
      ((void (__thiscall *)(_DWORD **))v8[40])(this);
    }
  }
  return 0;
}
