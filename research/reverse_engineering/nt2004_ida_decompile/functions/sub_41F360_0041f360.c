int __thiscall sub_41F360(_DWORD *this, _DWORD *a2)
{
  int *v2; // eax
  int v3; // eax

  v2 = (int *)this[194];
  if ( !v2 )
    return -1;
  v3 = *v2;
  if ( !v3 )
    return -1;
  this[194] = v3;
  *a2 = *(_DWORD *)(v3 + 12);
  return *(_DWORD *)(this[194] + 8);
}
