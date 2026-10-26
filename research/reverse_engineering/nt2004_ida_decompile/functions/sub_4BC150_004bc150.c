int __stdcall sub_4BC150(char *a1, unsigned __int16 *a2)
{
  int result; // eax
  int v3; // [esp-4h] [ebp-2Ch]
  char Buffer[32]; // [esp+8h] [ebp-20h] BYREF

  v3 = *a2;
  Buffer[0] = 0;
  sprintf(Buffer, "%d", v3);
  result = 0;
  strcat(a1, Buffer);
  return result;
}
