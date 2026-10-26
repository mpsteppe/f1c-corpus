int __thiscall sub_4F1270(_DWORD *this)
{
  void *v2; // eax
  int v3; // eax

  if ( !this[2] )
  {
    v2 = operator new(0x50u);
    if ( v2 )
      v3 = sub_5A9250(v2);
    else
      v3 = 0;
    this[2] = v3;
  }
  return this[2];
}
