int __thiscall sub_54AC30(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // edx

  v2 = *(_DWORD *)(a2 + 320);
  if ( v2 )
    *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  v3 = *(_DWORD *)(a2 + 16);
  if ( v3 )
    *(_DWORD *)(v3 + 320) = *(_DWORD *)(a2 + 320);
  if ( this[129] == a2 )
    this[129] = *(_DWORD *)(a2 + 16);
  return 0;
}

