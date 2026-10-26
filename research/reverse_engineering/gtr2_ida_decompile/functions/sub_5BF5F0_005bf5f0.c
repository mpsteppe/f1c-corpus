int __thiscall sub_5BF5F0(int this, int *a2, int a3)
{
  int v4; // ebx
  int i; // edi
  int v6; // ecx
  void *v8; // eax
  int v9; // ebx
  int v10; // ebp
  int j; // edi
  int v12; // ecx
  int v13; // [esp+0h] [ebp-1Ch]
  int v14; // [esp+4h] [ebp-18h]
  int v15; // [esp+8h] [ebp-14h]
  int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  int v18; // [esp+14h] [ebp-8h]
  void *retaddr; // [esp+1Ch] [ebp+0h]

  if ( !*(_BYTE *)(this + 33) )
    sub_5BEBD0(v13, v14, v15, v16, v17, v18);
  if ( *(_BYTE *)(this + 31) )
    sub_643E40("- Trying to load LMA motion file '%s'...", *(const char **)(a3 + 4));
  v4 = *(_DWORD *)(this + 12);
  for ( i = 0; i < v4; ++i )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * i);
    if ( v6 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(v6);
  }
  if ( sub_5BDF60((_DWORD *)this, a2) )
  {
    v8 = operator new(0x24u);
    v9 = 0;
    if ( v8 )
      v9 = sub_5D0910(v8, a3);
    while ( sub_5BE300(this, (int)a2, 0, v9, 0) )
      ;
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 20))(v9);
    v10 = *(_DWORD *)(this + 12);
    for ( j = 0; j < v10; ++j )
    {
      v12 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * j);
      if ( v12 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 8))(v12);
    }
    (*(void (__thiscall **)(void *))(*(_DWORD *)retaddr + 112))(retaddr);
    return v9;
  }
  else
  {
    sub_643E40("Invalid motion file header.");
    return 0;
  }
}
