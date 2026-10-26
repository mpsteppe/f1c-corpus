int __thiscall sub_694F7B(_DWORD *this)
{
  int v1; // eax

  v1 = this[5];
  if ( v1 )
  {
    this[5] = *(_DWORD *)(v1 + 12);
    *(_DWORD *)(v1 + 12) = 0;
  }
  return 0;
}
