FILE *__thiscall sub_4FE670(FILE **this)
{
  FILE *result; // eax

  result = *this;
  if ( *this )
  {
    fseek(result, 0, 0);
    sub_5BF5A6(this + 6, 4u, 1u, *this);
    result = (FILE *)fclose(*this);
    *this = 0;
  }
  return result;
}
