int *__thiscall sub_415700(int **this)
{
  int *result; // eax
  bool v2; // zf

  result = *this;
  v2 = *this == 0;
  this[2] = *this;
  if ( !v2 )
  {
    for ( result = (int *)*result; result; result = (int *)*result )
    {
      *((_BYTE *)result + 12) = 0;
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

