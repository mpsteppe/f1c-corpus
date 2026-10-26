int __thiscall sub_491D10(int *this)
{
  int v1; // eax
  int v2; // ecx
  int v3; // eax
  int v4; // eax

  v1 = *this;
  v2 = *(_DWORD *)(*this + 36);
  v3 = v1 + 28;
  if ( v2 )
    *(_DWORD *)(v3 + 8) = *(_DWORD *)(v2 + 4);
  v4 = *(_DWORD *)(v3 + 8);
  if ( v4 )
    return *(_DWORD *)v4;
  else
    return 0;
}

