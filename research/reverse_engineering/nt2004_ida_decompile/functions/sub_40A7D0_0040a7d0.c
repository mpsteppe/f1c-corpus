char __thiscall sub_40A7D0(_DWORD *this, int a2)
{
  int v4; // eax
  const char *v5; // eax

  if ( sub_409430(a2) )
    return 0;
  v4 = this[4];
  if ( a2 != v4 )
  {
    this[5] = v4;
    this[4] = a2;
    v5 = (const char *)sub_459B80(a2);
    if ( _strcmpi(v5, aSwingman) )
      sub_459B30(a2);
  }
  return 1;
}
