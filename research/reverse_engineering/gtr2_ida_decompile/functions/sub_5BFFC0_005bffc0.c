void *__thiscall sub_5BFFC0(void *this, int a2, int a3, int a4)
{
  void *result; // eax
  _DWORD v5[16]; // [esp+8h] [ebp-40h] BYREF

  result = this;
  v5[0] = a2;
  v5[10] = a4;
  memset(&v5[1], 0, 16);
  v5[5] = a3;
  memset(&v5[6], 0, 16);
  memset(&v5[11], 0, 16);
  v5[15] = 1065353216;
  qmemcpy(this, v5, 0x40u);
  return result;
}
