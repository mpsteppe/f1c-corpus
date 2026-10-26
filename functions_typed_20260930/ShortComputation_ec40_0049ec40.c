int __thiscall sub_49EC40(int *this)
{
  int result; // eax

  result = *this;
  if ( *this )
  {
    result = ResourceCascadeCleanup(result);
    *this = 0;
  }
  return result;
}

