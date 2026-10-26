int __thiscall sub_458610(_DWORD *this)
{
  int v2; // edi
  _DWORD *v3; // esi
  int v4; // ebx

  v2 = 1;
  v3 = this + 21;
  v4 = 4;
  do
  {
    if ( *v3 )
      v2 += sub_458610();
    ++v3;
    --v4;
  }
  while ( v4 );
  if ( this[25] )
    v2 += sub_458610();
  return v2;
}
