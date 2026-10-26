char __thiscall sub_5A7330(int **this, int a2, int a3, int a4)
{
  char result; // al
  int **v5; // edi
  int i; // ebx
  int v7; // eax
  _DWORD *v8; // ebp
  int v9; // ebx
  unsigned int v10; // ecx
  int v11; // eax
  char *v12; // edi
  char v13; // al
  unsigned int v14; // ecx
  char *v15; // edi
  const void *v16; // esi
  int v17; // ebx
  int v18; // esi
  unsigned __int8 v19; // [esp+Bh] [ebp-9h]

  result = a3;
  v5 = this;
  for ( i = 0; i < a3; result = sub_5A5D70(v5[261], v8) )
  {
    v7 = (*(int (__thiscall **)(int *))(*v5[261] + 88))(v5[261]);
    v19 = *(_BYTE *)(i + a2);
    v8 = (_DWORD *)v7;
    v9 = i + 1;
    v10 = (*(_DWORD *)(v7 + 36) >> 3) + ((*(_DWORD *)(v7 + 36) & 7) != 0);
    v11 = v19;
    if ( v19 == v10 )
    {
      v12 = (char *)v8[5];
      v13 = v10;
      v14 = v10 >> 2;
      qmemcpy(v12, (const void *)(v9 + a2), 4 * v14);
      v16 = (const void *)(v9 + a2 + 4 * v14);
      v15 = &v12[4 * v14];
      LOBYTE(v14) = v13;
      v11 = v19;
      qmemcpy(v15, v16, v14 & 3);
      v5 = this;
    }
    v17 = v11 + v9;
    v18 = *(unsigned __int8 *)(v17 + a2);
    sub_5A7080((int)(v8 + 2), (const void *)(++v17 + a2), v18);
    v8[1] = a4;
    i = v18 + v17;
  }
  return result;
}
