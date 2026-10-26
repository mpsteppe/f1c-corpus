int __thiscall sub_6814E4(int *this, int a2, _DWORD *a3)
{
  int v3; // edx
  unsigned int v4; // eax
  int result; // eax

  v3 = *this;
  v4 = *this & 0xFFF00000;
  if ( v4 )
  {
    switch ( v4 )
    {
      case 0x50000000u:
        goto LABEL_9;
      case 0x50200000u:
        result = 1;
        break;
      case 0x70800000u:
LABEL_9:
        result = this[3];
        break;
      default:
        if ( (v3 & 0xF0000000) == 0x60000000 )
          result = 4;
        else
          result = v3 & 0xFFFFF;
        break;
    }
  }
  else
  {
    result = 0;
  }
  if ( a2 * result + result <= (unsigned int)this[3] )
  {
    if ( a3 )
      *a3 = this[4] + 4 * a2 * result;
  }
  else
  {
    if ( a3 )
      *a3 = 0;
    return 0;
  }
  return result;
}
