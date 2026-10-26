char __thiscall sub_4DF890(int this)
{
  int *v2; // eax
  _WORD *v3; // ecx
  double v4; // st7
  int v5; // eax
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c3
  int v10[3]; // [esp+8h] [ebp-34h] BYREF
  int v11; // [esp+14h] [ebp-28h] BYREF
  _BYTE v12[4]; // [esp+18h] [ebp-24h] BYREF
  char Buffer[32]; // [esp+1Ch] [ebp-20h] BYREF

  v2 = 0;
  if ( *(int *)(this + 408) > 0 )
  {
    v3 = (_WORD *)(this + 412);
    while ( *v3 != 4129 )
    {
      v2 = (int *)((char *)v2 + 1);
      ++v3;
      if ( (int)v2 >= *(_DWORD *)(this + 408) )
        goto LABEL_8;
    }
    LOBYTE(v2) = *(_BYTE *)(this + 296) == 0;
    *(_BYTE *)(this + 296) = (_BYTE)v2;
    if ( !(_BYTE)v2 )
    {
      *(_DWORD *)(this + 300) = 0;
      *(_DWORD *)(this + 304) = 0;
      *(_DWORD *)(this + 308) = 0;
    }
  }
LABEL_8:
  if ( *(_BYTE *)(this + 296) )
  {
    v4 = *(float *)(this + 268) + *(float *)(this + 308);
    v5 = *(_DWORD *)(this + 304) + 1;
    *(_DWORD *)(this + 304) = v5;
    v11 = v5;
    *(float *)(this + 308) = v4;
    if ( !(v7 | v8) )
    {
      *(_DWORD *)(this + 300) = (unsigned __int64)((double)v11 / v4 + 0.5);
      *(_DWORD *)(this + 308) = 0;
      *(_DWORD *)(this + 304) = 0;
    }
    v2 = *(int **)(this + 300);
    if ( (int)v2 >= 0 )
    {
      sprintf(Buffer, "%d", *(_DWORD *)(this + 300));
      v10[0] = 1;
      sub_4DF1D0();
      v2 = &v11;
      if ( (int)&v11 > 0 && (int)v12 > 0 )
        LOBYTE(v2) = sub_4DF290((_DWORD *)this, 0, (int)v10, (int)&v11, (int)v12, 0, 1);
    }
  }
  return (char)v2;
}
