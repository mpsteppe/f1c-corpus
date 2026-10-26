int __thiscall sub_48FD30(_DWORD *this)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  double v5; // st7
  double v6; // st7
  char *v7; // esi
  const char *v8; // edi
  char v9; // al
  char *v10; // eax
  char *v11; // eax
  int v12; // esi
  char v13; // bl
  int v14; // edx
  int v15; // eax
  char *v16; // esi
  int v17; // ecx
  int v18; // eax
  int v19; // eax
  double v20; // st7
  int v21; // eax
  double v22; // st7
  const char *v23; // edi
  unsigned int v24; // ebp
  long double v25; // st7
  const char *v26; // eax
  int v27; // esi
  int v28; // esi
  int v29; // esi
  const char *v30; // eax
  unsigned int v31; // kr00_4
  __int32 v32; // esi
  const char *v33; // [esp-8h] [ebp-94h]
  const char *v34; // [esp+8h] [ebp-84h] BYREF
  double v35; // [esp+Ch] [ebp-80h]
  int v36; // [esp+14h] [ebp-78h]
  float v37; // [esp+28h] [ebp-64h]
  _DWORD *v38; // [esp+2Ch] [ebp-60h]
  float v39; // [esp+30h] [ebp-5Ch]
  float v40; // [esp+34h] [ebp-58h]
  float v41; // [esp+38h] [ebp-54h]
  char Buffer[80]; // [esp+3Ch] [ebp-50h] BYREF

  v1 = this[70] - 549;
  v38 = this;
  switch ( v1 )
  {
    case 0:
      v2 = sub_5210D0(&dword_BE120C);
      v3 = sub_4CFC00(v2);
      sub_4CE020(v3);
      return 0;
    case 1:
      v41 = sub_5210A0(&dword_BE120C);
      v5 = sub_521070(&dword_BE120C);
      sprintf(Buffer, "%1.3f", v41 - v5);
      sub_4CE020(Buffer);
      return 0;
    case 2:
      v6 = sub_521060(&dword_BE120C);
      sprintf(Buffer, "%1.3f", v6);
      sub_4CE020(Buffer);
      return 0;
    case 3:
      v7 = dword_91E07C;
      if ( dword_91E07C )
      {
        v8 = &dword_91E07C[108 * *((_DWORD *)dword_91E07C + 5447) + 21568];
        if ( (unsigned __int8)sub_523BA0(&unk_BE1210, v36) )
        {
          v9 = v7[14816];
          HIDWORD(v35) = v8;
          if ( v9 )
          {
            LODWORD(v35) = sub_41D840(&byte_91CC38, (const char *)&off_6FB0C4);
            v34 = v7;
            v31 = __readeflags();
            v32 = dword_16C6EBC + 1821700133;
            __writeeflags(v31);
            _InterlockedExchange((volatile __int32 *)&v34, v32);
            sprintf(Buffer, v34);
            sub_4CE020(Buffer);
          }
          else
          {
            v10 = sub_41D840(&byte_91CC38, (const char *)&off_6FB0B8);
            sprintf(Buffer, "%s  %s", v10, (const char *)HIDWORD(v35));
            sub_4CE020(Buffer);
          }
          return 0;
        }
        else if ( (unsigned __int8)sub_5242D0(&unk_91E040) )
        {
          if ( !v7[14816] )
            goto LABEL_59;
          v11 = sub_41D840(&byte_91CC38, "Instructor");
          sub_4CE020(v11);
          return 0;
        }
        else
        {
          v12 = *((_DWORD *)v7 + 4831);
          if ( v12 <= 0 )
            return 0;
          sprintf(Buffer, "P %d  %s", v12, v8);
          sub_4CE020(Buffer);
          return 0;
        }
      }
      else
      {
        sub_4CE020("---");
        return 0;
      }
    case 93:
      v13 = 1;
      if ( dword_757C10 < 1 )
        goto LABEL_60;
      v14 = 0;
      v15 = 0;
      if ( dword_757C10 <= 0 )
        goto LABEL_23;
      break;
    default:
      return 0;
  }
  while ( *(_DWORD *)(*(&dword_91E088 + v15) + 19324) != 1 )
  {
    if ( ++v15 >= dword_757C10 )
      goto LABEL_23;
  }
  v14 = *(&dword_91E088 + v15);
LABEL_23:
  v16 = dword_91E07C;
  v8 = &dword_91E07C[108 * *((_DWORD *)dword_91E07C + 5447) + 21568];
  if ( dword_91E07C[15572] || *((_DWORD *)dword_91E07C + 3894) == 1 && *((_DWORD *)dword_91E07C + 4822) )
  {
LABEL_60:
    sub_4CE020(WindowName);
    return 0;
  }
  v17 = *((_DWORD *)dword_91E07C + 4831);
  v39 = 0.0;
  if ( v14 )
  {
    v18 = *((_DWORD *)dword_91E07C + 4822);
    v19 = v18 == 2 ? 0 : v18 + 1;
    v20 = *(float *)(v14 + 4 * v19 + 19448);
    v39 = *(float *)(v14 + 4 * v19 + 19448);
    if ( v20 < 0.0 )
      v39 = 0.0;
  }
  if ( v17 <= 0 )
  {
LABEL_59:
    sub_4CE020(v8);
    return 0;
  }
  else
  {
    v21 = *((_DWORD *)dword_91E07C + 4822);
    v22 = dbl_FB1D18 - *((float *)dword_91E07C + 4858);
    v41 = 0.0;
    v40 = v22;
    v37 = *(float *)&dword_91E07C[4 * v21 + 19304];
    if ( v14 )
      v41 = *(float *)(v14 + 4 * v21 + 19448);
    if ( !v21 )
      v37 = sub_52B860(*((_DWORD *)dword_91E07C + 4821) - 1);
    if ( (v37 + 4.0 <= v40 || v40 <= (double)v37) && v40 >= 4.0 )
    {
      if ( *((_DWORD *)v16 + 4857) != 2 || *((_DWORD *)v16 + 3894) == 1 )
      {
        sprintf(Buffer, WindowName);
        sub_4CE020(Buffer);
        return 0;
      }
      else
      {
        v28 = *((_DWORD *)v16 + 4822);
        v41 = fmod(v39, 60.0);
        if ( v28 == 2 )
          v29 = 0;
        else
          v29 = v28 + 1;
        v30 = (const char *)sub_4CFC00(v29);
        sprintf(
          Buffer,
          "%s   %02.2d:%06.3f    %02.2d:%06.3f",
          v30,
          (unsigned int)(unsigned __int64)(v39 * 0.016666668),
          v41,
          (unsigned int)(unsigned __int64)(v40 * 0.016666668),
          (double)fmod(v40, 60.0));
        sub_4CE020(Buffer);
        return 0;
      }
    }
    else
    {
      if ( v39 <= 0.0 )
        v39 = v37;
      else
        v39 = v37 - v41;
      if ( v39 < 0.0 )
        v13 = 0;
      v23 = (const char *)abs32((unsigned __int64)(v39 * 0.016666668));
      v40 = fabs(fmod(v39, 60.0));
      v24 = abs32((unsigned __int64)(v41 * 0.016666668));
      v25 = fabs(fmod(v41, 60.0));
      if ( v39 != 0.0 || *((_DWORD *)v16 + 4822) )
      {
        v27 = *((_DWORD *)v16 + 4822);
        v35 = v40;
        v34 = v23;
        v33 = (const char *)sub_4CFC00(v27);
        if ( v13 )
          sprintf(Buffer, "%s   %02.2d:%06.3f   +%02.2d:%06.3f", v33, v24, (double)v25, v34, v35);
        else
          sprintf(Buffer, "%s   %02.2d:%06.3f   -%02.2d:%06.3f", v33, v24, (double)v25, v34, v35);
        sub_4CE020(Buffer);
        return 0;
      }
      else
      {
        v26 = (const char *)sub_4CFC00(3);
        sprintf(
          Buffer,
          "%s  %02.2d:%06.3f",
          v26,
          abs32((unsigned __int64)(v37 * 0.016666668)),
          (double)fabs(fmod(v37, 60.0)));
        sub_4CE020(Buffer);
        return 0;
      }
    }
  }
}
