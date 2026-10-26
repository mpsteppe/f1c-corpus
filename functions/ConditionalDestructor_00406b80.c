_DWORD *__thiscall ConditionalDestructor(_DWORD *this, char a2)
{
  ComplexDestructorWith4LinkedLists(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
