int __thiscall sub_4E9660(int *this)
{
  int v2; // edi
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char Buffer[4]; // [esp+8h] [ebp-190h] BYREF
  char *v9; // [esp+Ch] [ebp-18Ch]
  char v10[48]; // [esp+18h] [ebp-180h] BYREF
  char v11[16]; // [esp+48h] [ebp-150h] BYREF
  char v12[48]; // [esp+58h] [ebp-140h] BYREF
  char v13[16]; // [esp+88h] [ebp-110h] BYREF
  char v14[112]; // [esp+98h] [ebp-100h] BYREF
  char v15[8]; // [esp+108h] [ebp-90h] BYREF
  char v16[16]; // [esp+148h] [ebp-50h] BYREF
  char v17; // [esp+158h] [ebp-40h] BYREF

  v2 = (unsigned __int64)(*((float *)dword_91E07C + 4307) * 9.5492964);
  if ( *(_DWORD *)(dword_91E084 + 14820) )
  {
    v5 = sub_41D840(&byte_91CC38, "O");
    sprintf(v10, "%s", v5);
    v6 = sub_41D840(&byte_91CC38, "W");
    sprintf(v12, "%s", v6);
    sprintf(v14, "%s ---    %s ---", v10, v12);
  }
  else
  {
    v9 = &v17;
    *(float *)Buffer = dbl_B68308 - 273.16;
    sub_4E8B20();
    sub_4E8B20();
    v3 = sub_41D840(&byte_91CC38, "O");
    sprintf(Buffer, "%s", v3);
    v4 = sub_41D840(&byte_91CC38, "W");
    sprintf(v11, "%s", v4);
    sprintf(v13, "%s %s    %s %s", Buffer, v16, v11, v15);
  }
  sub_4E6210((int)v13, this[147] + 48, this[148] + 190, this[2], this[3], 0);
  sprintf(v13, "%d", v2);
  sub_4E6210((int)v13, this[147] + 432, this[148] + 190, this[2], this[3], 1);
  return sub_4E6210((int)"S", this[147] + 432, this[148] + 190, *this, this[3], 0);
}
