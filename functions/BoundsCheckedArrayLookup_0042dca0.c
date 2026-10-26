int __thiscall sub_42DCA0(int *this, int a2)
{
  if ( a2 < 0 || a2 >= *this )
    return 0;
  else
    return *(_DWORD *)(this[1] + 8 * a2 + 4);
}
