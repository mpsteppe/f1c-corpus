int __thiscall sub_410A80(_DWORD *this)
{
  int v1; // eax

  v1 = this[2];
  if ( v1 )
    return *(_DWORD *)(v1 + 4);
  else
    return 0;
}
