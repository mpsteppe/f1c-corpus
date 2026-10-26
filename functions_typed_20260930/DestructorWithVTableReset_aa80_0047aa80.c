LPVOID *__thiscall DestructorWithVTableReset_aa80(LPVOID *this, char a2)
{
  *this = &off_5A66E0;
  sub_485EB0(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

