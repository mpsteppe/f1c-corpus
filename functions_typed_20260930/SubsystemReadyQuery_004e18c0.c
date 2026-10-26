int __thiscall sub_4E18C0(int this, int a2)
{
  int v2; // eax
  int result; // eax

  switch ( a2 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
      v2 = 296 * a2 + this + 324;
      if ( !*(_DWORD *)v2 )
        goto LABEL_12;
      goto LABEL_11;
    case 4:
      if ( !*(_DWORD *)(this + 1508) || *(_BYTE *)(this + 1572) )
        goto LABEL_13;
      result = 1;
      break;
    case 5:
      if ( !*(_DWORD *)(this + 1576) || *(_BYTE *)(this + 1640) )
        goto LABEL_13;
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
      v2 = 68 * a2 + this + 1236;
      if ( !*(_DWORD *)v2 )
        goto LABEL_13;
LABEL_11:
      if ( *(_BYTE *)(v2 + 64) )
LABEL_13:
        result = 0;
      else
LABEL_12:
        result = 1;
      break;
    default:
      goto LABEL_13;
  }
  return result;
}

