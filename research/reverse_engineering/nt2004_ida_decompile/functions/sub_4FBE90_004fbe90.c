int __thiscall sub_4FBE90(int this)
{
  int v2; // ecx
  float *v3; // eax
  __int64 v4; // rax
  void *v5; // eax
  int v6; // ecx
  int v7; // eax
  double v8; // st7
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int result; // eax
  int v18; // [esp-4h] [ebp-5Ch]
  char v19; // [esp+0h] [ebp-58h]
  float v20; // [esp+8h] [ebp-50h]
  float v21; // [esp+Ch] [ebp-4Ch] BYREF
  _BYTE v22[4]; // [esp+10h] [ebp-48h] BYREF
  _BYTE v23[4]; // [esp+14h] [ebp-44h] BYREF
  char String1[64]; // [esp+18h] [ebp-40h] BYREF

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_21, 3154) )
    sub_500FE0((int)&unk_7D7920, aEnteredSteward_0, v19);
  sub_4F8C90((_DWORD *)(this + 200), (int)aStlite, (int)aStglow);
  sub_4F8C90((_DWORD *)(this + 212), (int)aPtlit02, (int)aPtglow02);
  sub_4F8C90((_DWORD *)(this + 224), (int)aPtlit01, (int)aPtglow01);
  sub_4F9D90((_DWORD *)this);
  v2 = *(_DWORD *)(this + 228);
  *(_DWORD *)(this + 252) = 0;
  if ( v2 )
  {
    sub_59E0C0(&v21, v22, v23);
    v3 = sub_403D10(&flt_628F60, &v21, 0);
    if ( v3 )
      *(float *)(this + 252) = v3[29];
  }
  v4 = (__int64)(flt_6290D0 * 0.0049999999 + 1.0);
  *(_DWORD *)(this + 264) = v4;
  *(_DWORD *)(this + 268) = operator new(8 * v4);
  v5 = operator new(4 * *(_DWORD *)(this + 264));
  v6 = *(_DWORD *)(this + 264);
  *(_DWORD *)(this + 272) = v5;
  v7 = 0;
  v20 = flt_6290D0 / (double)v6;
  if ( v6 > 0 )
  {
    do
    {
      v8 = (double)(v7 + 1);
      v9 = 8 * v7;
      *(float *)(*(_DWORD *)(this + 268) + v9 + 4) = v8 * v20;
      sub_4F8D70((_DWORD *)(v9 + *(_DWORD *)(this + 268)), 0);
      v7 = v10;
    }
    while ( v10 < *(_DWORD *)(this + 264) );
  }
  if ( flt_6290D0 <= 0.0 )
    *(_DWORD *)(this + 260) = 0;
  else
    *(float *)(this + 260) = (double)*(int *)(this + 264) / flt_6290D0;
  v11 = sub_5975F0(aXpitin, 0);
  *(_DWORD *)(this + 1200) = v11;
  if ( v11 )
  {
    sub_59EED0(-11, 2048);
  }
  else if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_21, 3209) )
  {
    sub_500FE0((int)&unk_7D7920, aNoPitInPolyFou, v19);
  }
  v12 = sub_5975F0(aXpitout, 0);
  *(_DWORD *)(this + 1204) = v12;
  if ( v12 )
  {
    sub_59EED0(-25, 2048);
  }
  else if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_21, 3215) )
  {
    sub_500FE0((int)&unk_7D7920, aNoPitOutPolyFo, v19);
  }
  v13 = sub_5975F0(aXpitbad, 0);
  *(_DWORD *)(this + 1208) = v13;
  if ( v13 )
    sub_59EED0(-69, 2048);
  v14 = sub_5975F0(aXfinish, 0);
  *(_DWORD *)(this + 1212) = v14;
  if ( v14 )
  {
    sub_59EED0(0, 2048);
  }
  else if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_21, 3225) )
  {
    sub_500FE0((int)&unk_7D7920, aNoFinishPolyFo, v19);
  }
  v15 = sub_5975F0(aXsector1, 0);
  *(_DWORD *)(this + 1216) = v15;
  if ( v15 )
  {
    sub_59EED0(1, 2048);
  }
  else if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_21, 3231) )
  {
    sub_500FE0((int)&unk_7D7920, aNoSector1PolyF, v19);
  }
  v16 = sub_5975F0(aXsector2, 0);
  *(_DWORD *)(this + 1220) = v16;
  if ( v16 )
  {
    sub_59EED0(2, 2048);
  }
  else if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_21, 3237) )
  {
    sub_500FE0((int)&unk_7D7920, aNoSector2PolyF, v19);
  }
  switch ( *(_DWORD *)dword_7689CC )
  {
    case 1:
      v18 = 0;
      goto LABEL_43;
    case 2:
      goto LABEL_36;
    case 3:
      if ( dword_76618C == 1 )
      {
LABEL_36:
        v18 = 7;
LABEL_43:
        sub_42F6C0(&dword_75CBA8, v18);
      }
      else if ( dword_766CBC )
      {
        sub_42F6C0(&dword_75CBA8, 5);
      }
      else
      {
        sub_42F6C0(&dword_75CBA8, 4);
      }
LABEL_44:
      sub_4BA330();
      *(_BYTE *)(this + 163) = 0;
      result = sub_4E8E50(String1, 64, aTrackType, 0);
      if ( !result )
      {
        result = _strcmpi(String1, aRoadCourse);
        if ( !result )
          *(_BYTE *)(this + 163) = 1;
      }
      return result;
    case 5:
      v18 = 4;
      goto LABEL_43;
    case 6:
      if ( dword_7D5DA4 == 2 )
        goto LABEL_44;
      v18 = 8;
      goto LABEL_43;
    default:
      goto LABEL_44;
  }
}
