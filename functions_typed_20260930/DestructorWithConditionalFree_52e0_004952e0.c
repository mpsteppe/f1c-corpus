char *__thiscall DestructorWithConditionalFree_52e0(char *this, char a2)
{
  sub_495300(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

