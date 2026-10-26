int __thiscall sub_694F8F(_DWORD *this)
{
  int result; // eax

  result = this[5];
  if ( result )
    return *(_DWORD *)(result + 8);
  return result;
}
