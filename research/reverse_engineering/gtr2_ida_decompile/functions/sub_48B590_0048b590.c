int __thiscall sub_48B590(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // ecx
  _DWORD *v4; // eax
  void *v5; // edi
  _DWORD *v6; // ebx
  _DWORD *i; // edi
  _DWORD *v8; // eax

  *this = a2;
  sub_617E70(this + 2);
  this[27] = 1065353216;
  this[28] = 0;
  this[26] = 0;
  sub_525140(this + 29);
  sub_525140(this + 33);
  v3 = (_DWORD *)this[38];
  v4 = (_DWORD *)*v3;
  a2 = (_DWORD *)*v3;
  if ( a2 != v3 )
  {
    do
    {
      v5 = (void *)v4[4];
      if ( v5 )
      {
        sub_48B260();
        j__free(v5);
      }
      sub_476240((int *)&a2);
      v4 = a2;
    }
    while ( a2 != (_DWORD *)this[38] );
  }
  v6 = *(_DWORD **)(this[38] + 4);
  for ( i = v6; !*((_BYTE *)i + 21); v6 = i )
  {
    sub_489CE0((void **)i[2]);
    i = (_DWORD *)*i;
    j__free(v6);
  }
  *(_DWORD *)(this[38] + 4) = this[38];
  v8 = (_DWORD *)this[38];
  this[39] = 0;
  *v8 = v8;
  *(_DWORD *)(this[38] + 8) = this[38];
  this[40] = 0;
  sub_525140(this + 249);
  return sub_525140(this + 253);
}
