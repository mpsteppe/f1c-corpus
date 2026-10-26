int __thiscall sub_430560(_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[2] )
    return 0;
  else
    return *(_DWORD *)(this[3] + 8 * a2);
}
