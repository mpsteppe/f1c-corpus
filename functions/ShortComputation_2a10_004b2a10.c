int __thiscall sub_4B2A10(_DWORD *this, char a2)
{
  unsigned __int16 v2; // dx
  int result; // eax

  LOBYTE(v2) = 0;
  HIBYTE(v2) = a2 + 1;
  result = ((unsigned __int16)this[11] ^ v2) & 0xF00 ^ this[11];
  this[11] = result;
  return result;
}
