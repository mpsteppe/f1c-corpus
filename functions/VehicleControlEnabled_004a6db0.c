// VehicleControlEnabled: Returns false if offset +0x4064 == 1 or 3. Value 2 does NOT disable. Also checks 8 health fields at 0x834-stride intervals + global mode + misc guard.
bool __thiscall sub_4A6DB0(int *this)
{
  int v1; // eax
  int v2; // ecx
  int v3; // eax
  bool result; // al

  result = (dword_7C56A4 == 7 || !dword_7C56A4)
        && ((v1 = *this, !*(_DWORD *)(*this + 2100))
         || !*(_BYTE *)(v1 + 2164)
         || !*(_DWORD *)(v1 + 2396)
         || !*(_BYTE *)(v1 + 2460)
         || !*(_DWORD *)(v1 + 2692)
         || !*(_BYTE *)(v1 + 2756)
         || !*(_DWORD *)(v1 + 2988)
         || !*(_BYTE *)(v1 + 3052)
          ? (v2 = 1)
          : (v2 = 0),
            (dword_7CE814 || !v2) && (v3 = *(_DWORD *)(v1 + 16484), v3 != 1) && v3 != 3)
        && (unsigned __int8)sub_4D21D0(&dword_8ACEE0) != 0;
  return result;
}
