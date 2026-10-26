int *__thiscall sub_582EB0(int **this)
{
  int *v1; // edx
  int *result; // eax
  bool v3; // zf
  int v4; // edi
  int *v5; // esi
  int *v6; // edx

  v1 = *this;
  result = 0;
  v3 = *this == 0;
  this[2] = *this;
  if ( !v3 )
  {
    v4 = *v1;
    *((_BYTE *)v1 + 8) = 0;
    if ( v4 && (v5 = *this) != 0 )
    {
      while ( *v5 != v4 )
      {
        result = v5;
        v5 = (int *)v5[1];
        if ( !v5 )
          return 0;
      }
      if ( v5 == this[2] )
        this[2] = (int *)v5[1];
      v6 = (int *)v5[1];
      if ( result )
        result[1] = (int)v6;
      else
        *this = v6;
      if ( this[1] == v5 )
        this[1] = result;
      this[3] = (int *)((char *)this[3] - 1);
      if ( *((_BYTE *)v5 + 8) )
      {
        if ( *v5 )
          sub_587BCF((LPVOID)*v5);
      }
      sub_587BCF(v5);
      return (int *)v4;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
