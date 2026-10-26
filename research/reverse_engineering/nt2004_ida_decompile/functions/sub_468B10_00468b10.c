int __thiscall sub_468B10(CHAR **this)
{
  CHAR **v1; // ebp
  CHAR *v2; // esi
  CHAR *v3; // edi
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  _DWORD *v10; // eax
  int v11; // eax
  char v12; // cl
  int v13; // ebp
  int v14; // edi
  _DWORD *v15; // eax
  _DWORD *v16; // esi
  _DWORD *v17; // eax
  int v19; // [esp+10h] [ebp-640h]
  int v20; // [esp+10h] [ebp-640h]
  int v22; // [esp+18h] [ebp-638h] BYREF
  char v23[28]; // [esp+1Ch] [ebp-634h] BYREF
  char String[384]; // [esp+38h] [ebp-618h] BYREF
  int v25; // [esp+1B8h] [ebp-498h]
  char v26; // [esp+1BCh] [ebp-494h]
  int v27; // [esp+1C4h] [ebp-48Ch]
  int v28; // [esp+1C8h] [ebp-488h]
  int v29; // [esp+1CCh] [ebp-484h]
  char v30[384]; // [esp+1D0h] [ebp-480h] BYREF
  char Str[512]; // [esp+350h] [ebp-300h] BYREF
  int v32[64]; // [esp+550h] [ebp-100h] BYREF

  v1 = this;
  v2 = *this;
  while ( v2 )
  {
    v3 = v2;
    v2 = (CHAR *)*((_DWORD *)v2 + 1);
    sub_4145A0(v3);
    sub_5BE8AE(v3);
  }
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  sub_57A080(v23);
  v4 = sub_468AD0(v1);
  if ( (unsigned __int8)sub_57A2F0(v4, 1) )
  {
    Str[0] = 0;
    v19 = 0;
    while ( sub_57A490(Str, 512) )
    {
      v5 = strstr(Str, asc_5FB9D8);
      if ( v5 )
        *v5 = 0;
      v6 = strstr(Str, asc_5FD0C8);
      if ( v6 )
        *v6 = 0;
      v7 = strstr(Str, asc_5FD0CC);
      if ( v7 )
        *v7 = 0;
      if ( strlen(Str) )
      {
        if ( !strncmp(Str, aTracks, strlen(aTracks)) )
        {
          v19 = 1;
        }
        else if ( v19 )
        {
          v8 = operator new(8u);
          v9 = v8;
          if ( v8 )
          {
            *v8 = 0;
            v8[1] = -1;
            sub_578600(Str);
            v10 = operator new(0xCu);
            if ( v10 )
            {
              *v10 = v9;
              v10[1] = 0;
              *((_BYTE *)v10 + 8) = 1;
            }
            else
            {
              v10 = 0;
            }
            if ( *v1 )
            {
              *((_DWORD *)v1[1] + 1) = v10;
            }
            else
            {
              *v1 = (CHAR *)v10;
              v1[2] = (CHAR *)v10;
            }
            v1[1] = (CHAR *)v10;
            ++v1[3];
          }
        }
        else
        {
          v11 = 0;
          memset(v30, 0, sizeof(v30));
          v25 = 0;
          v29 = 0;
          v27 = 0;
          v28 = 0;
          v26 = 1;
          do
          {
            v12 = Str[v11];
            v30[v11++] = v12;
          }
          while ( v12 );
          sub_578110(aDsfm, (int)dword_7652C8, 0, 0, 0);
          if ( sub_578110(aConnectiontype, (int)&v22, 0, 0, 0) )
            dword_7652C4 = v22;
          sub_578110(aUploadspeed, (int)&dword_764ED8, 0, 0, 0);
          sub_578110(aMaxplayers_0, (int)dword_600760, 0, 0, 0);
          if ( sub_577E50(String, aRacename, (int)v32) )
            sub_578600(v32);
          if ( sub_577E50(String, aPassword_0, (int)v32) )
            sub_578600(v32);
          sub_578110(aFlagrules, (int)&wParam, 0, 0, 0);
          sub_578110(aFuelusage, (int)&dword_600764, 0, 0, 0);
          sub_578110(aTireusage, (int)&dword_600768, 0, 0, 0);
          sub_578110(aMechfailures, (int)&dword_60076C, 0, 0, 0);
          sub_578110(aWeather, (int)&dword_600770, 0, 0, 0);
          sub_577FA0(aAllowsteerhelp, (int)&byte_600774, 0, 0, 0);
          sub_577FA0(aAllowbrakehelp, (int)&byte_600775, 0, 0, 0);
          sub_577FA0(aAllowabs, (int)&byte_600776, 0, 0, 0);
          sub_577FA0(aAllowtraction, (int)&byte_600777, 0, 0, 0);
          sub_577FA0(aAllowstability, (int)&byte_600778, 0, 0, 0);
          sub_577FA0(aAllowinvulnera, (int)&byte_7652D0, 0, 0, 0);
          sub_577FA0(aAllowspinrecov, (int)&byte_600779, 0, 0, 0);
          sub_577FA0(aAllowautoshift, (int)&byte_60077A, 0, 0, 0);
          sub_577FA0(aAllowautoclutc, (int)&byte_60077B, 0, 0, 0);
          sub_577FA0(aAllowautopace, (int)&byte_60077C, 0, 0, 0);
          sub_577FA0(aAllowautopit, (int)&byte_60077D, 0, 0, 0);
          sub_577FA0(aAllowdupvehicl, (int)&byte_7652D1, 0, 0, 0);
          sub_578220(aRacelength, (int)&flt_600780, 0, 0, 0, 0, 0, 0, 0);
          sub_578110(aDamagemultipli, (int)&dword_600784, 0, 0, 0);
        }
      }
    }
    sub_57A360(v23);
  }
  if ( (int)v1[3] <= 0 && dword_7D6B50 > 0 )
  {
    v13 = 0;
    v20 = dword_7D6B50;
    do
    {
      v14 = dword_7D6B58 + v13;
      v15 = operator new(8u);
      v16 = v15;
      if ( v15 )
      {
        *v15 = 0;
        v15[1] = -1;
        sub_578600(v14 + 260);
        v17 = operator new(0xCu);
        if ( v17 )
        {
          *v17 = v16;
          v17[1] = 0;
          *((_BYTE *)v17 + 8) = 1;
        }
        else
        {
          v17 = 0;
        }
        if ( *this )
        {
          *((_DWORD *)this[1] + 1) = v17;
        }
        else
        {
          *this = (CHAR *)v17;
          this[2] = (CHAR *)v17;
        }
        this[1] = (CHAR *)v17;
        ++this[3];
      }
      v13 += 400;
      --v20;
    }
    while ( v20 );
    v1 = this;
  }
  v1[2] = *v1;
  return sub_57A0A0(v23);
}
