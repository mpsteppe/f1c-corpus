_DWORD *__thiscall sub_448EE0(int this, _DWORD *a2)
{
  _DWORD *result; // eax
  int v3; // [esp+0h] [ebp-4h]

  BYTE1(v3) = BYTE1(this);
  LOBYTE(v3) = *(_BYTE *)(this + 25);
  result = a2;
  HIWORD(v3) = *(_WORD *)(this + 26);
  *a2 = v3;
  return result;
}
