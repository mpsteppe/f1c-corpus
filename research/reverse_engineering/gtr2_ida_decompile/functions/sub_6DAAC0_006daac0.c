int __stdcall sub_6DAAC0(int a1, _BYTE *a2, int a3, int a4)
{
  int result; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edx

  if ( *(int *)(a1 + 124) <= 0 )
  {
    if ( a3 + 4 <= (unsigned int)(a3 + 5) && a2 )
    {
      sub_6DA86B(a1, a2, a3, a4);
    }
    else
    {
      v5 = *(_DWORD *)(a1 + 5812);
      v6 = a4 + 2;
      if ( v5 <= 13 )
      {
        *(_WORD *)(a1 + 5808) |= v6 << v5;
        *(_DWORD *)(a1 + 5812) = v5 + 3;
      }
      else
      {
        v7 = v6 << v5;
        v8 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5808) |= v7;
        *(_BYTE *)(v8 + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5808);
        *(_BYTE *)(*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5809);
        v9 = *(_DWORD *)(a1 + 5812);
        ++*(_DWORD *)(a1 + 20);
        *(_DWORD *)(a1 + 5812) = v9 - 13;
        *(_WORD *)(a1 + 5808) = (unsigned __int16)v6 >> (16 - v9);
      }
      sub_6DA010(a1, (int)&unk_748118, (int)&unk_748598);
    }
    result = sub_6D95B2(a1);
    if ( a4 )
      return sub_6DA486(result);
  }
  else
  {
    if ( *(_BYTE *)(a1 + 28) == 2 )
      sub_6DA3C4((unsigned __int16 *)a1);
    return off_16C9470(a1, a2, a3, a4);
  }
  return result;
}
