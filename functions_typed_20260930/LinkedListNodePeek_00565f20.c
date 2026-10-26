bool __thiscall sub_565F20(int *this)
{
  int v1; // eax
  int v2; // ecx
  _DWORD *v3; // eax

  v1 = *this;
  v2 = *(_DWORD *)(*this + 8);
  if ( v2 )
    *(_DWORD *)(v1 + 8) = *(_DWORD *)(v2 + 4);
  v3 = *(_DWORD **)(v1 + 8);
  return v3 && *v3;
}

