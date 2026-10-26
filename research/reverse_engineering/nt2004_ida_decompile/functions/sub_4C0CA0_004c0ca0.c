int __thiscall sub_4C0CA0(int this)
{
  const char *v2; // edi
  int v3; // ebp
  const char *v4; // ebx
  const char *v5; // edi
  const char **v6; // eax
  const char *v7; // edi
  int i; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int result; // eax
  int v15; // ecx
  double v16; // [esp+18h] [ebp-28h]
  double v17; // [esp+18h] [ebp-28h]
  double v18; // [esp+18h] [ebp-28h]
  double v19; // [esp+18h] [ebp-28h]
  double v20; // [esp+18h] [ebp-28h]
  double v21; // [esp+38h] [ebp-8h]
  double v22; // [esp+38h] [ebp-8h]
  double v23; // [esp+38h] [ebp-8h]
  double v24; // [esp+38h] [ebp-8h]
  double v25; // [esp+38h] [ebp-8h]
  double v26; // [esp+38h] [ebp-8h]

  switch ( *(_DWORD *)(this + 96) )
  {
    case 0:
      if ( sub_41F230(dword_62A170, aNone_0, Destination) )
      {
        strncpy(Destination, aNone_0, 0x1FFu);
        byte_62A37B = 0;
      }
      goto LABEL_19;
    case 1:
      if ( !sub_41F230(dword_62A170, aSplash, Destination) )
        goto LABEL_19;
      strncpy(Destination, aSplash, 0x1FFu);
      goto LABEL_18;
    case 2:
      if ( !sub_41F230(dword_62A170, a05Cans, Destination) )
        goto LABEL_19;
      strncpy(Destination, a05Cans, 0x1FFu);
      byte_62A37B = 0;
      sprintf((char *const)(this + 106), Destination);
      goto LABEL_20;
    case 3:
      if ( !sub_41F230(dword_62A170, a1Can, Destination) )
        goto LABEL_19;
      strncpy(Destination, a1Can, 0x1FFu);
      byte_62A37B = 0;
      sprintf((char *const)(this + 106), Destination);
      goto LABEL_20;
    case 4:
      if ( !sub_41F230(dword_62A170, a15Cans, Destination) )
        goto LABEL_19;
      strncpy(Destination, a15Cans, 0x1FFu);
      goto LABEL_18;
    case 5:
      if ( sub_41F230(dword_62A170, a2Cans, Destination) )
      {
        strncpy(Destination, a2Cans, 0x1FFu);
        byte_62A37B = 0;
      }
      goto LABEL_19;
    default:
      if ( !sub_41F230(dword_62A170, aNone_0, Destination) )
        goto LABEL_19;
      strncpy(Destination, aNone_0, 0x1FFu);
LABEL_18:
      byte_62A37B = 0;
LABEL_19:
      sprintf((char *const)(this + 106), Destination);
LABEL_20:
      switch ( *(_DWORD *)(this + 160) )
      {
        case 0:
          if ( !sub_41F230(dword_62A170, aNoChange, Destination) )
            goto LABEL_32;
          strncpy(Destination, aNoChange, 0x1FFu);
          goto LABEL_31;
        case 1:
          if ( sub_41F230(dword_62A170, aChangeLeft, Destination) )
          {
            strncpy(Destination, aChangeLeft, 0x1FFu);
            byte_62A37B = 0;
          }
          goto LABEL_32;
        case 2:
          if ( sub_41F230(dword_62A170, aChangeRight, Destination) )
          {
            strncpy(Destination, aChangeRight, 0x1FFu);
            byte_62A37B = 0;
          }
          goto LABEL_32;
        case 3:
          if ( sub_41F230(dword_62A170, aChangeBoth, Destination) )
          {
            strncpy(Destination, aChangeBoth, 0x1FFu);
LABEL_31:
            byte_62A37B = 0;
          }
LABEL_32:
          sprintf((char *const)(this + 170), "%s", Destination);
          break;
        default:
          break;
      }
      if ( *(_DWORD *)(this + 220) == 1 )
      {
        if ( sub_41F230(dword_62A170, off_5FD8E4, Destination) )
        {
          strncpy(Destination, off_5FD8E4, 0x1FFu);
          byte_62A37B = 0;
        }
      }
      else
      {
        v2 = aRepair;
        if ( !*(_DWORD *)(this + 224) )
          v2 = aDoNotRepair;
        if ( sub_41F230(dword_62A170, v2, Destination) )
        {
          if ( v2 )
          {
            strncpy(Destination, v2, 0x1FFu);
            byte_62A37B = 0;
          }
          else
          {
            Destination[0] = 0;
          }
        }
      }
      sprintf((char *const)(this + 234), "%s", Destination);
      if ( *(_DWORD *)(this + 28) == 1 )
      {
        if ( sub_41F230(dword_62A170, off_5FD8E4, Destination) )
        {
          strncpy(Destination, off_5FD8E4, 0x1FFu);
          byte_62A37B = 0;
        }
        sprintf((char *const)(this + 42), "%s", Destination);
        goto LABEL_63;
      }
      if ( *(_DWORD *)(*(_DWORD *)this + 20904) == 3 )
      {
        strcpy((char *)(this + 42), aLongestLine);
        goto LABEL_63;
      }
      v3 = *(_DWORD *)(*(_DWORD *)this + 20908) - 1;
      if ( v3 < 0 )
      {
        v3 = 0;
LABEL_51:
        v4 = &byte_629120;
        goto LABEL_52;
      }
      if ( v3 <= 99 )
      {
        if ( v3 <= 1 )
          goto LABEL_51;
        v4 = aS_1;
      }
      else
      {
        v3 = 99;
        v4 = aS_1;
      }
LABEL_52:
      v5 = off_601E44;
      if ( !*(_DWORD *)(this + 32) )
        v5 = aNo_1;
      if ( sub_41F230(dword_62A170, v5, Destination) )
      {
        if ( v5 )
        {
          strncpy(Destination, v5, 0x1FFu);
          byte_62A37B = 0;
        }
        else
        {
          Destination[0] = 0;
        }
      }
      sprintf((char *const)(this + 42), "%s (%d Lap%s Left)", Destination, v3, v4);
LABEL_63:
      if ( *(_DWORD *)(this + 284) == 1
        || (v6 = (const char **)sub_4C0C70((_DWORD *)this, *(_DWORD *)(this + 288))) == 0 )
      {
        if ( sub_41F230(dword_62A170, off_5FD8E4, Destination) )
        {
          strncpy(Destination, off_5FD8E4, 0x1FFu);
          byte_62A37B = 0;
        }
      }
      else
      {
        v7 = *v6;
        if ( !*v6 )
          v7 = &byte_629120;
        if ( sub_41F230(dword_62A170, v7, Destination) )
        {
          if ( v7 )
          {
            strncpy(Destination, v7, 0x1FFu);
            byte_62A37B = 0;
          }
          else
          {
            Destination[0] = 0;
          }
        }
      }
      sprintf((char *const)(this + 298), "%s", Destination);
      for ( i = 0; i < 4; ++i )
      {
        if ( i )
        {
          if ( i == 1 )
          {
            v9 = this + 396;
          }
          else if ( i == 2 )
          {
            v9 = this + 460;
          }
          else
          {
            v9 = this + 524;
          }
        }
        else
        {
          v9 = this + 332;
        }
        v10 = *(_DWORD *)(v9 + 20);
        v11 = *(_DWORD *)(v9 + 24);
        v21 = (double)v10 * *(double *)(v9 + 8) + *(double *)v9;
        v16 = (double)v11 * *(double *)(v9 + 8) + *(double *)v9;
        if ( dword_7689F0 )
        {
          v22 = v21 * 0.1450377377387031;
          v17 = v16 * 0.1450377377387031;
          if ( v10 == v11 )
          {
            sprintf((char *const)(v9 + 30), "%.1f", v22);
          }
          else if ( v10 <= v11 )
          {
            if ( v10 < v11 )
              sprintf((char *const)(v9 + 30), "%.1f (-%.1f)", v22, v17 - v22);
          }
          else
          {
            sprintf((char *const)(v9 + 30), "%.1f (+%.1f)", v22, v22 - v17);
          }
        }
        else if ( v10 == v11 )
        {
          sprintf((char *const)(v9 + 30), "%d", (int)v21);
        }
        else if ( v10 <= v11 )
        {
          if ( v10 < v11 )
            sprintf((char *const)(v9 + 30), "%d (-%d)", (int)v21, (int)(v16 - v21));
        }
        else
        {
          sprintf((char *const)(v9 + 30), "%d (+%d)", (int)v21, (int)(v21 - v16));
        }
      }
      v23 = (double)*(int *)(this + 608) * *(double *)(this + 596) + *(double *)(this + 588);
      if ( sub_41F230(dword_62A170, aTurns, Destination) )
      {
        strncpy(Destination, aTurns, 0x1FFu);
        byte_62A37B = 0;
      }
      sprintf((char *const)(this + 618), "%.2f %s", v23, Destination);
      v12 = *(_DWORD *)(this + 672);
      v13 = *(_DWORD *)(this + 676);
      v24 = ((double)v12 * *(double *)(this + 660) + *(double *)(this + 652)) * 100.0;
      v18 = ((double)v13 * *(double *)(this + 660) + *(double *)(this + 652)) * 100.0;
      if ( dword_7689F0 )
      {
        v25 = v24 * 0.3937007874015748;
        v19 = v18 * 0.3937007874015748;
        if ( v12 == v13 )
        {
          sprintf((char *const)(this + 682), "%.2f", v25);
        }
        else if ( v12 <= v13 )
        {
          if ( v12 < v13 )
            sprintf((char *const)(this + 682), "%.2f (-%.2f)", v25, v19 - v25);
        }
        else
        {
          sprintf((char *const)(this + 682), "%.2f (+%.2f)", v25, v25 - v19);
        }
      }
      else if ( v12 == v13 )
      {
        sprintf((char *const)(this + 682), "%.1f", v24);
      }
      else if ( v12 <= v13 )
      {
        if ( v12 < v13 )
          sprintf((char *const)(this + 682), "%.1f (-%.1f)", v24, v18 - v24);
      }
      else
      {
        sprintf((char *const)(this + 682), "%.1f (+%.1f)", v24, v24 - v18);
      }
      if ( *(_DWORD *)(this + 732) == 1 )
      {
        if ( sub_41F230(dword_62A170, off_5FD8E4, Destination) )
        {
          strncpy(Destination, off_5FD8E4, 0x1FFu);
          byte_62A37B = 0;
        }
        return sprintf((char *const)(this + 746), "%s", Destination);
      }
      else
      {
        result = *(_DWORD *)(this + 736);
        v15 = *(_DWORD *)(this + 740);
        v26 = 100.0 - ((double)result * *(double *)(this + 724) + *(double *)(this + 716));
        v20 = 100.0 - ((double)v15 * *(double *)(this + 724) + *(double *)(this + 716));
        if ( result == v15 )
        {
          return sprintf((char *const)(this + 746), "%d%%", (int)v26);
        }
        else if ( result <= v15 )
        {
          if ( result < v15 )
            return sprintf((char *const)(this + 746), "%d%% (-%d%%)", (int)v26, (int)(v20 - v26));
        }
        else
        {
          return sprintf((char *const)(this + 746), "%d%% (+%d%%)", (int)v26, (int)(v26 - v20));
        }
      }
      return result;
  }
}
