_DWORD *__thiscall sub_4AF7D0(_DWORD *this, char a2)
{
  void *v3; // edi

  if ( *((_BYTE *)this + 8) )
  {
    v3 = (void *)*this;
    if ( *this )
    {
      sub_4B0A60(*this);
      sub_5BE8AE(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
