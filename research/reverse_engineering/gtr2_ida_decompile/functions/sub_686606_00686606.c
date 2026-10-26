int __thiscall sub_686606(_DWORD *this)
{
  unsigned int i; // eax

  for ( i = 0; i < this[2]; ++i )
    *(_DWORD *)(*(_DWORD *)(this[5] + 4 * i) + 48) = i;
  return 0;
}
