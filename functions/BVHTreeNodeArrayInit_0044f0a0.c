int __thiscall sub_44F0A0(_DWORD *this)
{
  int v1; // eax
  _DWORD *v2; // edx
  int result; // eax

  this[801] = 0;
  v1 = 0;
  v2 = this + 543;
  do
  {
    *((_BYTE *)this + v1 + 892) = 0;
    *v2 = 0;
    ++v1;
    ++v2;
  }
  while ( v1 < 256 );
  result = 0;
  memset(this + 802, 0, 0x30u);
  return result;
}
