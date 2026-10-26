int *__thiscall sub_575390(_DWORD *this, int a2)
{
  int *result; // eax
  int i; // esi

  result = (int *)this[71];
  this[73] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      if ( sub_5777C0(i) != -1 )
      {
        sub_577940(a2);
        sub_5777B0(-1);
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
