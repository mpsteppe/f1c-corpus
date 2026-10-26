bool __thiscall sub_499870(_DWORD *this)
{
  int v2; // eax
  bool v3; // zf
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  _DWORD **v7; // eax
  _DWORD *v8; // ecx

  v2 = this[4];
  v3 = v2 == 0;
  if ( v2 )
  {
    v4 = this[3];
    v5 = *(_DWORD *)(v4 + 12);
    v6 = v4 + 4;
    if ( v5 )
      *(_DWORD *)(v6 + 8) = *(_DWORD *)(v5 + 4);
    v7 = *(_DWORD ***)(v6 + 8);
    if ( v7 )
      v8 = *v7;
    else
      v8 = 0;
    this[4] = v8;
    if ( v8 )
      this[5] = FieldGetter_8e30(v8);
    v3 = this[4] == 0;
  }
  return !v3;
}
