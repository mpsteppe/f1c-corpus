char __usercall sub_519EB7@<al>(int a1@<esi>)
{
  int v1; // edi
  _WORD **v2; // eax
  _WORD *v3; // eax
  int *v4; // eax
  _DWORD *v5; // ecx
  int v6; // edx
  int v7; // eax
  _WORD **i; // [esp+8h] [ebp-14h]
  int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  int v12; // [esp+14h] [ebp-8h]
  char v13; // [esp+1Bh] [ebp-1h]

  v1 = *(_DWORD *)(a1 + 388);
  v13 = 0;
  if ( *(_BYTE *)(a1 + 200) && *(_DWORD *)(a1 + 140) )
  {
    if ( !*(_DWORD *)(v1 + 112) )
      *(_DWORD *)(v1 + 112) = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 24 * *(_DWORD *)(a1 + 32));
    v12 = *(_DWORD *)(v1 + 112);
    v10 = 0;
    if ( *(int *)(a1 + 32) <= 0 )
      return v13;
    v2 = (_WORD **)(*(_DWORD *)(a1 + 196) + 76);
    v11 = 0;
    for ( i = v2; ; i += 21 )
    {
      v3 = *v2;
      if ( !v3 )
        break;
      if ( !*v3 )
        break;
      if ( !v3[1] )
        break;
      if ( !v3[8] )
        break;
      if ( !v3[16] )
        break;
      if ( !v3[9] )
        break;
      if ( !v3[2] )
        break;
      v4 = (int *)(v11 + *(_DWORD *)(a1 + 140));
      if ( *v4 < 0 )
        break;
      v5 = v4 + 1;
      v6 = v12 - (_DWORD)v4;
      v7 = 5;
      do
      {
        *(_DWORD *)((char *)v5 + v6) = *v5;
        if ( *v5 )
          v13 = 1;
        ++v5;
        --v7;
      }
      while ( v7 );
      v12 += 24;
      ++v10;
      v11 += 256;
      v2 = i + 21;
      if ( v10 >= *(_DWORD *)(a1 + 32) )
        return v13;
    }
  }
  return 0;
}
