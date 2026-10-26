int __thiscall sub_42F960(void **this)
{
  *this = &std::logic_error::`vftable';
  if ( (unsigned int)this[9] >= 0x10 )
    j__free(this[4]);
  this[9] = (void *)15;
  this[8] = 0;
  *((_BYTE *)this + 16) = 0;
  return sub_63160F(this);
}
