_BYTE *__thiscall sub_4BA8C0(_BYTE *this, char a2)
{
  void *v3; // edi

  if ( this[8] )
  {
    v3 = *(void **)this;
    if ( *(_DWORD *)this )
    {
      nullsub_3();
      sub_587BCF(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
