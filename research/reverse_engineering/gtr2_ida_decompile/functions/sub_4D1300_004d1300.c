int __thiscall sub_4D1300(int this)
{
  int v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v9; // [esp+4h] [ebp-8h] BYREF
  int v10; // [esp+8h] [ebp-4h] BYREF

  if ( !*(_BYTE *)(this + 312) || !*(_BYTE *)(this + 313) )
    return 0;
  sub_4DE540(&v10, &v9);
  v2 = v9;
  v3 = *(_DWORD *)(this + 304) - v9;
  if ( v3 > 10 )
  {
    v4 = *(_DWORD *)(this + 296) + 1;
LABEL_7:
    *(_DWORD *)(this + 296) = v4;
    goto LABEL_8;
  }
  if ( v3 < -10 )
  {
    v4 = *(_DWORD *)(this + 296) - 1;
    goto LABEL_7;
  }
LABEL_8:
  v5 = *(_DWORD *)(this + 296);
  if ( v5 >= 0 )
  {
    v6 = *(_DWORD *)(this + 292) - *(_DWORD *)(this + 308) / 2;
    if ( v5 > v6 )
      *(_DWORD *)(this + 296) = v6;
  }
  else
  {
    *(_DWORD *)(this + 296) = 0;
  }
  v7 = v10;
  *(_DWORD *)(this + 304) = v2;
  *(_DWORD *)(this + 300) = v7;
  return 0;
}
