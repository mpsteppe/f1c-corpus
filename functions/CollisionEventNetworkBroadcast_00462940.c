bool __thiscall sub_462940(void *this, int a2)
{
  int v3; // ecx
  bool result; // al
  int v5; // edi
  bool v6; // bl
  float v7; // [esp+0h] [ebp-1C4h]
  _DWORD v8[108]; // [esp+14h] [ebp-1B0h] BYREF

  v3 = *(_DWORD *)(*(_DWORD *)this + 16324);
  result = 0;
  if ( v3 == 2 || v3 == 1 )
  {
    v7 = dbl_8AFEA0;
    v8[2] = a2;
    ProgressBarEventEncode(4, 32, 4, 255, LODWORD(v7), 1);
    v5 = COMVTableCallVia0x60(*(_DWORD *)(*(_DWORD *)this + 16312));
    *(_BYTE *)(v5 + 4) = 1;
    v6 = NetworkSendDispatch(v8, ((v8[0] >> 8) & 0x3FF) + 8, v5, 1, 1, -1, 0) == 0;
    VirtualMethodDispatch(*(_DWORD *)(*(_DWORD *)this + 16312), v5);
    return v6;
  }
  return result;
}
