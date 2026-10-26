int __thiscall sub_5B1190(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v7; // ecx
  int i; // eax

  v4 = operator new(0x6Cu);
  if ( v4 )
    v5 = sub_5AF2D0(v4);
  else
    v5 = 0;
  if ( sub_5AF330((char *)v5, a3) )
  {
    if ( v5 )
    {
      j_nullsub_6(v5);
      sub_5BE8AE();
    }
    if ( a2 )
      *a2 = 0;
    return -1;
  }
  else
  {
    v7 = this[85];
    if ( v7 )
    {
      for ( i = *(_DWORD *)(v7 + 104); i; i = *(_DWORD *)(i + 104) )
        v7 = i;
      *(_DWORD *)(v7 + 104) = v5;
      v5[25] = v7;
    }
    else
    {
      this[85] = v5;
    }
    ++this[84];
    if ( a2 )
      *a2 = v5;
    return -(sub_596220(this) != 0);
  }
}
