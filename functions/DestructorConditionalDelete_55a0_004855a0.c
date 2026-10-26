LPVOID *__thiscall DestructorConditionalDelete_55a0(LPVOID *this, char a2)
{
  *this = &off_5AB290;
  InitWithVTableCleanup(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
