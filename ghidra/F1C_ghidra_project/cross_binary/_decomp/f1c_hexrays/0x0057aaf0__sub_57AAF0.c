// f1c  0x0057aaf0  size=48
bool __fastcall sub_57AAF0(const void *a1, _DWORD *a2)
{
  _DWORD v3[12]; // [esp-34h] [ebp-40h] BYREF
  _DWORD *v4; // [esp-4h] [ebp-10h]

  v4 = a2;
  *a2 = 0;
  qmemcpy(v3, a1, sizeof(v3));
  return sub_57ABB0(v3[0], v3[1], v3[2], v3[3], v3[4], v3[5], v3[6], v3[7], v3[8], v3[9], v3[10], v3[11], v4) == 0;
}
