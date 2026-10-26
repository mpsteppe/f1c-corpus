int __thiscall sub_576E30(_DWORD *this, int a2)
{
  int result; // eax
  _DWORD *v4; // eax
  char *v5; // eax
  int v6; // esi
  _DWORD *v7; // eax
  char *v8; // eax
  _DWORD *v9; // eax
  char *v10; // eax
  int v11; // ecx
  _DWORD *v12; // eax
  char *v13; // eax
  double v14; // st7
  int i; // esi
  double v16; // st7
  double v17; // st7
  float v18; // [esp+10h] [ebp-18h]
  double v19; // [esp+10h] [ebp-18h]
  float v20; // [esp+18h] [ebp-10h]
  double v21; // [esp+18h] [ebp-10h]
  double v22; // [esp+20h] [ebp-8h]

  this[4604] = 2139095039;
  this[4605] = 2139095039;
  this[4606] = 2139095039;
  this[4607] = 2139095039;
  result = dword_B6FD6C;
  if ( dword_B6FD6C <= 0 || dword_B6FD6C > 2 )
    return result;
  sub_5D7710(2, 0);
  v18 = 0.0;
  v20 = 180.0;
  v4 = (_DWORD *)sub_616840("VehicleLifetime");
  if ( v4 )
  {
    v5 = sub_48D380(v4);
    v20 = atof(v5);
  }
  v6 = sub_616840("DefaultScoring");
  if ( v6 )
  {
    v7 = (_DWORD *)sub_616630("RaceTimeScaled");
    if ( v7 )
    {
      v8 = sub_48D380(v7);
      v18 = atof(v8);
    }
  }
  sub_53A250(0);
  if ( v6 )
  {
    v9 = (_DWORD *)sub_616630("RaceTimeScaled");
    if ( v9 )
    {
      v10 = sub_48D380(v9);
      v18 = atof(v10);
    }
  }
  if ( sub_616840("SceneOrder") )
  {
    v11 = dword_BE1CD8 + 396 * dword_BE1CD4;
    if ( v11 )
    {
      if ( sub_616630((char *)(v11 + 260)) )
      {
        v12 = (_DWORD *)sub_616630("RaceTime");
        if ( v12 )
        {
          v13 = sub_48D380(v12);
          v18 = atof(v13);
        }
      }
    }
  }
  if ( byte_B722E4 )
  {
    v18 = 1440.0;
  }
  else if ( v18 <= 0.0 )
  {
    goto LABEL_24;
  }
  if ( v20 > 0.0 )
  {
    v14 = v18 / v20;
    if ( v14 >= 1.0 )
    {
      if ( v14 > 10.0 )
        v14 = 10.0;
    }
    else
    {
      v14 = 1.0;
    }
    goto LABEL_25;
  }
LABEL_24:
  v14 = 1.0;
LABEL_25:
  v22 = v14;
  for ( i = 0; i < 4; ++i )
  {
    switch ( i )
    {
      case 0:
        v16 = 1.549999952316284;
        break;
      case 1:
        v16 = 1.600000023841858;
        break;
      case 2:
        v16 = 1.649999976158142;
        break;
      case 3:
        v16 = 1.799999952316284;
        break;
      default:
        v16 = 3.0;
        break;
    }
    v19 = v16 * *(double *)(a2 + 5120) * v22;
    v21 = v16 * *(double *)(a2 + 5128) * v22;
    v17 = sub_51C800(&dword_BE08A0) * v21 + v19;
    if ( *(_DWORD *)dword_B640C8 == 6 && dword_B6FD6C == 2 )
      v17 = v17 / flt_FADE28;
    if ( v17 <= 3.402823466385289e38 )
      *(float *)&this[i + 4604] = v17;
    else
      this[i + 4604] = 2139095039;
  }
  return sub_5D7710(1, 0);
}
