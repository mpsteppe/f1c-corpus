double __stdcall sub_53A560(float a1, _BYTE *a2, int a3)
{
  int v3; // ebp
  _DWORD *v4; // esi
  char *v5; // eax
  char *v6; // eax
  int v7; // ecx
  int v8; // eax
  double result; // st7
  float v10; // [esp+0h] [ebp-14h]
  float v11; // [esp+4h] [ebp-10h] BYREF
  char v12[4]; // [esp+8h] [ebp-Ch] BYREF
  char ArgList[4]; // [esp+Ch] [ebp-8h] BYREF
  int v14; // [esp+10h] [ebp-4h] BYREF

  *a2 = 0;
  if ( !sub_616840("SeasonRaces") || !dword_BE1CD8 || !sub_616630((char *)(dword_BE1CD8 + 396 * dword_BE1CD4 + 260)) )
    return 86400.0;
  if ( !sub_616630("TimeOfDayScene") )
    return 86400.0;
  v3 = 0;
  v4 = (_DWORD *)sub_616610(0);
  if ( v4 )
  {
    while ( 1 )
    {
      v11 = 0.0;
      v5 = sub_48D380(v4);
      if ( sscanf(v5, "%d:%d:%f", ArgList, v12, &v11) >= 2 )
        *(float *)&v14 = (double)*(int *)ArgList * 3600.0 + (double)*(int *)v12 * 60.0 + (double)SLODWORD(v11);
      if ( dword_B640C0 != 5
        && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\setup.cpp", 2506) )
      {
        sub_561210((int)byte_FAE910, "SceneTime: %d:%d    curTime:%d:%d", ArgList[0]);
      }
      if ( a1 < (double)*(float *)&v14 )
        break;
      v4 = (_DWORD *)sub_616610(++v3);
      if ( !v4 )
        goto LABEL_13;
    }
    v7 = v14;
  }
  else
  {
LABEL_13:
    v4 = (_DWORD *)sub_616610(0);
    *(float *)&v14 = 0.0;
    v6 = sub_48D380(v4);
    if ( sscanf(v6, "%d:%d:%f", v12, ArgList, &v14) >= 2 )
      v11 = (double)*(int *)v12 * 3600.0 + (double)*(int *)ArgList * 60.0 + (double)v14;
    if ( dword_B640C0 != 5 )
    {
      if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\setup.cpp", 2539) )
        sub_561210((int)byte_FAE910, "SceneTime: %d:%d    curTime:%d:%d", v12[0]);
    }
    v7 = LODWORD(v11);
  }
  v10 = *(float *)&v7;
  v8 = sub_6165E0(v4);
  sub_630FE0(a2, v8, a3);
  result = v10;
  a2[a3] = 0;
  return result;
}
