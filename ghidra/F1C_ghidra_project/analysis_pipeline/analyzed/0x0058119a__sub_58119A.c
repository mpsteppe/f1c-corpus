// Address: 0x0058119a
// Size: 146 bytes
// Name: sub_58119A
// Type: char __thiscall(_DWORD *this, int, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
char __thiscall sub_58119A(_DWORD *this, int a2, int a3)
{
  void *v3; // eax
  _DWORD *v4; // esi
  void *v5; // esi
  void *v7; // esi

  v3 = (void *)this[400];
  v4 = this + 393;
  if ( v3 )
    WaitForSingleObject(v3, this[401]);
  if ( sub_587100(a2, a3) )
  {
    v7 = (void *)v4[7];
    if ( v7 )
      ReleaseMutex(v7);
    return 0;
  }
  else
  {
    sub_587230(1);
    v5 = (void *)v4[7];
    if ( v5 )
      ReleaseMutex(v5);
    sub_57E280(1.0);
    return 1;
  }
}
