int __thiscall sub_59B7F0(_DWORD *this, char a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // ebx
  int v9; // esi
  int v11; // [esp+0h] [ebp-14h]
  int v12; // [esp+4h] [ebp-10h]

  v8 = dword_16C99F8;
  v9 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*this + 88))(*this);
  if ( !v9 )
    return v8;
  if ( a4 )
  {
    v12 = a4;
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v9 + 72) + 32))(*(_DWORD *)(v9 + 72));
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(v9 + 72) + 4) = 1;
  }
  sub_5A6B10(v9, 1, 0, a4, a5, a6);
  sub_5A6970(v11, v12);
  if ( a2 )
    sub_5A47C0(v9);
  else
    sub_5A6190(v9);
  return 0;
}
