char __thiscall sub_40D4C0(int this, int a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // edi
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax

  StructFieldInit(this);
  *(_DWORD *)(this + 40) = -1;
  *(_DWORD *)(this + 4) = a2;
  if ( !a2 )
    goto LABEL_73;
  v3 = StringKeyedLinkedListSearch(aType_0);
  if ( !v3 )
    goto LABEL_73;
  v4 = DataEntryAccessor(v3);
  if ( sub_588410(v4, aCameraSelect) )
  {
    if ( sub_588410(v4, aCameraTargetSe) )
    {
      if ( sub_588410(v4, aCameraAcquireC) )
      {
        if ( sub_588410(v4, aCameraReleaseC) )
        {
          if ( sub_588410(v4, aCameraSetLast) )
          {
            if ( sub_588410(v4, aCommentaryStar) )
            {
              if ( sub_588410(v4, aCommentaryStop) )
              {
                if ( sub_588410(v4, aFlyOver) )
                {
                  if ( sub_588410(v4, aGridwalk) )
                  {
                    if ( sub_588410(v4, aWait) )
                    {
                      if ( sub_588410(v4, aScriptEnd) )
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
    v5 = StringKeyedLinkedListSearch(aProbability);
    if ( v5 )
    {
      v6 = DataEntryAccessor(v5);
      *(float *)(this + 12) = sub_58850F(v6);
    }
    else
    {
      *(_DWORD *)(this + 12) = 1065353216;
    }
    v7 = StringKeyedLinkedListSearch(aTime);
    v8 = v7;
    if ( v7 )
    {
      v9 = DataEntryAccessor(v7);
      *(float *)(this + 16) = sub_58850F(v9);
      if ( *(_BYTE *)DataEntryAccessor(v8) != 43 )
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
    v10 = StringKeyedLinkedListSearch(aIterations);
    if ( !v10 || (v11 = DataEntryAccessor(v10), v12 = sub_587ECE(v11), *(_DWORD *)(this + 24) = v12, v12 < 1) )
      *(_DWORD *)(this + 24) = 1;
    v13 = StringKeyedLinkedListSearch(aWait_0);
    *(_BYTE *)(this + 32) = !v13 || (v14 = DataEntryAccessor(v13), sub_588410(v14, aNo));
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
      v15 = StringKeyedLinkedListSearch(aCamera);
      if ( v15 )
      {
        v16 = DataEntryAccessor(v15);
        *(_DWORD *)(this + 44) = CameraTargetNameResolver(v16);
      }
      *(_DWORD *)(this + 40) = 2 * (*(_DWORD *)(this + 44) == 0) + 2;
      break;
    case 5:
      *(_DWORD *)(this + 40) = 4;
      *(_DWORD *)(this + 44) = -1;
      v17 = StringKeyedLinkedListSearch(aPosition_0);
      if ( v17 )
      {
        v18 = DataEntryAccessor(v17);
        v19 = SingleFunctionCallWrapper_7f59(v18);
        if ( v19 >= 1 && v19 <= dword_5C329C )
        {
          v20 = 0;
          if ( dword_5C329C > 0 )
          {
            while ( v19 != *(_DWORD *)(dword_7C54F0[v20] + 16480) )
            {
              if ( ++v20 >= dword_5C329C )
                goto LABEL_73;
            }
            *(_DWORD *)(this + 44) = *(_DWORD *)(dword_7C54F0[v20] + 18580);
LABEL_54:
            *(_DWORD *)(this + 40) = 2;
          }
        }
      }
      else
      {
        v21 = StringKeyedLinkedListSearch(aDriver_0);
        if ( v21 )
        {
          v22 = DataEntryAccessor(v21);
          if ( !sub_588410(v22, aPlayer_0) )
          {
            *(_DWORD *)(this + 44) = *(_DWORD *)(dword_7C54E8 + 18580);
            *(_DWORD *)(this + 40) = 2;
          }
        }
      }
      break;
    case 7:
      *(_DWORD *)(this + 40) = 4;
      *(_DWORD *)(this + 44) = -1;
      v23 = StringKeyedLinkedListSearch(aCommentary);
      v24 = v23;
      if ( v23 )
      {
        v25 = DataEntryAccessor(v23);
        if ( sub_588410(v25, aGreeting) )
        {
          v26 = DataEntryAccessor(v24);
          if ( sub_588410(v26, aWelcomeToCount) )
          {
            v27 = DataEntryAccessor(v24);
            if ( sub_588410(v27, aTrackInfo) )
            {
              v28 = DataEntryAccessor(v24);
              if ( sub_588410(v28, aWeather_0) )
              {
                v29 = DataEntryAccessor(v24);
                if ( !sub_588410(v29, aCrowd) )
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
  StructFieldInit(this);
  *(_DWORD *)(this + 40) = -1;
  return 0;
}

