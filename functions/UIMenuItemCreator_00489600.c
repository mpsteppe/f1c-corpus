int __thiscall sub_489600(_DWORD *this, int a2, char *a3, int a4, int a5, char a6)
{
  int v7; // eax
  _DWORD *v8; // esi
  char *v9; // eax

  if ( !a2 )
    return -1;
  v7 = OperatorNewNhMallocWrapper(232);
  if ( v7 )
    v8 = (_DWORD *)VTableSetWithFlag(v7);
  else
    v8 = 0;
  StringCopyWithBufferRealloc(a2);
  v9 = a3;
  if ( !a3 )
  {
    v9 = (char *)this[46];
    if ( !v9 )
      v9 = byte_5EA438;
  }
  StringCopyWithBufferRealloc(v9);
  if ( a4 )
    StringCopyWithBufferRealloc(a4);
  if ( a5 )
    StringCopyWithBufferRealloc(a5);
  sub_486340(this, v8, a6);
  PopListWithDestructor(this);
  (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
  (*(void (__thiscall **)(_DWORD *, int))(*this + 172))(this, a2);
  return 0;
}
