int __usercall sub_47A480@<eax>(_BYTE *a1@<ecx>, int a2@<edi>)
{
  int v3; // ecx
  const char *v4; // edx
  const CHAR *v5; // eax
  const char *v6; // ecx
  const char *v7; // eax
  int v8; // eax
  int v9; // ecx
  int result; // eax
  int v11; // [esp-12h] [ebp-3DCh]
  char v12; // [esp+9h] [ebp-3C1h]
  char v13; // [esp+Dh] [ebp-3BDh]
  char v14; // [esp+25h] [ebp-3A5h]
  _BYTE v15[77]; // [esp+2Ah] [ebp-3A0h] BYREF
  __int16 v16; // [esp+77h] [ebp-353h]
  char v17; // [esp+79h] [ebp-351h]
  _BYTE v18[40]; // [esp+7Ah] [ebp-350h] BYREF
  _BYTE v19[4]; // [esp+A2h] [ebp-328h] BYREF
  int v20; // [esp+BAh] [ebp-310h] BYREF
  int v21; // [esp+BEh] [ebp-30Ch]
  _BYTE v22[32]; // [esp+C2h] [ebp-308h] BYREF
  _BYTE v23[16]; // [esp+E2h] [ebp-2E8h] BYREF
  _BYTE v24[20]; // [esp+F2h] [ebp-2D8h] BYREF
  _BYTE v25[288]; // [esp+106h] [ebp-2C4h] BYREF
  _BYTE v26[156]; // [esp+226h] [ebp-1A4h] BYREF
  _BYTE v27[264]; // [esp+2C2h] [ebp-108h] BYREF

  v3 = *(_DWORD *)(*(_DWORD *)a1 + 113328);
  if ( v3 )
  {
    if ( v3 == 2 || v3 == 1 )
    {
      v14 = 1;
      dword_B640C4 = 3;
    }
    else
    {
      v14 = 0;
      dword_B640C4 = 2;
    }
    if ( !byte_B6F124 )
    {
      sub_4733E0(&v20);
      if ( a1[296] )
      {
        v20 = 0;
      }
      else if ( !a1[297] || v14 )
      {
        v20 = 3;
        v21 = 3;
      }
      else
      {
        v20 = 2;
        v21 = 0;
        v26[148] = 1;
      }
      v4 = (const char *)(*(_DWORD *)a1 + 1504);
      if ( &v4[strlen(v4) + 1] == (const char *)(*(_DWORD *)a1 + 1505) )
      {
        memset(v15, 0, sizeof(v15));
        v16 = 0;
        v17 = 0;
        sub_501490(v15, 80);
        v4 = v15;
      }
      sub_630FE0(v22, v4, 31);
      v5 = (const CHAR *)dword_B6F75C;
      v22[31] = 0;
      if ( !dword_B6F75C )
        v5 = WindowName;
      sub_630FE0(v23, v5, 23);
      v24[7] = 0;
      v18[0] = 0;
      if ( (unsigned __int8)sub_501C30(&byte_B6F530, v18, 64, a2) )
      {
        sub_630FE0(v24, &v15[72], 31);
        v25[11] = 0;
        v27[0] = 0;
        if ( (unsigned __int8)sub_501C90(&byte_B6F530, v27, 256) )
          sub_473BB0();
        v6 = (const char *)dword_B71A94;
        if ( !dword_B71A94 )
          v6 = WindowName;
        v7 = sub_40D7B0(v6);
        sub_630FE0(v25, v7, 31);
        v11 = *((_DWORD *)a1 + 2) + 305;
        v25[31] = 0;
        sub_630FE0(v26, v11, 63);
        v26[63] = 0;
        sub_473BE0();
      }
      if ( !sub_59B5A0(v19, 528) )
        sub_42CB90();
      sub_479970();
    }
    *(_BYTE *)(*(_DWORD *)a1 + 1184) = 1;
    *(_BYTE *)(*(_DWORD *)a1 + 113348) = 7;
    *(_BYTE *)(*(_DWORD *)a1 + 113349) = 0;
    switch ( dword_B7321C )
    {
      case 1:
        v8 = 8;
        break;
      case 2:
        v8 = 12;
        break;
      case 3:
        v8 = 14;
        break;
      case 4:
        v8 = 32;
        break;
      default:
        v8 = 6;
        break;
    }
    v9 = dword_B7329C;
    dword_B73294 = v8;
    if ( v8 < dword_B7329C || (v9 = dword_B732A0, v8 > dword_B732A0) )
      dword_B73294 = v9;
    if ( v13 )
    {
      sub_48B680(dword_B7321C);
      sub_489890(dword_B73624, -1);
      sub_475CF0();
    }
    sub_59B4C0(dword_B732DC);
    *(_BYTE *)(*(_DWORD *)a1 + 1192) = 0;
    sub_46A230();
    if ( v12 && a1[27] )
      CINet::NextSession(*((CINet **)a1 + 2), *(_DWORD *)dword_B640C8);
  }
  result = *(_DWORD *)a1;
  *(double *)(*(_DWORD *)a1 + 2144) = 0.0;
  return result;
}
