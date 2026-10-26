// f1c  0x004c4cf0  size=86
int __thiscall sub_4C4CF0(_DWORD *this)
{
  int result; // eax
  int i; // esi
  LPVOID *v4; // edi
  bool v5; // zf

  result = sub_566650(byte_5EA438);
  for ( i = this[2]; i; result = sub_587BCF(v4) )
  {
    v4 = (LPVOID *)i;
    v5 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v5 )
      sub_587BCF(*v4);
  }
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  return result;
}
