int __thiscall sub_64FE1D(_DWORD *this)
{
  int v2; // edi
  void *v3; // eax
  void *v4; // ebx
  void *v5; // eax

  if ( this[2] != 4 )
    this[21] = 4;
  if ( !this[21] )
    return 0;
  v2 = this[26];
  v3 = operator new(16 * v2);
  v4 = v3;
  if ( v3 )
  {
    sub_41D1B0((int)v3, 16, v2, (int)sub_681563);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  this[22] = v5;
  if ( v5 )
    return 0;
  else
    return -2147024882;
}
