int __thiscall sub_59B780(_DWORD *this)
{
  double v2; // st7
  int v3; // edi
  _BYTE v5[4]; // [esp+0h] [ebp-18h] BYREF
  int v6; // [esp+14h] [ebp-4h] BYREF

  v2 = sub_5A3EA0(*this);
  sub_5A3B30((int)&v6, v2);
  v3 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*this + 88))(*this);
  sub_5A6B10(v3, 0, 14, 0, 3, 500);
  *(_BYTE *)(*(_DWORD *)(v3 + 72) + 4) = 1;
  sub_5A6970(v5, 4);
  return sub_5A47C0(v3);
}
