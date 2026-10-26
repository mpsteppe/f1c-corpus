// f1c  0x004b46b0  size=61
_DWORD *__thiscall sub_4B46B0(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // ecx

  memset((char *)this + 1, 0, 0x34u);
  memset((char *)this + 53, 0, 0x34u);
  v2 = this + 28;
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
  this[27] = 0;
  return this;
}
