void *__fastcall sub_5BFF20(void *a1, _DWORD *a2)
{
  void *result; // eax
  int v3; // ecx
  int v4; // edx
  _DWORD v5[16]; // [esp+8h] [ebp-40h] BYREF

  result = a1;
  v5[12] = *a2;
  v3 = a2[1];
  v4 = a2[2];
  v5[13] = v3;
  v5[0] = 1065353216;
  memset(&v5[1], 0, 16);
  v5[5] = 1065353216;
  memset(&v5[6], 0, 16);
  v5[10] = 1065353216;
  v5[11] = 0;
  v5[14] = v4;
  v5[15] = 1065353216;
  qmemcpy(result, v5, 0x40u);
  return result;
}
