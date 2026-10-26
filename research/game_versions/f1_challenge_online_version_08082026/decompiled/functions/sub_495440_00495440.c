char __thiscall sub_495440(int this)
{
  int v2; // edx
  int v3; // eax
  _WORD *v4; // ecx
  double v5; // st7
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c3
  int **v9; // eax
  int v11; // [esp-8h] [ebp-3Ch]
  int v12; // [esp-4h] [ebp-38h]
  int v13; // [esp+Ch] [ebp-28h] BYREF
  int v14; // [esp+10h] [ebp-24h] BYREF
  _BYTE v15[32]; // [esp+14h] [ebp-20h] BYREF

  v2 = *(_DWORD *)(this + 5528);
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = (_WORD *)(this + 5532);
    while ( *v4 != 4129 )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_8;
    }
    LOBYTE(v3) = *(_BYTE *)(this + 224) == 0;
    *(_BYTE *)(this + 224) = v3;
    if ( !(_BYTE)v3 )
    {
      *(_DWORD *)(this + 228) = 0;
      *(_DWORD *)(this + 232) = 0;
      *(_DWORD *)(this + 236) = 0;
    }
  }
LABEL_8:
  if ( *(_BYTE *)(this + 224) )
  {
    ++*(_DWORD *)(this + 232);
    v5 = sub_498730(this) + *(float *)(this + 236);
    *(float *)(this + 236) = v5;
    if ( !(v7 | v8) )
    {
      *(_DWORD *)(this + 228) = sub_587BDC(v5);
      *(_DWORD *)(this + 236) = 0;
      *(_DWORD *)(this + 232) = 0;
    }
    v3 = *(_DWORD *)(this + 228);
    if ( v3 >= 0 )
    {
      sub_58815F(v15, "%d", *(_DWORD *)(this + 228));
      LOBYTE(v3) = sub_4983B0(this + 5740, &v14, &v13, 1);
      if ( v14 > 0 && v13 > 0 )
      {
        sub_498560(this + 5740);
        sub_4981F0(v15, 0, v13, 0, v14, 1);
        v12 = v13;
        v11 = v14;
        v9 = (int **)sub_490920();
        LOBYTE(v3) = sub_4918D0(v9, 0, 0, v11, v12);
      }
    }
  }
  return v3;
}
