int __thiscall sub_5E4F50(int *this, char *a2, int a3)
{
  char *v3; // esi
  int v5; // edi
  char v6; // cl
  int v7; // esi
  int result; // eax

  v3 = a2;
  v5 = (char *)(this + 1) - a2;
  do
  {
    v6 = *v3;
    v3[v5] = *v3;
    ++v3;
  }
  while ( v6 );
  v7 = *this;
  this[9] = 1065353216;
  this[33] = 1065353216;
  this[37] = 1065353216;
  this[191] = a3;
  this[11] = 0;
  this[12] = 0;
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  this[24] = 0;
  this[25] = 0;
  this[26] = 0;
  this[27] = 0;
  this[28] = 0;
  this[29] = 0;
  this[30] = 0;
  this[34] = 0;
  this[192] = 0;
  this[193] = 0;
  this[195] = 0;
  this[196] = 0;
  this[197] = 0;
  this[198] = 0;
  *this = v7 | 0xE2;
  result = 0;
  this[10] = 1148846080;
  this[31] = 1070142186;
  this[32] = 1067945923;
  this[35] = 4737096;
  this[36] = -1;
  this[194] = 2;
  memset(this + 38, 0, 0x60u);
  memset(this + 62, 0, 0x60u);
  this[103] = 1;
  return result;
}
