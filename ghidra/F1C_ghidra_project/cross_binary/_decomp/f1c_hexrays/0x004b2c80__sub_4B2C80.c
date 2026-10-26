// f1c  0x004b2c80  size=336
unsigned int __thiscall sub_4B2C80(int this, float *a2)
{
  float v3; // edx
  float v5; // ecx
  __int16 v6; // ax
  double v7; // st7
  __int16 v8; // ax
  double v9; // st7
  __int16 v10; // ax
  float v12; // [esp+0h] [ebp-1Ch]
  float v13; // [esp+0h] [ebp-1Ch]
  float v14; // [esp+10h] [ebp-Ch] BYREF
  float v15; // [esp+14h] [ebp-8h]
  float v16; // [esp+18h] [ebp-4h]
  float v17; // [esp+20h] [ebp+4h]
  float v18; // [esp+20h] [ebp+4h]
  float v19; // [esp+20h] [ebp+4h]

  v3 = a2[2];
  v5 = a2[1];
  v14 = *a2;
  v15 = v5;
  v16 = v3;
  sub_4B21F0((_DWORD *)this, &v14);
  sub_4B2580((__int16 *)a2, &v14);
  if ( v14 <= 511.98001 )
  {
    if ( v14 >= -511.98001 )
    {
      v17 = v14 * 64.0;
      v6 = (int)v17;
    }
    else
    {
      v6 = -32767;
    }
  }
  else
  {
    v6 = 0x7FFF;
  }
  v7 = v15;
  *(_WORD *)(this + 9) = v6;
  if ( v7 <= 511.98001 )
  {
    if ( v15 >= -511.98001 )
    {
      v18 = v15 * 64.0;
      v8 = (int)v18;
    }
    else
    {
      v8 = -32767;
    }
  }
  else
  {
    v8 = 0x7FFF;
  }
  v9 = v16;
  *(_WORD *)(this + 11) = v8;
  if ( v9 <= 511.98001 )
  {
    if ( v16 >= -511.98001 )
    {
      v19 = v16 * 64.0;
      v10 = (int)v19;
    }
    else
    {
      v10 = -32767;
    }
  }
  else
  {
    v10 = 0x7FFF;
  }
  *(_WORD *)(this + 13) = v10;
  v12 = sub_4B29F0(a2);
  sub_4B2B90(this, v12);
  v13 = sub_4B2980(a2);
  return sub_4B2C20(this, v13);
}
