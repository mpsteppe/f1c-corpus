// Address: 0x004a19d0
// Size: 39 bytes
// Name: sub_4A19D0
// Type: int __stdcall(const char *, bool *)
// Source: IDA Hex-Rays decompilation

int __stdcall sub_4A19D0(const char *a1, bool *a2)
{
  *a2 = strcmp(a1, a0) != 0;
  return 1;
}
