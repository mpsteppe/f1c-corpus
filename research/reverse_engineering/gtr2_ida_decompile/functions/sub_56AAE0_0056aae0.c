char __thiscall sub_56AAE0(int this, _DWORD *a2)
{
  _DWORD *v2; // edx
  float *v3; // eax
  int v4; // ebx
  float v6; // [esp+0h] [ebp-18h]

  v2 = a2 + 10;
  *(_DWORD *)(this + 24) = *a2;
  v3 = (float *)(this + 32);
  v4 = 2;
  do
  {
    qmemcpy(v3 - 1, v2 - 9, 0x24u);
    *v3 = dbl_FB1D18;
    qmemcpy(v3 + 8, v2, 0x24u);
    v3[9] = dbl_FB1D18;
    qmemcpy(v3 + 17, v2 + 9, 0x24u);
    v3[18] = dbl_FB1D18;
    qmemcpy(v3 + 26, v2 + 18, 0x24u);
    v3[27] = dbl_FB1D18;
    qmemcpy(v3 + 35, v2 + 27, 0x24u);
    v3[36] = dbl_FB1D18;
    qmemcpy(v3 + 44, v2 + 36, 0x24u);
    v3[45] = dbl_FB1D18;
    qmemcpy(v3 + 53, v2 + 45, 0x24u);
    v3[54] = dbl_FB1D18;
    qmemcpy(v3 + 62, v2 + 54, 0x24u);
    v3[63] = dbl_FB1D18;
    qmemcpy(v3 + 71, v2 + 63, 0x24u);
    v3[72] = dbl_FB1D18;
    qmemcpy(v3 + 80, v2 + 72, 0x24u);
    v2 += 90;
    v3[81] = dbl_FB1D18;
    v3 += 90;
    --v4;
  }
  while ( v4 );
  *(float *)this = dbl_FB1D18 - 1.0;
  v6 = dbl_FB1D18;
  return sub_56A0D0((float *)this, v6, -1);
}
