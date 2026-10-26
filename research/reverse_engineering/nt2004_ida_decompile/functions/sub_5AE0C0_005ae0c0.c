int __thiscall sub_5AE0C0(_DWORD *this, int a2)
{
  int result; // eax

  do
  {
    result = this[14];
    if ( result && (dword_7E8D60 & result & *(_DWORD *)(a2 + 132)) != result )
      break;
    sub_5AE110(a2);
    if ( this[17] )
      sub_5AE0C0(a2);
    result = this[16];
    if ( !result )
      break;
    this = (_DWORD *)this[19];
  }
  while ( this );
  return result;
}
