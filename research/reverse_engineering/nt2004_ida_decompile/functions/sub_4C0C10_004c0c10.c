char *__thiscall sub_4C0C10(char *this, int a2)
{
  char *result; // eax
  int v3; // edx
  int v4; // ecx

  result = &this[64 * a2];
  v3 = *((_DWORD *)result + 8) + 1;
  *((_DWORD *)result + 8) = v3;
  v4 = *((_DWORD *)result + 7);
  if ( v3 >= v4 )
  {
    if ( result[41] )
      *((_DWORD *)result + 8) = 0;
    else
      *((_DWORD *)result + 8) = v4 - 1;
  }
  return result;
}
