char __thiscall sub_4A82F0(int this)
{
  char result; // al

  result = *(_BYTE *)(this + 8);
  if ( result )
    return sub_5BE8AE(*(LPVOID *)this);
  return result;
}
