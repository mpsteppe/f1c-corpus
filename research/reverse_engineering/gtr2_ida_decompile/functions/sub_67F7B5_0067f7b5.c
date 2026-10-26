_DWORD *__thiscall sub_67F7B5(_DWORD *this, int a2, int a3, int a4, const void *a5)
{
  _DWORD *v5; // edx

  sub_67EC68(this, 14);
  v5[4] = a2;
  v5[6] = a3;
  v5[7] = a4;
  *v5 = &off_73CE7C;
  qmemcpy(v5 + 8, a5, 0x20u);
  return v5;
}
