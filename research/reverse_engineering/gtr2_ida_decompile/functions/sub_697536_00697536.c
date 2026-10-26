_DWORD *__thiscall sub_697536(_DWORD *this, double *a2)
{
  double v2; // st7
  int v3; // edi
  const void *v4; // eax
  unsigned int v5; // edx
  int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-Ch]

  v2 = 0.0;
  v3 = 0;
  v4 = this + 8;
  v5 = 5;
  if ( !a2 || *((_DWORD *)a2 + 1) != 3 )
    return sub_69741E(this, v5, v3, v2, v4);
  v4 = a2 + 2;
  switch ( *((_DWORD *)a2 + 4) )
  {
    case 2:
      v5 = ((_DWORD)a2[3] & 0x9FFFFFFF | 0x20000000) >> 29;
      v3 = *((_DWORD *)a2 + 6);
      return sub_69741E(this, v5, v3, v2, v4);
    case 3:
      v8 = 4;
      goto LABEL_16;
    case 4:
      v8 = 8;
LABEL_16:
      v3 = *((_DWORD *)a2 + 6);
      v5 = v8;
      return sub_69741E(this, v5, v3, v2, v4);
    case 5:
      v7 = 9;
      goto LABEL_11;
    case 6:
      v7 = 10;
      goto LABEL_11;
    case 7:
      v7 = 11;
      goto LABEL_11;
    case 8:
      v7 = 12;
LABEL_11:
      v5 = v7;
      v2 = a2[3];
      break;
  }
  return sub_69741E(this, v5, v3, v2, v4);
}
