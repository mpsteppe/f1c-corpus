int __thiscall sub_463F70(float **this)
{
  int v2; // ecx
  const char *v3; // edx
  char *v4; // eax
  const char *v5; // edx
  const char *v6; // ecx
  int v7; // eax
  char *v8; // eax
  char *v9; // eax
  int v10; // edx
  int v11; // ecx
  float v13; // [esp+0h] [ebp-130h]
  char v14; // [esp+Fh] [ebp-121h]
  int v15; // [esp+10h] [ebp-120h]
  int v16; // [esp+14h] [ebp-11Ch] BYREF
  _BYTE v17[32]; // [esp+18h] [ebp-118h] BYREF
  _BYTE v18[24]; // [esp+38h] [ebp-F8h] BYREF
  _BYTE v19[32]; // [esp+50h] [ebp-E0h] BYREF
  _BYTE v20[48]; // [esp+70h] [ebp-C0h] BYREF
  _BYTE v21[77]; // [esp+A0h] [ebp-90h] BYREF
  __int16 v22; // [esp+EDh] [ebp-43h]
  char v23; // [esp+EFh] [ebp-41h]
  _BYTE v24[64]; // [esp+F0h] [ebp-40h] BYREF

  v2 = *((_DWORD *)*this + 4081);
  if ( !v2 )
    return sub_45ECD0(*this);
  if ( v2 == 2 || v2 == 1 )
  {
    v14 = 1;
    dword_7C56A0 = 3;
  }
  else
  {
    v14 = 0;
    dword_7C56A0 = 2;
  }
  if ( !byte_7CE260 )
  {
    ThunkToFUN00461480(&v16);
    v3 = (const char *)(*this + 71);
    v16 = 2;
    if ( strlen(v3) )
    {
      sub_587DD0(v17, v3, 31);
    }
    else
    {
      v21[0] = byte_5EA438[0];
      memset(&v21[1], 0, 0x4Cu);
      v22 = 0;
      v23 = 0;
      sub_4B0B20(v21, 80);
      sub_587DD0(v17, v21, 31);
    }
    v4 = (char *)dword_7CE684;
    v17[31] = 0;
    if ( !dword_7CE684 )
      v4 = byte_5EA438;
    sub_587DD0(v18, v4, 23);
    v18[23] = 0;
    v24[0] = 0;
    if ( (unsigned __int8)NameComparisonAt0x1b4(v24, 64) )
    {
      sub_587DD0(v19, v24, 31);
      v5 = (const char *)dword_7CFE0C;
      v19[31] = 0;
      if ( !dword_7CFE0C )
        v5 = byte_5EA438;
      v6 = &v5[strlen(v5)];
      if ( v6 > v5 )
      {
        while ( *v6 != 92 )
        {
          if ( --v6 <= v5 )
            goto LABEL_20;
        }
        ++v6;
      }
LABEL_20:
      sub_587DD0(v20, v6, 31);
      v20[31] = 0;
    }
    ShortComputation_23b0((int)&v16);
    (*this)[223] = 5.0;
  }
  *((_BYTE *)*this + 40) = 1;
  *((_BYTE *)*this + 16344) = 8;
  *((_BYTE *)*this + 16345) = 0;
  switch ( dword_7D0E50 )
  {
    case 1:
      v7 = 8;
      break;
    case 2:
      v7 = 12;
      break;
    case 3:
      v7 = 14;
      break;
    case 4:
      v7 = 32;
      break;
    default:
      v7 = 6;
      break;
  }
  dword_7D0E98 = v7;
  if ( v7 < dword_7D0EA0 )
  {
    v7 = dword_7D0EA0;
LABEL_32:
    dword_7D0E98 = v7;
    goto LABEL_33;
  }
  if ( v7 > dword_7D0EA4 )
  {
    v7 = dword_7D0EA4;
    goto LABEL_32;
  }
LABEL_33:
  if ( v14 )
  {
    SingleCallWrapper(dword_7D0E50);
    WheelSpeedConversionWithZeroGuard(dword_7D10EC, -1);
    v8 = (char *)dword_7D0E88;
    if ( !dword_7D0E88 )
      v8 = byte_5EA438;
    StringCopyWithBufferRealloc(v8);
    v9 = (char *)dword_7D0E90;
    if ( !dword_7D0E90 )
      v9 = byte_5EA438;
    StringCopyWithBufferRealloc(v9);
    v7 = dword_7D0E98;
    dword_7D0EC0 = dword_7D0E9C;
    dword_7D0EC4 = dword_7D0EA0;
    v10 = dword_7D0E98;
    dword_7D0EBC = dword_7D0E98;
    dword_7D0EC8 = dword_7D0EA4;
  }
  else
  {
    v10 = dword_7D0EBC;
  }
  v11 = v7;
  if ( v7 <= 4 )
    v11 = 4;
  if ( v10 >= v11 )
  {
    v15 = v7;
    if ( v7 <= 4 )
      v15 = 4;
  }
  else
  {
    v15 = v10;
  }
  v13 = (float)v15;
  CollisionInvDistanceStore(*this, v13);
  SingleFunctionCallWrapper_a750(dword_7D0EE0);
  *((_BYTE *)*this + 48) = 0;
  GlobalFlagBasedStateSetter((int)(*this + 28132));
  return sub_45ECD0(*this);
}
