// f1c  0x0050070d  size=223
int __stdcall sub_50070D(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, int a9, int a10)
{
  int v10; // ebx
  int v11; // eax
  _BYTE v13[76]; // [esp+4h] [ebp-64h] BYREF
  _DWORD v14[4]; // [esp+50h] [ebp-18h] BYREF
  _DWORD v15[6]; // [esp+60h] [ebp-8h] BYREF
  _BYTE v16[24]; // [esp+78h] [ebp+10h] BYREF
  int v17; // [esp+94h] [ebp+2Ch]
  int v18; // [esp+98h] [ebp+30h]
  _BYTE v19[16]; // [esp+9Ch] [ebp+34h] BYREF
  _BYTE v20[12]; // [esp+ACh] [ebp+44h] BYREF

  sub_502BEA(v20);
  sub_5064BF(v19);
  v10 = 0;
  if ( a1 )
  {
    if ( a4 && a8 )
    {
      if ( a9 == -1 )
        a9 = 524292;
      v11 = sub_506559(v13, a1, a2, a3, 0, 0);
      if ( v11 < 0 )
        goto LABEL_10;
      v14[1] = a5;
      v14[0] = a4;
      v14[2] = a6;
      v14[3] = 0;
      v15[0] = *a8;
      v15[1] = a8[1];
      v15[2] = a8[2];
      v15[3] = a8[3];
      v15[4] = 0;
      v15[5] = 1;
      qmemcpy(v16, v15, sizeof(v16));
      v17 = a10;
      v18 = a7;
      v11 = sub_5063A5(v13, v14, a9);
      if ( v11 < 0 )
LABEL_10:
        v10 = v11;
    }
    else
    {
      v10 = -2005530516;
    }
  }
  else
  {
    v10 = -2005530516;
  }
  sub_506554(v19);
  sub_502BF4(v20);
  return v10;
}
