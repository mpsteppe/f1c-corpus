int __thiscall sub_4F0CB0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // ecx
  int result; // eax

  *a2 = this[49];
  a2[1] = this[50];
  a2[2] = this[51];
  v3 = this + 52;
  *a3 = *v3;
  result = v3[1];
  a3[1] = result;
  a3[2] = v3[2];
  return result;
}
