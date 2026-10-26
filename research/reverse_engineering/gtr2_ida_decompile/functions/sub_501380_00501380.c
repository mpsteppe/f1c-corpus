char __thiscall sub_501380(_DWORD *this, int a2)
{
  char result; // al
  int v3; // ecx

  result = 0;
  switch ( a2 )
  {
    case 0:
      v3 = this[72];
      goto LABEL_11;
    case 1:
      v3 = this[73];
      goto LABEL_11;
    case 2:
      v3 = this[78];
      goto LABEL_11;
    case 5:
      v3 = this[75];
      goto LABEL_11;
    case 6:
      v3 = this[77];
      goto LABEL_11;
    case 7:
      v3 = this[70];
      goto LABEL_11;
    case 8:
      v3 = this[71];
      goto LABEL_11;
    case 9:
      v3 = this[74];
      goto LABEL_11;
    case 10:
      v3 = this[76];
LABEL_11:
      if ( !v3 )
        result = 1;
      break;
    default:
      return result;
  }
  return result;
}
