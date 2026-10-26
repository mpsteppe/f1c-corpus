int __thiscall sub_4190C0(_DWORD *this)
{
  int i; // esi
  LPVOID *v3; // edi
  bool v4; // zf
  int result; // eax

  for ( i = this[104]; i; result = FreeWrapper_7bcf(v3) )
  {
    v3 = (LPVOID *)i;
    v4 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v4 && *v3 )
      FreeWrapper_7bcf(*v3);
  }
  this[104] = 0;
  this[105] = 0;
  this[106] = 0;
  this[107] = 0;
  return result;
}
