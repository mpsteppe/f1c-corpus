// positive sp value has been detected, the output may be wrong!
char __userpurge sub_56FA59@<al>(char a1@<cf>, int **a2@<ecx>, int a3)
{
  int *v4; // eax
  int **v5; // ebp
  DWORD v6; // eax
  int **v7; // edi
  int *v8; // eax
  bool v9; // zf
  int v10; // eax
  int *v11; // eax
  int *v12; // eax
  int *v13; // eax
  int v15; // edi
  _BYTE *v16; // ecx
  _BYTE *v17; // ecx
  int **v18; // [esp-8h] [ebp-18h]
  int v19; // [esp+0h] [ebp-10h] BYREF
  u_long v20; // [esp+4h] [ebp-Ch]

  MEMORY[0xFFFEC2E9] += a1 + 351044607;
  v4 = a2[701];
  v5 = a2 + 697;
  if ( v4 && ((v6 = WaitForSingleObject(v4, (DWORD)a2[702])) == 0 || v6 == 128) )
    v7 = v5;
  else
    v7 = 0;
  v20 = htonl(0);
  htons(0);
  sub_56B5E0(a2 + 673, &v19);
  *(_DWORD *)(a3 + 304) = v20;
  v8 = *v7;
  v9 = *v7 == 0;
  v7[2] = *v7;
  if ( v9 || (v10 = *v8) == 0 )
  {
LABEL_13:
    sub_5735F0(a3, 0);
  }
  else
  {
    while ( *(_DWORD *)(a3 + 304) != *(_DWORD *)(v10 + 304) || *(_WORD *)(a3 + 300) != *(_WORD *)(v10 + 300) )
    {
      v11 = v7[2];
      if ( v11 )
      {
        v12 = (int *)v11[1];
        v7[2] = v12;
        if ( v12 )
        {
          v10 = *v12;
          if ( v10 )
            continue;
        }
      }
      goto LABEL_13;
    }
    *(_DWORD *)(v10 + 4) = *(_DWORD *)(a3 + 4);
    v15 = a3 - v10;
    v16 = (_BYTE *)(v10 + 8);
    do
    {
      *v16 = v16[v15];
      ++v16;
    }
    while ( (unsigned int)&v16[-8 - v10] < 0x20 );
    *(_BYTE *)(v10 + 40) = *(_BYTE *)(a3 + 40);
    *(_BYTE *)(v10 + 41) = *(_BYTE *)(a3 + 41);
    *(_BYTE *)(v10 + 42) = *(_BYTE *)(a3 + 42);
    *(_BYTE *)(v10 + 43) = *(_BYTE *)(a3 + 43);
    *(_BYTE *)(v10 + 44) = *(_BYTE *)(a3 + 44);
    v17 = (_BYTE *)(v10 + 45);
    do
    {
      *v17 = v17[v15];
      ++v17;
    }
    while ( (unsigned int)&v17[-45 - v10] < 0xFF );
    *(_WORD *)(v10 + 300) = *(_WORD *)(a3 + 300);
    *(_DWORD *)(v10 + 304) = *(_DWORD *)(a3 + 304);
    ((void (__thiscall *)(int **, int))(*a2)[31])(a2, a3);
    v5 = v18;
  }
  v13 = v5[4];
  if ( v13 )
    ReleaseMutex(v13);
  return 1;
}
