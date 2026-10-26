_DWORD *__thiscall sub_4D3610(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // ecx

  memset((char *)this + 1, 0, 0x1Cu);
  memset((char *)this + 29, 0, 0x1Cu);
  v2 = this + 16;
  v3 = 4;
  do
  {
    *v2 = 0;
    v2[1] = 0;
    v2[2] = 0;
    v2[3] = 0;
    v2 += 4;
    --v3;
  }
  while ( v3 );
  this[15] = 0;
  return this;
}
