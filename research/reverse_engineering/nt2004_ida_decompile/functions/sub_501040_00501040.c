int __thiscall sub_501040(char *this)
{
  int i; // eax
  double v3; // st7
  _DWORD *v4; // eax
  int v5; // ecx
  char **v6; // edi
  float *v7; // ebx
  int result; // eax
  int v9; // edx
  float *v10; // ecx
  double v11; // st7
  int v12; // eax
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // ebx
  int v17; // edi
  int v18; // ecx
  char String[64]; // [esp+10h] [ebp-40h] BYREF

  for ( i = 0; i < 3; *(float *)&this[4 * i + 60] = v3 )
  {
    if ( i == 1 )
    {
      *((_DWORD *)this + 14) = 0;
    }
    else if ( i )
    {
      *(float *)&this[4 * i + 52] = flt_6290CC[i];
    }
    else
    {
      *((float *)this + 13) = flt_6290D8;
    }
    v3 = flt_6290D0[i++];
  }
  *(_DWORD *)this = 0;
  if ( !sub_4E8E50(String, 64, aTrackType, 0) )
  {
    if ( _strcmpi(String, aSuperspeedway) )
    {
      if ( _strcmpi(String, aSpeedway) )
      {
        if ( _strcmpi(String, aShortTrack) )
        {
          if ( !_strcmpi(String, aRoadCourse) )
            *(_DWORD *)this = 3;
        }
        else
        {
          *(_DWORD *)this = 2;
        }
      }
      else
      {
        *(_DWORD *)this = 0;
      }
    }
    else
    {
      *(_DWORD *)this = 1;
    }
  }
  if ( *(_DWORD *)this > 2u )
  {
    v4 = this + 28;
    v5 = 6;
    do
    {
      *(v4 - 6) = -1082130432;
      *v4++ = -1082130432;
      --v5;
    }
    while ( v5 );
  }
  else
  {
    *((_DWORD *)this + 1) = 1040187392;
    *((_DWORD *)this + 2) = 1048576000;
    *((_DWORD *)this + 3) = 1052770304;
    *((_DWORD *)this + 4) = 1059061760;
    *((_DWORD *)this + 5) = 1061158912;
    *((_DWORD *)this + 6) = 1063256064;
  }
  v6 = off_5EA8B8;
  v7 = (float *)(this + 4);
  do
  {
    if ( *(_DWORD *)this <= 2u && (int)v6 < (int)&dword_5EA8D0 && !sub_4E8E50(String, 64, *v6, 0) )
      *v7 = atof(String);
    ++v6;
    ++v7;
  }
  while ( (int)v6 < (int)&dword_5EA8D0 );
  result = *(_DWORD *)this;
  if ( *(int *)this >= 0 && result <= 2 )
  {
    if ( flt_6290D0[0] > 0.0 )
    {
      v9 = 0;
      v10 = (float *)(this + 4);
      while ( *v10 >= 0.0 )
      {
        ++v9;
        v11 = flt_6290D0[0] * *v10++;
        *(v10 - 1) = v11;
        if ( v9 >= 6 )
        {
          v12 = *((_DWORD *)this + 3);
          v13 = *((_DWORD *)this + 4);
          *((_DWORD *)this + 7) = *((_DWORD *)this + 2);
          v14 = *((_DWORD *)this + 5);
          *((_DWORD *)this + 8) = v12;
          result = *((_DWORD *)this + 6);
          *((_DWORD *)this + 9) = v13;
          v15 = *((_DWORD *)this + 1);
          *((_DWORD *)this + 10) = v14;
          *((_DWORD *)this + 11) = result;
          *((_DWORD *)this + 12) = v15;
          goto LABEL_34;
        }
      }
    }
    result = (int)(this + 28);
    v18 = 6;
    do
    {
      *(_DWORD *)(result - 24) = -1082130432;
      *(_DWORD *)result = -1082130432;
      result += 4;
      --v18;
    }
    while ( v18 );
  }
LABEL_34:
  v16 = 1;
  if ( dword_7D7928 == 2 && dword_6290F4 >= 3 )
    v16 = dword_628FA4 - 1;
  v17 = 0;
  *((_DWORD *)this + 19) = 0;
  if ( dword_6290C4 > 0 )
  {
    while ( 1 )
    {
      result = sub_403CE0(&flt_628F60, v17);
      if ( result )
      {
        if ( *(_DWORD *)(result + 328) == v16 )
          break;
      }
      result = dword_6290C4;
      if ( ++v17 >= dword_6290C4 )
        return result;
    }
    *((float *)this + 19) = *(float *)(result + 116);
  }
  return result;
}
