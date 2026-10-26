int __thiscall sub_565CB0(int this)
{
  int v2; // edi
  double v3; // st7
  double v5; // [esp+4h] [ebp-C0h]
  float v6; // [esp+14h] [ebp-B0h]
  float v7; // [esp+14h] [ebp-B0h]
  float v8; // [esp+14h] [ebp-B0h]
  int v9; // [esp+18h] [ebp-ACh] BYREF
  int v10; // [esp+1Ch] [ebp-A8h] BYREF
  int v11; // [esp+20h] [ebp-A4h] BYREF
  char v12[32]; // [esp+24h] [ebp-A0h] BYREF
  char Buffer[128]; // [esp+44h] [ebp-80h] BYREF

  v2 = sub_5651B0((float *)this);
  v6 = *(float *)(this + 20) - dbl_FB1D10;
  *(float *)(this + 20) = v6;
  if ( *((_DWORD *)dword_91E07C + 4845) != 1 || *((_DWORD *)dword_91E07C + 4831) != 1 || v6 <= 0.0 )
    return 1;
  *(_DWORD *)(this + 16) = 1082130432;
  v7 = *((float *)dword_91E07C + 4866);
  sub_4E42F0(v7, &v11, &v9, (float *)&v10);
  v5 = *(float *)&v10;
  if ( v11 <= 0 )
    sprintf(Buffer, "%d:%06.3f", v9, v5);
  else
    sprintf(Buffer, "%d:%.2d:%06.3f", v11, v9, v5);
  sub_562B70((int)Buffer, 210, 130, (int)dword_FFFF00, 0, 0, 1.0, 1.0);
  if ( v7 == 0.0 )
    v3 = 0.0;
  else
    v3 = (double)dword_FADE18 * flt_91BDE4[0] / v7;
  if ( byte_B72478 )
  {
    v8 = v3 * 0.001 * 3600.0;
    strcpy(v12, sub_41D840(&byte_91CC38, (const char *)&off_6F4840));
  }
  else
  {
    v8 = v3 * 0.0006213712 * 3600.0;
    strcpy(v12, sub_41D840(&byte_91CC38, (const char *)&off_6F4830));
  }
  sprintf(Buffer, "%7.3f %s", v8, v12);
  sub_562B70((int)Buffer, 640, 130, (int)&loc_48AAB3, 2, 0, 1.0, 1.0);
  sprintf(Buffer, "%c", byte_903BA5);
  sub_562B70((int)Buffer, 1180, 50, (int)byte_FFFFFF, 1, 7, 2.0999999, 2.0999999);
  return v2;
}
