char __thiscall sub_57EE80(int this, _DWORD *a2, _DWORD *a3, DWORD dwMilliseconds)
{
  char v5; // bl
  DWORD v6; // eax
  _DWORD **v7; // eax
  _DWORD *v8; // esi
  int v9; // eax
  _DWORD **v10; // eax
  void *v11; // edi

  v5 = 0;
  v6 = WaitForSingleObject(*(HANDLE *)(this + 2776), dwMilliseconds);
  if ( v6 != 258 && v6 != -1 )
  {
    v7 = *(_DWORD ***)(this + 2760);
    *(_DWORD *)(this + 2768) = v7;
    if ( v7 )
    {
      v8 = *v7;
      if ( *v7 )
      {
        while ( !NetworkMessageEventComparisonWithShortMasking(v8, a2) )
        {
          v9 = *(_DWORD *)(this + 2768);
          if ( v9 )
          {
            v10 = *(_DWORD ***)(v9 + 4);
            *(_DWORD *)(this + 2768) = v10;
            if ( v10 )
            {
              v8 = *v10;
              if ( *v10 )
                continue;
            }
          }
          v5 = 0;
          goto LABEL_10;
        }
        v5 = 1;
        *a3 = ReadFieldAtOffset0x14(v8);
      }
    }
LABEL_10:
    v11 = *(void **)(this + 2776);
    if ( v11 )
      ReleaseMutex(v11);
  }
  return v5;
}
