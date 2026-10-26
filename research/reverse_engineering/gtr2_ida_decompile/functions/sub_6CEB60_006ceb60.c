int __stdcall sub_6CEB60(int a1)
{
  int v1; // edi
  int v2; // esi
  int v3; // ebx
  int v4; // esi
  _WORD *v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  _DWORD *v9; // ecx
  int v10; // edi
  bool v11; // zf
  int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  _WORD **i; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 432);
  v3 = 0;
  v14 = 0;
  if ( *(_DWORD *)(a1 + 224) && *(_DWORD *)(a1 + 164) )
  {
    if ( !*(_DWORD *)(v2 + 112) )
      *(_DWORD *)(v2 + 112) = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 24 * *(_DWORD *)(a1 + 36));
    v4 = *(_DWORD *)(v2 + 112);
    v13 = *(_DWORD *)(a1 + 36);
    if ( v13 <= 0 )
      return v14;
    v16 = 0;
    for ( i = (_WORD **)(*(_DWORD *)(a1 + 220) + 76); ; i += 21 )
    {
      v5 = *i;
      if ( !*i )
        break;
      if ( !*v5 )
        break;
      if ( !v5[1] )
        break;
      if ( !v5[8] )
        break;
      if ( !v5[16] )
        break;
      if ( !v5[9] )
        break;
      if ( !v5[2] )
        break;
      v6 = *(_DWORD *)(v1 + 164);
      v7 = *(_DWORD *)(v6 + v16);
      v8 = v16 + v6;
      if ( v7 < 0 )
        break;
      v9 = (_DWORD *)(v8 + 4);
      v10 = 5;
      do
      {
        v11 = *v9 == 0;
        *(_DWORD *)((char *)v9 + v4 - v8) = *v9;
        if ( !v11 )
          v14 = 1;
        ++v9;
        --v10;
      }
      while ( v10 );
      v4 += 24;
      ++v3;
      v16 += 256;
      if ( v3 >= v13 )
        return v14;
      v1 = a1;
    }
  }
  return 0;
}
