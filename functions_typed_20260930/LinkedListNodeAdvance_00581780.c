int __thiscall sub_581780(_DWORD *this)
{
  int v1; // eax
  int v2; // ecx

  v1 = this[2];
  if ( v1 )
    this[2] = *(_DWORD *)(v1 + 4);
  v2 = this[2];
  if ( v2 )
    return *(_DWORD *)v2;
  else
    return 0;
}

