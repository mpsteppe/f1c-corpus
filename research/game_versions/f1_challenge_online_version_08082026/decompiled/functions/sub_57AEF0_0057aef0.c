int __thiscall sub_57AEF0(_DWORD *this)
{
  int i; // esi
  LPVOID *v3; // edi
  int result; // eax
  int j; // esi
  LPVOID *v6; // edi

  *this = &off_5B8A1C;
  for ( i = this[6]; i; result = sub_587BCF(v3) )
  {
    v3 = (LPVOID *)i;
    i = *(_DWORD *)(i + 4);
    if ( *((_BYTE *)v3 + 8) )
      sub_587BCF(*v3);
  }
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  for ( j = this[2]; j; result = sub_587BCF(v6) )
  {
    v6 = (LPVOID *)j;
    j = *(_DWORD *)(j + 4);
    if ( *((_BYTE *)v6 + 8) )
      sub_587BCF(*v6);
  }
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  *this = &off_5B8A40;
  return result;
}
