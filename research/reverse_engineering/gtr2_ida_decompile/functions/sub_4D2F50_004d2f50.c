int __thiscall sub_4D2F50(_DWORD *this)
{
  int v1; // eax

  v1 = this[15];
  if ( v1 )
    return *(_DWORD *)(v1 + 24);
  else
    return this[2];
}
