int __thiscall sub_4F83B0(int this)
{
  int result; // eax
  int i; // edi
  int j; // edi

  result = *(_DWORD *)(this + 1684);
  if ( result )
  {
    for ( i = 0; i < 180; i += 4 )
      ObjectDestructor((_DWORD *)(i + *(_DWORD *)(this + 1684)));
    result = FreeWrapper_7bcf(*(LPVOID *)(this + 1684));
    *(_DWORD *)(this + 1684) = 0;
  }
  if ( *(_DWORD *)(this + 1752) )
  {
    for ( j = 0; j < 180; j += 4 )
      ObjectDestructor((_DWORD *)(j + *(_DWORD *)(this + 1752)));
    result = FreeWrapper_7bcf(*(LPVOID *)(this + 1752));
    *(_DWORD *)(this + 1752) = 0;
  }
  *(_BYTE *)(this + 4) = 0;
  return result;
}

