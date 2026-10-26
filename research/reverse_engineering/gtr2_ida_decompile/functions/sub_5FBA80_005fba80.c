_DWORD *__thiscall sub_5FBA80(_DWORD *this)
{
  _DWORD *result; // eax
  bool v3; // zf
  int i; // edx
  _DWORD *v5; // esi
  _DWORD *v6; // ecx
  int *v7; // ebx

  result = (_DWORD *)*this;
  v3 = *this == 0;
  this[2] = *this;
  if ( !v3 )
  {
    for ( i = *result; *result; i = *result )
    {
      v5 = result;
      v6 = 0;
      while ( *v5 != i )
      {
        v6 = v5;
        v5 = (_DWORD *)v5[1];
        if ( !v5 )
          goto LABEL_18;
      }
      if ( v5 == result )
        this[2] = v5[1];
      if ( v6 )
        v6[1] = v5[1];
      else
        *this = v5[1];
      if ( (_DWORD *)this[1] == v5 )
        this[1] = v6;
      --this[3];
      if ( *((_BYTE *)v5 + 8) )
      {
        v7 = (int *)*v5;
        if ( *v5 )
        {
          sub_5FB8B0((int *)*v5);
          j__free(v7);
        }
      }
      j__free(v5);
LABEL_18:
      result = (_DWORD *)*this;
      v3 = *this == 0;
      this[2] = *this;
      if ( v3 )
        break;
    }
  }
  return result;
}
