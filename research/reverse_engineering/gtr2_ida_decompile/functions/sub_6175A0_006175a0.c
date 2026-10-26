int __thiscall sub_6175A0(int this)
{
  int *v2; // ecx
  int v3; // eax

  v2 = (int *)(this + 96);
  *(_DWORD *)(this + 124) = -1;
  *(_DWORD *)(this + 128) = -1;
  v3 = *v2;
  *(_BYTE *)(this + 132) = 0;
  (*(void (__thiscall **)(int *))(v3 + 16))(v2);
  return sub_613F20(this);
}
