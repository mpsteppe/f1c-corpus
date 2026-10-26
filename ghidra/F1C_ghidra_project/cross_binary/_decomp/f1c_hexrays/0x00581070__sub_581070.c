// f1c  0x00581070  size=297
char __thiscall sub_581070(int this, int a2)
{
  void *v3; // eax
  DWORD v4; // eax
  int v5; // ecx
  int *v6; // eax
  bool v7; // zf
  int v8; // eax
  int v9; // eax
  int *v10; // eax
  void *v11; // eax
  void *v12; // esi
  char v14; // [esp+13h] [ebp-29h]
  _BYTE v15[28]; // [esp+14h] [ebp-28h] BYREF
  int v16; // [esp+38h] [ebp-4h]

  v14 = 0;
  sub_587030(-1, 255, 0);
  v3 = *(void **)(this + 2776);
  v16 = 0;
  if ( v3 && ((v4 = WaitForSingleObject(v3, *(_DWORD *)(this + 2780))) == 0 || v4 == 128) )
    v5 = this + 2760;
  else
    v5 = 0;
  v6 = *(int **)v5;
  v7 = *(_DWORD *)v5 == 0;
  *(_DWORD *)(v5 + 8) = *(_DWORD *)v5;
  if ( !v7 )
  {
    v8 = *v6;
    if ( v8 )
    {
      while ( *(_DWORD *)(v8 + 20) != a2 )
      {
        v9 = *(_DWORD *)(v5 + 8);
        if ( v9 )
        {
          v10 = *(int **)(v9 + 4);
          *(_DWORD *)(v5 + 8) = v10;
          if ( v10 )
          {
            v8 = *v10;
            if ( v8 )
              continue;
          }
        }
        goto LABEL_14;
      }
      sub_587370(v8);
      v14 = 1;
    }
  }
LABEL_14:
  if ( *(_DWORD *)(this + 2776) )
    ReleaseMutex(*(HANDLE *)(this + 2776));
  if ( v14 )
  {
    v11 = *(void **)(this + 1600);
    if ( v11 )
      WaitForSingleObject(v11, *(_DWORD *)(this + 1604));
    sub_587370(v15);
    v12 = *(void **)(this + 1600);
    if ( v12 )
      ReleaseMutex(v12);
  }
  v16 = -1;
  sub_5870D0(v15);
  return v14;
}
