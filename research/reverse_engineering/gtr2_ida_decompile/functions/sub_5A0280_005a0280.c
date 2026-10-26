char __thiscall sub_5A0280(_DWORD *this, int a2)
{
  void *v2; // eax
  _DWORD *v3; // edi
  int v4; // esi
  void *v5; // edi
  void *v6; // eax
  void *v7; // esi

  v2 = (void *)this[737];
  v3 = this + 729;
  if ( v2 )
    WaitForSingleObject(v2, this[738]);
  v4 = *(_DWORD *)(a2 + 72);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
  sub_5E5780(v4, 0);
  v5 = (void *)v3[8];
  if ( v5 )
    ReleaseMutex(v5);
  v6 = (void *)this[748];
  if ( v6 )
    WaitForSingleObject(v6, this[749]);
  sub_5A6B80(a2);
  sub_5E5780(a2, 0);
  v7 = (void *)this[748];
  if ( v7 )
    ReleaseMutex(v7);
  return 1;
}
