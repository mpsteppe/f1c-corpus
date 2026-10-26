int __thiscall sub_499B50(_DWORD *this)
{
  int result; // eax

  result = this[12];
  if ( result )
  {
    result = ResourceCascadeCleanup(result);
    this[12] = 0;
  }
  if ( this[11] )
    return DestructorWithConditionalFreeFlagClear();
  return result;
}

