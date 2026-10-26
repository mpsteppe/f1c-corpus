_DWORD *__thiscall sub_407C90(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // edx

  result = (_DWORD *)this[6];
  this[8] = result;
  if ( result )
  {
    result = (_DWORD *)*result;
    if ( result )
    {
      while ( a2 != result )
      {
        v3 = this[8];
        if ( v3 )
          this[8] = *(_DWORD *)(v3 + 4);
        result = (_DWORD *)this[8];
        if ( result )
        {
          result = (_DWORD *)*result;
          if ( result )
            continue;
        }
        return result;
      }
      if ( a2 )
      {
        v4 = (_DWORD *)this[6];
        result = 0;
        if ( v4 )
        {
          while ( (_DWORD *)*v4 != a2 )
          {
            result = v4;
            v4 = (_DWORD *)v4[1];
            if ( !v4 )
              return result;
          }
          if ( v4 == (_DWORD *)this[8] )
            this[8] = v4[1];
          v5 = v4[1];
          if ( result )
            result[1] = v5;
          else
            this[6] = v5;
          if ( (_DWORD *)this[7] == v4 )
            this[7] = result;
          --this[9];
          if ( *((_BYTE *)v4 + 8) && *v4 )
            (**(void (__thiscall ***)(_DWORD, int))*v4)(*v4, 1);
          return (_DWORD *)FreeWrapper_7bcf(v4);
        }
      }
    }
  }
  return result;
}
