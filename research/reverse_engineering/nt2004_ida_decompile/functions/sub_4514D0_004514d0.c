int __thiscall sub_4514D0(_DWORD *this)
{
  int v1; // eax
  _DWORD *v2; // edx
  int result; // eax

  this[802] = 0;
  v1 = 0;
  v2 = this + 544;
  do
  {
    *((_BYTE *)this + v1 + 896) = 0;
    *v2 = 0;
    ++v1;
    ++v2;
  }
  while ( v1 < 256 );
  result = 0;
  memset(this + 803, 0, 0x30u);
  return result;
}
