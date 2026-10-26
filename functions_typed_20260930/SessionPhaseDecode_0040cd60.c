int __thiscall sub_40CD60(_DWORD *this)
{
  int v1; // eax
  int result; // eax

  v1 = this[6];
  if ( v1 == this[2] )
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
        this[3] = 4;
        result = this[3];
        break;
      default:
        return this[3];
    }
  }
  else
  {
    this[3] = 5;
    return this[3];
  }
  return result;
}

