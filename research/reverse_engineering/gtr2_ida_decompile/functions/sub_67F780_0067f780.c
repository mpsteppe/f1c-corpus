_DWORD *__thiscall sub_67F780(_DWORD *this, int a2, int a3, const void *a4)
{
  _DWORD *v4; // edx

  sub_67EC68(this, 14);
  v4[4] = a2;
  v4[6] = a3;
  *v4 = &off_73CE7C;
  qmemcpy(v4 + 8, a4, 0x20u);
  return v4;
}
