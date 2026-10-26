int __thiscall sub_491DB0(int *this)
{
  int i; // esi
  LPVOID *v3; // edi
  char v4; // al
  int result; // eax

  for ( i = *this; i; result = FreeWrapper_7bcf(v3) )
  {
    v3 = (LPVOID *)i;
    v4 = *(_BYTE *)(i + 8);
    i = *(_DWORD *)(i + 4);
    if ( v4 && *v3 )
      FreeWrapper_7bcf(*v3);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
