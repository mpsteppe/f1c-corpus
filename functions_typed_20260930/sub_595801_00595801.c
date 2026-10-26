int sub_595801()
{
  int v0; // edi
  int v1; // ebx
  int *v2; // ebp
  unsigned int v3; // esi
  unsigned int i; // eax
  unsigned int v5; // eax
  unsigned int v6; // edx
  int v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  v0 = -1;
  CriticalSectionLazyInitEnter(18);
  v1 = 0;
  v8 = 0;
  v9 = 0;
  v2 = dword_8D4920;
  while ( 1 )
  {
    v3 = *v2;
    if ( !*v2 )
      break;
    for ( i = v3 + 1152; v3 < i; i = *v2 + 1152 )
    {
      if ( (*(_BYTE *)(v3 + 4) & 1) == 0 )
      {
        if ( !*(_DWORD *)(v3 + 8) )
        {
          CriticalSectionLazyInitEnter(17);
          if ( !*(_DWORD *)(v3 + 8) )
          {
            InitializeCriticalSection((LPCRITICAL_SECTION)(v3 + 12));
            ++*(_DWORD *)(v3 + 8);
          }
          CritSectLeave(17);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(v3 + 12));
        if ( (*(_BYTE *)(v3 + 4) & 1) == 0 )
        {
          *(_DWORD *)v3 = -1;
          v0 = v9 + (int)(v3 - *v2) / 36;
          if ( v0 != -1 )
            goto LABEL_22;
          v1 = v8;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(v3 + 12));
        v1 = v8;
      }
      v3 += 36;
    }
    v9 += 32;
    ++v2;
    v8 = ++v1;
    if ( (int)v2 >= (int)&uNumber )
      goto LABEL_22;
  }
  v5 = MallocWrapperForNhMalloc(1152);
  if ( v5 )
  {
    uNumber += 32;
    v6 = v5 + 1152;
    dword_8D4920[v1] = v5;
    while ( v5 < v6 )
    {
      *(_BYTE *)(v5 + 4) = 0;
      *(_DWORD *)v5 = -1;
      *(_DWORD *)(v5 + 8) = 0;
      *(_BYTE *)(v5 + 5) = 10;
      v5 += 36;
      v6 = dword_8D4920[v1] + 1152;
    }
    v0 = 32 * v1;
    CriticalSectionEnterWithLazyInit(32 * v1);
  }
LABEL_22:
  CritSectLeave(18);
  return v0;
}

