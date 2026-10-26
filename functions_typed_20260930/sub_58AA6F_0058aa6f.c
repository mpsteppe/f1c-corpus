void __cdecl sub_58AA6F(LPVOID lpMem)
{
  int v1; // eax
  bool v2; // zf
  int v3; // eax
  int v4; // [esp+Ch] [ebp-28h] BYREF
  int v5; // [esp+10h] [ebp-24h]
  int v6; // [esp+14h] [ebp-20h] BYREF
  int v7; // [esp+18h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  if ( lpMem )
  {
    if ( dword_8D4908 == 3 )
    {
      CriticalSectionLazyInitEnter(9);
      ms_exc.registration.TryLevel = 0;
      v1 = sub_593E1B(lpMem);
      v7 = v1;
      if ( v1 )
        sub_593E46(v1, lpMem);
      ms_exc.registration.TryLevel = -1;
      CritSectLeave(9);
      v2 = v7 == 0;
    }
    else
    {
      if ( dword_8D4908 != 2 )
      {
LABEL_11:
        HeapFree(hHeap, 0, lpMem);
        return;
      }
      CriticalSectionLazyInitEnter(9);
      ms_exc.registration.TryLevel = 1;
      v3 = MemoryRegionValidationHeapLookup(lpMem, &v4, &v6);
      v5 = v3;
      if ( v3 )
        CounterThreshold(v4, v6, v3);
      ms_exc.registration.TryLevel = -1;
      CritSectLeave(9);
      v2 = v5 == 0;
    }
    if ( !v2 )
      return;
    goto LABEL_11;
  }
}

