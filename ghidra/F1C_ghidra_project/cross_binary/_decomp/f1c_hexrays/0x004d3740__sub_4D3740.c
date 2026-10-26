// f1c  0x004d3740  size=110
int __thiscall sub_4D3740(_DWORD *this)
{
  int v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h] BYREF

  sub_54C150(&v3, 2048);
  sub_4BC390((float *)&unk_5F070C + 4656 * v3, (int)this);
  sub_54C150(&v4, 2048);
  sub_424CD0((int *)&unk_5EC6D8 + 4656 * v3, v4 + 1, 0);
  sub_54FAE0(this[5]);
  return 0;
}
