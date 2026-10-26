int __thiscall sub_491CF0(int *this)
{
  int v1; // eax
  int v2; // ecx

  v1 = *this;
  v2 = *(_DWORD *)(*this + 28);
  *(_DWORD *)(v1 + 36) = v2;
  if ( v2 )
    return *(_DWORD *)v2;
  else
    return 0;
}
