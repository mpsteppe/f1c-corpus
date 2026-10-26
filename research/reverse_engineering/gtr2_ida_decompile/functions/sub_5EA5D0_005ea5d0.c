int __thiscall sub_5EA5D0(_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[92] )
    return 0;
  else
    return *(_DWORD *)(*(_DWORD *)(this[93] + 36 * a2 + 8) + 4);
}
