DWORD __thiscall sub_574140(HANDLE *this)
{
  DWORD result; // eax
  HANDLE v3; // esi

  result = WaitForSingleObject(this[53], 1u);
  if ( result != 258 && result != -1 )
  {
    v3 = this[53];
    if ( v3 )
      return ReleaseMutex(v3);
  }
  return result;
}
