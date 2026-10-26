char __thiscall sub_59F170(_DWORD *this, int a2)
{
  void *v2; // eax
  _DWORD *v3; // esi
  void *v4; // esi

  v2 = (void *)this[759];
  v3 = this + 751;
  if ( v2 )
    WaitForSingleObject(v2, this[760]);
  (*(void (__thiscall **)(int))(*(_DWORD *)a2 + 8))(a2);
  sub_5E5780(a2, 0);
  v4 = (void *)v3[8];
  if ( v4 )
    ReleaseMutex(v4);
  return 1;
}
