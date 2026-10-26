int __thiscall sub_4E17C0(char *this, int a2, int a3)
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
        if ( *(_DWORD *)&this[296 * a2 + 324] && this[296 * a2 + 388] )
          return sub_4E0E70(this, a2);
      }
      else if ( !*(_DWORD *)&this[296 * a2 + 324] || !this[296 * a2 + 388] )
      {
        return sub_4E0E20(this, a2);
      }
      return result;
    case 4:
      v4 = a3 == 0;
      result = (int)(this + 1508);
      goto LABEL_11;
    case 5:
      v4 = a3 == 0;
      result = (int)(this + 1576);
      goto LABEL_11;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      result = (int)&this[68 * a2 + 1236];
      v4 = a3 == 0;
LABEL_11:
      v5 = *(_DWORD *)result;
      if ( v4 )
      {
        if ( v5 && !*(_BYTE *)(result + 64) )
          result = sub_4E0D00(this, result);
      }
      else if ( !v5 || *(_BYTE *)(result + 64) )
      {
        result = sub_4E0D70((int *)result);
      }
      break;
    default:
      return result;
  }
  return result;
}
