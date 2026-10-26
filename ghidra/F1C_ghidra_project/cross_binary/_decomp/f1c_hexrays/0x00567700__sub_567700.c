// f1c  0x00567700  size=63
int __fastcall sub_567700(int *a1, _DWORD *a2, float a3, float *a4)
{
  float v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-4h]

  v8 = sub_587BDC(a3 * 0.00027777778);
  *a1 = v8;
  v7 = a3 - (double)v8 * 3600.0;
  return sub_5676C0(a2, a4, v7);
}
