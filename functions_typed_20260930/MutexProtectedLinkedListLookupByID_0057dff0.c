char __thiscall sub_57DFF0(int this, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // ebx
  void *v8; // eax
  int v9; // esi
  DWORD v10; // eax
  int v11; // ecx
  int *v12; // eax
  int v13; // eax
  int v14; // eax
  int *v15; // eax

  v7 = 0;
  v8 = *(void **)(this + 2748);
  v9 = this + 2732;
  if ( v8 && ((v10 = WaitForSingleObject(v8, *(_DWORD *)(this + 2752))) == 0 || v10 == 128) )
    v11 = v9;
  else
    v11 = 0;
  v12 = *(int **)v11;
  *(_DWORD *)(v11 + 8) = *(_DWORD *)v11;
  if ( v12 )
  {
    v13 = *v12;
    if ( v13 )
    {
      while ( (*(_DWORD *)(v13 + 4) != a3 || *(_WORD *)(v13 + 2) != HIWORD(a2))
           && (*(_DWORD *)(v13 + 20) != a3 || *(_WORD *)(v13 + 18) != HIWORD(a2)) )
      {
        v14 = *(_DWORD *)(v11 + 8);
        if ( v14 )
        {
          v15 = *(int **)(v14 + 4);
          *(_DWORD *)(v11 + 8) = v15;
          if ( v15 )
          {
            v13 = *v15;
            if ( v13 )
              continue;
          }
        }
        goto LABEL_17;
      }
      v7 = v13;
    }
  }
LABEL_17:
  if ( *(_DWORD *)(v9 + 16) )
    ReleaseMutex(*(HANDLE *)(v9 + 16));
  if ( v7 )
    return sub_57DE30((char *)this, v7, a6);
  else
    return 0;
}

