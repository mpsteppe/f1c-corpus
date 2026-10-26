int __userpurge sub_601A70@<eax>(int a1@<ecx>, char *a2@<ebp>, int a3)
{
  int result; // eax
  int v5; // edi
  char *v6; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  char *v14; // eax
  char v15; // cl
  int v17; // [esp+B4h] [ebp-584h]
  int i; // [esp+B8h] [ebp-580h]
  char v19[88]; // [esp+BCh] [ebp-57Ch] BYREF
  int v20; // [esp+114h] [ebp-524h]
  int v21; // [esp+118h] [ebp-520h]
  char v22[516]; // [esp+1ECh] [ebp-44Ch] BYREF
  _BYTE v23[544]; // [esp+3F0h] [ebp-248h] BYREF
  int v24; // [esp+610h] [ebp-28h]
  int v25; // [esp+614h] [ebp-24h]
  int v26; // [esp+628h] [ebp-10h]
  int v27; // [esp+62Ch] [ebp-Ch]
  int v28; // [esp+630h] [ebp-8h]
  int v29; // [esp+634h] [ebp-4h]

  v17 = 0;
  result = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(a1 + 9544) + 16))(*(_DWORD *)(a1 + 9544));
  v5 = 0;
  for ( i = result; v5 < i; ++v5 )
  {
    v6 = (char *)operator new(0x440u);
    v7 = (*(int (__stdcall **)(_DWORD, int, int, int, int, _DWORD, char *))(**(_DWORD **)(a1 + 9544) + 36))(
           *(_DWORD *)(a1 + 9544),
           v5,
           1,
           23,
           23,
           0,
           a2);
    *(_DWORD *)(a1 + 8) = v7;
    if ( !v7 )
      i |= 0x4000000u;
    v8 = (*(int (__stdcall **)(_DWORD, int, int, int, int, _DWORD))(**(_DWORD **)(a1 + 9544) + 36))(
           *(_DWORD *)(a1 + 9544),
           v5,
           1,
           24,
           25,
           0);
    *(_DWORD *)(a1 + 8) = v8;
    if ( !v8 )
      i |= 0x8000000u;
    v9 = (*(int (__stdcall **)(_DWORD, int, int, int, int, _DWORD))(**(_DWORD **)(a1 + 9544) + 36))(
           *(_DWORD *)(a1 + 9544),
           v5,
           1,
           24,
           24,
           0);
    *(_DWORD *)(a1 + 8) = v9;
    if ( !v9 )
      i |= 0x10000000u;
    v10 = (*(int (__stdcall **)(_DWORD, int, int, int, int, _DWORD))(**(_DWORD **)(a1 + 9544) + 36))(
            *(_DWORD *)(a1 + 9544),
            v5,
            1,
            20,
            20,
            0);
    *(_DWORD *)(a1 + 8) = v10;
    if ( !v10 )
      i |= 0x20000000u;
    v11 = (*(int (__stdcall **)(_DWORD, int, int, int, int, _DWORD))(**(_DWORD **)(a1 + 9544) + 36))(
            *(_DWORD *)(a1 + 9544),
            v5,
            1,
            22,
            22,
            0);
    *(_DWORD *)(a1 + 8) = v11;
    if ( !v11 )
      i |= 0x80000000;
    a2 = 0;
    v12 = (*(int (__stdcall **)(_DWORD, int, int, int, int))(**(_DWORD **)(a1 + 9544) + 36))(
            *(_DWORD *)(a1 + 9544),
            v5,
            1,
            22,
            21);
    *(_DWORD *)(a1 + 8) = v12;
    if ( !v12 )
      v17 |= 0x40000000u;
    if ( (v17 & 0xFC000000) != 0 )
    {
      v13 = (*(int (__stdcall **)(_DWORD, int, int, char *))(**(_DWORD **)(a1 + 9544) + 56))(
              *(_DWORD *)(a1 + 9544),
              v5,
              1,
              v19);
      *(_DWORD *)(a1 + 8) = v13;
      if ( v13 || (*((_DWORD *)v6 + 72) = v20, v20 > 512) && (*((_DWORD *)v6 + 73) = v21, v21 > 512) )
      {
        *(_DWORD *)(a1 + 8) = (*(int (__stdcall **)(_DWORD, int, _DWORD, char *, _DWORD))(**(_DWORD **)(a1 + 9544) + 20))(
                                *(_DWORD *)(a1 + 9544),
                                v5,
                                0,
                                v22,
                                0);
        *(_DWORD *)v6 = i;
        *((_DWORD *)v6 + 1) = v5;
        *((_DWORD *)v6 + 2) = v26;
        *((_DWORD *)v6 + 3) = v27;
        *((_DWORD *)v6 + 4) = v28;
        *((_DWORD *)v6 + 5) = v29;
        v14 = v23;
        do
        {
          v15 = *v14;
          v14[v6 - v23 + 32] = *v14;
          ++v14;
        }
        while ( v15 );
        *((_DWORD *)v6 + 74) = 0;
        *((_DWORD *)v6 + 6) = v24;
        *((_DWORD *)v6 + 7) = v25;
        a2 = v6;
        (**(void (__thiscall ***)(int))a1)(a1);
      }
    }
    result = i;
  }
  return result;
}
