_DWORD *__thiscall sub_4A7310(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax
  int v4; // eax

  result = (_DWORD *)this[68];
  this[70] = result;
  if ( result && (result = (_DWORD *)*result) != 0 )
  {
    while ( a2 != result )
    {
      v4 = this[70];
      if ( v4 )
        this[70] = *(_DWORD *)(v4 + 4);
      result = (_DWORD *)this[70];
      if ( result )
      {
        result = (_DWORD *)*result;
        if ( result )
          continue;
      }
      goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    if ( a2 )
    {
      result = operator new(0xCu);
      if ( result )
      {
        *result = a2;
        result[1] = 0;
        *((_BYTE *)result + 8) = 0;
      }
      else
      {
        result = 0;
      }
      if ( this[68] )
      {
        *(_DWORD *)(this[69] + 4) = result;
      }
      else
      {
        this[68] = result;
        this[70] = result;
      }
      this[69] = result;
      ++this[71];
    }
  }
  return result;
}
