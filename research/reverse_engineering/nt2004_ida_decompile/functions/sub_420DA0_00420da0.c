int __thiscall sub_420DA0(int this, float a2)
{
  int v2; // ebx
  int v4; // edx
  _DWORD *v5; // eax
  int v6; // ecx
  signed int v7; // ecx
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  _DWORD *v11; // esi
  int result; // eax
  const char *v13; // [esp+Ch] [ebp-1Ch]
  int v14[3]; // [esp+10h] [ebp-18h] BYREF
  _DWORD v15[3]; // [esp+1Ch] [ebp-Ch] BYREF
  signed int v16; // [esp+2Ch] [ebp+4h]
  float v17; // [esp+2Ch] [ebp+4h]

  v2 = 0;
  *(_DWORD *)(this + 23856) = 1020054733;
  *(_BYTE *)(this + 76) = 0;
  *(_DWORD *)(this + 24636) = -1;
  *(_DWORD *)(this + 23848) = 0;
  *(_DWORD *)(this + 23716) = 0;
  *(_DWORD *)(this + 40) = 0;
  *(_DWORD *)(this + 44) = 0;
  memset((void *)(this + 23432), 0, 0x50u);
  *(_BYTE *)(this + 24280) = 1;
  *(_DWORD *)(this + 23736) = 0;
  *(_DWORD *)(this + 24212) = 0;
  *(_DWORD *)(this + 23820) = 0;
  *(_DWORD *)(this + 23936) = 0x40000000;
  *(_DWORD *)(this + 23928) = 1061997773;
  *(_DWORD *)(this + 23940) = 1061997773;
  *(_DWORD *)(this + 23956) = 1061997773;
  *(_DWORD *)(this + 23932) = 1090519040;
  *(_DWORD *)(this + 23944) = 1065353216;
  *(_DWORD *)(this + 23948) = 6;
  *(_DWORD *)(this + 23952) = 8;
  switch ( dword_7D7928 )
  {
    case 3:
      *(_DWORD *)(this + 23936) = 1077936128;
      *(_DWORD *)(this + 23940) = 1065353216;
      *(_DWORD *)(this + 23944) = 0x40000000;
LABEL_7:
      *(_DWORD *)(this + 23948) = 7;
      break;
    case 1:
      *(_DWORD *)(this + 23952) = 9;
      *(_DWORD *)(this + 23932) = 1088421888;
      *(_DWORD *)(this + 23956) = 1060320051;
      *(_DWORD *)(this + 23940) = 1060320051;
      break;
    case 2:
      *(_DWORD *)(this + 23936) = 0x40000000;
      *(_DWORD *)(this + 23944) = 1069547520;
      *(_DWORD *)(this + 23940) = 1063675494;
      goto LABEL_7;
  }
  *(_DWORD *)(this + 23816) = 0;
  sub_428020(this);
  *(_DWORD *)(this + 24620) = 0;
  *(_DWORD *)(this + 23732) = 0;
  *(_DWORD *)(this + 23868) = 1232348144;
  sub_427F60(500);
  *(float *)(this + 23960) = *(float *)(this + 18768);
  *(_DWORD *)(this + 24168) = 1065353216;
  *(_DWORD *)(this + 24232) = 3;
  *(_BYTE *)(this + 24236) = 0;
  *(_DWORD *)(this + 24260) = 0;
  *(_DWORD *)(this + 24240) = 0;
  *(_DWORD *)(this + 24248) = 0;
  *(_DWORD *)(this + 24244) = 0;
  *(_DWORD *)(this + 24252) = 1065353216;
  *(_DWORD *)(this + 23964) = 1065353216;
  *(_DWORD *)(this + 24256) = 50;
  *(float *)(this + 24048) = (double)(rand() % 8) + 2.0;
  v4 = rand() % 50;
  *(_DWORD *)(this + 24056) = 1048576000;
  *(_DWORD *)(this + 24060) = 1048576000;
  *(_DWORD *)(this + 23752) = 0;
  *(_DWORD *)(this + 23616) = -1082130432;
  *(_DWORD *)(this + 23920) = -1;
  *(_DWORD *)(this + 23832) = 0;
  *(_DWORD *)(this + 23596) = 0;
  *(_DWORD *)(this + 24024) = 0;
  *(_DWORD *)(this + 24672) = 1232348144;
  *(float *)(this + 24052) = (double)v4 * 0.0049999999 + 0.1;
  if ( LOBYTE(a2) )
  {
    *(_DWORD *)(this + 24228) = 0;
    v5 = (_DWORD *)(this + 21208);
    v6 = 5;
    do
    {
      *v5 = -1;
      v5 += 2;
      --v6;
    }
    while ( v6 );
    sub_41FB90(this);
    sub_421590(0, 0);
    *(_DWORD *)(this + 23816) = dword_75CBB4;
    *(_DWORD *)(this + 23920) = -1;
    *(_DWORD *)(this + 24616) = 0;
    v7 = 0;
    v16 = 0;
    if ( (int)NumOfElements > 0 )
    {
      v13 = (const char *)(*(_DWORD *)(this + 80) + 24908);
      do
      {
        v8 = dword_75AAD0[v7];
        if ( !strcmp(v13, (const char *)(v8 + 24908)) && v8 != this )
          *(_DWORD *)(this + 24616) = v8;
        v7 = ++v16;
      }
      while ( v16 < (int)NumOfElements );
    }
    v9 = *(_DWORD *)(this + 80);
    *(_DWORD *)(this + 72) = dword_628FA8 + *(_DWORD *)(v9 + 25264);
    sub_4045E0(&flt_628F60, *(_DWORD *)(v9 + 25264), v14, v15);
    v10 = sub_4040B0(&flt_628F60, (float *)v14, 0, *(_DWORD *)(this + 72), 0.0, 0);
    *(_DWORD *)(this + 23608) = v10;
    if ( !v10 )
      *(_DWORD *)(this + 23608) = sub_403D10(&flt_628F60, (float *)v14, 0);
    if ( *(_DWORD *)(*(_DWORD *)(this + 80) + 16584) == 1 )
    {
      *(_DWORD *)(this + 64) = 2139095039;
      if ( flt_6290B4 >= 1.0 )
        v17 = flt_6290B4;
      else
        v17 = 1.0;
      sub_51E0F0(v17);
    }
    sub_426A80(this);
  }
  v11 = (_DWORD *)(this + 24640);
  do
  {
    result = sub_4C1760(v2);
    *v11 = result;
    ++v2;
    ++v11;
  }
  while ( v2 < 8 );
  return result;
}
