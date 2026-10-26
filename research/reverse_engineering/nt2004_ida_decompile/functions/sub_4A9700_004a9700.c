int __thiscall sub_4A9700(_DWORD *this, char *String2)
{
  float *v3; // eax
  float *v4; // esi
  double v5; // st7
  float ***v6; // edi
  float **v7; // eax
  int v9; // [esp+10h] [ebp-98h] BYREF
  int v10; // [esp+14h] [ebp-94h] BYREF
  int v11; // [esp+18h] [ebp-90h] BYREF
  int v12; // [esp+1Ch] [ebp-8Ch] BYREF
  int v13; // [esp+20h] [ebp-88h] BYREF
  int v14; // [esp+24h] [ebp-84h] BYREF
  _BYTE v15[128]; // [esp+28h] [ebp-80h] BYREF

  v15[0] = byte_629120;
  memset(&v15[1], 0, 127);
  if ( !String2 || !strlen(String2) || sub_4AD420(String2) )
    return -1;
  v3 = (float *)operator new(0x20u);
  if ( v3 )
  {
    *v3 = 0.0;
    v3[1] = NAN;
    v3[2] = 0.0;
    v3[3] = NAN;
    v3[4] = 0.0;
    v3[5] = NAN;
    v3[6] = 1.0;
    v3[7] = 1.0;
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  sub_578600(String2);
  while ( sub_4A84A0(this) )
  {
    if ( strstr(Str, asc_608AB4) )
      break;
    if ( sub_577E50(byte_7656E8, aFile, (int)v15) )
    {
      sub_578600(v15);
    }
    else if ( sub_578110(aColorargb, (int)&v10, (int)&v14, (int)&v12, (int)&v9) )
    {
      *((_DWORD *)v4 + 5) = v9 | ((v12 | ((v14 | (v10 << 8)) << 8)) << 8);
    }
    else if ( sub_578220(aScale, (int)&v13, (int)&v11, 0, 0, 0, 0, 0, 0) )
    {
      v5 = *(float *)&v11;
      v4[6] = *(float *)&v13;
      v4[7] = v5;
    }
  }
  if ( (unsigned __int8)sub_4B0B30(v4) )
  {
    v6 = (float ***)(this[123] + 348);
    if ( v4 )
    {
      v7 = (float **)operator new(0xCu);
      if ( v7 )
      {
        *v7 = v4;
        v7[1] = 0;
        *((_BYTE *)v7 + 8) = 1;
      }
      else
      {
        v7 = 0;
      }
      if ( !*v6 )
      {
        *v6 = v7;
        v6[2] = v7;
        v6[1] = v7;
        v6[3] = (float **)((char *)v6[3] + 1);
        return 0;
      }
      v6[1][1] = (float *)v7;
      v6[1] = v7;
      v6[3] = (float **)((char *)v6[3] + 1);
    }
    return 0;
  }
  else
  {
    if ( v4 )
    {
      if ( *((_DWORD *)v4 + 2) )
        sub_5BE8AE(*((LPVOID *)v4 + 2));
      if ( *(_DWORD *)v4 )
        sub_5BE8AE(*(LPVOID *)v4);
      sub_5BE8AE(v4);
    }
    return -1;
  }
}
