// f1c  0x005822b0  size=84
int __thiscall sub_5822B0(int *this)
{
  int i; // esi
  LPVOID *v3; // edi
  int result; // eax

  for ( i = *this; i; result = sub_587BCF(v3) )
  {
    v3 = (LPVOID *)i;
    i = *(_DWORD *)(i + 4);
    if ( *((_BYTE *)v3 + 8) && *v3 )
      sub_587BCF(*v3);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
