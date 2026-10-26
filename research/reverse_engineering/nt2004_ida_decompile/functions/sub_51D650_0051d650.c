void __thiscall sub_51D650(int this, float *a2)
{
  int v3; // eax
  double v4; // st7
  float v5; // [esp+8h] [ebp-38h]
  double v6[3]; // [esp+Ch] [ebp-34h] BYREF
  int v7; // [esp+24h] [ebp-1Ch]
  int v8; // [esp+28h] [ebp-18h]
  int v9; // [esp+2Ch] [ebp-14h]
  int v10; // [esp+30h] [ebp-10h]
  double v11; // [esp+34h] [ebp-Ch]
  int v12; // [esp+3Ch] [ebp-4h]
  float v13; // [esp+44h] [ebp+4h]

  v3 = *(_DWORD *)(this + 18420);
  v6[0] = *a2;
  v6[1] = a2[1];
  v6[2] = a2[2];
  v7 = 0;
  v8 = 0x40000000;
  v9 = 0x40000000;
  v10 = 1201543096;
  v12 = v3;
  if ( sub_44E900(dbl_760B48, (int)v6) )
  {
    v4 = a2[1] - v11;
    v5 = *(float *)(this + 20740) + 0.1;
    v13 = *(float *)(this + 20740) - 0.1;
    if ( v4 >= v13 )
    {
      if ( v4 > v5 )
        v4 = v5;
    }
    else
    {
      v4 = v13;
    }
    *(float *)(this + 20744) = (v4 + *(float *)(this + 20740)) * 0.5;
  }
}
