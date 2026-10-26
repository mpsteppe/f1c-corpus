int __thiscall sub_4B5350(_DWORD *this)
{
  int v1; // ebx
  int v2; // ebp
  int v3; // edi
  int result; // eax
  int v6; // edi
  char Destination[64]; // [esp+10h] [ebp-40h] BYREF

  v1 = dword_6090C0;
  v2 = dword_766078;
  v3 = dword_6090B8;
  sub_4B59D0(dword_6090C0, dword_766078, dword_6090B8);
  result = this[2];
  if ( result )
  {
    v6 = dword_6090BC + v3;
    sub_4B3EF0(Destination, 64);
    sub_505C90(v1, v6, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
    sub_4B3F60(Destination, 64);
    return sub_505C90(v2, v6, -1, 0, 1065353216, 1065353216, *(_DWORD *)(this[5] + 16));
  }
  return result;
}
