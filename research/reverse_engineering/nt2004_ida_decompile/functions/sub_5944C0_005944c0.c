int __thiscall sub_5944C0(_DWORD *this, int *a2)
{
  int *v2; // eax
  int result; // eax
  int i; // ecx

  if ( (*(_BYTE *)a2 & 4) != 0 )
    v2 = (int *)(*this + 300);
  else
    v2 = a2;
  result = *v2;
  if ( this[61] )
  {
    for ( i = *(_DWORD *)(result + 204); i; i = *(_DWORD *)(i + 204) )
      result = i;
    *(_DWORD *)(result + 204) = a2;
    a2[51] = 0;
    a2[50] = result;
  }
  else
  {
    this[61] = result;
    a2[50] = 0;
    a2[51] = 0;
  }
  return result;
}
