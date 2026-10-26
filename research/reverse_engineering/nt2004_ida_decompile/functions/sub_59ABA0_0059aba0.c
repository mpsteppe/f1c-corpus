int __thiscall sub_59ABA0(_DWORD *this)
{
  int *i; // esi
  int result; // eax

  for ( i = (int *)this[95]; i; i = (int *)i[6] )
    result = sub_59A9F0(i, (int)this, 0);
  return result;
}
