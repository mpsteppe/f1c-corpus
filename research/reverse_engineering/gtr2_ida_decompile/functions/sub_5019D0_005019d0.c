int __thiscall sub_5019D0(_DWORD *this, int a2, _BYTE *a3, int a4)
{
  int result; // eax
  int v5; // edx

  result = 3;
  switch ( a2 )
  {
    case 0:
      v5 = this[266];
      result = this[72];
      break;
    case 1:
      v5 = this[284];
      result = this[73];
      break;
    case 2:
      v5 = this[329];
      result = this[78];
      break;
    case 5:
      v5 = this[302];
      result = this[75];
      break;
    case 6:
      v5 = this[320];
      result = this[77];
      break;
    case 7:
      v5 = this[248];
      result = this[70];
      break;
    case 8:
      v5 = this[275];
      result = this[71];
      break;
    case 9:
      v5 = this[293];
      result = this[74];
      break;
    case 10:
      v5 = this[311];
      result = this[76];
      break;
    default:
      v5 = a4;
      break;
  }
  if ( !(_BYTE)a4 && v5 < result )
    result = v5;
  if ( a3 )
    *a3 = result;
  return result;
}
