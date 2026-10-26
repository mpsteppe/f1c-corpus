char __thiscall sub_41E9B0(void *this, int a2)
{
  char v4; // bl
  _BYTE v5[96]; // [esp+8h] [ebp-94h] BYREF
  _DWORD v6[10]; // [esp+68h] [ebp-34h] BYREF
  int v7; // [esp+98h] [ebp-4h]

  sub_6170B0(v5);
  v7 = 0;
  if ( (unsigned __int8)sub_617210(a2, 7289) )
  {
    sub_6175D0(1);
    (*(void (__thiscall **)(_DWORD *, int))(v6[0] + 4))(v6, 2468);
    v4 = ((int (__thiscall *)(void *, _BYTE *))loc_41E650)(this, v5);
    sub_613C30(v5);
    v7 = -1;
    sub_617170(v5);
    return v4;
  }
  else
  {
    v7 = -1;
    sub_617170(v5);
    return 0;
  }
}
