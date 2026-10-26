int __thiscall sub_681B61(void *this, int a2)
{
  void *v3; // eax
  void *v4; // esi

  v3 = operator new(0x34u);
  if ( v3 )
    v4 = sub_681563(v3);
  else
    v4 = 0;
  if ( !v4 )
    return -1;
  if ( (int)sub_6CD18B(a2) < 0 )
  {
    sub_681758(v4, 1);
    return -1;
  }
  return sub_681779((int)this, v4);
}
