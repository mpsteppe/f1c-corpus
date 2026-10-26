int *__thiscall sub_585320(_DWORD *this, int a2)
{
  int *result; // eax
  int i; // esi

  result = (int *)this[71];
  this[73] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      if ( sub_587720(i) != -1 )
      {
        sub_5878A0(a2);
        sub_587710(-1);
      }
      result = (int *)this[73];
      if ( !result )
        break;
      result = (int *)result[1];
      this[73] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
