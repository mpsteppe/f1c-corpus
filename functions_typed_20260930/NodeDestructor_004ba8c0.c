_BYTE *__thiscall sub_4BA8C0(_BYTE *this, char a2)
{
  void *v3; // edi

  if ( this[8] )
  {
    v3 = *(void **)this;
    if ( *(_DWORD *)this )
    {
      EmptyStub_0170();
      FreeWrapper_7bcf(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

