// f1c  0x00496e40  size=68
int *__thiscall sub_496E40(_DWORD *this)
{
  int *result; // eax
  int i; // ecx

  result = (int *)this[1591];
  this[1593] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)i + 108))(i);
      result = (int *)this[1593];
      if ( !result )
        break;
      result = (int *)result[1];
      this[1593] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
