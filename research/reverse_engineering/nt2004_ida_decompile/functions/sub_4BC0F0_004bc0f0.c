int __stdcall sub_4BC0F0(char *a1, float *a2)
{
  int result; // eax
  double v3; // [esp+0h] [ebp-30h]
  char Buffer[32]; // [esp+10h] [ebp-20h] BYREF

  v3 = *a2;
  Buffer[0] = 0;
  sprintf(Buffer, "%.5f", v3);
  result = 0;
  strcat(a1, Buffer);
  return result;
}
