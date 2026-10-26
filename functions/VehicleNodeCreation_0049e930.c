int __thiscall sub_49E930(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // eax
  void *v5; // edi

  v3 = OperatorNewNhMallocWrapper(96);
  if ( v3 )
    v4 = StructInitWithZeroFill(v3);
  else
    v4 = 0;
  this[2] = v4;
  if ( v4 )
  {
    *(_DWORD *)(v4 + 68) |= 1u;
    if ( D3DTextureCreation(a2, 0, 2052) )
    {
      v5 = (void *)this[2];
      if ( v5 )
      {
        EmptyStub_7470(this[2]);
        FreeWrapper_7bcf(v5);
      }
      this[2] = 0;
    }
  }
  return this[2];
}
