bool __thiscall sub_4627C0(void *this, int a2, _WORD *a3)
{
  _BYTE *v4; // esi
  bool v5; // bl
  int v7; // [esp+10h] [ebp-4h] BYREF

  v4 = (_BYTE *)sub_57A880(*(_DWORD *)(*(_DWORD *)this + 16312));
  sub_57A8E0(v4);
  v7 = 128;
  sub_57A230(a2, &v7);
  v5 = v7 == 128;
  *(_BYTE *)(a2 + 101) = sub_462370(this) - 1;
  *(_BYTE *)(a2 + 102) = v4[43];
  if ( a3 )
    *a3 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v4 + 24))(v4);
  sub_57A8B0(*(_DWORD *)(*(_DWORD *)this + 16312), v4);
  return v5;
}
