int __thiscall sub_46A560(_DWORD *this)
{
  int v2; // edi
  _BYTE *v3; // ebp
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  double v14; // [esp+0h] [ebp-218h]
  double v15; // [esp+0h] [ebp-218h]
  int v16; // [esp+4h] [ebp-214h]
  int v17; // [esp+4h] [ebp-214h]
  int v18; // [esp+4h] [ebp-214h]
  int v19; // [esp+4h] [ebp-214h]
  int v20; // [esp+4h] [ebp-214h]
  int v21; // [esp+4h] [ebp-214h]
  int v22; // [esp+4h] [ebp-214h]
  char v23; // [esp+14h] [ebp-204h] BYREF
  __int16 v24; // [esp+15h] [ebp-203h]
  char v25; // [esp+17h] [ebp-201h]
  _BYTE v26[256]; // [esp+18h] [ebp-200h] BYREF
  _BYTE v27[256]; // [esp+118h] [ebp-100h] BYREF

  v24 = 0;
  v25 = 0;
  v23 = byte_5EA438[0];
  sub_4B0B20(v27, 256);
  sub_489CB0(this);
  sub_566650(v27);
  sub_4894D0(&v23);
  v2 = this[17];
  while ( v2 )
  {
    v3 = (_BYTE *)v2;
    v2 = *(_DWORD *)(v2 + 4);
    sub_434420(v3);
    sub_587BCF(v3);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  sub_486F30(aExperienceLaps, -1);
  sub_486F30(aStarts, -1);
  sub_486F30(aAvgStartingPos, -1);
  sub_486F30(aAvgFinishPosit, -1);
  sub_486F30(aPolePositions, -1);
  sub_486F30(aPoints, -1);
  sub_486F30(aWins, -1);
  sub_486F30(aLapRecords, -1);
  sub_486F30(aDriversChampii, -1);
  v16 = dword_7D2DD4;
  v4 = (const char *)sub_487010(0);
  sub_58815F(v26, "%s%s%i", v4, &v23, v16);
  sub_489600(v26, 0, 0, 0, 0);
  v17 = dword_7D2DD8;
  v5 = (const char *)sub_487010(1);
  sub_58815F(v26, "%s%s%i", v5, &v23, v17);
  sub_489600(v26, 0, 0, 0, 0);
  v14 = flt_7D2DF4;
  v6 = (const char *)sub_487010(2);
  sub_58815F(v26, "%s%s%.1f", v6, &v23, v14);
  sub_489600(v26, 0, 0, 0, 0);
  v15 = flt_7D2DF8;
  v7 = (const char *)sub_487010(3);
  sub_58815F(v26, "%s%s%.1f", v7, &v23, v15);
  sub_489600(v26, 0, 0, 0, 0);
  v18 = dword_7D2DEC;
  v8 = (const char *)sub_487010(4);
  sub_58815F(v26, "%s%s%i", v8, &v23, v18);
  sub_489600(v26, 0, 0, 0, 0);
  v19 = dword_7D2DE0;
  v9 = (const char *)sub_487010(5);
  sub_58815F(v26, "%s%s%i", v9, &v23, v19);
  sub_489600(v26, 0, 0, 0, 0);
  v20 = dword_7D2DE8;
  v10 = (const char *)sub_487010(6);
  sub_58815F(v26, "%s%s%i", v10, &v23, v20);
  sub_489600(v26, 0, 0, 0, 0);
  v21 = dword_7D2DF0;
  v11 = (const char *)sub_487010(7);
  sub_58815F(v26, "%s%s%i", v11, &v23, v21);
  sub_489600(v26, 0, 0, 0, 0);
  v22 = dword_7D2DE4;
  v12 = (const char *)sub_487010(8);
  sub_58815F(v26, "%s%s%i", v12, &v23, v22);
  return sub_489600(v26, 0, 0, 0, 0);
}
