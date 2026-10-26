int __thiscall sub_681A51(void *this, int a2, int a3, int a4, int a5)
{
  void *v6; // eax
  void *v7; // esi

  v6 = operator new(0x34u);
  if ( v6 )
    v7 = sub_681563(v6);
  else
    v7 = 0;
  if ( !v7 )
    return -1;
  if ( (int)sub_6CD143(a2, a3, a4, a5) < 0 )
  {
    sub_681758(v7, 1);
    return -1;
  }
  return sub_681779((int)this, v7);
}
