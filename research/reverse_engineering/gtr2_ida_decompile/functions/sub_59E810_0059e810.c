char __thiscall sub_59E810(_DWORD *this, int a2, int a3)
{
  void *v4; // eax
  _DWORD *v5; // esi
  DWORD v6; // eax
  _DWORD *v7; // edi
  void *v8; // esi
  void *v10; // esi

  v4 = (void *)this[404];
  v5 = this + 397;
  if ( v4 && ((v6 = WaitForSingleObject(v4, this[405])) == 0 || v6 == 128) )
    v7 = v5;
  else
    v7 = 0;
  if ( sub_5A6DA0(v7, a2, a3) )
  {
    v10 = (void *)v5[7];
    if ( v10 )
      ReleaseMutex(v10);
    return 0;
  }
  else
  {
    sub_5A6EC0(1);
    v8 = (void *)v5[7];
    if ( v8 )
      ReleaseMutex(v8);
    sub_59DA50(this, 1.0);
    return 1;
  }
}
