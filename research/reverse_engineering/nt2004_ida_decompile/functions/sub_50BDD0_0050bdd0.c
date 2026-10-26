int __thiscall sub_50BDD0(_DWORD *this, int a2, int a3)
{
  int result; // eax
  bool v4; // zf
  int v5; // edx

  result = a2;
  switch ( a2 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
      if ( a3 )
      {
        if ( LOBYTE(this[76 * a2 + 101]) )
          return sub_50B1D0(this, a2);
      }
      else if ( !LOBYTE(this[76 * a2 + 101]) )
      {
        return sub_50B170(this, a2);
      }
      return result;
    case 4:
      v4 = a3 == 0;
      result = (int)(this + 389);
      goto LABEL_9;
    case 5:
      v4 = a3 == 0;
      result = (int)(this + 406);
      goto LABEL_9;
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
      result = (int)&this[17 * a2 + 321];
      v4 = a3 == 0;
LABEL_9:
      v5 = *(_DWORD *)result;
      if ( v4 )
      {
        if ( v5 && !*(_BYTE *)(result + 64) )
          result = sub_50AEE0(this, result);
      }
      else if ( !v5 || *(_BYTE *)(result + 64) )
      {
        result = sub_50AF50(this, (int *)result);
      }
      break;
    default:
      return result;
  }
  return result;
}
