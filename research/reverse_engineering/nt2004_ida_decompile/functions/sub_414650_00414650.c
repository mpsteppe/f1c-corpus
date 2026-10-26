char __thiscall sub_414650(int this, int a2)
{
  int v3; // eax
  const char *v4; // edi
  int v5; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // edi
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  int v12; // eax
  int v13; // eax
  const char *v14; // eax
  int v15; // eax
  char *v16; // eax
  int v17; // eax
  const char *v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  const char *v22; // eax
  int v23; // eax
  int v24; // edi
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  int v30; // eax

  sub_414620(this);
  *(_DWORD *)(this + 40) = -1;
  *(_DWORD *)(this + 4) = a2;
  if ( !a2 )
    goto LABEL_73;
  v3 = sub_57A720(aType_0);
  if ( !v3 )
    goto LABEL_73;
  v4 = (const char *)sub_57A6D0(v3);
  if ( _strcmpi(v4, aCameraSelect) )
  {
    if ( _strcmpi(v4, aCameraTargetSe) )
    {
      if ( _strcmpi(v4, aCameraAcquireC) )
      {
        if ( _strcmpi(v4, aCameraReleaseC) )
        {
          if ( _strcmpi(v4, aCameraSetLast) )
          {
            if ( _strcmpi(v4, aCommentaryStar) )
            {
              if ( _strcmpi(v4, aCommentaryStop) )
              {
                if ( _strcmpi(v4, aFlyOver) )
                {
                  if ( _strcmpi(v4, aGridwalk) )
                  {
                    if ( _strcmpi(v4, aWait) )
                    {
                      if ( _strcmpi(v4, aScriptEnd) )
                        *(_DWORD *)(this + 36) = 0;
                      else
                        *(_DWORD *)(this + 36) = 12;
                    }
                    else
                    {
                      *(_DWORD *)(this + 36) = 11;
                    }
                  }
                  else
                  {
                    *(_DWORD *)(this + 36) = 10;
                  }
                }
                else
                {
                  *(_DWORD *)(this + 36) = 9;
                }
              }
              else
              {
                *(_DWORD *)(this + 36) = 8;
              }
            }
            else
            {
              *(_DWORD *)(this + 36) = 7;
            }
          }
          else
          {
            *(_DWORD *)(this + 36) = 6;
          }
        }
        else
        {
          *(_DWORD *)(this + 36) = 3;
        }
      }
      else
      {
        *(_DWORD *)(this + 36) = 2;
      }
    }
    else
    {
      *(_DWORD *)(this + 36) = 5;
    }
  }
  else
  {
    *(_DWORD *)(this + 36) = 4;
  }
  if ( *(_DWORD *)(this + 36) )
  {
    v5 = sub_57A720(aProbability);
    if ( v5 )
    {
      v6 = (const char *)sub_57A6D0(v5);
      *(float *)(this + 12) = atof(v6);
    }
    else
    {
      *(_DWORD *)(this + 12) = 1065353216;
    }
    v7 = sub_57A720(aTime);
    v8 = v7;
    if ( v7 )
    {
      v9 = (const char *)sub_57A6D0(v7);
      *(float *)(this + 16) = atof(v9);
      if ( *(_BYTE *)sub_57A6D0(v8) != 43 )
      {
        *(_DWORD *)(this + 20) = 1;
        goto LABEL_35;
      }
    }
    else
    {
      *(_DWORD *)(this + 16) = 0;
    }
    *(_DWORD *)(this + 20) = 2;
LABEL_35:
    v10 = sub_57A720(aIterations);
    if ( !v10 || (v11 = (const char *)sub_57A6D0(v10), v12 = atol(v11), *(_DWORD *)(this + 24) = v12, v12 < 1) )
      *(_DWORD *)(this + 24) = 1;
    v13 = sub_57A720(aWait_0);
    *(_BYTE *)(this + 32) = !v13 || (v14 = (const char *)sub_57A6D0(v13), _strcmpi(v14, aNo_0));
  }
  switch ( *(_DWORD *)(this + 36) )
  {
    case 1:
      goto LABEL_72;
    case 2:
    case 3:
    case 8:
    case 9:
    case 0xA:
    case 0xB:
    case 0xC:
      goto LABEL_54;
    case 4:
    case 6:
      *(_DWORD *)(this + 44) = 0;
      v15 = sub_57A720(aCamera);
      if ( v15 )
      {
        v16 = (char *)sub_57A6D0(v15);
        *(_DWORD *)(this + 44) = sub_414C70(v16);
      }
      *(_DWORD *)(this + 40) = 2 * (*(_DWORD *)(this + 44) == 0) + 2;
      break;
    case 5:
      *(_DWORD *)(this + 40) = 4;
      *(_DWORD *)(this + 44) = -1;
      v17 = sub_57A720(aPosition_0);
      if ( v17 )
      {
        v18 = (const char *)sub_57A6D0(v17);
        v19 = atoi(v18);
        if ( v19 >= 1 && v19 <= (int)NumOfElements )
        {
          v20 = 0;
          if ( (int)NumOfElements > 0 )
          {
            while ( v19 != *(_DWORD *)(dword_75AAD0[v20] + 20884) )
            {
              if ( ++v20 >= (int)NumOfElements )
                goto LABEL_73;
            }
            *(_DWORD *)(this + 44) = *(_DWORD *)(dword_75AAD0[v20] + 25248);
LABEL_54:
            *(_DWORD *)(this + 40) = 2;
          }
        }
      }
      else
      {
        v21 = sub_57A720(aDriver);
        if ( v21 )
        {
          v22 = (const char *)sub_57A6D0(v21);
          if ( !_strcmpi(v22, aPlayer_1) )
          {
            *(_DWORD *)(this + 44) = *(_DWORD *)(dword_75AACC + 25248);
            *(_DWORD *)(this + 40) = 2;
          }
        }
      }
      break;
    case 7:
      *(_DWORD *)(this + 40) = 4;
      *(_DWORD *)(this + 44) = -1;
      v23 = sub_57A720(aCommentary);
      v24 = v23;
      if ( v23 )
      {
        v25 = (const char *)sub_57A6D0(v23);
        if ( _strcmpi(v25, aGreeting) )
        {
          v26 = (const char *)sub_57A6D0(v24);
          if ( _strcmpi(v26, aWelcomeToCount) )
          {
            v27 = (const char *)sub_57A6D0(v24);
            if ( _strcmpi(v27, aTrackInfo) )
            {
              v28 = (const char *)sub_57A6D0(v24);
              if ( _strcmpi(v28, aWeather_0) )
              {
                v29 = (const char *)sub_57A6D0(v24);
                if ( !_strcmpi(v29, aCrowd) )
                  *(_DWORD *)(this + 44) = 4;
              }
              else
              {
                *(_DWORD *)(this + 44) = 3;
              }
            }
            else
            {
              *(_DWORD *)(this + 44) = 2;
            }
          }
          else
          {
            *(_DWORD *)(this + 44) = 1;
          }
        }
        else
        {
          *(_DWORD *)(this + 44) = 0;
        }
      }
      if ( *(int *)(this + 44) >= 0 )
        *(_DWORD *)(this + 40) = 2;
      break;
    default:
      *(_DWORD *)(this + 36) = 0;
LABEL_72:
      *(_DWORD *)(this + 40) = 4;
      break;
  }
LABEL_73:
  v30 = *(_DWORD *)(this + 40);
  if ( v30 == 4 )
    *(_DWORD *)(this + 24) = 0;
  if ( v30 != -1 )
    return 1;
  sub_414620(this);
  *(_DWORD *)(this + 40) = -1;
  return 0;
}
