int __cdecl sub_58A0BF(int a1)
{
  int v1; // ebx
  int v2; // edi
  int i; // esi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int result; // eax

  v1 = 0;
  v2 = 0;
  CriticalSectionLazyInitEnter(2);
  for ( i = 0; i < dword_8D5A40; ++i )
  {
    v4 = *(_DWORD *)(dword_8D4A24 + 4 * i);
    if ( v4 && (*(_BYTE *)(v4 + 12) & 0x83) != 0 )
    {
      CriticalSectionEnter(i, *(_DWORD *)(dword_8D4A24 + 4 * i));
      v5 = *(_DWORD *)(dword_8D4A24 + 4 * i);
      v6 = *(_DWORD *)(v5 + 12);
      if ( (v6 & 0x83) != 0 )
      {
        if ( a1 == 1 )
        {
          if ( MemoryBlockValidationCheck(v5) != -1 )
            ++v1;
        }
        else if ( !a1 && (v6 & 2) != 0 && MemoryBlockValidationCheck(*(_DWORD *)(dword_8D4A24 + 4 * i)) == -1 )
        {
          v2 = -1;
        }
      }
      CriticalSectionLeave_c232(i, *(_DWORD *)(dword_8D4A24 + 4 * i));
    }
  }
  CritSectLeave(2);
  result = v1;
  if ( a1 != 1 )
    return v2;
  return result;
}
