errno_t __cdecl _set_errno(int Value)
{
  errno_t result; // eax

  result = Value;
  if ( Value == 1 )
  {
    result = (errno_t)_errno();
    *(_DWORD *)result = 33;
  }
  else if ( Value > 1 && Value <= 3 )
  {
    result = (errno_t)_errno();
    *(_DWORD *)result = 34;
  }
  return result;
}
