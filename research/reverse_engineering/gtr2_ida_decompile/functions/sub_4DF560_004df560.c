_DWORD *__thiscall sub_4DF560(int *this, _DWORD *a2)
{
  _DWORD *v3; // eax
  int v4; // eax

  ++this[20];
  v3 = (_DWORD *)a2[36];
  a2[38] = this;
  for ( a2[39] = 0; v3; v3 = (_DWORD *)v3[35] )
  {
    v3[38] = this;
    v3[39] = 0;
  }
  sub_4CD670(a2, this[3], this[1]);
  v4 = this[16];
  if ( v4 )
  {
    for ( ; *(_DWORD *)(v4 + 140); v4 = *(_DWORD *)(v4 + 140) )
      ;
    *(_DWORD *)(v4 + 140) = a2;
    return a2;
  }
  else
  {
    this[16] = (int)a2;
    return a2;
  }
}
