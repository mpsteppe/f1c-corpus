// f1c  0x00585f90  size=27
bool __thiscall sub_585F90(_DWORD *this)
{
  void *v1; // ecx
  BOOL v2; // eax

  v1 = (void *)this[20];
  v2 = 0;
  if ( v1 )
    return ReleaseMutex(v1);
  return v2;
}
