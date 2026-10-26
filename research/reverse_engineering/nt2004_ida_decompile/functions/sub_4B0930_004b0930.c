int __thiscall sub_4B0930(int this, char a2)
{
  int result; // eax

  result = *(_DWORD *)(this + 8);
  if ( result && (*(_BYTE *)(this + 28) || a2) )
  {
    result = sub_5A2B00(result);
    *(_DWORD *)(this + 8) = 0;
  }
  return result;
}
