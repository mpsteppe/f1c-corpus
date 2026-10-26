bool __thiscall sub_5A7280(int this, int a2)
{
  int v3; // eax
  bool v4; // bl
  void *v5; // eax
  int v6; // edi
  int v8; // [esp-18h] [ebp-20h]
  int v9; // [esp-14h] [ebp-1Ch]
  int v10; // [esp-10h] [ebp-18h]
  int v11; // [esp-Ch] [ebp-14h]
  int v12; // [esp-8h] [ebp-10h]

  v3 = *(_DWORD *)(this + 1024);
  v4 = 0;
  if ( v3 < a2 || v3 <= 0 )
    return 0;
  v5 = (void *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 1044) + 88))(*(_DWORD *)(this + 1044));
  v6 = (int)v5;
  if ( v5 )
  {
    sub_5A6B10(v5, 0, 13, 0, 1, *(_DWORD *)(this + 1036));
    sub_5A6970(this, *(_DWORD *)(this + 1024));
    (*(void (__thiscall **)(_DWORD, _DWORD, int, int, int, int, int))(**(_DWORD **)(v6 + 72) + 12))(
      *(_DWORD *)(v6 + 72),
      *(_DWORD *)(this + 1040),
      v8,
      v9,
      v10,
      v11,
      v12);
    v4 = sub_5A47C0(*(void **)(this + 1044), v6) == 0;
  }
  *(_DWORD *)(this + 1024) = 0;
  *(_DWORD *)(this + 1028) = 0;
  *(_DWORD *)(this + 1036) = 500;
  *(_DWORD *)(this + 1032) = 0;
  return v4;
}
