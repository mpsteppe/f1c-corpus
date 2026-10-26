_DWORD *__fastcall sub_60BF40(_DWORD *a1, int a2, int a3)
{
  int v3; // eax
  int v4; // eax
  _DWORD *v6; // [esp+8h] [ebp-4h] BYREF

  v6 = a1;
  v3 = *a1;
  v6 = 0;
  v4 = (*(int (__thiscall **)(_DWORD *, int, _DWORD **))(v3 + 648))(a1, a3, &v6);
  return v4 == 0 ? v6 : 0;
}
