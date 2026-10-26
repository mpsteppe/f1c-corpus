int __stdcall sub_592250(int *a1, int a2, int a3, int a4, int a5)
{
  void *v5; // eax
  int v6; // eax

  v5 = operator new(0x40u);
  if ( v5 )
    v6 = sub_59F160(v5);
  else
    v6 = 0;
  *a1 = v6;
  return -(sub_59F580(a2, a3, a4, a5) != 0);
}
