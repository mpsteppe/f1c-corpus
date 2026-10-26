unsigned int *__thiscall sub_682578(_DWORD *this, int a2, unsigned int *a3)
{
  int v3; // ecx
  unsigned int *result; // eax
  unsigned int v5; // edx

  v3 = this[5];
  result = *(unsigned int **)(*(_DWORD *)(v3 + 4 * a2) + 20);
  v5 = 0;
  if ( result != (unsigned int *)-1 )
  {
    do
    {
      result = *(unsigned int **)(*(_DWORD *)(v3 + 4 * (_DWORD)result) + 20);
      ++v5;
    }
    while ( result != (unsigned int *)-1 );
    result = a3;
    if ( *a3 < v5 )
      *a3 = v5;
  }
  return result;
}
