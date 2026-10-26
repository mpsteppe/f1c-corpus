int __thiscall sub_45CF50(char *this, int a2)
{
  int v3; // esi
  int v4; // eax
  const char *v5; // edx
  char v6; // al
  const char *v7; // edx
  unsigned __int16 v9; // [esp+6h] [ebp-112h] BYREF
  char v10[16]; // [esp+8h] [ebp-110h] BYREF
  char v11[32]; // [esp+18h] [ebp-100h] BYREF
  _BYTE v12[96]; // [esp+38h] [ebp-E0h] BYREF
  _BYTE v13[125]; // [esp+98h] [ebp-80h] BYREF
  __int16 v14; // [esp+115h] [ebp-3h]
  char v15; // [esp+117h] [ebp-1h]

  sub_461550(v11);
  if ( (unsigned __int8)sub_4627C0(v11, &v9) )
  {
    sub_45CE30(aHostname, v11, this);
    v10[0] = 0;
    sub_58815F(v10, "%d", v9);
    sub_45CE30(aHostport, v10, this);
    sub_4C5690(v12);
    v3 = dword_8AC490 + 396 * dword_8AC48C;
    if ( v3 )
    {
      v13[0] = byte_5EA438[0];
      memset(&v13[1], 0, 0x7Cu);
      v14 = 0;
      v15 = 0;
      v4 = sub_4C5900(v13, 128);
      v5 = v13;
      if ( v4 )
        v5 = (const char *)(v3 + 260);
      sub_45CE30(aMapname, v5, this);
    }
    sub_58815F(v10, "%d", v12[68] + v12[69] + 1);
    sub_45CE30(aNumplayers, v10, this);
    sub_58815F(v10, "%d", v12[70]);
    sub_45CE30(aMaxplayers_0, v10, this);
    v6 = sub_462A00(dword_7CD25C);
    v7 = aOpenplaying;
    if ( !v6 )
      v7 = aClosedplaying;
    sub_45CE30(aGamemode, v7, this);
  }
  return nullsub_3(v11);
}
