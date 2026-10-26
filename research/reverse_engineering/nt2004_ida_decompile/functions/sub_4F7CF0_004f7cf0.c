int __thiscall sub_4F7CF0(_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[96] )
    return -2;
  else
    return this[2 * a2];
}
