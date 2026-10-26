// f1c  0x004a1a00  size=91
int __stdcall sub_4A1A00(char *a1, float *a2)
{
  int result; // eax
  double v3; // [esp+0h] [ebp-30h]
  char v4[32]; // [esp+10h] [ebp-20h] BYREF

  v3 = *a2;
  v4[0] = 0;
  sub_58815F(v4, "%.5f", v3);
  result = 0;
  strcat(a1, v4);
  return result;
}
