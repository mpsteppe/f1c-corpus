LPVOID *__thiscall UIDestructorWithSelfFree(LPVOID *this, char a2)
{
  *this = &off_5AC830;
  sub_485EB0(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
