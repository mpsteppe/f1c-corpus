BOOL __thiscall sub_67EC87(_DWORD *this, int a2)
{
  BOOL result; // eax

  result = a2;
  if ( a2 )
    return this[1] == *(_DWORD *)(a2 + 4);
  return result;
}
