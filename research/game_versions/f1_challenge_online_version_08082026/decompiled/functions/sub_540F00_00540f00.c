int __thiscall sub_540F00(int *this, _DWORD *a2, char a3, int a4, int a5)
{
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int v11; // [esp+14h] [ebp-4h] BYREF

  v6 = 2048;
  v11 = 0;
  if ( !a2 )
    return v11;
  v7 = a2[8];
  if ( !v7 )
    return v11;
  if ( (*a2 & 1) != 0 )
    v6 = 2064;
  if ( (*a2 & 0x20) != 0 )
  {
    v8 = this[1272];
    if ( !v8 )
      goto LABEL_11;
    if ( v8 <= 0 || v8 > 2 )
      goto LABEL_12;
    if ( (a3 & 0x40) != 0 )
LABEL_11:
      v6 |= 0x2000u;
    else
      v6 |= 0x1000u;
  }
LABEL_12:
  v9 = (*(int (__stdcall **)(int, int, int, int *, int))(*(_DWORD *)v7 + 44))(v7, a4 * a2[2], a5 * a2[2], &v11, v6);
  *this = v9;
  if ( v9 )
    return 0;
  ++a2[5];
  return v11;
}
