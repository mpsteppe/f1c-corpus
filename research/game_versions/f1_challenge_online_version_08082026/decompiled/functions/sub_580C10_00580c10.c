char __thiscall sub_580C10(int this, int *a2, int a3, char a4)
{
  void *v5; // eax
  DWORD v6; // eax
  _DWORD *v7; // eax
  void *v9; // esi
  void *v10; // eax
  DWORD v11; // eax
  int v12; // esi
  _DWORD *v13; // eax
  _DWORD *v14; // edi
  void *v15; // eax
  void *v16; // esi
  int v17; // eax
  _DWORD v19[4]; // [esp+18h] [ebp-1Ch] BYREF
  int v20; // [esp+30h] [ebp-4h]
  _DWORD *v21; // [esp+38h] [ebp+4h]

  LOWORD(v19[0]) = 2;
  v19[1] = htonl(0);
  HIWORD(v19[0]) = htons(0);
  sub_57B9F0((_DWORD *)(this + 2692), v19);
  v5 = *(void **)(this + 2876);
  if ( v5 && ((v6 = WaitForSingleObject(v5, *(_DWORD *)(this + 2880))) == 0 || v6 == 128) )
    v7 = (_DWORD *)(this + 2872);
  else
    v7 = 0;
  *a2 = (*v7)++;
  v9 = *(void **)(this + 2876);
  if ( v9 )
    ReleaseMutex(v9);
  v10 = *(void **)(this + 2776);
  if ( v10 && ((v11 = WaitForSingleObject(v10, *(_DWORD *)(this + 2780))) == 0 || v11 == 128) )
    v21 = (_DWORD *)(this + 2760);
  else
    v21 = 0;
  v12 = v21[3];
  v13 = (_DWORD *)sub_587C03(32);
  v20 = 0;
  if ( v13 )
    v14 = sub_57B780(v13, *a2, v12, a3);
  else
    v14 = 0;
  v20 = -1;
  if ( a3 > 0 && a3 <= 2 )
  {
    if ( a4 )
    {
      v15 = *(void **)(this + 1600);
      if ( v15 )
        WaitForSingleObject(v15, *(_DWORD *)(this + 1604));
      sub_587370(v14);
      v16 = *(void **)(this + 1600);
      if ( v16 )
        ReleaseMutex(v16);
    }
    else
    {
      sub_57DD40((int **)this, v19, (int)v14);
    }
  }
  if ( v14 )
  {
    v17 = sub_587C03(12);
    if ( v17 )
    {
      *(_DWORD *)v17 = v14;
      *(_DWORD *)(v17 + 4) = 0;
      *(_BYTE *)(v17 + 8) = 1;
    }
    else
    {
      v17 = 0;
    }
    if ( *v21 )
    {
      *(_DWORD *)(v21[1] + 4) = v17;
    }
    else
    {
      *v21 = v17;
      v21[2] = v17;
    }
    v21[1] = v17;
    ++v21[3];
  }
  if ( *(_DWORD *)(this + 2776) )
    ReleaseMutex(*(HANDLE *)(this + 2776));
  return 1;
}
