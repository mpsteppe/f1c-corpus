_DWORD *__thiscall sub_49D070(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  _DWORD *v4; // esi

  result = operator new(8u);
  v4 = result;
  if ( result )
  {
    *result = 0;
    result[1] = -1;
    result = (_DWORD *)sub_578600(a2);
  }
  else
  {
    v4 = 0;
  }
  if ( v4 )
  {
    result = operator new(0xCu);
    if ( result )
    {
      *result = v4;
      result[1] = 0;
      *((_BYTE *)result + 8) = 1;
    }
    else
    {
      result = 0;
    }
    if ( this[17] )
    {
      *(_DWORD *)(this[18] + 4) = result;
    }
    else
    {
      this[17] = result;
      this[19] = result;
    }
    this[18] = result;
    ++this[20];
  }
  return result;
}
