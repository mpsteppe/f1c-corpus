int *__thiscall sub_4BC450(int *this, int a2, char *Buffer)
{
  int *result; // eax
  bool v5; // zf
  int i; // edx
  const char *v7; // eax

  if ( Buffer )
    sub_57A4C0(Buffer);
  result = (int *)*this;
  v5 = *this == 0;
  this[2] = *this;
  if ( !v5 )
  {
    for ( i = *result; *result; i = *result )
    {
      v7 = *(const char **)(i + 4);
      if ( !v7 )
        v7 = &byte_629120;
      if ( strlen(v7) )
        (**(void (__thiscall ***)(int, int))i)(i, a2);
      result = (int *)this[2];
      if ( !result )
        break;
      result = (int *)result[1];
      this[2] = (int)result;
      if ( !result )
        break;
    }
  }
  return result;
}
