// f1c  0x0057ec10  size=293
char __thiscall sub_57EC10(int this, int a2, _DWORD *a3)
{
  void *v4; // eax
  DWORD v5; // eax
  int v6; // ecx
  int *v7; // eax
  int v8; // eax
  int v9; // edi
  void *v10; // eax
  DWORD v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  void *v14; // esi
  char v16; // [esp+13h] [ebp-11h]

  v4 = *(void **)(this + 2776);
  v16 = 0;
  if ( !v4 )
    return 0;
  v5 = WaitForSingleObject(v4, *(_DWORD *)(this + 2780));
  if ( v5 )
  {
    if ( v5 != 128 )
      return 0;
  }
  v6 = a2;
  if ( a2 >= 0 && a2 < *(_DWORD *)(this + 2772) )
  {
    v7 = *(int **)(this + 2760);
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
    v9 = *((_DWORD *)sub_4B3DB0(*(void **)(v8 + 28)) + 1);
  if ( *(_DWORD *)(this + 2776) )
    ReleaseMutex(*(HANDLE *)(this + 2776));
  if ( v9 != -1 )
  {
    v10 = *(void **)(this + 2832);
    if ( v10 )
    {
      v11 = WaitForSingleObject(v10, *(_DWORD *)(this + 2836));
      if ( !v11 || v11 == 128 )
      {
        v12 = *(_DWORD **)(this + 2816);
        if ( v12 )
        {
          while ( !*v12 || *(_DWORD *)*v12 != v9 )
          {
            v12 = (_DWORD *)v12[1];
            if ( !v12 )
              goto LABEL_27;
          }
          v13 = (_DWORD *)*v12;
          if ( v13 )
          {
            v16 = 1;
            *a3 = v13[1];
          }
        }
LABEL_27:
        v14 = *(void **)(this + 2832);
        if ( v14 )
          ReleaseMutex(v14);
      }
    }
  }
  return v16;
}
