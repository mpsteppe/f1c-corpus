void *__thiscall DestructorWithConditionalFree_e0b0(void *this, char a2)
{
  sub_48E0D0((int)this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

