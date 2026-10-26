int __thiscall sub_40D0B0(_DWORD *this)
{
  _DWORD *v1; // ecx
  int result; // eax

  v1 = (_DWORD *)this[6];
  result = 0;
  if ( v1 )
  {
    switch ( dword_7CFDC4 )
    {
      case 1:
        result = UtilityFunction_a610(v1, 1);
        break;
      case 2:
        result = UtilityFunction_a610(v1, 0);
        break;
      case 3:
        result = UtilityFunction_a610(v1, 3);
        break;
      default:
        result = UtilityFunction_a610(v1, 2);
        break;
    }
  }
  return result;
}
