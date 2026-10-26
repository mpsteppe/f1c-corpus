// f1c  0x005007ef  size=211
int __stdcall sub_5007EF(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        const void *a9,
        int a10,
        int a11)
{
  int v11; // esi
  int v12; // eax
  _BYTE v14[76]; // [esp+4h] [ebp-5Ch] BYREF
  _DWORD v15[4]; // [esp+50h] [ebp-10h] BYREF
  _BYTE v16[24]; // [esp+60h] [ebp+0h] BYREF
  _BYTE v17[24]; // [esp+78h] [ebp+18h] BYREF
  int v18; // [esp+94h] [ebp+34h]
  int v19; // [esp+98h] [ebp+38h]
  _BYTE v20[12]; // [esp+9Ch] [ebp+3Ch] BYREF
  _BYTE v21[4]; // [esp+A8h] [ebp+48h] BYREF

  sub_502BEA(v20);
  sub_506538(v21);
  if ( a1 && a4 && a9 )
  {
    if ( a10 == -1 )
      a10 = 524292;
    v12 = sub_506971(v14, a1, a2, a3, 0, 0);
    if ( v12 < 0 )
      goto LABEL_8;
    v15[1] = a5;
    v15[2] = a6;
    v15[0] = a4;
    v15[3] = a7;
    qmemcpy(v16, a9, sizeof(v16));
    qmemcpy(v17, a9, sizeof(v17));
    v18 = a11;
    v19 = a8;
    v12 = sub_5063A5(v14, v15, a10);
    if ( v12 < 0 )
LABEL_8:
      v11 = v12;
    else
      v11 = 0;
  }
  else
  {
    v11 = -2005530516;
  }
  sub_50696C(v21);
  sub_502BF4(v20);
  return v11;
}
