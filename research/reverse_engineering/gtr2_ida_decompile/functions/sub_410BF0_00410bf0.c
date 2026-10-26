int __thiscall sub_410BF0(_DWORD *this)
{
  _DWORD *v1; // ecx
  int result; // eax

  v1 = (_DWORD *)this[8];
  result = 0;
  if ( v1 )
  {
    switch ( dword_B71A4C )
    {
      case 1:
        result = v1[5];
        break;
      case 2:
        result = v1[4];
        break;
      case 3:
        result = v1[7];
        break;
      default:
        result = v1[6];
        break;
    }
  }
  return result;
}
