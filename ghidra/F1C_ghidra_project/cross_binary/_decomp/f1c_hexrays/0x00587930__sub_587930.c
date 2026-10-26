// f1c  0x00587930  size=188
char __thiscall sub_587930(int **this, int a2, int a3, int a4)
{
  char result; // al
  int i; // ebx
  int v6; // edi
  int v7; // ebp
  unsigned __int8 v8; // al
  int v9; // ebx
  int v10; // ebx
  unsigned __int8 v11; // al
  int v12; // esi

  result = a3;
  for ( i = 0; i < a3; result = sub_585400(this[261], (_DWORD *)v7) )
  {
    v6 = a2;
    v7 = (*(int (__thiscall **)(int *))(*this[261] + 88))(this[261]);
    v8 = *(_BYTE *)(i + a2);
    v9 = i + 1;
    if ( v8 == (*(_DWORD *)(v7 + 36) >> 3) + ((*(_DWORD *)(v7 + 36) & 7) != 0) )
    {
      qmemcpy(
        *(void **)(v7 + 20),
        (const void *)(v9 + a2),
        (*(_DWORD *)(v7 + 36) >> 3) + ((*(_DWORD *)(v7 + 36) & 7) != 0));
      v6 = a2;
    }
    v10 = v8 + v9;
    v11 = *(_BYTE *)(v10 + v6);
    ++v10;
    v12 = v11;
    sub_587510(v7 + 8, (const void *)(v10 + v6), v11);
    *(_DWORD *)(v7 + 4) = a4;
    i = v12 + v10;
  }
  return result;
}
