// f1c  0x004b69a0  size=45
_DWORD *__thiscall sub_4B69A0(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx

  v2 = this[620];
  v3 = (this[622] + 1) % this[621];
  this[622] = v3;
  return sub_4B4E10((char *)(v2 + 176 * v3));
}
