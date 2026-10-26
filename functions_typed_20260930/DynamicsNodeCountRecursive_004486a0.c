int __thiscall sub_4486A0(_DWORD *this)
{
  int v2; // edi
  _DWORD *v3; // esi
  int v4; // ebx

  v2 = 1;
  v3 = this + 19;
  v4 = 4;
  do
  {
    if ( *v3 )
      v2 += DynamicsNodeCountRecursive();
    ++v3;
    --v4;
  }
  while ( v4 );
  if ( this[23] )
    v2 += DynamicsNodeCountRecursive();
  return v2;
}

