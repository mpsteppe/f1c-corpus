_DWORD *__thiscall sub_67F8F4(_DWORD *this, const void *a2, int a3, int a4)
{
  _DWORD *v4; // edx

  sub_67EC68(this, 15);
  *v4 = &off_73CE94;
  qmemcpy(v4 + 4, a2, 0x20u);
  v4[12] = a3;
  v4[13] = a4;
  return v4;
}
