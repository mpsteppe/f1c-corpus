int __thiscall sub_4A5800(_DWORD *this)
{
  int v1; // eax

  v1 = this[15];
  if ( v1 )
    return *(_DWORD *)(v1 + 20);
  else
    return this[1];
}
