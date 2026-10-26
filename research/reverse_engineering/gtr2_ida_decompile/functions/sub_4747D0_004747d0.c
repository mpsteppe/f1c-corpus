bool __thiscall sub_4747D0(void *this, int a2, _WORD *a3)
{
  _BYTE *v4; // esi
  bool v5; // bl
  int v7; // [esp+10h] [ebp-4h] BYREF

  v4 = (_BYTE *)sub_59B5F0(*(_DWORD *)(*(_DWORD *)this + 113316));
  sub_59B650(v4);
  v7 = 188;
  sub_59B1B0(v4, a2, &v7);
  v5 = v7 == 188;
  *(_BYTE *)(a2 + 105) = *(_BYTE *)(*(_DWORD *)this + 112884) - 1;
  *(_BYTE *)(a2 + 106) = v4[43];
  if ( a3 )
    *a3 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v4 + 24))(v4);
  sub_59B620(*(_DWORD *)(*(_DWORD *)this + 113316), v4);
  return v5;
}
