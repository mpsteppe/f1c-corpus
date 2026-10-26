int __thiscall sub_681AAA(void *this, int a2, int a3, int a4, double a5)
{
  void *v6; // eax
  void *v7; // esi

  v6 = (void *)sub_6816E7(128);
  if ( v6 )
    v7 = sub_681563(v6);
  else
    v7 = 0;
  if ( !v7 )
    return -1;
  if ( sub_681566((double *)v7, a2, a3, a4, a5) < 0 )
  {
    sub_663A9B(v7, 1);
    return -1;
  }
  return sub_681833((int)this, (long double *)v7);
}
