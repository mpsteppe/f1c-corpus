void __thiscall sub_61C300(void **this)
{
  if ( *this )
  {
    j__free(*this);
    off_16C9698();
  }
  else
  {
    if ( this[1] )
    {
      j__free(this[1]);
      this[1] = 0;
    }
    if ( this[2] )
    {
      j__free(this[2]);
      this[2] = 0;
    }
    if ( this[3] )
    {
      j__free(this[3]);
      this[3] = 0;
    }
  }
}
