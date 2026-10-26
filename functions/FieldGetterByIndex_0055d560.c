_DWORD *__thiscall sub_55D560(_DWORD *this, int a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = a3;
  if ( a3 )
  {
    switch ( a2 )
    {
      case 1:
        *a3 = this[5];
        break;
      case 2:
        *a3 = this[9];
        break;
      case 3:
        *a3 = this[13];
        break;
    }
  }
  return result;
}
