char __thiscall sub_5A0CE0(_DWORD *this, int *a2, _DWORD *a3)
{
  void *v3; // eax
  _DWORD *v4; // esi
  int v5; // eax
  void *v6; // esi
  int v7; // edi

  v3 = (void *)this[759];
  v4 = this + 751;
  if ( v3 )
    WaitForSingleObject(v3, this[760]);
  v5 = sub_5A0560();
  v6 = (void *)v4[8];
  v7 = v5;
  if ( v6 )
    ReleaseMutex(v6);
  *a2 = v7;
  *a3 = 308;
  return 1;
}
