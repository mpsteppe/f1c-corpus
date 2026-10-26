int __thiscall sub_52AE20(_DWORD *this)
{
  char *v2; // edx
  int v3; // eax
  int v4; // eax
  const char *v5; // eax
  double v6; // st7
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  int v9; // eax
  int v10; // edx
  double v11; // st7
  double v12; // st7
  int result; // eax
  int v14; // [esp+10h] [ebp-12Ch]
  float v15; // [esp+10h] [ebp-12Ch]
  float v16; // [esp+10h] [ebp-12Ch]
  int v17; // [esp+14h] [ebp-128h]
  float v18; // [esp+18h] [ebp-124h]
  char String[32]; // [esp+1Ch] [ebp-120h] BYREF
  char Buffer[256]; // [esp+3Ch] [ebp-100h] BYREF

  ((void (*)(void))sub_52B930)();
  this[6] = 0;
  if ( (dword_75CBAC & 1) == 0 || dword_7D5DA4 == 2 )
  {
    result = sub_595B70(0x20000);
    this[4] = 0;
    return result;
  }
  if ( byte_7676DC )
    *(float *)this = flt_7D74C4;
  else
    *this = 1065353216;
  if ( dword_767454[0] )
  {
    if ( dword_767454[0] != 1 || !sub_57AE50(aSeasonraces) )
      goto LABEL_18;
    v2 = dword_766594;
    if ( !dword_766594 )
      v2 = &byte_629120;
    if ( !sub_57A720(v2) )
      goto LABEL_18;
    v3 = sub_57A720(aWeather);
    if ( !v3 )
      goto LABEL_18;
    v4 = sub_52C610(v3);
  }
  else
  {
    v5 = dword_62A0C8;
    if ( !dword_62A0C8 )
      v5 = &byte_629120;
    sprintf(Buffer, "%sweather.txt", v5);
    v4 = sub_52CA90(Buffer);
  }
  if ( v4 )
  {
LABEL_18:
    switch ( dword_767454[0] )
    {
      case 3:
        v17 = 1059481190;
        break;
      case 4:
        v17 = 1062584975;
        break;
      case 5:
        v17 = 1064849899;
        break;
      default:
        v17 = 1051931443;
        break;
    }
    v14 = dword_767598;
    if ( dword_767598 == 39 )
    {
      v15 = 25.0;
      if ( !sub_4E8E50(String, 32, aAverageDayTemp, 0) )
        v15 = (atof(String) - -40.0) * 0.5555555555555556 - 40.0;
      v6 = (sub_4D1B00(&dword_7D3C50) * 7.5 + v15 - -40.0) * 1.8 - 40.0;
      v16 = v6;
      if ( v6 >= 40.0 )
      {
        if ( v16 > 100.0 )
          v16 = 100.0;
      }
      else
      {
        v16 = 40.0;
      }
      v14 = (int)v16;
    }
    sub_52B930(this);
    v7 = operator new(0x10u);
    if ( v7 )
      v8 = sub_52AC20(v7);
    else
      v8 = 0;
    this[14] = v8;
    *v8 = 0;
    v18 = ((double)v14 - -40.0) * 0.5555555555555556 - 40.0;
    *(float *)(this[14] + 4) = v18;
    *(_DWORD *)(this[14] + 8) = v17;
    *(_DWORD *)(this[14] + 12) = 0;
    sub_52C0C0(*(float *)(this[14] + 8));
    v9 = this[8];
    v10 = this[14];
    this[9] = v9;
    this[10] = v9;
    v11 = *(float *)(v10 + 4);
    *((float *)this + 11) = *(float *)(v10 + 4);
    *((float *)this + 12) = v11;
  }
  qmemcpy(String, this + 7, 0x18u);
  sub_52CDC0(this);
  this[13] = this[14];
  *((_BYTE *)this + 60) = 1;
  this[16] = -8388609;
  qmemcpy(this + 7, String, 0x18u);
  this[2] = this[7];
  this[1] = 0;
  *((_WORD *)this + 34) = 0;
  *((_WORD *)this + 35) = -1;
  *((_WORD *)this + 36) = -1;
  *((_WORD *)this + 37) = 0;
  *((_WORD *)this + 38) = 0x7FFF;
  *((_WORD *)this + 39) = 0x8000;
  sub_595B70(0x20000);
  this[4] = *((float *)this + 10) > 0.0;
  v12 = flt_7D4054[(unsigned __int8)dword_7D3C50++] * 0.050000001;
  *((float *)this + 47) = v12;
  result = sub_52B7E0(this);
  if ( (dword_75CBAC & 1) != 0 && dword_7D5DA4 != 2 )
  {
    result = strcmp((const char *)this + 380, byte_7D74CC);
    if ( result )
    {
      strncpy((char *)this + 380, byte_7D74CC, 0xBu);
      *((_BYTE *)this + 391) = 0;
      return sub_52A7D0((int)(this + 48), 1);
    }
  }
  return result;
}
