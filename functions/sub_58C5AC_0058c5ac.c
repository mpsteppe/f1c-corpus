_DWORD *sub_58C5AC()
{
  _DWORD *v0; // edi
  int v1; // esi
  int v2; // eax
  int v3; // esi
  int v4; // eax

  v0 = 0;
  CriticalSectionLazyInitEnter(2);
  v1 = 0;
  if ( dword_8D5A40 > 0 )
  {
    while ( 1 )
    {
      v2 = *(_DWORD *)(dword_8D4A24 + 4 * v1);
      if ( !v2 )
        break;
      if ( (*(_BYTE *)(v2 + 12) & 0x83) == 0 )
      {
        CriticalSectionEnter(v1, *(_DWORD *)(dword_8D4A24 + 4 * v1));
        if ( (*(_BYTE *)(*(_DWORD *)(dword_8D4A24 + 4 * v1) + 12) & 0x83) == 0 )
        {
          v0 = *(_DWORD **)(dword_8D4A24 + 4 * v1);
          goto LABEL_11;
        }
        CriticalSectionLeave_c232(v1, *(_DWORD *)(dword_8D4A24 + 4 * v1));
      }
      if ( ++v1 >= dword_8D5A40 )
        goto LABEL_13;
    }
    v3 = 4 * v1;
    *(_DWORD *)(v3 + dword_8D4A24) = MallocWrapperForNhMalloc(56);
    v4 = *(_DWORD *)(v3 + dword_8D4A24);
    if ( !v4 )
      goto LABEL_13;
    InitializeCriticalSection((LPCRITICAL_SECTION)(v4 + 32));
    EnterCriticalSection((LPCRITICAL_SECTION)(*(_DWORD *)(v3 + dword_8D4A24) + 32));
    v0 = *(_DWORD **)(v3 + dword_8D4A24);
LABEL_11:
    if ( v0 )
    {
      v0[4] = -1;
      v0[1] = 0;
      v0[3] = 0;
      v0[2] = 0;
      *v0 = 0;
      v0[7] = 0;
    }
  }
LABEL_13:
  CritSectLeave(2);
  return v0;
}
