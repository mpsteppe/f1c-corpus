int __thiscall sub_5A30D0(_DWORD *this)
{
  void *v1; // eax
  _DWORD *v2; // esi
  int v3; // eax
  void *v4; // esi
  int v5; // edi

  v1 = (void *)this[737];
  v2 = this + 729;
  if ( v1 )
    WaitForSingleObject(v1, this[738]);
  v3 = sub_5A2BB0();
  v4 = (void *)v2[8];
  v5 = v3;
  if ( v4 )
    ReleaseMutex(v4);
  return v5;
}
