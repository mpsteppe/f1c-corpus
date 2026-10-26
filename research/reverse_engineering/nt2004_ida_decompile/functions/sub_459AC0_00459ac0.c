int __thiscall sub_459AC0(LPVOID **this)
{
  LPVOID *v1; // esi
  int result; // eax

  v1 = *this;
  if ( *this )
  {
    sub_4587E0(*this);
    if ( v1[45] )
      sub_5BE8AE(v1[45]);
    if ( v1[43] )
      sub_5BE8AE(v1[43]);
    if ( v1[3] )
      sub_5BE8AE(v1[3]);
    if ( *v1 )
      sub_5BE8AE(*v1);
    return sub_5BE8AE(v1);
  }
  return result;
}
