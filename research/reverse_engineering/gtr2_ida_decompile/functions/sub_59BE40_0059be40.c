int __thiscall sub_59BE40(int this, int a2, int *a3)
{
  int v4; // eax
  int result; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  v6 = 0;
  sub_59B260(this, a2, &v6);
  v4 = v6 + a2;
  *(_WORD *)(this + 300) = *(_WORD *)(v6 + a2);
  *(_DWORD *)(this + 304) = *(_DWORD *)(v4 + 2);
  result = v4 + 2 - a2 + 4;
  *a3 = result;
  return result;
}
