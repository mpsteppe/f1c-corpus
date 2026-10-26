int __thiscall sub_4FCA50(_DWORD *this)
{
  int i; // esi
  LPVOID *v3; // edi
  bool v4; // zf
  int result; // eax

  for ( i = this[21]; i; result = FreeWrapper_7bcf(v3) )
  {
    v3 = (LPVOID *)i;
    v4 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v4 )
      FreeWrapper_7bcf(*v3);
  }
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  this[24] = 0;
  return result;
}

