int __thiscall sub_4C5DE0(void **this)
{
  LPVOID **v2; // esi
  LPVOID **v3; // ebp
  char v4; // al
  LPVOID *v5; // edi
  int result; // eax
  void *v7; // ebx

  sub_4C62C0(this);
  v2 = (LPVOID **)this[2];
  while ( v2 )
  {
    v3 = v2;
    v4 = *((_BYTE *)v2 + 8);
    v2 = (LPVOID **)v2[1];
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( v5[1] )
          sub_587BCF(v5[1]);
        sub_587BCF(v5);
      }
    }
    sub_587BCF(v3);
  }
  result = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  v7 = *this;
  if ( v7 )
    return sub_587BCF(v7);
  return result;
}
