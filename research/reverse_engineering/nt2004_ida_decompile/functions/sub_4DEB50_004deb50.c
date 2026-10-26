int __thiscall sub_4DEB50(int *this, char a2)
{
  if ( a2 )
  {
    this[2] = 11;
    return sub_421590(*this, 16, 0);
  }
  else
  {
    if ( this[2] == 11 )
      this[2] = dword_75CBB4;
    return sub_421590(*this, 16, 0);
  }
}
