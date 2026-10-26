char __thiscall sub_41FC00(int this)
{
  char result; // al

  result = *(_BYTE *)(this + 20416);
  if ( !result )
  {
    *(_DWORD *)(this + 20444) = 0;
    *(_BYTE *)(this + 21516) = 1;
  }
  return result;
}
