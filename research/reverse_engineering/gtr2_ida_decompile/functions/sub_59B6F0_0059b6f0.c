int __thiscall sub_59B6F0(
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
        int a15,
        int a16)
{
  int v16; // ebp
  int v18; // eax
  int v19; // edx
  _DWORD v21[12]; // [esp-30h] [ebp-40h] BYREF

  v16 = a14;
  v18 = (*(int (__thiscall **)(_DWORD, int, _DWORD, int))(*(_DWORD *)*this + 104))(
          *this,
          a14 + 8,
          *(unsigned __int8 *)(a14 + 43),
          a16);
  qmemcpy(v21, &a2, sizeof(v21));
  a16 = v18;
  sub_5A3C40(v21[0], v21[1], v21[2], v21[3], v21[4], v21[5], v21[6], v21[7], v21[8], v21[9], v21[10], v21[11]);
  (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)*this + 196))(*this, v16);
  v19 = a15;
  *(_BYTE *)(*this + 97) = 0;
  sub_5A3F00(v19);
  return a16;
}
