// f1c  0x00498d90  size=91
int __thiscall sub_498D90(_DWORD *this)
{
  int v2; // esi
  void (__thiscall ***v3)(_DWORD, int); // ecx
  _DWORD *v4; // esi
  void (__thiscall ***v5)(_DWORD, int); // ebx

  v2 = this[18];
  for ( *this = &off_5AC9E8; v2; this[18] = v2 )
  {
    v3 = (void (__thiscall ***)(_DWORD, int))this[18];
    v2 = *(_DWORD *)(v2 + 72);
    if ( v3 )
      (**v3)(v3, 1);
  }
  v4 = (_DWORD *)sub_498F60(this);
  while ( v4 )
  {
    v5 = (void (__thiscall ***)(_DWORD, int))v4;
    v4 = (_DWORD *)sub_486320(v4);
    if ( v5 )
      (**v5)(v5, 1);
  }
  return sub_49A990(this);
}
