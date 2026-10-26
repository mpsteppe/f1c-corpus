LPVOID *__thiscall ScalarDeletingDestructor_fe90(LPVOID *this, char a2)
{
  VTableSubInit(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

