_DWORD *__thiscall sub_67F5FE(_DWORD *this, int a2, int a3, int a4, int a5, int a6, const void *a7)
{
  _DWORD *v7; // edx

  sub_67EC68(this, 13);
  v7[5] = 0;
  v7[6] = 0;
  v7[4] = a2;
  v7[7] = a3;
  v7[8] = a4;
  v7[9] = a5;
  v7[10] = a6;
  *v7 = &off_73CE70;
  qmemcpy(v7 + 12, a7, 0x20u);
  return v7;
}
