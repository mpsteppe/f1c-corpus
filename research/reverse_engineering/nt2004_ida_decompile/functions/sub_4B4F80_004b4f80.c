int __thiscall sub_4B4F80(_DWORD *this)
{
  int result; // eax
  int v3; // ebx
  int v4; // ebp
  int v5; // esi
  int v6; // esi
  int v7; // ecx
  int v8; // esi
  int v9; // ecx
  int v10; // esi
  int v11; // esi
  char Destination[63]; // [esp+4h] [ebp-40h] BYREF
  char v13; // [esp+43h] [ebp-1h]

  result = this[2];
  if ( result )
  {
    v3 = dword_766078;
    v4 = dword_6090C0;
    v5 = dword_6090B8;
    sub_4B59D0(dword_6090C0, dword_766078, dword_6090B8);
    v6 = dword_6090BC + v5;
    sub_4B37E0(Destination, 64);
    v7 = this[5];
    v13 = 0;
    sub_505C90(v4, v6, -1, 1, 1065353216, 1065353216, *(_DWORD *)(v7 + 16));
    sub_4B3840(Destination, 64);
    sub_505C90(v3, v6, -1, 0, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
    v8 = dword_6090BC + v6;
    sub_4B3960(Destination, 64);
    v9 = this[5];
    v13 = 0;
    sub_505C90(v4, v8, -1, 1, 1065353216, 1065353216, *(_DWORD *)(v9 + 16));
    sub_4B39B0(Destination, 64);
    sub_505C90(v3, v8, -1, 0, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
    v10 = dword_6090BC + v8;
    sub_4B3200(Destination, 64);
    sub_505C90(v4, v10, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
    sub_4B3270(Destination, 64);
    sub_505C90(v3, v10, -1, 0, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
    v11 = dword_6090BC + v10;
    sub_4B35A0(Destination, 64);
    return sub_505C90(240, v11, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
  }
  return result;
}
