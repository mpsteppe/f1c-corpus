char *__thiscall sub_519D70(char *this)
{
  char *result; // eax
  char *v2; // edx
  int v3; // esi

  result = this;
  v2 = this + 8;
  v3 = 32;
  do
  {
    *((_DWORD *)v2 - 2) = 2139095039;
    *((_DWORD *)v2 - 1) = 0;
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = 0;
    v2[40] = 0;
    v2 += 52;
    --v3;
  }
  while ( v3 );
  return result;
}
