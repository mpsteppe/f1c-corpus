int __thiscall sub_42A730(_DWORD *this)
{
  int result; // eax

  result = this[2];
  if ( result )
    return *(_DWORD *)(result + 44);
  return result;
}
