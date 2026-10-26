int __thiscall sub_42E470(_BYTE *this, int a2, int a3)
{
  int result; // eax

  result = a2;
  if ( *(_DWORD *)(a2 + 16) == *(_DWORD *)(a3 + 16) )
  {
    result = *(_DWORD *)(a2 + 20);
    if ( *(_DWORD *)(a3 + 20) != result )
    {
      *(_DWORD *)(a3 + 20) = result;
      this[6564] = 1;
      *this = 1;
    }
  }
  return result;
}
