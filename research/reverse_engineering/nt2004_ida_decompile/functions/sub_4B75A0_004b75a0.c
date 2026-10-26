int __thiscall sub_4B75A0(_DWORD *this)
{
  _DWORD *v1; // ebp
  int v2; // esi
  _DWORD *v3; // edi
  int v4; // ebx
  const char *v5; // esi
  int v6; // esi
  int v7; // esi
  int v8; // ebx
  int v9; // ebp
  int result; // eax
  float v11; // [esp+0h] [ebp-84h]
  float v12; // [esp+4h] [ebp-80h]
  float v13; // [esp+18h] [ebp-6Ch] BYREF
  float v14; // [esp+1Ch] [ebp-68h] BYREF
  char *Source; // [esp+20h] [ebp-64h]
  int v16; // [esp+24h] [ebp-60h] BYREF
  int v17; // [esp+28h] [ebp-5Ch] BYREF
  int v18; // [esp+2Ch] [ebp-58h] BYREF
  int v19; // [esp+30h] [ebp-54h] BYREF
  int v20; // [esp+34h] [ebp-50h]
  int v21; // [esp+38h] [ebp-4Ch]
  _DWORD *v22; // [esp+3Ch] [ebp-48h]
  int v23; // [esp+40h] [ebp-44h]
  char Destination[61]; // [esp+44h] [ebp-40h] BYREF
  __int16 v25; // [esp+81h] [ebp-3h]
  char v26; // [esp+83h] [ebp-1h]

  v1 = this;
  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x3Cu);
  v25 = 0;
  v22 = this;
  v26 = 0;
  sub_4B7880(this);
  v2 = dword_75AACC + 16588;
  sub_4C0CA0(dword_75AACC + 16588);
  if ( (int)sub_4C0BF0(v1[19]) <= 1 )
    sub_4B78E0(1);
  v3 = v1 + 1;
  sub_506960(0);
  sub_5072A0(aPitstopAdjustm, 0.5, 0, dword_60911C, 2, -1.0, -1.0, 0);
  v4 = 0;
  Source = (char *)(v2 + 42);
  do
  {
    sub_4598D0(v3, &v14, &v13);
    v12 = v13 * 0.80000001;
    v11 = v14 * 0.80000001;
    sub_506C80(LODWORD(v11), LODWORD(v12));
    v5 = (const char *)sub_4BFF30(v4);
    if ( sub_41F230(dword_62A170, v5, ::Destination) )
    {
      if ( v5 )
      {
        strncpy(::Destination, v5, 0x1FFu);
        byte_62A37B = 0;
      }
      else
      {
        ::Destination[0] = 0;
      }
    }
    strncpy(Destination, ::Destination, 0x3Fu);
    v6 = v4 + 1;
    v26 = 0;
    v23 = v4 + 1;
    sub_5072A0(Destination, 0.5, v4 + 1, -1, 1, -1.0, -1.0, 0);
    if ( sub_41F230(dword_62A170, Source, ::Destination) )
    {
      if ( Source )
      {
        strncpy(::Destination, Source, 0x1FFu);
        byte_62A37B = 0;
      }
      else
      {
        ::Destination[0] = 0;
      }
    }
    strncpy(Destination, ::Destination, 0x3Fu);
    v26 = 0;
    sub_5072A0(Destination, 0.5, v4 + 1, -256, 0, -1.0, -1.0, 0);
    if ( v4 == v1[19] )
    {
      sub_506B70(&v17, &v19, 0);
      sub_506B50(&v18, &v16);
      *(float *)&v20 = (double)v16 / (double)(int)v1[17];
      v21 = (int)*(float *)&v20;
      v7 = v19 + v21 * v6;
      v8 = v7 + v21;
      v9 = v18 + v17;
      v20 = v17;
      sub_4AB110(v17, v7, v17, v7 + v21, -256, dword_7E8CDC);
      sub_4AB110(v20, v8, v9, v8, -256, dword_7E8CDC);
      sub_4AB110(v9, v8, v9, v7, -256, dword_7E8CDC);
      sub_4AB110(v9, v7, v20, v7, -256, dword_7E8CDC);
      v1 = v22;
      v6 = v23;
    }
    result = sub_506C80(LODWORD(v14), LODWORD(v13));
    v4 = v6;
    Source += 64;
  }
  while ( v6 < 12 );
  return result;
}
