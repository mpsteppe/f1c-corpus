char __thiscall sub_59DE60(int this, int a2, _DWORD *a3)
{
  void *v4; // eax
  DWORD v5; // eax
  int v6; // ecx
  int *v7; // eax
  int v8; // eax
  int v9; // edi
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  void *v14; // eax
  _DWORD *v15; // esi
  DWORD v16; // eax
  int v17; // eax
  char v18; // bl
  void *v19; // esi
  _DWORD v21[4]; // [esp+8h] [ebp-10h] BYREF

  v4 = *(void **)(this + 2804);
  if ( !v4 )
    return 0;
  v5 = WaitForSingleObject(v4, *(_DWORD *)(this + 2808));
  if ( v5 && v5 != 128 )
    return 0;
  v6 = a2;
  if ( a2 >= 0 && a2 < *(_DWORD *)(this + 2800) )
  {
    v7 = *(int **)(this + 2788);
    if ( a2 <= 0 )
    {
LABEL_9:
      if ( v7 )
      {
        v8 = *v7;
        goto LABEL_12;
      }
    }
    else
    {
      while ( v7 )
      {
        v7 = (int *)v7[1];
        if ( --v6 <= 0 )
          goto LABEL_9;
      }
    }
  }
  v8 = 0;
LABEL_12:
  v9 = -1;
  if ( v8 )
  {
    v10 = *(_DWORD **)(v8 + 28);
    v11 = v10[1];
    v21[0] = *v10;
    v12 = v10[2];
    v13 = v10[3];
    v21[2] = v12;
    v21[3] = v13;
    v9 = v11;
  }
  if ( *(_DWORD *)(this + 2804) )
    ReleaseMutex(*(HANDLE *)(this + 2804));
  if ( v9 == -1 )
    return 0;
  v14 = *(void **)(this + 2860);
  v15 = (_DWORD *)(this + 2844);
  if ( !v14 )
    return 0;
  v16 = WaitForSingleObject(v14, v15[5]);
  if ( v16 )
  {
    if ( v16 != 128 )
      return 0;
  }
  v17 = sub_59D540(v15, (int)v21);
  if ( v17 )
  {
    *a3 = *(_DWORD *)(v17 + 4);
    v18 = 1;
  }
  else
  {
    v18 = 0;
  }
  v19 = (void *)v15[4];
  if ( v19 )
    ReleaseMutex(v19);
  return v18;
}
