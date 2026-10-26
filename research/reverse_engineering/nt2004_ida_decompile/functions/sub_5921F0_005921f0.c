int __stdcall sub_5921F0(int *a1)
{
  void *v1; // eax
  int v2; // eax

  v1 = operator new(0x34u);
  if ( v1 )
    v2 = sub_5997B0(v1);
  else
    v2 = 0;
  *a1 = v2;
  return -(sub_5997E0(0) != 0);
}
