BOOL __thiscall sub_50BEB0(int this, int a2)
{
  BOOL result; // eax

  switch ( a2 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
      result = *(_BYTE *)(304 * a2 + this + 404) == 0;
      break;
    case 4:
      if ( !*(_DWORD *)(this + 1556) || *(_BYTE *)(this + 1620) )
        goto LABEL_12;
      result = 1;
      break;
    case 5:
      if ( !*(_DWORD *)(this + 1624) || *(_BYTE *)(this + 1688) )
        goto LABEL_12;
      result = 1;
      break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
      if ( !*(_DWORD *)(68 * a2 + this + 1284) || *(_BYTE *)(68 * a2 + this + 1348) )
        goto LABEL_12;
      result = 1;
      break;
    default:
LABEL_12:
      result = 0;
      break;
  }
  return result;
}
