int __userpurge sub_5BBFE6@<eax>(int a1@<eax>, int a2@<ecx>, int a3, int a4)
{
  int *v5; // ecx
  int v6; // eax
  int v7; // esi
  _BYTE v9[36]; // [esp+8h] [ebp-30h] BYREF
  int v10; // [esp+2Ch] [ebp-Ch]
  void *v11; // [esp+30h] [ebp-8h]
  int v12; // [esp+34h] [ebp-4h]

  v12 = -1;
  v11 = &loc_6EA908;
  v10 = a1;
  if ( a4 )
    return (*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(a2 + 532) + 4))(*(_DWORD *)(a2 + 532), a3, a4);
  sub_5BFC10(v9);
  v5 = *(int **)(a2 + 532);
  v6 = *v5;
  v12 = 0;
  v7 = (*(int (__thiscall **)(int *, int, _BYTE *))(v6 + 4))(v5, a3, v9);
  v12 = -1;
  nullsub_7(v9);
  return v7;
}
