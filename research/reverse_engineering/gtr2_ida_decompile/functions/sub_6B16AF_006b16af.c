int __thiscall sub_6B16AF(_DWORD *this)
{
  if ( (unsigned __int16)this[50] >= 0x200u )
    *(_DWORD *)(this[67] + 4 * this[70]) |= (this[68] - this[70] - 1) << 24;
  return 0;
}
