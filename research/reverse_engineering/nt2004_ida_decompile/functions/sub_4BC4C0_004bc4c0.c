int *__thiscall sub_4BC4C0(int **this)
{
  int *result; // eax
  bool v3; // zf
  int i; // ecx

  result = *this;
  v3 = *this == 0;
  this[2] = *this;
  if ( !v3 )
  {
    for ( i = *result; *result; i = *result )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)i + 8))(i);
      result = this[2];
      if ( !result )
        break;
      result = (int *)result[1];
      this[2] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
