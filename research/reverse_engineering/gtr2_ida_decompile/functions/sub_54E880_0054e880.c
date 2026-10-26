char __userpurge sub_54E880@<al>(
        float *a1@<ecx>,
        int a2@<ebp>,
        const char *a3,
        int a4,
        int a5,
        float *a6,
        float *a7,
        float *a8,
        float *a9,
        float a10,
        float a11,
        int a12,
        char a13)
{
  const char *v14; // eax
  const char *v15; // ecx
  int v16; // eax
  int v17; // ecx
  bool v18; // al
  char result; // al
  const char *v20; // [esp+2Ch] [ebp-204h]
  char Buffer[256]; // [esp+30h] [ebp-200h] BYREF
  char v22[256]; // [esp+130h] [ebp-100h] BYREF

  v14 = (const char *)&off_71F344;
  if ( !(_BYTE)a5 )
    v14 = (const char *)&off_71F340;
  sprintf(Buffer, "FPDriver%s_M%02d.lma", v14, a4);
  sprintf(v22, "ExtDriver_M%02d.lma", a4);
  if ( (_BYTE)a5 )
  {
    v15 = "FPDriver-ShiftR_M.lma";
    v20 = "ExtDriver-ShiftR_M.lma";
  }
  else
  {
    v15 = "FPDriver-ShiftL_M.lma";
    v20 = "ExtDriver-ShiftL_M.lma";
  }
  a1[8] = 0.0;
  if ( a12 != ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) || !byte_B718D8 || !byte_B718F0 )
    goto LABEL_13;
  if ( !a13 )
    goto LABEL_15;
  if ( sub_54D5C0(a1, a3, (int)"FPDriver_A.lma", (int)Buffer, (int)v15) )
  {
    if ( !sub_54DF70((int)a1, a5, (int)a3, a5, a6) )
      sub_408AC0((_DWORD *)a1 + 15);
  }
  else
  {
LABEL_13:
    v16 = sub_5DA9A0("FPDRIVER", a3);
    if ( v16 )
      sub_5DC6F0(v16);
  }
LABEL_15:
  if ( *a7 == 0.0 && a7[1] == 0.0 && a7[2] == 0.0 )
  {
    if ( (_BYTE)a5 )
    {
      a1[23] = 0.37;
      a1[24] = 0.07;
      a1[25] = -0.49000001;
    }
    else
    {
      a1[23] = -0.28;
      a1[24] = -0.02;
      a1[25] = -0.67000002;
    }
  }
  else
  {
    a1[23] = *a7;
    a1[24] = a7[1];
    a1[25] = a7[2];
  }
  if ( *a8 == 0.0 && a8[1] == 0.0 && a8[2] == 0.0 )
  {
    if ( (_BYTE)a5 )
    {
      a1[26] = 0.23999999;
      a1[27] = 0.07;
      a1[28] = -0.49000001;
    }
    else
    {
      a1[26] = -0.46000001;
      a1[27] = -0.02;
      a1[28] = -0.67000002;
    }
  }
  else
  {
    a1[26] = *a8;
    a1[27] = a8[1];
    a1[28] = a8[2];
  }
  if ( *a9 == 0.0 && a9[1] == 0.0 && a9[2] == 0.0 )
  {
    if ( (_BYTE)a5 )
    {
      a1[29] = 0.13;
      a1[30] = 0.07;
      a1[31] = -0.54000002;
    }
    else
    {
      a1[29] = -0.57999998;
      a1[30] = -0.02;
      a1[31] = -0.67000002;
    }
  }
  else
  {
    a1[29] = *a9;
    a1[30] = a9[1];
    a1[31] = a9[2];
  }
  a1[25] = a1[25] - 0.11;
  a1[28] = a1[28] - 0.11;
  a1[31] = a1[31] - 0.11;
  sub_54E350((__int32)a1, 1032805417, -1087666913, a10, a11);
  v17 = (int)a6;
  v18 = *a6 == 0.0 && a6[1] == 0.0 && a6[2] == 0.0;
  LOBYTE(v17) = !v18;
  sub_54CD40(a1, a2, (int)a3, "ExtDriver_A.lma", (int)v22, (int)v20, v17);
  sub_54D000();
  result = byte_B71908;
  if ( !byte_B71908 )
  {
    sub_408730(dword_91BE2C, 0.0);
    sub_408A90((_DWORD *)a1 + 52);
    sub_408AC0((_DWORD *)a1 + 53);
    return sub_408AC0((_DWORD *)a1 + 55);
  }
  return result;
}
