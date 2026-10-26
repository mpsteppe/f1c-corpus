int __thiscall sub_65D86A(unsigned int *this)
{
  unsigned int v1; // esi
  unsigned int v2; // eax
  char v3; // bl
  _BYTE *v4; // eax

  v1 = this[1];
  if ( *this >= v1 )
    return 0;
  while ( 1 )
  {
    v2 = *this;
    v3 = *(_BYTE *)*this;
    if ( v3 == 10 )
      return 1;
    if ( v3 != 92 )
      goto LABEL_12;
    if ( v2 + 1 < v1 && *(_BYTE *)(v2 + 1) == 10 )
    {
      v4 = (_BYTE *)(v2 + 2);
    }
    else
    {
      if ( v2 + 2 >= v1 || *(_BYTE *)(v2 + 1) != 13 || *(_BYTE *)(v2 + 2) != 10 )
      {
LABEL_12:
        v4 = (_BYTE *)(v2 + 1);
        goto LABEL_13;
      }
      v4 = (_BYTE *)(v2 + 3);
    }
    ++this[7];
LABEL_13:
    *this = (unsigned int)v4;
    if ( (unsigned int)v4 >= this[1] )
      return 0;
  }
}
