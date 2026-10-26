bool __thiscall sub_4641B0(void *this, int a2, _WORD *a3)
{
  _BYTE *v4; // esi
  bool v5; // bl
  int v7; // [esp+10h] [ebp-4h] BYREF

  v4 = (_BYTE *)sub_56A5B0(*(_DWORD *)(*(_DWORD *)this + 6708));
  sub_56A610(v4);
  v7 = 92;
  sub_569F60(a2, &v7);
  v5 = v7 == 92;
  *(_BYTE *)(a2 + 69) = sub_463BC0(this) - 1;
  *(_BYTE *)(a2 + 70) = v4[43];
  if ( a3 )
    *a3 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v4 + 24))(v4);
  sub_56A5E0(*(_DWORD *)(*(_DWORD *)this + 6708), v4);
  return v5;
}
