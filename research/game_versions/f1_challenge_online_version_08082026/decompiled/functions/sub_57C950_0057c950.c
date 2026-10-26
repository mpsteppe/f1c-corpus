char __thiscall sub_57C950(int this, int a2, int a3, int *a4)
{
  char v4; // bl
  void *v6; // eax
  int v7; // esi
  DWORD v8; // eax
  int v9; // eax
  int v10; // ecx
  int *v11; // eax
  int v12; // eax
  _DWORD *v13; // eax
  void *v14; // eax

  v4 = 0;
  if ( a4 )
  {
    v6 = *(void **)(this + 2776);
    v7 = this + 2760;
    if ( v6 && ((v8 = WaitForSingleObject(v6, *(_DWORD *)(this + 2780))) == 0 || v8 == 128) )
      v9 = v7;
    else
      v9 = 0;
    v10 = *a4;
    if ( *a4 >= 0 && v10 < *(_DWORD *)(v9 + 12) )
    {
      v11 = *(int **)v9;
      if ( v10 <= 0 )
      {
LABEL_13:
        if ( v11 )
        {
          v12 = *v11;
          if ( v12 )
          {
            v13 = sub_4B3DB0(*(void **)(v12 + 28));
            v4 = 1;
            *(_DWORD *)a2 = *v13;
            *(_DWORD *)(a2 + 4) = v13[1];
            *(_DWORD *)(a2 + 8) = v13[2];
            *(_DWORD *)(a2 + 12) = v13[3];
          }
        }
      }
      else
      {
        while ( v11 )
        {
          v11 = (int *)v11[1];
          if ( --v10 <= 0 )
            goto LABEL_13;
        }
      }
    }
    v14 = *(void **)(v7 + 16);
    if ( v14 )
      ReleaseMutex(v14);
    return v4;
  }
  else
  {
    *(_WORD *)(a2 + 2) = *(_WORD *)(this + 2320);
    *(_DWORD *)(a2 + 4) = -1;
    return 1;
  }
}
