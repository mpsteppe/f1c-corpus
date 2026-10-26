int __thiscall sub_659F38(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int result; // eax

  if ( a3 && !a2 )
    return -2005530516;
  this[25] = a2;
  this[26] = a3;
  result = sub_65D800(a2, a3, 0, 1, a4, a5);
  if ( result >= 0 )
    return 0;
  return result;
}
