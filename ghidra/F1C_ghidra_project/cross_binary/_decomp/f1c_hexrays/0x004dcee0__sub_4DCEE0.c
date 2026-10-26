// f1c  0x004dcee0  size=61
int __thiscall sub_4DCEE0(_DWORD *this, float a2, float a3, float a4, int a5)
{
  int v6; // eax
  int v8; // [esp-10h] [ebp-10h]
  int v9; // [esp-Ch] [ebp-Ch]

  v9 = sub_587BDC(a4);
  v8 = sub_587BDC((double)dword_5D6D64 * a3);
  v6 = sub_587BDC((double)dword_5D6D60 * a2);
  return sub_4DCDD0(this, v6, v8, v9, a5);
}
