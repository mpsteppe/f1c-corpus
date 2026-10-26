int __thiscall sub_458650(_DWORD *this, int a2, int a3)
{
  int result; // eax
  _DWORD *v5; // edi
  int v6; // ebp

  this[20] = a3;
  *(_DWORD *)(a2 + 4 * a3) = this;
  result = a3 + 1;
  v5 = this + 21;
  v6 = 4;
  do
  {
    if ( *v5 )
      result = sub_458650(a2, result);
    ++v5;
    --v6;
  }
  while ( v6 );
  if ( this[25] )
    return sub_458650(a2, result);
  return result;
}
