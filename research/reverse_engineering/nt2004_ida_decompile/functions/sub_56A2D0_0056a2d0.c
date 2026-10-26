int __thiscall sub_56A2D0(_DWORD *this)
{
  unsigned __int64 v2; // st7
  int v3; // edi
  _BYTE v5[4]; // [esp+10h] [ebp-4h] BYREF

  *(double *)&v2 = sub_575000(*this);
  sub_573750(v5, v2, HIDWORD(v2));
  v3 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*this + 88))(*this);
  sub_576880(0, 14, 0, 3, 500);
  *(_BYTE *)(*(_DWORD *)(v3 + 72) + 4) = 1;
  sub_576A80(v5, 4);
  return sub_5753F0(v3);
}
