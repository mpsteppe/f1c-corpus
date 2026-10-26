int __thiscall sub_68466B(_DWORD *this, _DWORD *a2)
{
  _DWORD *v2; // ebx
  unsigned int v4; // ecx
  int v5; // edi
  _DWORD *v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // edx
  unsigned int v10; // edi
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v16; // [esp+8h] [ebp-10h]
  unsigned int v17; // [esp+Ch] [ebp-Ch]
  unsigned int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]

  v2 = a2;
  if ( (*a2 & 0xFFF00000) != 0 )
  {
    v4 = *a2 & 0xFFFFF;
    v17 = v4;
    if ( a2[1] / v4 )
    {
      v19 = 0;
      v16 = a2[1] / v4;
      do
      {
        v5 = v19;
        v18 = v4;
        do
        {
          v6 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v5 + v2[2]));
          v7 = v6[18];
          if ( v7 != -1 && v6[2] == -1 )
          {
            v8 = *(_DWORD *)(this[6] + 4 * v7);
            v6[16] |= 1 << *(_DWORD *)(v8 + 36);
            v2 = a2;
            *(_DWORD *)(v8 + 40) = 1;
          }
          v5 += 4;
          --v18;
        }
        while ( v18 );
        v9 = v19;
        v10 = v17;
        do
        {
          v11 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v9 + v2[2]));
          v12 = *(_DWORD *)(v11 + 72);
          if ( v12 != -1 && *(_DWORD *)(v11 + 8) == -1 )
          {
            v13 = *(_DWORD *)(this[6] + 4 * v12);
            if ( *(_DWORD *)(v13 + 40) )
            {
              v14 = ((unsigned __int8)*(_DWORD *)(v13 + 36) + 1) & 0x1F;
              *(_DWORD *)(v13 + 40) = 0;
              *(_DWORD *)(v13 + 36) = v14;
            }
          }
          v9 += 4;
          --v10;
        }
        while ( v10 );
        v4 = v17;
        v19 += 4 * v17;
        --v16;
      }
      while ( v16 );
    }
  }
  return 0;
}
