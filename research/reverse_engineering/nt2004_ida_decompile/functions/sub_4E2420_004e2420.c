int __thiscall sub_4E2420(int *this)
{
  int result; // eax
  int i; // esi
  LPVOID *v4; // edi
  char v5; // al

  result = sub_4E2510();
  for ( i = *this; i; result = sub_5BE8AE(v4) )
  {
    v4 = (LPVOID *)i;
    v5 = *(_BYTE *)(i + 8);
    i = *(_DWORD *)(i + 4);
    if ( v5 )
      sub_5BE8AE(*v4);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
