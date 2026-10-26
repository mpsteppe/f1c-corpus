int __fastcall sub_4A6F70(_DWORD *a1)
{
  _BYTE *v1; // esi
  int v2; // eax
  int v3; // edi
  int v4; // eax

  v1 = a1;
  v2 = *a1;
  LOBYTE(a1) = *(_DWORD *)dword_B72314 != 5;
  (*(void (__thiscall **)(_BYTE *, _DWORD *))(v2 + 40))(v1, a1);
  sub_4DE580(0);
  if ( v1[276] && (unsigned __int8)sub_551D70(&unk_FADD40) && !(unsigned __int8)sub_4CD650(v1) )
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)v1 + 148))(v1);
  v3 = *(_DWORD *)v1;
  v4 = sub_551D70(&unk_FADD40);
  (*(void (__thiscall **)(_BYTE *, int))(v3 + 36))(v1, v4);
  return -1;
}
