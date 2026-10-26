char __thiscall sub_4AB930(int this)
{
  int v2; // edx
  int v3; // eax
  _WORD *v4; // ecx
  double v5; // st7
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c3
  int v10; // [esp+8h] [ebp-28h] BYREF
  int v11; // [esp+Ch] [ebp-24h] BYREF
  char Buffer[32]; // [esp+10h] [ebp-20h] BYREF

  v2 = *(_DWORD *)(this + 408);
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = (_WORD *)(this + 412);
    while ( *v4 != 4129 )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_8;
    }
    LOBYTE(v3) = *(_BYTE *)(this + 296) == 0;
    *(_BYTE *)(this + 296) = v3;
    if ( !(_BYTE)v3 )
    {
      *(_DWORD *)(this + 300) = 0;
      *(_DWORD *)(this + 304) = 0;
      *(_DWORD *)(this + 308) = 0;
    }
  }
LABEL_8:
  if ( *(_BYTE *)(this + 296) )
  {
    ++*(_DWORD *)(this + 304);
    v5 = sub_4AE720(this, v2) + *(float *)(this + 308);
    *(float *)(this + 308) = v5;
    if ( !(v7 | v8) )
    {
      *(_DWORD *)(this + 300) = (__int64)((double)*(int *)(this + 304) / v5 + 0.5);
      *(_DWORD *)(this + 308) = 0;
      *(_DWORD *)(this + 304) = 0;
    }
    v3 = *(_DWORD *)(this + 300);
    if ( v3 >= 0 )
    {
      sprintf(Buffer, "%d", *(_DWORD *)(this + 300));
      sub_4AE370(0, (int)Buffer, (int)&v10, (int)&v11);
      LOBYTE(v3) = v10;
      if ( v10 > 0 && v11 > 0 )
        LOBYTE(v3) = sub_4AE3F0(0, (int)Buffer, v10, v11, 0);
    }
  }
  return v3;
}
