int __thiscall sub_4AEF30(_DWORD *this)
{
  int result; // eax

  result = 0;
  this[15] = 0;
  this[16] = 0;
  this[17] = 0;
  this[22] = 0;
  this[23] = 0;
  this[19] = 0;
  this[21] = 1;
  this[20] = 0;
  memset(this + 24, 0, 0x28u);
  memset(this + 34, 0, 0x28u);
  return result;
}
