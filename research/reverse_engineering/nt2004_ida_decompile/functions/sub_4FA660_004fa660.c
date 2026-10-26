bool __thiscall sub_4FA660(int this, int a2)
{
  double v3; // st7
  double v4; // st6
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  int v10; // ecx
  float v12; // [esp+4h] [ebp-54h]
  float v13; // [esp+8h] [ebp-50h]
  float v14; // [esp+Ch] [ebp-4Ch]
  float v15; // [esp+10h] [ebp-48h]
  float v16; // [esp+14h] [ebp-44h]
  char String[64]; // [esp+18h] [ebp-40h] BYREF

  v15 = flt_7D7974 - 100.0;
  v12 = flt_6290D0;
  v14 = sub_4BBF40();
  v3 = v15 + 30.0;
  if ( v14 <= v3 )
  {
    if ( v15 - (v12 - 30.0) <= v14 )
      goto LABEL_6;
    v4 = v14 + v12;
  }
  else
  {
    v4 = v14 - v12;
  }
  v14 = v4;
LABEL_6:
  v13 = flt_76622C;
  if ( flt_76622C > v3 )
  {
    v5 = flt_76622C - v12;
LABEL_10:
    v13 = v5;
    goto LABEL_11;
  }
  if ( v15 - (v12 - 30.0) > flt_76622C )
  {
    v5 = flt_76622C + v12;
    goto LABEL_10;
  }
LABEL_11:
  v16 = 200.0;
  if ( !sub_4E8E50(String, 64, aAiracetimemid, 0) )
  {
    v6 = atof(String);
    if ( v6 > 0.0 )
    {
      v7 = v6 * *(float *)(this + 184) * 1.25;
      if ( v7 >= 200.0 )
        v16 = v7;
    }
  }
  v8 = v12;
  if ( *(_BYTE *)(this + 163) )
    v9 = v8 * 0.60000002;
  else
    v9 = v8 * 0.75;
  if ( v16 > v9 )
    v16 = v9;
  v10 = a2;
  if ( v15 - v16 < v13 )
    v10 = a2 + 1;
  return v14 > (double)v15 && dword_766228 >= v10;
}
