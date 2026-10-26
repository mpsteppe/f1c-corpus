unsigned int __userpurge sub_6D5530@<eax>(int a1@<esi>, int a2, int a3)
{
  int v3; // ebx
  int v4; // ecx
  unsigned int result; // eax
  int v6; // ebx
  int v7; // edi
  unsigned __int8 *v8; // eax
  bool v9; // zf
  int v10; // ebx
  int v11; // ecx
  int v12; // edx
  _BYTE *v13; // eax
  int v14; // ebx
  int v15; // ecx
  int v16; // ecx
  int v17; // [esp-4h] [ebp-10h]
  int v18; // [esp-4h] [ebp-10h]
  int v19; // [esp-4h] [ebp-10h]
  int v20; // [esp+8h] [ebp-4h]
  unsigned int v21; // [esp+14h] [ebp+8h]
  unsigned __int8 v22; // [esp+1Ah] [ebp+Eh]

  v3 = *(_DWORD *)(a1 + 28);
  if ( !a3 )
  {
    v4 = **(_DWORD **)(a1 + 32);
    v17 = *(_DWORD *)(a1 + 32);
    *(_DWORD *)(v4 + 20) = 40;
    (*(void (__stdcall **)(int))v4)(v17);
  }
  result = *(_DWORD *)(a1 + 12);
  if ( !result )
  {
    v6 = a3 + v3;
    v7 = *(_DWORD *)(a1 + 24) | ((a2 & ((1 << a3) - 1)) << (24 - v6));
    v22 = BYTE2(v7);
    if ( v6 >= 8 )
    {
      v21 = (unsigned int)v6 >> 3;
      v20 = v6 - 8 * ((unsigned int)v6 >> 3);
      do
      {
        v8 = *(unsigned __int8 **)(a1 + 16);
        *v8 = v22;
        *(_DWORD *)(a1 + 16) = v8 + 1;
        v9 = (*(_DWORD *)(a1 + 20))-- == 1;
        if ( v9 )
        {
          v10 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 24);
          if ( !(*(int (__stdcall **)(_DWORD))(v10 + 12))(*(_DWORD *)(a1 + 32)) )
          {
            v11 = **(_DWORD **)(a1 + 32);
            v18 = *(_DWORD *)(a1 + 32);
            *(_DWORD *)(v11 + 20) = 24;
            (*(void (__stdcall **)(int))v11)(v18);
          }
          v12 = *(_DWORD *)(v10 + 4);
          *(_DWORD *)(a1 + 16) = *(_DWORD *)v10;
          *(_DWORD *)(a1 + 20) = v12;
        }
        if ( v22 == 255 )
        {
          v13 = *(_BYTE **)(a1 + 16);
          *v13 = 0;
          *(_DWORD *)(a1 + 16) = v13 + 1;
          v9 = (*(_DWORD *)(a1 + 20))-- == 1;
          if ( v9 )
          {
            v14 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 24);
            if ( !(*(int (__stdcall **)(_DWORD))(v14 + 12))(*(_DWORD *)(a1 + 32)) )
            {
              v15 = **(_DWORD **)(a1 + 32);
              v19 = *(_DWORD *)(a1 + 32);
              *(_DWORD *)(v15 + 20) = 24;
              (*(void (__stdcall **)(int))v15)(v19);
            }
            v16 = *(_DWORD *)(v14 + 4);
            *(_DWORD *)(a1 + 16) = *(_DWORD *)v14;
            *(_DWORD *)(a1 + 20) = v16;
          }
        }
        v7 <<= 8;
        result = v21 - 1;
        v9 = v21 == 1;
        v22 = BYTE2(v7);
        --v21;
      }
      while ( !v9 );
      v6 = v20;
    }
    *(_DWORD *)(a1 + 24) = v7;
    *(_DWORD *)(a1 + 28) = v6;
  }
  return result;
}
