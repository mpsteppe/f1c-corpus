int __thiscall sub_49ECA0(_DWORD *this)
{
  int result; // eax

  result = this[1];
  if ( result )
  {
    result = ResourceCascadeCleanup(result);
    this[1] = 0;
  }
  return result;
}
