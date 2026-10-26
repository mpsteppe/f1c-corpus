int __thiscall sub_461F90(int *this)
{
  int result; // eax

  result = *this;
  if ( *(_DWORD *)(*this + 112540) )
  {
    result = sub_563E70();
    if ( result )
      return SetFlagIfPointerNonNull(*(_DWORD *)(*this + 112540));
  }
  return result;
}

