int __thiscall sub_57B100(int this)
{
  int i; // esi
  LPVOID *v3; // edi
  int result; // eax
  int j; // esi
  LPVOID *v6; // edi

  *(_BYTE *)(this + 4) = 0;
  for ( i = *(_DWORD *)(this + 8); i; result = FreeWrapper_7bcf(v3) )
  {
    v3 = (LPVOID *)i;
    i = *(_DWORD *)(i + 4);
    if ( *((_BYTE *)v3 + 8) )
      FreeWrapper_7bcf(*v3);
  }
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 20) = 0;
  for ( j = *(_DWORD *)(this + 24); j; result = FreeWrapper_7bcf(v6) )
  {
    v6 = (LPVOID *)j;
    j = *(_DWORD *)(j + 4);
    if ( *((_BYTE *)v6 + 8) )
      FreeWrapper_7bcf(*v6);
  }
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  return result;
}
