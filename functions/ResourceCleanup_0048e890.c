char __thiscall sub_48E890(_DWORD *this)
{
  int v2; // eax

  v2 = this[58];
  if ( v2 )
  {
    MutexSemaphoreCleanup(v2);
    this[58] = 0;
  }
  this[59] = 0;
  return 1;
}
