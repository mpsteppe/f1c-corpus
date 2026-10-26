int __thiscall sub_542B70(_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[2] )
    return 0;
  else
    return this[3] + 104 * a2;
}
