int __thiscall sub_410B50(_DWORD *this)
{
  int v1; // eax
  int v2; // edx
  int result; // eax
  int v4; // eax

  v1 = this[8];
  v2 = this[2];
  if ( v1 == v2 )
  {
    switch ( *(_DWORD *)(v1 + 52) )
    {
      case 0:
        this[3] = 0;
        result = this[3];
        break;
      case 1:
        this[3] = 1;
        result = this[3];
        break;
      case 2:
        this[3] = 2;
        result = this[3];
        break;
      case 3:
        this[3] = 3;
        result = this[3];
        break;
      case 4:
        goto LABEL_7;
      default:
        return this[3];
    }
  }
  else
  {
    v4 = this[11];
    if ( v4 && v4 == v2 )
    {
LABEL_7:
      this[3] = 4;
      return this[3];
    }
    else
    {
      this[3] = 5;
      return this[3];
    }
  }
  return result;
}
