unsigned int __usercall sub_519019@<eax>(int a1@<ebx>, int a2)
{
  int v2; // esi
  unsigned int result; // eax
  unsigned __int8 v4; // bl
  unsigned int v5; // edx
  bool v6; // zf
  unsigned int v7; // eax
  unsigned int v8; // edx
  int v9; // ecx
  int v10; // eax
  const char *v11; // eax
  unsigned __int8 v12[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = a2;
  result = a2 + 212;
  ++*(_DWORD *)(a2 + 212);
  if ( *(_DWORD *)result >= *(_DWORD *)(v2 + 192) )
  {
    if ( *(_BYTE *)(v2 + 275) )
    {
      *(_DWORD *)result = 0;
      MemsetWithByteFill(a1, v2, *(char **)(v2 + 216), 0, *(_DWORD *)(v2 + 200) + 1);
      while ( 1 )
      {
        v4 = ++*(_BYTE *)(v2 + 276);
        if ( v4 >= 7u )
          break;
        result = (*(_DWORD *)(v2 + 184) - dword_5AFAA0[v4] + dword_5AFABC[v4] - 1) / (unsigned int)dword_5AFABC[v4];
        v5 = ((result * *(unsigned __int8 *)(v2 + 281) + 7) >> 3) + 1;
        v6 = (*(_BYTE *)(v2 + 96) & 2) == 0;
        *(_DWORD *)(v2 + 208) = result;
        *(_DWORD *)(v2 + 204) = v5;
        if ( v6 )
        {
          result = (*(_DWORD *)(v2 + 188) - dword_5AFAD8[v4] + dword_5AFAF4[v4] - 1) / (unsigned int)dword_5AFAF4[v4];
          v6 = *(_DWORD *)(v2 + 208) == 0;
          *(_DWORD *)(v2 + 192) = result;
          if ( v6 )
            continue;
        }
        return result;
      }
    }
    if ( (*(_BYTE *)(v2 + 92) & 0x20) == 0 )
    {
      *(_DWORD *)(v2 + 112) = &a2;
      *(_DWORD *)(v2 + 116) = 1;
      while ( 1 )
      {
        if ( !*(_DWORD *)(v2 + 104) )
        {
          while ( !*(_DWORD *)(v2 + 252) )
          {
            sub_518828(v2, 0);
            CallbackDispatchWithNullGuard(v2, (int)v12, 4);
            *(_DWORD *)(v2 + 252) = ByteArrayToInt(v12);
            AnimationHandleAlloc(v2);
            sub_517F58(v2, v2 + 268, 4);
            if ( *(_DWORD *)(v2 + 268) != *(_DWORD *)"IDAT" )
              GuardedCallWithLongjmp(v2, (int)"Not enough image data");
          }
          v7 = *(_DWORD *)(v2 + 160);
          v8 = *(_DWORD *)(v2 + 252);
          v9 = *(_DWORD *)(v2 + 156);
          *(_DWORD *)(v2 + 104) = v7;
          *(_DWORD *)(v2 + 100) = v9;
          if ( v7 > v8 )
            *(_DWORD *)(v2 + 104) = v8;
          sub_517F58(v2, v9, *(_DWORD *)(v2 + 104));
          *(_DWORD *)(v2 + 252) -= *(_DWORD *)(v2 + 104);
        }
        v10 = sub_517ADC((unsigned __int8 **)(v2 + 100), 1);
        if ( v10 == 1 )
          break;
        if ( v10 )
        {
          v11 = *(const char **)(v2 + 124);
          if ( !v11 )
            v11 = "Decompression Error";
          GuardedCallWithLongjmp(v2, (int)v11);
        }
        if ( !*(_DWORD *)(v2 + 116) )
          GuardedCallWithLongjmp(v2, (int)"Extra compressed data");
      }
      if ( !*(_DWORD *)(v2 + 116) || *(_DWORD *)(v2 + 104) || *(_DWORD *)(v2 + 252) )
        GuardedCallWithLongjmp(v2, (int)"Extra compressed data");
      *(_DWORD *)(v2 + 88) |= 8u;
      *(_DWORD *)(v2 + 92) |= 0x20u;
      *(_DWORD *)(v2 + 116) = 0;
    }
    if ( *(_DWORD *)(v2 + 252) || *(_DWORD *)(v2 + 104) )
      GuardedCallWithLongjmp(v2, (int)"Extra compression data");
    result = ResourceResetWithCounter((_DWORD *)(v2 + 100));
    *(_DWORD *)(v2 + 88) |= 8u;
  }
  return result;
}
