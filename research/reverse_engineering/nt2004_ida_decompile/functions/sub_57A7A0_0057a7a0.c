int __thiscall sub_57A7A0(_DWORD *this)
{
  int v2; // esi
  int v3; // ebp
  int result; // eax

  sub_57AC20(this);
  v2 = this[9];
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 4);
    if ( *(_BYTE *)(v3 + 8) && *(_DWORD *)v3 )
    {
      if ( **(_DWORD **)v3 )
        sub_5BE8AE();
      sub_5BE8AE();
    }
    sub_5BE8AE();
  }
  result = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  return result;
}
