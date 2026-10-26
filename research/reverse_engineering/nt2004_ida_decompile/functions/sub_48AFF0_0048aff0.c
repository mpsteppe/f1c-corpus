int __thiscall sub_48AFF0(_DWORD *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  int result; // eax
  int v7; // [esp+8h] [ebp-60h] BYREF
  int v8; // [esp+Ch] [ebp-5Ch] BYREF
  int v9; // [esp+10h] [ebp-58h] BYREF
  _BYTE v10[4]; // [esp+14h] [ebp-54h] BYREF
  char Buffer[80]; // [esp+18h] [ebp-50h] BYREF

  v2 = sub_5A9800(this[217]);
  v3 = sub_5A9590(v2);
  v4 = this[218];
  if ( v4 >= 0 )
  {
    if ( v4 >= v3 )
      this[218] = 0;
  }
  else
  {
    this[218] = v3 - 1;
  }
  sub_5A95E0(this[218], &v9, &v8, &v7, v10);
  v5 = v7;
  switch ( v7 )
  {
    case 5:
    case 6:
      v5 = 16;
      goto LABEL_8;
    case 7:
    case 8:
      v5 = 32;
LABEL_8:
      v7 = v5;
      break;
    default:
      break;
  }
  sprintf(Buffer, "%-4d x %-4d %d bit", v9, v8, v5);
  result = sub_4A1AC0(Buffer);
  dword_62A13C = this[218];
  return result;
}
