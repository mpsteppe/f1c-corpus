_DWORD *__thiscall sub_48CC20(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // edx
  int v3; // edx
  int v4; // edx
  int v5; // eax

  this[203] = 5;
  this[204] = 5;
  result = (_DWORD *)this[199];
  this[201] = result;
  if ( result )
  {
    for ( result = (_DWORD *)*result; result; result = (_DWORD *)*result )
    {
      v2 = result[1];
      if ( v2 )
      {
        v3 = *(_DWORD *)(v2 + 12);
        if ( v3 )
        {
          v4 = *(_DWORD *)(v3 + 28) + 2;
          if ( v4 <= this[203] )
            v4 = this[203];
          this[203] = v4;
          v5 = *(_DWORD *)(*(_DWORD *)(result[1] + 12) + 32);
          if ( v5 <= this[204] )
            v5 = this[204];
          this[204] = v5;
        }
      }
      result = (_DWORD *)this[201];
      if ( !result )
        break;
      result = (_DWORD *)result[1];
      this[201] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
