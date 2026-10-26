int __thiscall sub_59BDE0(int this, _DWORD *a2, int a3, _DWORD *a4)
{
  int v5; // edx
  int result; // eax
  int v7; // [esp+8h] [ebp-4h] BYREF

  v7 = 0;
  sub_59B1F0(this, a2, a3, &v7);
  v5 = v7;
  *(_WORD *)((char *)a2 + v7) = *(_WORD *)(this + 300);
  *(_DWORD *)((char *)a2 + v5 + 2) = *(_DWORD *)(this + 304);
  result = v5 + 6;
  *a4 = v5 + 6;
  return result;
}
