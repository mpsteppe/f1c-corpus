int __fastcall sub_62A860(int a1, int a2, int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  __int32 v11; // [esp+0h] [ebp-14h] BYREF
  __int32 v12; // [esp+4h] [ebp-10h]

  if ( !a1 || *(_BYTE *)(a1 + 92) != 119 )
    return -2;
  *(_DWORD *)a1 = a2;
  *(_DWORD *)(a1 + 4) = a3;
  if ( !a3 )
    goto LABEL_11;
  while ( 1 )
  {
    if ( *(_DWORD *)(a1 + 16) )
      goto LABEL_7;
    v6 = *(_DWORD *)(a1 + 72);
    v12 = *(_DWORD *)(a1 + 64);
    v11 = v12;
    v3 = __readeflags();
    v4 = dword_16F0F8E + dword_16C6E4C + 1;
    __writeeflags(v3);
    _InterlockedExchange(&v11, v4);
    *(_DWORD *)(a1 + 12) = v6;
    if ( sub_631E50(v6, 1, v11, v12) != 0x4000 )
      break;
    *(_DWORD *)(a1 + 16) = 0x4000;
LABEL_7:
    v7 = sub_62B260(a1, 0);
    *(_DWORD *)(a1 + 56) = v7;
    if ( v7 || !*(_DWORD *)(a1 + 4) )
      goto LABEL_11;
  }
  *(_DWORD *)(a1 + 56) = -1;
LABEL_11:
  v8 = sub_62CAA0(a3);
  v9 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a1 + 76) = v8;
  return a3 - v9;
}
