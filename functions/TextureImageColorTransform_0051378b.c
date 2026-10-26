void __cdecl sub_51378B(int a1)
{
  int v2; // edi
  int v3; // ecx
  _BYTE *v4; // eax
  unsigned int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned __int16 v8; // cx
  int v9; // eax
  int v10; // edi
  char v11; // [esp+Ch] [ebp-4h]
  char v12; // [esp+18h] [ebp+8h]

  v2 = *(unsigned __int8 *)(a1 + 278);
  if ( ((unsigned int)&unk_602000 & *(_DWORD *)(a1 + 96)) != 0 )
  {
    EngineSoundWaveTableGenerator(a1);
    if ( v2 == 3 )
    {
      v3 = *(unsigned __int16 *)(a1 + 264);
      if ( *(_WORD *)(a1 + 264) )
      {
        v4 = (_BYTE *)(*(_DWORD *)(a1 + 260) + 2);
        do
        {
          *(v4 - 2) = *(_BYTE *)((unsigned __int8)*(v4 - 2) + *(_DWORD *)(a1 + 312));
          *(v4 - 1) = *(_BYTE *)((unsigned __int8)*(v4 - 1) + *(_DWORD *)(a1 + 312));
          *v4 = *(_BYTE *)((unsigned __int8)*v4 + *(_DWORD *)(a1 + 312));
          v4 += 3;
          --v3;
        }
        while ( v3 );
      }
    }
  }
  if ( (*(_BYTE *)(a1 + 96) & 8) != 0 && v2 == 3 )
  {
    v5 = 8 - *(unsigned __int8 *)(a1 + 336);
    v6 = 8 - *(unsigned __int8 *)(a1 + 337);
    v7 = 8 - *(unsigned __int8 *)(a1 + 338);
    v12 = 8 - *(_BYTE *)(a1 + 337);
    v11 = 8 - *(_BYTE *)(a1 + 338);
    if ( v5 > 8 )
      LOBYTE(v5) = 0;
    if ( v6 > 8 )
      v12 = 0;
    if ( v7 > 8 )
      v11 = 0;
    v8 = *(_WORD *)(a1 + 264);
    if ( v8 )
    {
      v9 = 0;
      v10 = v8;
      do
      {
        *(_BYTE *)(v9 + *(_DWORD *)(a1 + 260)) >>= v5;
        *(_BYTE *)(v9 + *(_DWORD *)(a1 + 260) + 1) >>= v12;
        *(_BYTE *)(v9 + *(_DWORD *)(a1 + 260) + 2) >>= v11;
        v9 += 3;
        --v10;
      }
      while ( v10 );
    }
  }
}
