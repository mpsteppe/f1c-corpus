int __thiscall sub_549250(_DWORD *this, int *a2)
{
  int *v2; // eax
  int result; // eax
  int i; // ecx

  if ( (*(_BYTE *)a2 & 4) != 0 )
    v2 = (int *)(*this + 296);
  else
    v2 = a2;
  result = *v2;
  if ( this[61] )
  {
    for ( i = *(_DWORD *)(result + 108); i; i = *(_DWORD *)(i + 108) )
      result = i;
    *(_DWORD *)(result + 108) = a2;
    a2[27] = 0;
    a2[26] = result;
  }
  else
  {
    this[61] = result;
    a2[26] = 0;
    a2[27] = 0;
  }
  return result;
}
