// Address: 0x00562605
// Size: 11 bytes
// Name: sub_562605
// Type: char __fastcall(char *, char *)
// Source: IDA Hex-Rays decompilation

char __fastcall sub_562605(char *a1, char *a2)
{
  char result; // al

  result = *a1;
  *a1 = *a2;
  *a2 = result;
  return result;
}
