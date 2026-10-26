int __usercall sub_504933@<eax>(int a1@<ebp>)
{
  _BYTE *v1; // ecx
  _DWORD *v2; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // ecx
  _DWORD *v9; // esi
  int v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // esi
  unsigned int v13; // esi
  int v14; // eax
  _DWORD *v15; // eax
  unsigned int v16; // esi
  _DWORD *v17; // esi
  unsigned int v18; // edx
  int v19; // eax
  bool v20; // cf

  SEHHandlerInit();
  v2 = v1;
  if ( v1[8] != 2 )
    return -2147467259;
  v4 = *(_DWORD *)(*(_DWORD *)v1 + 4184);
  v5 = OperatorNewNhMallocWrapper(16 * v4);
  *(_DWORD *)(a1 - 48) = v5;
  *(_DWORD *)(a1 - 4) = 0;
  if ( v5 )
  {
    sub_5008C2(v5, 16, v4, (int (__thiscall *)(int))sub_5007EC);
    *(_DWORD *)(a1 - 16) = *(_DWORD *)(a1 - 48);
  }
  else
  {
    *(_DWORD *)(a1 - 16) = 0;
  }
  *(_DWORD *)(a1 - 4) = -1;
  if ( !*(_DWORD *)(a1 - 16) )
    return -2147024882;
  v6 = *(_DWORD *)(v2[1] + 4184);
  v7 = OperatorNewNhMallocWrapper(16 * v6);
  *(_DWORD *)(a1 - 48) = v7;
  *(_DWORD *)(a1 - 4) = 1;
  if ( v7 )
  {
    sub_5008C2(v7, 16, v6, (int (__thiscall *)(int))sub_5007EC);
    *(_DWORD *)(a1 - 20) = *(_DWORD *)(a1 - 48);
  }
  else
  {
    *(_DWORD *)(a1 - 20) = 0;
  }
  *(_DWORD *)(a1 - 4) = -1;
  if ( *(_DWORD *)(a1 - 20) )
  {
    v8 = *v2;
    v9 = (_DWORD *)v2[1];
    v10 = (*(_DWORD *)(*v2 + 4184) << 16) / v9[1046];
    v11 = v9[1047];
    v12 = v9[1048];
    *(_DWORD *)(a1 - 40) = 0;
    *(_DWORD *)(a1 - 28) = 0;
    *(_DWORD *)(a1 - 52) = v10;
    *(_DWORD *)(a1 - 56) = (*(_DWORD *)(v8 + 4188) << 16) / v11;
    *(_DWORD *)(a1 - 60) = (*(_DWORD *)(v8 + 4192) << 16) / v12;
    do
    {
      *(_DWORD *)(a1 - 44) = -1;
      v13 = 0;
      *(_DWORD *)(a1 - 48) = 0;
      *(_DWORD *)(a1 - 24) = 0;
      if ( v11 )
      {
        do
        {
          v14 = *(_DWORD *)(a1 - 44);
          *(_DWORD *)(a1 - 32) = 0;
          *(_DWORD *)(a1 - 36) = 0;
          if ( ((v13 ^ v14) & 0xFFFF0000) != 0 )
          {
            (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, _DWORD))(*(_DWORD *)*v2 + 4))(
              *v2,
              HIWORD(v13),
              HIWORD(*(_DWORD *)(a1 - 40)),
              *(_DWORD *)(a1 - 16));
            *(_DWORD *)(a1 - 44) = v13;
          }
          if ( *(_DWORD *)(v2[1] + 4184) )
          {
            v15 = *(_DWORD **)(a1 - 20);
            do
            {
              v16 = *(_DWORD *)(a1 - 32);
              *(_DWORD *)(a1 - 32) = *(_DWORD *)(a1 - 52) + v16;
              v17 = (_DWORD *)(*(_DWORD *)(a1 - 16) + 16 * HIWORD(v16));
              v18 = ++*(_DWORD *)(a1 - 36);
              *v15 = *v17++;
              v15[1] = *v17++;
              v15[2] = *v17;
              v15[3] = v17[1];
              v15 += 4;
            }
            while ( v18 < *(_DWORD *)(v2[1] + 4184) );
          }
          (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2[1] + 8))(
            v2[1],
            *(_DWORD *)(a1 - 24),
            *(_DWORD *)(a1 - 28),
            *(_DWORD *)(a1 - 20));
          v13 = *(_DWORD *)(a1 - 56) + *(_DWORD *)(a1 - 48);
          v19 = v2[1];
          ++*(_DWORD *)(a1 - 24);
          v11 = *(_DWORD *)(v19 + 4188);
          v20 = *(_DWORD *)(a1 - 24) < v11;
          *(_DWORD *)(a1 - 48) = v13;
        }
        while ( v20 );
      }
      *(_DWORD *)(a1 - 40) += *(_DWORD *)(a1 - 60);
      ++*(_DWORD *)(a1 - 28);
    }
    while ( *(_DWORD *)(a1 - 28) < *(_DWORD *)(v2[1] + 4192) );
    FreeWrapper_7bcf(*(LPVOID *)(a1 - 16));
    FreeWrapper_7bcf(*(LPVOID *)(a1 - 20));
    return 0;
  }
  else
  {
    FreeWrapper_7bcf(*(LPVOID *)(a1 - 16));
    return -2147024882;
  }
}
