int __thiscall sub_558B30(int this, int a2)
{
  int result; // eax
  int v4; // edi
  int v5; // ebx
  int v6; // edx
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  int v9; // eax
  int v10; // [esp+10h] [ebp+4h]

  result = *(_DWORD *)(this + 48);
  if ( result <= 0 )
    return result;
  if ( a2 >= *(_DWORD *)(this + 44) )
    return result;
  v4 = *(_DWORD *)(this + 52) + (a2 << 7);
  if ( (*(_BYTE *)v4 & 0x40) == 0 )
    return result;
  if ( *(char *)(this + 32) >= 0 )
  {
    v9 = *(_DWORD *)(v4 + 120);
    if ( v9 )
      *(_DWORD *)(v9 + 124) = *(_DWORD *)(v4 + 124);
    result = *(_DWORD *)(v4 + 124);
    if ( result )
      *(_DWORD *)(result + 120) = *(_DWORD *)(v4 + 120);
    if ( !*(_DWORD *)(v4 + 120) )
      *(_DWORD *)(this + 56) = *(_DWORD *)(v4 + 124);
    *(_DWORD *)(v4 + 120) = 0;
    *(_DWORD *)(v4 + 124) = 0;
    goto LABEL_17;
  }
  if ( *(_DWORD *)(*(_DWORD *)(this + 60) + 4 * result - 4) == v4 )
  {
LABEL_17:
    *(_DWORD *)v4 &= ~0x40u;
    --*(_DWORD *)(this + 48);
    return result;
  }
  TextureAllocationWithFormatSizeFlags(0);
  v5 = *(_DWORD *)(*(_DWORD *)(this + 80) + 32);
  if ( v5 )
  {
    v6 = *(_DWORD *)(this + 36);
    v7 = (_DWORD *)(v5 + ((v6 * *(_DWORD *)(v4 + 4)) << 6));
    v8 = (_DWORD *)(v5
                  + ((v6 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 60) + 4 * *(_DWORD *)(this + 48) - 4) + 4)) << 6));
    v10 = 0;
    if ( v6 > 0 )
    {
      do
      {
        *v7 = *v8;
        v7[1] = v8[1];
        v7[2] = v8[2];
        v7[6] = v8[6];
        v7 += 16;
        v8 += 16;
        ++v10;
      }
      while ( v10 < *(_DWORD *)(this + 36) );
    }
  }
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 60) + 4 * *(_DWORD *)(this + 48) - 4) + 4) = *(_DWORD *)(v4 + 4);
  *(_DWORD *)(*(_DWORD *)(this + 60) + 4 * *(_DWORD *)(v4 + 4)) = *(_DWORD *)(*(_DWORD *)(this + 60)
                                                                            + 4 * *(_DWORD *)(this + 48)
                                                                            - 4);
  *(_DWORD *)v4 &= ~0x40u;
  result = *(_DWORD *)(this + 48) - 1;
  *(_DWORD *)(this + 48) = result;
  return result;
}
