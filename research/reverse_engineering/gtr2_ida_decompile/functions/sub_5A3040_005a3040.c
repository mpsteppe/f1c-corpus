int __thiscall sub_5A3040(_DWORD *this)
{
  void *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax
  void *v5; // esi
  int v6; // edi
  void *v7; // eax
  void *v8; // esi

  v2 = (void *)this[748];
  v3 = this + 740;
  if ( v2 )
    WaitForSingleObject(v2, this[749]);
  v4 = sub_5A1150();
  v5 = (void *)v3[8];
  v6 = v4;
  if ( v5 )
    ReleaseMutex(v5);
  v7 = (void *)this[737];
  if ( v7 )
    WaitForSingleObject(v7, this[738]);
  *(_DWORD *)(v6 + 72) = sub_5A2BB0();
  v8 = (void *)this[737];
  if ( v8 )
    ReleaseMutex(v8);
  return v6;
}
