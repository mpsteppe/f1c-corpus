int __thiscall sub_4B5170(_DWORD *this)
{
  int v1; // ebx
  int v2; // ebp
  int v3; // edi
  int result; // eax
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  char Destination[64]; // [esp+10h] [ebp-40h] BYREF

  v1 = dword_6090C0;
  v2 = dword_766078;
  v3 = dword_6090B8;
  sub_4B59D0(dword_6090C0, dword_766078, dword_6090B8);
  result = this[2];
  if ( result )
  {
    v6 = dword_6090BC + v3;
    sub_4B3630(Destination, 64);
    sub_505C90(v1, v6, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
    sub_4B3750(Destination, 64);
    sub_505C90(v2, v6, -1, 0, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
    v7 = dword_6090BC + v6;
    sub_4B3310(Destination, 64);
    sub_505C90(v1, v7, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
    sub_4B3380(Destination, 64);
    sub_505C90(v2, v7, -1, 0, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
    v8 = dword_6090BC + v7;
    sub_4B3470(Destination, 64);
    sub_505C90(v1, v8, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
    sub_4B34E0(Destination, 64);
    sub_505C90(v2, v8, -1, 0, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
    v9 = dword_6090BC + v8;
    sub_4B35A0(Destination, 64);
    return sub_505C90(240, v9, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
  }
  return result;
}
