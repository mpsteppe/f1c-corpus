int *__thiscall sub_4AD000(_DWORD *this)
{
  int *result; // eax
  int i; // ecx

  result = (int *)this[279];
  this[281] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)i + 88))(i);
      result = (int *)this[281];
      if ( !result )
        break;
      result = (int *)result[1];
      this[281] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
