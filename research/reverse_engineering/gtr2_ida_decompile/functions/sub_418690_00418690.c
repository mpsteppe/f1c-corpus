int __thiscall sub_418690(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // esi
  float v7[3]; // [esp+4h] [ebp-Ch] BYREF

  switch ( this[8] )
  {
    case 0:
    case 3:
    case 4:
    case 5:
    case 6:
      goto LABEL_2;
    case 1:
      v3 = this[9];
      if ( v3 )
        *(float *)(v3 + 32) = dbl_FB1D18 + flt_B72D18;
LABEL_2:
      result = sub_57A7F0(this, *(_DWORD *)(this[9] + 216), this[9] + 224);
      break;
    case 2:
      v4 = this[9];
      v5 = *(_DWORD *)(v4 + 216);
      v7[0] = *(double *)(v4 + 328);
      v7[1] = *(double *)(v4 + 336);
      v7[2] = *(double *)(v4 + 344);
      sub_5EDA00(1, 0);
      sub_5767B0(a2, v7);
      sub_5ED820(v5, 1);
      result = sub_5EDA00(0, 0);
      break;
    case 7:
      if ( (*(_BYTE *)(*(_DWORD *)this[9] + 22580) & 1) == 0 )
        JUMPOUT(0x4187BD);
      result = sub_418758(a2);
      break;
    case 8:
      v6 = this[9];
      sub_5EDA00(1, 0);
      sub_5767B0(a2, 0);
      sub_5ED820(v6, 1);
      result = sub_5EDA00(0, 0);
      break;
    default:
      JUMPOUT(0x4187BE);
  }
  return result;
}
