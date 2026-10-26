_DWORD *__fastcall sub_4B1D5C(_DWORD *a1, int a2)
{
  *(_BYTE *)(a2 - 1) += BYTE1(a1);
  sub_4D99B0(0, 0);
  *a1 = &off_700498;
  a1[210] = &unk_B7111C;
  a1[212] = 1;
  a1[213] = 0;
  a1[214] = 1;
  a1[215] = 1;
  a1[216] = 418;
  sub_4D3CF0(off_6F1D6C, -1);
  sub_4D3CF0("On", -1);
  sub_4AC060((int)a1);
  return a1;
}
