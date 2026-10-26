char *__thiscall sub_4C0C40(char *this, int a2)
{
  char *result; // eax

  result = &this[64 * a2];
  if ( --*((_DWORD *)result + 8) < 0 )
  {
    if ( result[41] )
      *((_DWORD *)result + 8) = *((_DWORD *)result + 7) - 1;
    else
      *((_DWORD *)result + 8) = 0;
  }
  return result;
}
