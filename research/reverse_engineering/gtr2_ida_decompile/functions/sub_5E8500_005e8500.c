char *__thiscall sub_5E8500(char *this, char *a2)
{
  char *result; // eax
  int v3; // edx
  char v4; // cl

  result = a2;
  if ( a2 )
  {
    v3 = this + 4 - a2;
    do
    {
      v4 = *result;
      result[v3] = *result;
      ++result;
    }
    while ( v4 );
  }
  return result;
}
