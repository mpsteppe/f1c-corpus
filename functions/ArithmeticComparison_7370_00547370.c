char *__thiscall sub_547370(char *this, int a2)
{
  char *result; // eax
  int v3; // edx
  char v4; // cl

  result = this;
  if ( a2 )
  {
    v3 = a2 - (_DWORD)this;
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
