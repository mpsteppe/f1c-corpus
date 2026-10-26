int *__thiscall sub_4AE540(_DWORD *this)
{
  int *result; // eax
  int i; // ebx
  _DWORD *v4; // esi
  _DWORD *v5; // eax
  LPVOID *v6; // ebx

  result = (int *)this[87];
  this[89] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      sub_4B0C50(i);
      v4 = (_DWORD *)this[87];
      v5 = 0;
      if ( v4 )
      {
        while ( *v4 != i )
        {
          v5 = v4;
          v4 = (_DWORD *)v4[1];
          if ( !v4 )
            goto LABEL_22;
        }
        if ( v4 == (_DWORD *)this[89] )
          this[89] = v4[1];
        if ( v5 )
          v5[1] = v4[1];
        else
          this[87] = v4[1];
        if ( (_DWORD *)this[88] == v4 )
          this[88] = v5;
        --this[90];
        if ( *((_BYTE *)v4 + 8) )
        {
          v6 = (LPVOID *)*v4;
          if ( *v4 )
          {
            if ( v6[2] )
              sub_5BE8AE(v6[2]);
            if ( *v6 )
              sub_5BE8AE(*v6);
            sub_5BE8AE(v6);
          }
        }
        sub_5BE8AE(v4);
      }
LABEL_22:
      result = (int *)this[87];
      this[89] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
