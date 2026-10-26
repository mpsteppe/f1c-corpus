int __thiscall sub_409A10(int *this, float *a2, int a3)
{
  int v4; // edi
  int v5; // eax
  _BYTE v7[12]; // [esp+8h] [ebp-Ch] BYREF

  v4 = *this;
  v5 = sub_409510(this, (int)v7, a2, 1);
  return (*(int (__thiscall **)(int *, int, int))(v4 + 16))(this, v5, a3);
}
