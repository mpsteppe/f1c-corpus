int __thiscall sub_56A220(
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
        char *Source)
{
  int v15; // ebp
  int v17; // eax
  int v18; // ecx
  char *v20[12]; // [esp-30h] [ebp-40h] BYREF

  v15 = a14;
  v17 = (*(int (__thiscall **)(_DWORD, int, _DWORD))(*(_DWORD *)*this + 104))(
          *this,
          a14 + 8,
          *(unsigned __int8 *)(a14 + 43));
  qmemcpy(v20, &a2, sizeof(v20));
  a14 = v17;
  sub_5750A0((char)v20[0], v20[1], v20[2], v20[3], v20[4], v20[5], v20[6], v20[7], v20[8], v20[9], v20[10], v20[11]);
  (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)*this + 192))(*this, v15);
  v18 = *this;
  v20[11] = Source;
  *(_BYTE *)(v18 + 93) = 0;
  sub_575060(v20[11]);
  return a14;
}
