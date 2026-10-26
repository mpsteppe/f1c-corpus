int __thiscall sub_552F20(int this, char *a2)
{
  int v3; // eax
  char *v4; // eax
  char v5; // dl
  int i; // ecx
  int *v7; // eax
  int v8; // ecx

  switch ( *(_DWORD *)(*(_DWORD *)(this + 100) + 48) )
  {
    case 5:
    case 6:
      sub_552BA0(this);
      break;
    case 7:
    case 8:
      sub_552D70(this);
      break;
    default:
      break;
  }
  v3 = CRTStrrchr(a2, 92);
  if ( v3 )
    v4 = (char *)(v3 + 1);
  else
    v4 = a2;
  v5 = *v4;
  for ( i = 0; v5 != 46; ++i )
  {
    *(_BYTE *)(this + i + 20) = v5;
    v5 = v4[i + 1];
  }
  *(_BYTE *)(i + this + 20) = 0;
  v7 = *(int **)(this + 100);
  v8 = *(_DWORD *)(this + 44);
  *(float *)this = 1.0 / (double)v7[7];
  *(float *)(this + 4) = 1.0 / (double)v7[8];
  v7[13] = v8;
  return 0;
}
