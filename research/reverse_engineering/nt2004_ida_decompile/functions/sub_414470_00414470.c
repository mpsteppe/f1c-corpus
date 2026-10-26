int __thiscall sub_414470(int *this)
{
  int v1; // eax
  bool v2; // zf

  v1 = *this;
  v2 = *this == 0;
  this[2] = *this;
  if ( v2 )
    return 0;
  else
    return *(_DWORD *)v1;
}
