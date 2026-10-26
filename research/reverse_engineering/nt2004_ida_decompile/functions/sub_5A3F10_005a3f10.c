char __thiscall sub_5A3F10(int this, int a2)
{
  char result; // al

  *(_DWORD *)(this + 152) = a2;
  result = *(_BYTE *)(this + 155);
  if ( result )
    *(_DWORD *)(this + 156) = 32;
  else
    *(_DWORD *)(this + 156) &= ~0x20u;
  return result;
}
