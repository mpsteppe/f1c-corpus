_DWORD *__thiscall sub_59A9CA(_DWORD *this, _DWORD *a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // esi
  char *v6; // eax
  char *v7; // eax
  _BYTE *v8; // eax
  int v9; // eax

  if ( a2[2] < a3 )
    sub_59AF68();
  v5 = a2[2] - a3;
  if ( a4 < v5 )
    v5 = a4;
  if ( this == a2 )
  {
    sub_599348(this, a3 + v5, 0xFFFFFFFF);
    sub_599348(this, 0, a3);
  }
  else
  {
    if ( !v5 || v5 != a2[2] )
      goto LABEL_22;
    v6 = (char *)a2[1];
    if ( !v6 )
      v6 = (char *)&unk_5B9D34;
    if ( (unsigned __int8)*(v6 - 1) < 0xFEu )
    {
      sub_5993AF(this, 1);
      v7 = (char *)a2[1];
      if ( !v7 )
        v7 = (char *)&unk_5B9D34;
      this[1] = v7;
      this[2] = a2[2];
      this[3] = a2[3];
      ++*(v7 - 1);
    }
    else
    {
LABEL_22:
      if ( sub_599560(this, v5, 1) )
      {
        v8 = (_BYTE *)a2[1];
        if ( !v8 )
          v8 = &unk_5B9D34;
        sub_58CC00(this[1], &v8[a3], v5);
        v9 = this[1];
        this[2] = v5;
        *(_BYTE *)(v9 + v5) = 0;
      }
    }
  }
  return this;
}
