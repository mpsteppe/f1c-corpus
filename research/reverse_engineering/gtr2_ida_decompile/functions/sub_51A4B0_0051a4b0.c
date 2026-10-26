int __thiscall sub_51A4B0(_DWORD *this, int a2, float a3, float a4, float a5)
{
  int v6; // esi
  int v7; // edi
  int result; // eax
  float v9; // [esp+0h] [ebp-10h]
  float v10; // [esp+0h] [ebp-10h]
  float v11; // [esp+0h] [ebp-10h]

  v9 = a3 * 722.66315;
  v6 = sub_4015C0(v9) + 511;
  v10 = a4 * 722.66315;
  v7 = sub_4015C0(v10) + 511;
  v11 = a5 * 722.66315;
  result = sub_4015C0(v11);
  *this = result + ((v7 + ((v6 + (a2 << 10)) << 10)) << 10) + 511;
  return result;
}
