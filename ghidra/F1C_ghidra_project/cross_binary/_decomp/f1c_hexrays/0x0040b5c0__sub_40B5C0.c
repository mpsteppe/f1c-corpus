// f1c  0x0040b5c0  size=104
char *__thiscall sub_40B5C0(_DWORD *this, char a2)
{
  int v3; // eax
  char *v4; // ebp
  char *v5; // esi
  int v6; // eax
  int v7; // edi

  if ( (a2 & 2) != 0 )
  {
    v3 = *(this - 1);
    v4 = (char *)(this - 1);
    v5 = (char *)&this[52 * v3];
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v5 -= 208;
        sub_4584A0(v5);
        --v7;
      }
      while ( v7 );
    }
    if ( (a2 & 1) != 0 )
      sub_587BCF(v4);
    return v4;
  }
  else
  {
    sub_4584A0(this);
    if ( (a2 & 1) != 0 )
      sub_587BCF(this);
    return (char *)this;
  }
}
