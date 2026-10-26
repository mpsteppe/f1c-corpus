int __thiscall sub_4E14C0(int this, char a2, char a3, int a4, int a5, char a6)
{
  int result; // eax

  *(_BYTE *)(this + 384) = a2;
  *(_BYTE *)(this + 385) = a3;
  *(_BYTE *)(this + 387) = a6;
  result = a5;
  *(_DWORD *)(this + 388) = a4;
  *(_DWORD *)(this + 404) = a5;
  return result;
}
