int __thiscall sub_4CF6B0(_DWORD *this, int a2, float a3, float a4, float a5)
{
  int result; // eax
  int v6; // [esp+0h] [ebp-4h]
  float v7; // [esp+Ch] [ebp+8h]
  float v8; // [esp+Ch] [ebp+8h]
  float v9; // [esp+Ch] [ebp+8h]
  int v10; // [esp+10h] [ebp+Ch]

  v7 = a3 * 722.66315;
  v6 = (int)v7;
  v8 = a4 * 722.66315;
  v10 = (int)v8;
  v9 = a5 * 722.66315;
  result = ((v10 + ((v6 + (a2 << 10)) << 10)) << 10) + (int)v9 + 536346111;
  *this = result;
  return result;
}
