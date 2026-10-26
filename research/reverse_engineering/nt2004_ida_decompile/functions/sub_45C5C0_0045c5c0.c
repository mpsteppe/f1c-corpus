_DWORD *__thiscall sub_45C5C0(_DWORD *this)
{
  _DWORD *v2; // esi
  char *v3; // eax
  int v4; // ecx
  int i; // esi

  v2 = this + 1;
  sub_506720(this + 1);
  v2[10] = 0;
  v2[11] = -1;
  v2[12] = 0;
  v2[13] = -1;
  sub_506BA0(v2);
  v3 = (char *)(this + 17);
  v4 = 8;
  do
  {
    *v3 = 0;
    *((_DWORD *)v3 + 32) = -1;
    *((_DWORD *)v3 + 33) = -1082130432;
    *((_DWORD *)v3 + 34) = 3;
    v3 += 140;
    --v4;
  }
  while ( v4 );
  *this = &off_5D640C;
  this[297] = 0;
  for ( i = 0; i < 8; ++i )
    sub_45C6C0(i);
  *((_BYTE *)this + 1192) = 0;
  this[299] = 0;
  this[300] = 0;
  return this;
}
