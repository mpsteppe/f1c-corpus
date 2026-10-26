char __thiscall sub_4B5400(_DWORD *this, char a2)
{
  int v3; // eax
  int v4; // ebp
  bool v5; // bl
  int v6; // eax
  bool v7; // al
  bool v8; // al
  bool v9; // zf
  char Destination[16]; // [esp+50h] [ebp-10h] BYREF

  v3 = this[6];
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 16);
    if ( v4 )
    {
      if ( this[8] )
      {
        v5 = (int)(__int64)dbl_7DA9D0 % 2 == 0;
        sub_59FE60(0.0, 0.0, v4, 0.0, 0.0, 1.0, 1.0, 0, 0);
        LOBYTE(v3) = a2;
        if ( !a2 )
        {
          v6 = dword_75AAC4;
          if ( *(_DWORD *)(dword_75AAC4 + 3448) && *(_BYTE *)(dword_75AAC4 + 3512) || v5 )
          {
            v7 = *(_DWORD *)(dword_75AAC4 + 3448) && *(_BYTE *)(dword_75AAC4 + 3512);
            sub_59FFB0(195, 26, 18, 53, v7 ? -16711936 : -65536);
            v6 = dword_75AAC4;
          }
          if ( *(_DWORD *)(v6 + 3516) && *(_BYTE *)(v6 + 3580) || v5 )
          {
            v8 = *(_DWORD *)(v6 + 3516) && *(_BYTE *)(v6 + 3580);
            sub_59FFB0(42, 35, 14, 35, v8 ? -16711936 : -65536);
          }
          sub_4B5B40(2, 48, 16, 25, 15);
          sub_4B5B40(0, 164, 16, 25, 15);
          sub_4B5B40(3, 48, 74, 25, 15);
          sub_4B5B40(1, 164, 74, 25, 15);
          sub_4B5D70(2, 48, 4, 25, 7);
          sub_4B5D70(0, 164, 4, 25, 7);
          sub_4B5D70(3, 48, 94, 25, 7);
          sub_4B5D70(1, 164, 94, 25, 7);
          if ( *(_DWORD *)(dword_75AAD0[dword_75AAC0] + 25248) != *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248)
            || (v9 = byte_76026C == 0, byte_76026C = 0, v9) )
          {
            sub_59FFB0(59, 49, 46, 6, -16711936);
          }
          else
          {
            sub_59FFB0(59, 49, 46, 6, -256);
          }
          sub_59FFB0(87, 45, 16, 13, 65280);
          v3 = this[2];
          if ( v3 )
          {
            sub_4B3D00(Destination, 15);
            sub_505C90(58, 105, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[6] + 16));
            sub_4B3D70(Destination, 15);
            sub_505C90(66, 105, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[6] + 16));
            sub_4B3E30(Destination, 15);
            sub_505C90(184, 105, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[6] + 16));
            sub_4B3EA0(Destination, 15);
            LOBYTE(v3) = sub_505C90(192, 105, -1, 1, 1065353216, 1065353216, *(_DWORD *)(this[6] + 16));
          }
        }
      }
    }
  }
  return v3;
}
