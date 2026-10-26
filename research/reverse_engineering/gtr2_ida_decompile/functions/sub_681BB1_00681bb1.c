int __thiscall sub_681BB1(void *this, int a2)
{
  void *v3; // eax
  void *v4; // esi

  v3 = (void *)sub_6816E7(128);
  if ( v3 )
    v4 = sub_681563(v3);
  else
    v4 = 0;
  if ( !v4 )
    return -1;
  if ( sub_6815D6((double *)v4, a2) < 0 )
  {
    sub_663A9B(v4, 1);
    return -1;
  }
  return sub_681833((int)this, (long double *)v4);
}
