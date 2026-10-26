int __thiscall sub_49D700(_DWORD *this)
{
  int v1; // ebx
  int v2; // ebp
  int v3; // edi
  int v5; // edi
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // edi
  int v12; // edi
  char v14[63]; // [esp+10h] [ebp-40h] BYREF
  char v15; // [esp+4Fh] [ebp-1h]

  v1 = dword_7CE238;
  v2 = dword_5CCBC0;
  v3 = dword_5CCBB8;
  DualTextDisplay(dword_5CCBC0, dword_7CE238, dword_5CCBB8);
  v5 = dword_5CCBBC + v3;
  sub_49C310(v14, 64);
  v6 = this[5];
  v7 = this[2];
  v15 = 0;
  StringFormatAndRender(v14, v2, v5, v7, *(_DWORD *)(v6 + 84), 1);
  sub_49C370((int)v14, 64);
  StringFormatAndRender(v14, v1, v5, this[2], *(_DWORD *)(this[5] + 84), 0);
  v8 = dword_5CCBBC + v5;
  sub_49C490(v14, 64);
  v9 = this[5];
  v10 = this[2];
  v15 = 0;
  StringFormatAndRender(v14, v2, v8, v10, *(_DWORD *)(v9 + 84), 1);
  sub_49C4E0((int)v14, 64);
  StringFormatAndRender(v14, v1, v8, this[2], *(_DWORD *)(this[5] + 84), 0);
  v11 = dword_5CCBBC + v8;
  sub_49BCD0((int)v14, 64);
  StringFormatAndRender(v14, v2, v11, this[2], *(_DWORD *)(this[5] + 84), 1);
  sub_49BD40((int)v14, 64);
  StringFormatAndRender(v14, v1, v11, this[2], *(_DWORD *)(this[5] + 84), 0);
  v12 = dword_5CCBBC + v11;
  sub_49C0B0(v14, 64);
  return StringFormatAndRender(v14, 240, v12, this[2], *(_DWORD *)(this[5] + 84), 1);
}

