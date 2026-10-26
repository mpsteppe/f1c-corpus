int *__thiscall sub_4EDE20(int **this, int a2, int a3)
{
  int *result; // eax
  bool v5; // zf
  int i; // ecx
  const char *v7; // eax

  if ( a3 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)a2 + 40))(a2, a3);
  result = *this;
  v5 = *this == 0;
  this[2] = *this;
  if ( !v5 )
  {
    for ( i = *result; *result; i = *result )
    {
      v7 = *(const char **)(i + 4);
      if ( !v7 )
        v7 = WindowName;
      if ( strlen(v7) )
        (**(void (__thiscall ***)(int, int))i)(i, a2);
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
