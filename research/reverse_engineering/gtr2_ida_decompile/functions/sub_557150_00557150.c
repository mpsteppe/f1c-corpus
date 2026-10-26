FILE *__thiscall sub_557150(FILE **this)
{
  FILE *result; // eax

  result = *this;
  if ( *this )
  {
    fseek(result, 0, 0);
    sub_631E50(this + 71, 4, 1, *this);
    result = (FILE *)fclose(*this);
    *this = 0;
  }
  return result;
}
