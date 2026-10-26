int __thiscall sub_52F8E0(float *this)
{
  int v1; // ebp
  int v2; // edi
  _DWORD *v3; // esi
  int result; // eax
  float v6; // [esp+10h] [ebp-30h]
  float v7; // [esp+14h] [ebp-2Ch]
  float v8; // [esp+18h] [ebp-28h]
  float v9; // [esp+1Ch] [ebp-24h]
  float v10; // [esp+20h] [ebp-20h]
  float v11; // [esp+24h] [ebp-1Ch]
  float v12; // [esp+28h] [ebp-18h]
  float v13; // [esp+2Ch] [ebp-14h]
  float v14; // [esp+30h] [ebp-10h]
  float v15; // [esp+34h] [ebp-Ch] BYREF
  float v16; // [esp+38h] [ebp-8h]
  float v17; // [esp+3Ch] [ebp-4h]

  v6 = 3.4028235e38;
  v7 = 3.4028235e38;
  v8 = 3.4028235e38;
  v9 = -3.4028235e38;
  v10 = -3.4028235e38;
  v11 = -3.4028235e38;
  v1 = sub_5DAB20(dword_FB1D04);
  v2 = 0;
  if ( v1 <= 0 )
    goto LABEL_21;
  do
  {
    v3 = (_DWORD *)sub_5DAB30(v2);
    if ( (unsigned __int8)sub_5ED600(0) && (*v3 & 0x10) == 0 )
    {
      sub_56C0A0(&v15);
      if ( v6 > (double)v12 )
        v6 = v12;
      if ( v7 > (double)v13 )
        v7 = v13;
      if ( v8 > (double)v14 )
        v8 = v14;
      if ( v9 < (double)v15 )
        v9 = v15;
      if ( v10 < (double)v16 )
        v10 = v16;
      if ( v11 < (double)v17 )
        v11 = v17;
    }
    ++v2;
  }
  while ( v2 < v1 );
  if ( v9 <= (double)v6 || v10 <= (double)v7 || v11 <= (double)v8 )
  {
LABEL_21:
    result = sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\searchgrid.cpp", 327);
    if ( (_BYTE)result )
      return sub_561210((int)byte_FAE910, "Could not get extents of scene ... numInstances=%d", v1);
  }
  else
  {
    result = (int)this;
    this[585] = v6;
    this[587] = v8;
    this[586] = 8.0 / (v9 - v6);
    this[588] = 8.0 / (v11 - v8);
  }
  return result;
}
