double __thiscall sub_4B9A10(int *this)
{
  int v2; // esi
  double v3; // st6
  double v4; // st7
  double v5; // st7
  float v7; // [esp+8h] [ebp-Ch] BYREF
  float v8; // [esp+Ch] [ebp-8h]
  float v9; // [esp+10h] [ebp-4h] BYREF

  v2 = *this;
  v7 = 0.0;
  v9 = 0.0;
  QueuePeek((_DWORD *)v2, &v7, &v9);
  if ( *(_BYTE *)(v2 + 3969) )
  {
    v3 = dbl_8AFEA0 - *(float *)(v2 + 3972);
    v8 = v3;
    if ( v3 < v7 )
      v8 = v7;
    v4 = dbl_8AFEA0 - v8;
  }
  else
  {
    v4 = v9 - v7;
    v8 = v7;
  }
  v9 = v4;
  if ( v4 <= 0.0 )
    return 0.0;
  v5 = Delegation(this);
  return (v5 - v8) / v9;
}

