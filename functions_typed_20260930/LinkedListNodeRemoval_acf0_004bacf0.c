int *__thiscall sub_4BACF0(int **this)
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
    v3 = *v1 == 0;
    *((_BYTE *)v1 + 8) = 0;
    if ( v3 )
      return 0;
    v5 = *this;
    if ( !*this )
    {
      return 0;
    }
    else
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
        FreeWrapper_7bcf((LPVOID)*v5);
      FreeWrapper_7bcf(v5);
      return (int *)v4;
    }
  }
  return result;
}

