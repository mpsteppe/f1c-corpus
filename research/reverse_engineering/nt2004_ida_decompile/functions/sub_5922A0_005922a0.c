int __stdcall sub_5922A0(void **a1, int a2, int a3, int a4)
{
  void *v4; // eax
  int v5; // eax

  v4 = operator new(0x40u);
  if ( v4 )
    v5 = sub_59F160(v4);
  else
    v5 = 0;
  *a1 = (void *)v5;
  if ( !sub_59F600(v5, a2, 0, 0, a3, a4) )
    return 0;
  if ( *a1 )
  {
    j_nullsub_6(*a1);
    sub_5BE8AE();
  }
  return -1;
}
