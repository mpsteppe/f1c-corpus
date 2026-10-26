_DWORD *__thiscall sub_45B360(_DWORD *this)
{
  char *v2; // esi
  char *v3; // eax
  int v4; // ecx
  int i; // esi

  v2 = (char *)(this + 1);
  ShortComputation_cb70(this + 1);
  *((_DWORD *)v2 + 10) = 0;
  *((_DWORD *)v2 + 11) = -1;
  sub_4DCF80(v2);
  v3 = (char *)(this + 15);
  v4 = 8;
  do
  {
    *v3 = 0;
    *((_DWORD *)v3 + 20) = -1;
    *((_DWORD *)v3 + 21) = -1082130432;
    *((_DWORD *)v3 + 22) = 3;
    v3 += 92;
    --v4;
  }
  while ( v4 );
  *this = &off_59F080;
  this[199] = 0;
  for ( i = 0; i < 8; ++i )
    PerIndexStructFieldResetter(i);
  *((_BYTE *)this + 800) = 0;
  this[201] = 0;
  this[202] = 0;
  return this;
}

