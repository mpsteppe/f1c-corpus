int __thiscall sub_42F780(_DWORD *this, int a2)
{
  int result; // eax

  result = this[4];
  if ( *(_DWORD *)(result + 108) )
    return sub_54B280(result + 80);
  return result;
}
