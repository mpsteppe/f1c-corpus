int __thiscall sub_4C2850(_DWORD *this)
{
  int v1; // eax

  v1 = this[1];
  this[2] = v1;
  if ( v1 )
    return *(_DWORD *)v1;
  else
    return 0;
}
