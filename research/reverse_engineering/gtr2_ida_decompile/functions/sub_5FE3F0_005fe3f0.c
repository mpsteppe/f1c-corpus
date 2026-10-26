float *__thiscall sub_5FE3F0(void *this)
{
  float *v2; // eax
  long double v3; // st7
  float *v4; // edi
  long double v5; // st6
  float v6; // edx
  float v7; // eax
  float *result; // eax
  float v9; // [esp+4h] [ebp-34h]
  float v10; // [esp+8h] [ebp-30h]
  float v11; // [esp+Ch] [ebp-2Ch]
  float v12; // [esp+10h] [ebp-28h]
  float v13; // [esp+14h] [ebp-24h]
  float v14; // [esp+18h] [ebp-20h]
  float v15; // [esp+1Ch] [ebp-1Ch] BYREF
  float v16; // [esp+20h] [ebp-18h] BYREF
  float v17; // [esp+24h] [ebp-14h]
  float v18; // [esp+28h] [ebp-10h]
  float v19; // [esp+2Ch] [ebp-Ch] BYREF
  float v20; // [esp+30h] [ebp-8h]
  float v21; // [esp+34h] [ebp-4h]

  if ( (*(_BYTE *)this & 8) != 0 )
  {
    sub_5E5050(*((char **)this + 68), 6);
    sub_5E4DB0(*((_DWORD **)this + 68), &v15, &v16);
    v2 = (float *)*((_DWORD *)this + 68);
    v3 = tan(v15 * 0.5);
    v9 = v2[9];
    v10 = v2[10];
    v4 = v2 + 141;
    v21 = v9;
    v5 = tan(v16 * 0.5);
    v12 = v9 * v3;
    v13 = v10 * v3;
    v11 = v9 * v5;
    v20 = v11;
    v14 = v10 * v5;
    v18 = -v12;
    v19 = v18;
    sub_5D7810(&v19, (float *)this + 14, v2 + 141);
    v17 = -v13;
    v20 = v14;
    v19 = v17;
    v21 = v10;
    sub_5D7810(&v19, (float *)this + 17, v4);
    v6 = v17;
    v17 = -v14;
    v20 = v17;
    v19 = v6;
    v21 = v10;
    sub_5D7810(&v19, (float *)this + 20, v4);
    v7 = v18;
    v18 = -v11;
    v20 = v18;
    v19 = v7;
    v21 = v9;
    sub_5D7810(&v19, (float *)this + 23, v4);
    v19 = v12;
    v20 = v11;
    v21 = v9;
    sub_5D7810(&v19, (float *)this + 26, v4);
    v19 = v12;
    v20 = v18;
    v21 = v9;
    sub_5D7810(&v19, (float *)this + 29, v4);
    v19 = v13;
    v20 = v17;
    v21 = v10;
    sub_5D7810(&v19, (float *)this + 32, v4);
    v19 = v13;
    v20 = v14;
    v21 = v10;
    return sub_5D7810(&v19, (float *)this + 35, v4);
  }
  return result;
}
