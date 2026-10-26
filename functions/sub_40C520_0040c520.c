int __thiscall sub_40C520(_DWORD *this)
{
  int result; // eax

  *(_DWORD *)(this[8] + 8) = this[7];
  result = this[7];
  *(_DWORD *)(result + 8) = this[8];
  return result;
}
