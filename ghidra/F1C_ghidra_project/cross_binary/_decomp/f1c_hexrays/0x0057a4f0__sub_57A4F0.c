// f1c  0x0057a4f0  size=107
int __thiscall sub_57A4F0(
        _DWORD *this,
        char a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15)
{
  int v15; // ebp
  int v17; // eax
  int v18; // eax
  _DWORD v20[12]; // [esp-30h] [ebp-40h] BYREF

  v15 = a14;
  sub_585860(*(unsigned __int8 *)(a14 + 43));
  v17 = (*(int (__thiscall **)(_DWORD, int, _DWORD))(*(_DWORD *)*this + 104))(
          *this,
          v15 + 8,
          *(unsigned __int8 *)(v15 + 43));
  qmemcpy(v20, &a2, sizeof(v20));
  a14 = v17;
  sub_585030(v20[0], v20[1], v20[2], v20[3], v20[4], v20[5], v20[6], v20[7], v20[8], v20[9], v20[10], v20[11]);
  (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)*this + 192))(*this, v15);
  v18 = *this;
  v20[11] = a15;
  *(_BYTE *)(v18 + 93) = 0;
  sub_584FF0(v20[11]);
  return a14;
}
