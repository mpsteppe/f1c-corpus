int __userpurge sub_567450@<eax>(int a1@<ecx>, double a2@<st0>, int a3, int a4)
{
  int v5; // eax
  int v6; // edi
  char *v7; // eax
  double v8; // st7
  int v9; // edi
  int v10; // ebx
  double v12; // [esp+0h] [ebp-134h]
  int v13[4]; // [esp+14h] [ebp-120h] BYREF
  int v14; // [esp+24h] [ebp-110h] BYREF
  int v15; // [esp+28h] [ebp-10Ch] BYREF
  int v16; // [esp+2Ch] [ebp-108h] BYREF
  char String[125]; // [esp+34h] [ebp-100h] BYREF
  __int16 v18; // [esp+B1h] [ebp-83h]
  char v19; // [esp+B3h] [ebp-81h]
  char Buffer[125]; // [esp+B4h] [ebp-80h] BYREF
  __int16 v21; // [esp+131h] [ebp-3h]
  char v22; // [esp+133h] [ebp-1h]

  memset(String, 0, sizeof(String));
  v18 = 0;
  v19 = 0;
  memset(Buffer, 0, sizeof(Buffer));
  v21 = 0;
  v22 = 0;
  sub_563E80(a3, &v14, &v15, &v16);
  v5 = *(_DWORD *)(a4 + 19324);
  v6 = v5 - 1;
  if ( v5 == 1 )
  {
    v7 = sub_41D840(&byte_91CC38, "LAPS");
    sprintf(Buffer, "%d %s", *(_DWORD *)(a1 + 36), v7);
  }
  else
  {
    sub_5511F0(dword_FADD40, 0);
    sub_52B830();
    *(float *)&v13[1] = a2;
    sub_52B830();
    if ( a2 > 0.0 )
    {
      v8 = a2 - *(float *)v13;
      *(float *)v13 = v8;
      if ( v8 > 0.0 )
      {
        sub_4E42B0(*(float *)v13, &v14, (float *)v13);
        v12 = *(float *)v13;
        if ( v14 <= 0 )
          sprintf(&String[116], "%.3f", v12);
        else
          sprintf(&String[116], "%d:%06.3f", v14, v12);
      }
    }
  }
  sprintf(String, "%c", v6 + byte_903BA0);
  v9 = v16;
  v10 = v14;
  sub_562B70((int)String, v14, v16, (int)byte_FFFFFF, 0, 7, 1.0, 1.0);
  sub_630FE0(String, 108 * *(_DWORD *)(a4 + 21788) + a4 + 21656, 127);
  v19 = 0;
  _strupr(String);
  sub_562B70((int)String, v10 + 40, v9, (int)byte_FFFFFF, 0, 0, 1.0, 1.0);
  sub_630FE0(String, Buffer, 127);
  v19 = 0;
  return sub_562B70((int)String, v15, v9, (int)dword_FFFF00, 1, 0, 1.0, 1.0);
}
