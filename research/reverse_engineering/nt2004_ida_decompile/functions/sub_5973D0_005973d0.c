int __thiscall sub_5973D0(_DWORD *this, _DWORD *a2)
{
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  _DWORD *v7; // ebx
  _DWORD *v8; // eax

  if ( a2[17] )
    sub_5973D0(a2[17]);
  if ( a2[16] && a2[19] )
    sub_5973D0(a2[19]);
  if ( a2[140] )
  {
    sub_5B8650();
    sub_597C00(a2[140]);
    if ( a2[140] )
    {
      sub_5B8270(a2[140]);
      sub_5BE8AE();
    }
  }
  if ( sub_59D650(a2) )
    return -1;
  v4 = 0;
  if ( (int)this[86] > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this[87];
      v7 = *(_DWORD **)(v6 + v5 + 16);
      v8 = (_DWORD *)(v6 + v5 + 16);
      if ( v7 == a2 )
        *v8 = 0;
      ++v4;
      v5 += 24;
    }
    while ( v4 < this[86] );
  }
  sub_597500(a2);
  sub_59D5F0(a2);
  sub_5BE8AE();
  return 0;
}
