// f1c  0x00565f50  size=22
bool __thiscall sub_565F50(int *this)
{
  int v1; // ecx
  _DWORD *v2; // eax
  bool v3; // zf

  v1 = *this;
  v2 = *(_DWORD **)v1;
  v3 = *(_DWORD *)v1 == 0;
  *(_DWORD *)(v1 + 8) = *(_DWORD *)v1;
  return !v3 && *v2;
}
