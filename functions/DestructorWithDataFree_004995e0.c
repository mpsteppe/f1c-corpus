_DWORD *__thiscall sub_4995E0(_DWORD *this, char a2)
{
  void *v3; // edi

  if ( *((_BYTE *)this + 8) )
  {
    v3 = (void *)*this;
    if ( *this )
    {
      FreeIfNonNull(*this);
      FreeWrapper_7bcf(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
