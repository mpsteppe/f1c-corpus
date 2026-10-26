_DWORD *__thiscall sub_499360(int *this, _DWORD *a2)
{
  _DWORD *v3; // edi
  int v4; // eax

  a2[39] = this;
  sub_4869E0(a2, this[3], this[1]);
  v3 = (_DWORD *)this[17];
  if ( v3 )
  {
    if ( sub_486320((_DWORD *)this[17]) )
    {
      do
        v3 = (_DWORD *)sub_486320(v3);
      while ( sub_486320(v3) );
    }
    sub_486330(v3, (int)a2);
    ++this[21];
    return a2;
  }
  else
  {
    v4 = this[21] + 1;
    this[17] = (int)a2;
    this[21] = v4;
    return a2;
  }
}
