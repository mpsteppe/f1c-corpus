int __thiscall sub_4DCC90(
        _DWORD *this,
        int a2,
        int a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        int a9,
        int a10)
{
  double v10; // st7
  int v12; // edi
  int v13; // ebx
  int v14; // ebp
  int v15; // eax
  int v17; // [esp-18h] [ebp-1Ch]
  float v18; // [esp+10h] [ebp+Ch]

  v10 = (double)dword_5D6D60;
  v12 = CRTFtol(v10);
  v18 = (float)dword_5D6D64;
  v13 = CRTFtol(v10);
  v14 = CRTFtol(v10 * a7);
  v17 = CRTFtol(v18 * a8);
  v15 = CRTFtol(a6);
  return sub_4DCBA0(this, a2, a3, v12, v13, v15, v14, v17, a9, a10);
}
