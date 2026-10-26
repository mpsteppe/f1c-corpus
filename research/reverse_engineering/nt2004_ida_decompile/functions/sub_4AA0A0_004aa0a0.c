int __thiscall sub_4AA0A0(_DWORD *this, int a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  int v5; // ebp
  int v6; // edi
  int v7; // ecx
  char v9; // [esp+11h] [ebp-12Bh]
  char v10; // [esp+12h] [ebp-12Ah]
  char v11; // [esp+13h] [ebp-129h]
  int v12; // [esp+14h] [ebp-128h] BYREF
  int v13; // [esp+18h] [ebp-124h] BYREF
  _DWORD *v14; // [esp+1Ch] [ebp-120h]
  int v15; // [esp+20h] [ebp-11Ch] BYREF
  int v16; // [esp+24h] [ebp-118h]
  int v17; // [esp+28h] [ebp-114h] BYREF
  int v18; // [esp+2Ch] [ebp-110h]
  int v19; // [esp+30h] [ebp-10Ch]
  float v20; // [esp+34h] [ebp-108h]
  int v21; // [esp+38h] [ebp-104h]
  char String[125]; // [esp+3Ch] [ebp-100h] BYREF
  __int16 v23; // [esp+B9h] [ebp-83h]
  char v24; // [esp+BBh] [ebp-81h]
  char String2[128]; // [esp+BCh] [ebp-80h] BYREF

  String[0] = byte_629120;
  memset(&String[1], 0, 0x7Cu);
  v23 = 0;
  v3 = 0;
  v4 = 0;
  v24 = 0;
  v5 = 0;
  v6 = this[119] + 1;
  v14 = this;
  v19 = 0;
  v16 = 0;
  v20 = 0.0;
  v21 = 0;
  v18 = 0;
  *(float *)&v12 = 0.0;
  *(float *)&v13 = 0.0;
  *(float *)&v17 = 0.0;
  *(float *)&v15 = 0.0;
  this[119] = v6;
  v9 = 0;
  v11 = 0;
  v10 = 0;
  if ( !sub_4A84A0(this) )
    goto LABEL_29;
  do
  {
    if ( strstr(Str, asc_608AB4) )
    {
      if ( --v16 <= 0 )
        break;
LABEL_20:
      if ( !v9 )
        continue;
      goto LABEL_21;
    }
    if ( strstr(Str, asc_608AB8) )
    {
      ++v16;
      goto LABEL_20;
    }
    if ( sub_578220(aLocation, (int)&v12, (int)&v13, (int)&v17, (int)&v15, 0, 0, 0, 0) )
    {
      v4 = (__int64)*(float *)&v12;
      v5 = (__int64)*(float *)&v13;
      v3 = (__int64)*(float *)&v17;
      v19 = (__int64)*(float *)&v15;
      v9 = 1;
    }
    else
    {
      if ( !sub_578220(aPosWH, (int)&v12, (int)&v13, (int)&v17, (int)&v15, 0, 0, 0, 0) )
      {
        if ( sub_577E50(byte_7656E8, aSurface, (int)String2) )
        {
          v11 = 1;
        }
        else if ( sub_577E50(byte_7656E8, aAnimdelta, (int)String) )
        {
          v20 = atof(String);
        }
        else if ( sub_577E50(byte_7656E8, aAnimrule, (int)String) )
        {
          v21 = atol(String);
        }
        else if ( sub_577E50(byte_7656E8, aSubanimframe, (int)String) && v10 )
        {
          sub_4AA0A0(a2, v18);
        }
        goto LABEL_20;
      }
      v4 = (__int64)*(float *)&v13;
      v5 = (__int64)(*(float *)&v15 + *(float *)&v13);
      v3 = (__int64)*(float *)&v12;
      v19 = (__int64)(*(float *)&v17 + *(float *)&v12);
      v9 = 1;
    }
LABEL_21:
    if ( v11 && !v10 )
    {
      v18 = sub_4B0F90(v4, v5, v3, v19, String2, 0, 1, a3);
      v10 = 1;
    }
  }
  while ( sub_4A84A0(v14) );
  v7 = v18;
  if ( v18 )
  {
    if ( v20 > 0.0 )
      *(float *)(v18 + 20) = v20;
    *(_DWORD *)(v7 + 24) = v21;
  }
LABEL_29:
  --v14[119];
  return 0;
}
