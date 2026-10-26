int __thiscall sub_469050(int this)
{
  char *v2; // eax
  CHAR *v3; // eax
  CHAR *v4; // eax
  CHAR *v5; // eax
  bool v6; // zf
  CHAR **i; // eax
  CHAR *v8; // eax
  int v9; // eax
  CHAR ***v10; // eax
  char v12; // [esp-14h] [ebp-3Ch]
  char v13; // [esp+0h] [ebp-28h]
  double v14; // [esp+0h] [ebp-28h]
  char v15; // [esp+8h] [ebp-20h]
  char ArgList[4]; // [esp+Ch] [ebp-1Ch] BYREF

  sub_57A080(ArgList);
  v2 = sub_468AD0((CHAR **)this);
  if ( (unsigned __int8)sub_57A110(v2, 0, 1, 1) )
  {
    sub_57A400((int)ArgList, aDedicatedServe, v15);
    sub_57A400((int)ArgList, aSettings, v13);
    sub_57A400((int)ArgList, aDsfmD, dword_7652C8[0]);
    sub_57A400((int)ArgList, aConnectiontype_0, dword_7652C4);
    sub_57A400((int)ArgList, aUploadspeedD, dword_764ED8);
    sub_57A400((int)ArgList, aMaxplayersD, dword_600760[0]);
    LOBYTE(v3) = lParam;
    if ( !lParam )
      v3 = &byte_629120;
    sub_57A400((int)ArgList, aRacenameS, (char)v3);
    LOBYTE(v4) = dword_764ED0;
    if ( !dword_764ED0 )
      v4 = &byte_629120;
    sub_57A400((int)ArgList, aPasswordS, (char)v4);
    sub_57A400((int)ArgList, aFlagrulesD, wParam);
    sub_57A400((int)ArgList, aFuelusageD, dword_600764);
    sub_57A400((int)ArgList, aTireusageD, dword_600768);
    sub_57A400((int)ArgList, aMechfailuresD, dword_60076C);
    sub_57A400((int)ArgList, aWeatherD, dword_600770);
    sub_57A400((int)ArgList, aAllowsteerhelp_0, byte_600774);
    sub_57A400((int)ArgList, aAllowbrakehelp_0, byte_600775);
    sub_57A400((int)ArgList, aAllowabsD, byte_600776);
    sub_57A400((int)ArgList, aAllowtractionD, byte_600777);
    sub_57A400((int)ArgList, aAllowstability_0, byte_600778);
    sub_57A400((int)ArgList, aAllowinvulnera_0, byte_7652D0);
    sub_57A400((int)ArgList, aAllowspinrecov_0, byte_600779);
    sub_57A400((int)ArgList, aAllowautoshift_0, byte_60077A);
    sub_57A400((int)ArgList, aAllowautoclutc_0, byte_60077B);
    sub_57A400((int)ArgList, aAllowautopaceD, byte_60077C);
    sub_57A400((int)ArgList, aAllowautopitD, byte_60077D);
    sub_57A400((int)ArgList, aAllowdupvehicl_0, byte_7652D1);
    v14 = flt_600780;
    sub_57A400((int)ArgList, aRacelength4f, SLOBYTE(v14));
    sub_57A400((int)ArgList, aDamagemultipli_0, dword_600784);
    sub_57A400((int)ArgList, aTracks_0, v12);
    v5 = *(CHAR **)this;
    v6 = *(_DWORD *)this == 0;
    *(_DWORD *)(this + 8) = *(_DWORD *)this;
    if ( !v6 )
    {
      for ( i = *(CHAR ***)v5; i; i = *v10 )
      {
        v8 = *i;
        if ( !v8 )
          v8 = &byte_629120;
        sub_57A400((int)ArgList, aS_5, (char)v8);
        v9 = *(_DWORD *)(this + 8);
        if ( !v9 )
          break;
        v10 = *(CHAR ****)(v9 + 4);
        *(_DWORD *)(this + 8) = v10;
        if ( !v10 )
          break;
      }
    }
    sub_57A360(ArgList);
  }
  return sub_57A0A0(ArgList);
}
