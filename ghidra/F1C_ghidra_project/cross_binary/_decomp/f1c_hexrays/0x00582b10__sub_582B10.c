// f1c  0x00582b10  size=131
_DWORD *__thiscall sub_582B10(_DWORD *this)
{
  _DWORD *v1; // edx
  _DWORD *result; // eax
  bool v3; // zf
  int v4; // ebx
  _DWORD *v5; // esi
  int v6; // edx
  void *v7; // edi

  v1 = (_DWORD *)*this;
  result = 0;
  v3 = *this == 0;
  this[2] = *this;
  if ( !v3 )
  {
    v4 = *v1;
    *((_BYTE *)v1 + 8) = 0;
    if ( v4 && (v5 = (_DWORD *)*this) != 0 )
    {
      while ( *v5 != v4 )
      {
        result = v5;
        v5 = (_DWORD *)v5[1];
        if ( !v5 )
          return 0;
      }
      if ( v5 == (_DWORD *)this[2] )
        this[2] = v5[1];
      v6 = v5[1];
      if ( result )
        result[1] = v6;
      else
        *this = v6;
      if ( (_DWORD *)this[1] == v5 )
        this[1] = result;
      --this[3];
      if ( *((_BYTE *)v5 + 8) )
      {
        v7 = (void *)*v5;
        if ( *v5 )
        {
          sub_5867B0(*v5);
          sub_587BCF(v7);
        }
      }
      sub_587BCF(v5);
      return (_DWORD *)v4;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
