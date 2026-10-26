int __thiscall sub_67F74B(_DWORD *this, int a2, double a3, const void *a4)
{
  int v4; // edx

  sub_67EC68(this, 14);
  *(double *)(v4 + 24) = a3;
  *(_DWORD *)(v4 + 16) = a2;
  *(_DWORD *)v4 = &off_73CE7C;
  qmemcpy((void *)(v4 + 32), a4, 0x20u);
  return v4;
}
