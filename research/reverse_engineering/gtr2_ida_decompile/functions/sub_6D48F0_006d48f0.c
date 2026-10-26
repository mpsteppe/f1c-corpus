int __userpurge sub_6D48F0@<eax>(int a1@<esi>, int a2, int a3)
{
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // edi
  unsigned __int8 *v7; // eax
  bool v8; // zf
  int v9; // edx
  unsigned __int8 *v10; // eax
  int v11; // edx
  int v13; // [esp+10h] [ebp+8h]
  int v14; // [esp+14h] [ebp+Ch]
  unsigned __int8 v15; // [esp+16h] [ebp+Eh]

  v3 = *(_DWORD *)(a1 + 12);
  if ( !a3 )
  {
    v4 = *(_DWORD *)(a1 + 32);
    *(_DWORD *)(*(_DWORD *)v4 + 20) = 40;
    (**(void (__stdcall ***)(int))v4)(v4);
  }
  v5 = a3 + v3;
  v6 = *(_DWORD *)(a1 + 8) | ((a2 & ((1 << a3) - 1)) << (24 - v5));
  v15 = BYTE2(v6);
  if ( v5 < 8 )
  {
LABEL_12:
    *(_DWORD *)(a1 + 8) = v6;
    *(_DWORD *)(a1 + 12) = v5;
    return 1;
  }
  while ( 1 )
  {
    v7 = *(unsigned __int8 **)a1;
    *v7 = v15;
    *(_DWORD *)a1 = v7 + 1;
    v8 = (*(_DWORD *)(a1 + 4))-- == 1;
    if ( v8 )
    {
      v13 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 24);
      if ( !(*(int (__stdcall **)(_DWORD))(v13 + 12))(*(_DWORD *)(a1 + 32)) )
        return 0;
      v9 = *(_DWORD *)(v13 + 4);
      *(_DWORD *)a1 = *(_DWORD *)v13;
      *(_DWORD *)(a1 + 4) = v9;
    }
    if ( v15 == 255 )
    {
      v10 = *(unsigned __int8 **)a1;
      *v10 = 0;
      *(_DWORD *)a1 = v10 + 1;
      v8 = (*(_DWORD *)(a1 + 4))-- == 1;
      if ( v8 )
        break;
    }
LABEL_11:
    v6 <<= 8;
    v5 -= 8;
    v15 = BYTE2(v6);
    if ( v5 < 8 )
      goto LABEL_12;
  }
  v14 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 24);
  if ( (*(int (__stdcall **)(_DWORD))(v14 + 12))(*(_DWORD *)(a1 + 32)) )
  {
    v11 = *(_DWORD *)(v14 + 4);
    *(_DWORD *)a1 = *(_DWORD *)v14;
    *(_DWORD *)(a1 + 4) = v11;
    goto LABEL_11;
  }
  return 0;
}
