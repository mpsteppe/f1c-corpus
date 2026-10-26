_DWORD *__thiscall sub_499360(int *this, _DWORD *a2)
{
  _DWORD *v3; // edi
  int v4; // eax

  a2[39] = this;
  MultiRegionOffsetAccumulationWithVTableDispatch(a2, this[3], this[1]);
  v3 = (_DWORD *)this[17];
  if ( v3 )
  {
    if ( StructFieldAccessor((_DWORD *)this[17]) )
    {
      do
        v3 = (_DWORD *)StructFieldAccessor(v3);
      while ( StructFieldAccessor(v3) );
    }
    FieldSetterAt0x8c(v3, (int)a2);
    ++this[21];
    return a2;
  }
  else
  {
    v4 = this[21] + 1;
    this[17] = (int)a2;
    this[21] = v4;
    return a2;
  }
}
