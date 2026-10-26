bool __thiscall sub_474860(void *this, int a2, char a3)
{
  int v4; // ecx
  bool result; // al
  int v6; // edi
  bool v7; // bl
  float v8; // [esp+4h] [ebp-364h]
  _DWORD v9[3]; // [esp+18h] [ebp-350h] BYREF
  char v10; // [esp+24h] [ebp-344h]

  v4 = *(_DWORD *)(*(_DWORD *)this + 113328);
  result = 0;
  if ( v4 == 2 || v4 == 1 )
  {
    v10 = a3;
    v9[2] = a2;
    v8 = dbl_FB1D18;
    sub_51B2A0(4, 28, 5, 255, LODWORD(v8), 3);
    v6 = sub_59B480(*(_DWORD *)(*(_DWORD *)this + 113316));
    *(_BYTE *)(v6 + 4) = 1;
    v7 = sub_59B7F0((char)v9, ((v9[0] >> 8) & 0x3FF) + 8, v6, 1, 1, -1, 0) == 0;
    sub_59B490(*(_DWORD *)(*(_DWORD *)this + 113316), v6);
    return v7;
  }
  return result;
}
