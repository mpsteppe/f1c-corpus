_DWORD *__thiscall sub_5E87A0(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *result; // eax

  result = a2;
  if ( a2 )
  {
    if ( a3 )
    {
      if ( a3 == 1 )
        *a2 = this[56];
    }
    else
    {
      *a2 = this[55];
    }
  }
  return result;
}
