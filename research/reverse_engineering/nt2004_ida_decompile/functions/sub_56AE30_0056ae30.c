int __thiscall sub_56AE30(int this)
{
  int i; // esi
  int v3; // edi
  int result; // eax
  int j; // esi
  int v6; // edi

  *(_BYTE *)(this + 4) = 0;
  for ( i = *(_DWORD *)(this + 8); i; result = sub_5BE8AE() )
  {
    v3 = i;
    i = *(_DWORD *)(i + 4);
    if ( *(_BYTE *)(v3 + 8) )
      sub_5BE8AE();
  }
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 20) = 0;
  for ( j = *(_DWORD *)(this + 24); j; result = sub_5BE8AE() )
  {
    v6 = j;
    j = *(_DWORD *)(j + 4);
    if ( *(_BYTE *)(v6 + 8) )
      sub_5BE8AE();
  }
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  return result;
}
