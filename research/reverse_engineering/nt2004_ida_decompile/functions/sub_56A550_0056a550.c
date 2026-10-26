char __thiscall sub_56A550(int *this)
{
  int v1; // ecx
  void *v2; // eax
  int v3; // esi
  DWORD v4; // eax
  int v5; // ecx
  char v6; // al
  void *v7; // esi
  char v8; // bl

  v1 = *this;
  v2 = *(void **)(v1 + 1600);
  v3 = v1 + 1572;
  if ( v2 && ((v4 = WaitForSingleObject(v2, *(_DWORD *)(v1 + 1604))) == 0 || v4 == 128) )
    v5 = v3;
  else
    v5 = 0;
  v6 = sub_5772A0(v5);
  v7 = *(void **)(v3 + 28);
  v8 = v6;
  if ( v7 )
    ReleaseMutex(v7);
  return v8;
}
