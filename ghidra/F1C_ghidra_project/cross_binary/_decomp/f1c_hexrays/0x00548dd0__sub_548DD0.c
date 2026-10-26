// f1c  0x00548dd0  size=36
int __thiscall sub_548DD0(_DWORD *this)
{
  int *i; // esi
  int result; // eax

  for ( i = (int *)this[92]; i; i = (int *)i[6] )
    result = sub_548C20(i, (int)this, 0);
  return result;
}
