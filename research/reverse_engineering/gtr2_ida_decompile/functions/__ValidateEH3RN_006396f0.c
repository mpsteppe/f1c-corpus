int __cdecl _ValidateEH3RN(unsigned int a1)
{
  unsigned int v2; // ebx
  struct _TEB *v3; // eax
  unsigned int v5; // edi
  unsigned int v6; // edx
  unsigned int *v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // edi
  int v10; // esi
  char *v11; // eax
  unsigned int v12; // ebx
  int v13; // ecx
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // edx
  _DWORD *v17; // eax
  int v18; // ebx
  int j; // edx
  unsigned int *v20; // eax
  int v21; // esi
  int v22; // eax
  int i; // ecx
  unsigned int *v24; // eax
  int v25; // edx
  _MEMORY_BASIC_INFORMATION Buffer; // [esp+8h] [ebp-20h] BYREF
  PVOID StackLimit; // [esp+24h] [ebp-4h]
  int v28; // [esp+30h] [ebp+8h]

  v2 = *(_DWORD *)(a1 + 8);
  if ( (v2 & 3) != 0 )
    return 0;
  v3 = NtCurrentTeb();
  StackLimit = v3->NtTib.StackLimit;
  if ( v2 >= (unsigned int)StackLimit && (PVOID)v2 < v3->NtTib.StackBase )
    return 0;
  v5 = *(_DWORD *)(a1 + 12);
  if ( v5 == -1 )
    return 1;
  v6 = 0;
  v28 = 0;
  v7 = (unsigned int *)v2;
  do
  {
    if ( *v7 != -1 && *v7 >= v6 )
      return 0;
    if ( v7[1] )
      ++v28;
    ++v6;
    v7 += 3;
  }
  while ( v6 <= v5 );
  if ( v28 )
  {
    v8 = *(_DWORD *)(a1 - 8);
    if ( v8 < (unsigned int)StackLimit || v8 >= a1 )
      return 0;
  }
  v9 = v2 & 0xFFFFF000;
  v10 = 0;
  if ( dword_FB8360 > 0 )
  {
    while ( dword_FB8368[v10] != v9 )
    {
      if ( ++v10 >= dword_FB8360 )
        goto LABEL_19;
    }
    if ( v10 <= 0 || InterlockedExchange(&Target, 1) )
      return 1;
    if ( dword_FB8368[v10] != v9 )
    {
      v22 = dword_FB8360;
      v10 = dword_FB8360 - 1;
      if ( dword_FB8360 - 1 < 0 )
        goto LABEL_50;
      do
      {
        if ( dword_FB8368[v10] == v9 )
          break;
        --v10;
      }
      while ( v10 >= 0 );
      if ( v10 >= 0 )
      {
        if ( !v10 )
        {
LABEL_56:
          InterlockedExchange(&Target, 0);
          return 1;
        }
      }
      else
      {
LABEL_50:
        if ( dword_FB8360 < 16 )
          v22 = ++dword_FB8360;
        v10 = v22 - 1;
      }
    }
    for ( i = 0; i <= v10; v9 = v25 )
    {
      v24 = (unsigned int *)(4 * i + 16483176);
      v25 = dword_FB8368[i++];
      *v24 = v9;
    }
    goto LABEL_56;
  }
LABEL_19:
  if ( VirtualQuery((LPCVOID)v2, &Buffer, 0x1Cu) && (int *)Buffer.Type == &dword_1000000 )
  {
    if ( (Buffer.Protect & 0xCC) == 0 )
      goto LABEL_29;
    if ( *(_WORD *)Buffer.AllocationBase == 23117 )
    {
      v11 = (char *)Buffer.AllocationBase + *((_DWORD *)Buffer.AllocationBase + 15);
      if ( *(_DWORD *)v11 == 17744 && *((_WORD *)v11 + 12) == 267 )
      {
        v12 = v2 - (unsigned int)Buffer.AllocationBase;
        v13 = (int)&v11[*((unsigned __int16 *)v11 + 10) + 24];
        if ( *((_WORD *)v11 + 3) )
        {
          v14 = *(_DWORD *)&v11[*((unsigned __int16 *)v11 + 10) + 36];
          if ( v12 < v14 || v12 >= v14 + *(_DWORD *)(v13 + 8) || *(char *)(v13 + 39) >= 0 )
          {
LABEL_29:
            if ( !InterlockedExchange(&Target, 1) )
            {
              v15 = dword_FB8360;
              v16 = dword_FB8360;
              if ( dword_FB8360 > 0 )
              {
                v17 = (_DWORD *)(4 * dword_FB8360 + 16483172);
                do
                {
                  if ( *v17 == v9 )
                    break;
                  --v16;
                  --v17;
                }
                while ( v16 > 0 );
              }
              if ( !v16 )
              {
                v18 = 15;
                if ( dword_FB8360 <= 15 )
                  v18 = dword_FB8360;
                for ( j = 0; j <= v18; v9 = v21 )
                {
                  v20 = (unsigned int *)(4 * j + 16483176);
                  v21 = dword_FB8368[j++];
                  *v20 = v9;
                }
                if ( v15 < 16 )
                  dword_FB8360 = v15 + 1;
              }
              InterlockedExchange(&Target, 0);
            }
            return 1;
          }
          return 0;
        }
      }
    }
  }
  return -1;
}
