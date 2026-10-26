int __thiscall sub_64FD9A(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int v4; // ecx
  int v5; // edi
  void *v6; // eax
  void *v7; // ebx
  void *v8; // eax

  v2 = a2[2];
  v4 = this[2];
  if ( v4 != v2 && v4 != 4 )
    this[21] = v2;
  if ( this[21] || this[4] )
  {
    v5 = this[26];
    v6 = operator new(16 * v5);
    v7 = v6;
    if ( v6 )
    {
      sub_41D1B0((int)v6, 16, v5, (int)sub_681563);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    this[22] = v8;
    if ( !v8 )
      return -2147024882;
    if ( this[4] )
    {
      if ( a2[4] )
      {
        a2[5] = 1;
        this[5] = 1;
      }
    }
  }
  return 0;
}
