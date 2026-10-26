char __thiscall sub_406700(_DWORD *this, int a2)
{
  void *v3; // eax
  DWORD v4; // eax
  void *v5; // esi

  v3 = (void *)this[20];
  if ( !v3 )
    return 0;
  v4 = WaitForSingleObject(v3, this[21]);
  if ( v4 )
  {
    if ( v4 != 128 )
      return 0;
  }
  this[19] = a2;
  v5 = (void *)this[20];
  if ( v5 )
    ReleaseMutex(v5);
  return 1;
}

