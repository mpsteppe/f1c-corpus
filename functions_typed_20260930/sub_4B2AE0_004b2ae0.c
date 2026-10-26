int __thiscall sub_4B2AE0(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax

  v2 = this[12];
  result = (v2 ^ (a2 << 28)) & 0x70000000;
  this[12] = result ^ v2;
  return result;
}

