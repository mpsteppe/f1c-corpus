BOOL __cdecl sub_517F72(int a1)
{
  int v1; // esi
  int v2; // edi

  v1 = a1;
  v2 = 1;
  if ( (*(_BYTE *)(a1 + 268) & 0x20) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 92) & 0x300) != 0x300 )
      goto LABEL_6;
  }
  else if ( (*(_BYTE *)(a1 + 93) & 8) == 0 )
  {
    goto LABEL_6;
  }
  v2 = 0;
LABEL_6:
  CallbackDispatchWithNullGuard(a1, (int)&a1, 4);
  return v2 && ByteArrayToInt((unsigned __int8 *)&a1) != *(_DWORD *)(v1 + 256);
}

