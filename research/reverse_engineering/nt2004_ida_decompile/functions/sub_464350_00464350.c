bool __thiscall sub_464350(void *this, int a2)
{
  int v3; // ecx
  bool result; // al
  int v5; // edi
  bool v6; // bl
  float v7; // [esp+0h] [ebp-E4h]
  _DWORD v8[52]; // [esp+14h] [ebp-D0h] BYREF

  v3 = *(_DWORD *)(*(_DWORD *)this + 6720);
  result = 0;
  if ( v3 == 2 || v3 == 1 )
  {
    v7 = dbl_7DA9D0;
    v8[2] = a2;
    sub_4D0D00(4, 32, 4, 63, LODWORD(v7), 3);
    v5 = sub_56A3B0(*(_DWORD *)(*(_DWORD *)this + 6708));
    *(_BYTE *)(v5 + 4) = 1;
    v6 = sub_56A3D0(v8, (LOWORD(v8[0]) >> 6) + 8, v5, 1, 1, -1, 0) == 0;
    sub_56A3C0(*(_DWORD *)(*(_DWORD *)this + 6708), v5);
    return v6;
  }
  return result;
}
