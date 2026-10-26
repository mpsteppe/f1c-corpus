char __thiscall sub_4AE1E0(_DWORD *this, int a2, char *a3, _BYTE *a4)
{
  _BYTE *v4; // ebp
  _DWORD *v5; // edi
  int v6; // ebx
  int v7; // esi
  int v8; // eax
  double v9; // st7
  int v10; // ebx
  int v11; // edi
  int v12; // edi
  int v13; // ebp
  int v14; // ebx
  double v15; // st7
  char *v16; // eax
  int v17; // edx
  char v18; // cl
  const CHAR *v19; // eax
  int v20; // edx
  CHAR v21; // cl
  char *v22; // eax
  int v23; // edx
  char v24; // cl
  char *v25; // eax
  int v26; // edx
  char v27; // cl
  char v28; // cl
  int v29; // ebx
  char *v30; // ebp
  int v31; // eax
  float v33; // [esp+1Ch] [ebp-2B4h]
  float v34; // [esp+1Ch] [ebp-2B4h]
  float v35; // [esp+1Ch] [ebp-2B4h]
  int v37; // [esp+24h] [ebp-2ACh]
  char v38[8]; // [esp+28h] [ebp-2A8h] BYREF
  char Buffer[48]; // [esp+30h] [ebp-2A0h] BYREF
  char v40[48]; // [esp+60h] [ebp-270h] BYREF
  char v41[48]; // [esp+90h] [ebp-240h] BYREF
  char v42[48]; // [esp+C0h] [ebp-210h] BYREF
  char v43[48]; // [esp+F0h] [ebp-1E0h] BYREF
  char v44[48]; // [esp+120h] [ebp-1B0h] BYREF
  char v45[48]; // [esp+150h] [ebp-180h] BYREF
  char v46[48]; // [esp+180h] [ebp-150h] BYREF
  char v47[48]; // [esp+1B0h] [ebp-120h] BYREF
  char v48[48]; // [esp+1E0h] [ebp-F0h] BYREF
  char v49[48]; // [esp+210h] [ebp-C0h] BYREF
  char v50[48]; // [esp+240h] [ebp-90h] BYREF
  char v51[48]; // [esp+270h] [ebp-60h] BYREF
  char v52[48]; // [esp+2A0h] [ebp-30h] BYREF

  v4 = a4;
  v5 = this;
  if ( a4 )
    *a4 = 0;
  v6 = a2;
  v7 = *(&dword_91E088 + a2);
  if ( (unsigned __int8)sub_523BA0(&unk_BE1210) )
  {
    if ( *(_BYTE *)(v7 + 14816) )
      strcpy(Buffer, sub_41D840(&byte_91CC38, (const char *)&off_6FB0C4));
    else
      strcpy(Buffer, sub_41D840(&byte_91CC38, (const char *)&off_6FB0B8));
  }
  else if ( dword_B6E084 )
  {
    sprintf(Buffer, "%d", *(_DWORD *)(v7 + 19328));
  }
  else
  {
    sprintf(Buffer, "%d", *(_DWORD *)(v7 + 19324));
  }
  if ( *(_DWORD *)dword_B72314 == 5 )
  {
    v8 = 108 * *(_DWORD *)(v7 + 21788);
    if ( *(_DWORD *)(v7 + 21784) == 2 )
      sprintf(v40, off_6FF8A4, v8 + v7 + 21568, 47);
    else
      sprintf(v40, "%s", (const char *)(v8 + v7 + 21568));
  }
  else
  {
    sub_630FE0(v40, 108 * *(_DWORD *)(v7 + 21788) + v7 + 21568, 47);
    v40[47] = 0;
  }
  if ( dword_B6E088 )
    sub_630FE0(v49, v7 + 21808, 47);
  else
    sub_630FE0(v49, v7 + 21872, 47);
  v49[47] = 0;
  sub_630FE0(v41, v7 + 22064, 47);
  v41[47] = 0;
  v9 = *(float *)(v7 + 16084);
  if ( dword_B72454 )
    sprintf(v42, "%.0flbs", v9 * 2.2);
  else
    sprintf(v42, "%.0fkg", v9);
  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    v10 = dword_FADE18;
    v11 = *(_DWORD *)(v7 + 19284);
    if ( dword_FADE18 == 0x7FFFFFFF )
      sprintf(v38, "--");
    else
      sprintf(v38, "%d", dword_FADE18);
    if ( v11 >= 0 )
    {
      if ( v11 > v10 && !dword_B6FA78 )
        v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    sprintf(v50, "%d", v11);
    v5 = this;
    v6 = a2;
  }
  else
  {
    sprintf(v50, "%d", *(int *)(v7 + 19284) < 0 ? 0 : *(_DWORD *)(v7 + 19284));
  }
  sub_42CD50(v6, v43, 1);
  sub_42CD50(v6, v44, 2);
  *(_DWORD *)v38 = sub_42CD50(v6, v51, 0);
  if ( byte_B722E4 )
  {
    if ( dword_B6E084 )
    {
      v12 = *(_DWORD *)(v7 + 19356);
      v13 = *(_DWORD *)(v7 + 19360);
      v14 = *(_DWORD *)(v7 + 19364);
      v37 = *(_DWORD *)(v7 + 19368);
    }
    else
    {
      v12 = *(_DWORD *)(v7 + 19336);
      v13 = *(_DWORD *)(v7 + 19340);
      v14 = *(_DWORD *)(v7 + 19344);
      v37 = *(_DWORD *)(v7 + 19348);
    }
    strcpy(v45, "-");
    strcpy(v46, "-");
    strcpy(v47, "-");
    if ( v12 >= 0 )
      sprintf(v45, "%d", v12);
    if ( v13 >= 0 )
      sprintf(v46, "%d", v13);
    if ( v14 >= 0 )
      sprintf(v47, "%d", v14);
    v33 = sub_530630(v12, 1);
    v34 = sub_530630(v13, 2) + v33;
    v35 = sub_530630(v14, 3) + v34;
    v15 = sub_530630(v37, 4);
    sprintf(v48, "%.1f", v15 + v35);
    v4 = a4;
    v5 = this;
    v6 = a2;
  }
  if ( *(_BYTE *)(v7 + 14816) )
  {
    v16 = (char *)sub_4CF8E0(v5);
    if ( v16 )
    {
      v17 = v4 - v16;
      do
      {
        v18 = *v16;
        v16[v17] = *v16;
        ++v16;
      }
      while ( v18 );
      goto LABEL_65;
    }
  }
  else if ( *(_DWORD *)v38 == 1 )
  {
    v25 = (char *)sub_4CF900(v5);
    if ( v25 )
    {
      v26 = v4 - v25;
      do
      {
        v27 = *v25;
        v25[v26] = *v25;
        ++v25;
      }
      while ( v27 );
      goto LABEL_65;
    }
  }
  else
  {
    if ( *(_DWORD *)v38 != 2 )
    {
      if ( *(_DWORD *)v38 == 3 )
      {
        v19 = *(const CHAR **)(v5[61] + 88);
        if ( !v19 )
          v19 = WindowName;
        v20 = v4 - v19;
        do
        {
          v21 = *v19;
          v19[v20] = *v19;
          ++v19;
        }
        while ( v21 );
      }
      goto LABEL_65;
    }
    v22 = (char *)sub_4CF8C0(v5);
    if ( v22 )
    {
      v23 = v4 - v22;
      do
      {
        v24 = *v22;
        v22[v23] = *v22;
        ++v22;
      }
      while ( v24 );
      goto LABEL_65;
    }
  }
  *v4 = 0;
LABEL_65:
  sub_49A060(v5, v6, v52, 47);
  *a3 = 0;
  v28 = 1;
  v29 = 0;
  v30 = Buffer;
  do
  {
    v31 = v5[153];
    if ( v31 == 1 )
    {
      if ( v29 < 0 || v29 > 2 && v29 != 12 )
        goto LABEL_73;
LABEL_70:
      if ( !v28 )
        *(_WORD *)&a3[strlen(a3)] = 9;
      strcat(a3, v30);
      v28 = 0;
      v5 = this;
      goto LABEL_73;
    }
    if ( v31 )
    {
      if ( v31 == 3 )
      {
        if ( *(_DWORD *)dword_B72314 == 7 )
        {
          switch ( v29 )
          {
            case 0:
            case 1:
            case 2:
            case 4:
            case 5:
            case 11:
            case 12:
            case 13:
              goto LABEL_70;
            default:
              break;
          }
        }
        else
        {
          switch ( v29 )
          {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 12:
            case 13:
              goto LABEL_70;
            default:
              break;
          }
        }
      }
      else
      {
        if ( v31 != 2 )
          goto LABEL_70;
        switch ( v29 )
        {
          case 0:
          case 1:
          case 2:
          case 6:
          case 7:
          case 9:
          case 12:
          case 13:
            goto LABEL_70;
          default:
            break;
        }
      }
    }
    else
    {
      switch ( v29 )
      {
        case 0:
        case 1:
        case 2:
        case 10:
        case 11:
        case 12:
        case 13:
          goto LABEL_70;
        default:
          break;
      }
    }
LABEL_73:
    ++v29;
    v30 += 48;
  }
  while ( v29 < 14 );
  return 1;
}
