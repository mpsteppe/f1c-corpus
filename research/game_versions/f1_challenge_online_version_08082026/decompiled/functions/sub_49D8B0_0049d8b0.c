int __thiscall sub_49D8B0(_DWORD *this)
{
  int v1; // ebx
  int v2; // ebp
  int v3; // edi
  int result; // eax
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  char v10[64]; // [esp+10h] [ebp-40h] BYREF

  v1 = dword_5CCBC0;
  v2 = dword_7CE238;
  v3 = dword_5CCBB8;
  sub_49E410(dword_5CCBC0, dword_7CE238, dword_5CCBB8);
  result = this[2];
  if ( result )
  {
    v6 = dword_5CCBBC + v3;
    sub_49C140((int)v10, 64);
    sub_49F6A0(v10, v1, v6, this[2], *(_DWORD *)(this[5] + 84), 1);
    sub_49C280((int)v10, 64);
    sub_49F6A0(v10, v2, v6, this[2], *(_DWORD *)(this[5] + 84), 0);
    v7 = dword_5CCBBC + v6;
    sub_49BDE0((int)v10, 64);
    sub_49F6A0(v10, v1, v7, this[2], *(_DWORD *)(this[5] + 84), 1);
    sub_49BE50(v10, 64);
    sub_49F6A0(v10, v2, v7, this[2], *(_DWORD *)(this[5] + 84), 0);
    v8 = dword_5CCBBC + v7;
    sub_49BF80((int)v10, 64);
    sub_49F6A0(v10, v1, v8, this[2], *(_DWORD *)(this[5] + 84), 1);
    sub_49BFF0((int)v10, 64);
    sub_49F6A0(v10, v2, v8, this[2], *(_DWORD *)(this[5] + 84), 0);
    v9 = dword_5CCBBC + v8;
    sub_49C0B0(v10, 64);
    return sub_49F6A0(v10, 240, v9, this[2], *(_DWORD *)(this[5] + 84), 1);
  }
  return result;
}
