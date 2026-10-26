int __thiscall sub_47E0A0(_DWORD *this)
{
  const char *v2; // edi
  int v3; // eax
  int v4; // eax
  int *v5; // eax
  int v6; // eax
  int result; // eax
  int v8; // ebp
  LPVOID **v9; // eax
  char v10; // cl
  LPVOID *v11; // ebx
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  char v19; // [esp+Ch] [ebp-108h] BYREF
  __int16 v20; // [esp+Dh] [ebp-107h]
  char v21; // [esp+Fh] [ebp-105h]
  LPVOID **v22; // [esp+10h] [ebp-104h]
  _BYTE v23[256]; // [esp+14h] [ebp-100h] BYREF

  v2 = 0;
  v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 21);
  if ( v3 )
  {
    v4 = sub_48F590(v3);
    if ( v4 )
    {
      if ( *(int *)(v4 + 72) > 0 && (v5 = *(int **)(v4 + 60)) != 0 )
        v6 = *v5;
      else
        v6 = 0;
      v2 = *(const char **)(v6 + 60);
    }
  }
  result = sub_489CB0(this);
  if ( v2 )
  {
    v8 = this[17];
    v20 = 0;
    v19 = byte_5EA438[0];
    v21 = 0;
    while ( v8 )
    {
      v9 = (LPVOID **)v8;
      v10 = *(_BYTE *)(v8 + 8);
      v8 = *(_DWORD *)(v8 + 4);
      v22 = v9;
      if ( v10 )
      {
        v11 = *v9;
        if ( *v9 )
        {
          if ( *v11 )
            sub_587BCF(*v11);
          sub_587BCF(v11);
          v9 = v22;
        }
      }
      sub_587BCF(v9);
    }
    this[17] = 0;
    this[18] = 0;
    this[19] = 0;
    this[20] = 0;
    sub_486F30(aTeam_1, -1);
    sub_486F30(aFounded, -1);
    sub_486F30(aHeadquarters, -1);
    sub_486F30(aStarts, -1);
    sub_486F30(aPolePositions, -1);
    sub_486F30(aWins, -1);
    sub_486F30(aConstructorCha, -1);
    sub_4894D0(&v19);
    v12 = (const char *)sub_487010(0);
    sub_58815F(v23, "%s%s%s", v12, &v19, v2 + 700);
    sub_489600(v23, 0, 0, 0, 0);
    v13 = (const char *)sub_487010(1);
    sub_58815F(v23, "%s%s%s", v13, &v19, v2 + 828);
    sub_489600(v23, 0, 0, 0, 0);
    v14 = (const char *)sub_487010(2);
    sub_58815F(v23, "%s%s%s", v14, &v19, v2 + 844);
    sub_489600(v23, 0, 0, 0, 0);
    v15 = (const char *)sub_487010(3);
    sub_58815F(v23, "%s%s%s", v15, &v19, v2 + 908);
    sub_489600(v23, 0, 0, 0, 0);
    v16 = (const char *)sub_487010(4);
    sub_58815F(v23, "%s%s%s", v16, &v19, v2 + 924);
    sub_489600(v23, 0, 0, 0, 0);
    v17 = (const char *)sub_487010(5);
    sub_58815F(v23, "%s%s%s", v17, &v19, v2 + 940);
    sub_489600(v23, 0, 0, 0, 0);
    v18 = (const char *)sub_487010(6);
    sub_58815F(v23, "%s%s%s", v18, &v19, v2 + 956);
    sub_489600(v23, 0, 0, 0, 0);
    sub_58815F(v23, "%s", &v19);
    return sub_489600(v23, 0, 0, 0, 0);
  }
  return result;
}
