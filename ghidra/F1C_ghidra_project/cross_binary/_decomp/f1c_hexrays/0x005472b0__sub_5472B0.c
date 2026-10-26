// f1c  0x005472b0  size=29
char *__thiscall sub_5472B0(char *this, char *a2)
{
  char *result; // eax
  char *v3; // edx
  char v4; // cl

  result = a2;
  if ( a2 )
  {
    v3 = (char *)(this - a2);
    do
    {
      v4 = *result;
      result[(_DWORD)v3] = *result;
      ++result;
    }
    while ( v4 );
  }
  return result;
}
