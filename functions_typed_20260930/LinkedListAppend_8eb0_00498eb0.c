_DWORD *__thiscall sub_498EB0(int *this, _DWORD *a2)
{
  _DWORD *v3; // eax
  int v4; // ecx
  int i; // eax

  ++this[23];
  v3 = (_DWORD *)a2[36];
  a2[38] = this;
  for ( a2[39] = 0; v3; v3 = (_DWORD *)v3[35] )
  {
    v3[38] = this;
    v3[39] = 0;
  }
  MultiRegionOffsetAccumulationWithVTableDispatch(a2, this[3], this[1]);
  v4 = this[19];
  if ( v4 )
  {
    for ( i = *(_DWORD *)(v4 + 140); i; i = *(_DWORD *)(i + 140) )
      v4 = i;
    *(_DWORD *)(v4 + 140) = a2;
    return a2;
  }
  else
  {
    this[19] = (int)a2;
    return a2;
  }
}

