char __thiscall sub_461ED0(void *this, int a2)
{
  int v3; // esi
  int v4; // eax
  _BYTE v6[64]; // [esp+4h] [ebp-40h] BYREF

  if ( *(_DWORD *)(*(_DWORD *)this + 112540) )
  {
    v3 = (unsigned __int16)word_7D0FE8;
    v6[0] = 0;
    sub_587DD0(v6, a2, 63);
    v6[63] = 0;
    if ( sub_587C20(v6, byte_5C3F6C) )
    {
      sub_5897CA(v6, byte_5C3F6C);
      v4 = sub_5897CA(0, byte_5C3F6C);
      if ( v4 )
        v3 = sub_587ECE(v4);
    }
    sub_563260(*(_DWORD *)(*(_DWORD *)this + 112540), v6, v3, 1, 5);
  }
  return 1;
}
