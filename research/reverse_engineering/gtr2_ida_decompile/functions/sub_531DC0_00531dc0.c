int __thiscall sub_531DC0(int this, int a2, char a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  bool v10; // cl
  int v11; // edi
  int v12; // ebx
  _DWORD *v13; // eax
  char *v14; // eax
  _DWORD *v15; // eax
  char *v16; // eax
  int v17; // ebp
  _DWORD *v18; // eax
  int v19; // edi
  int v20; // edx
  int v21; // ecx
  int v22; // ebp
  _DWORD *v23; // eax
  char *v24; // eax
  _DWORD *v25; // eax
  char *v26; // eax
  int v27; // edi
  double v28; // st7
  _DWORD *v29; // eax
  char *v30; // eax
  _DWORD *v31; // eax
  char *v32; // eax
  _DWORD *v33; // eax
  char *v34; // eax
  double v35; // st7
  double v36; // st6
  double v37; // rt0
  double v38; // st6
  int v39; // [esp+4h] [ebp-58h]
  int v40; // [esp+8h] [ebp-54h]
  int v41; // [esp+8h] [ebp-54h]
  int v42; // [esp+Ch] [ebp-50h]
  int v43; // [esp+10h] [ebp-4Ch]
  int v44; // [esp+14h] [ebp-48h]
  int v45; // [esp+18h] [ebp-44h]
  char Buffer[64]; // [esp+1Ch] [ebp-40h] BYREF

  if ( dword_B71F24 == 3 )
  {
    result = *(_DWORD *)(22616 * *(_DWORD *)(this + 820) + dword_B763DC + 19324) - 1;
    *(_DWORD *)(this + 816) = result;
  }
  else if ( dword_B71F24 == 4 )
  {
    result = *(_DWORD *)(22616 * *(_DWORD *)(this + 820) + dword_B763DC + 19324) - 1;
    *(_DWORD *)(this + 816) = result;
    if ( !result )
      ++*(_DWORD *)(this + 808);
  }
  else
  {
    result = dword_B71F24 - 6;
    if ( dword_B71F24 == 6 )
    {
      v42 = 0;
      v43 = 0;
      v45 = 0;
      v44 = 0;
      v39 = 0;
      if ( *(_DWORD *)(this + 836) == -1 )
      {
        result = a2;
        *(_DWORD *)(this + 4 * a2 + 216) = 0;
        *(_DWORD *)(this + 4 * a2 + 600) = 0;
        *(_DWORD *)(this + 4 * a2 + 24) = 999;
        *(_DWORD *)(this + 4 * a2 + 408) = 999;
      }
      else
      {
        v6 = 22616 * *(_DWORD *)(this + 820);
        v7 = *(_DWORD *)(dword_B763DC + v6 + 19328);
        *(_DWORD *)(this + 4 * a2 + 24) = *(_DWORD *)(v6 + dword_B763DC + 19324);
        *(_DWORD *)(this + 4 * a2 + 408) = v7;
        v8 = 22616 * *(_DWORD *)(this + 820);
        v9 = *(_DWORD *)(v8 + dword_B763DC + 19380);
        v10 = v9 == 3 || v9 == 2;
        *(_BYTE *)(this + 828) = v10;
        *(_DWORD *)(this + 832) = *(_DWORD *)(v8 + dword_B763DC + 19284);
        v11 = (unsigned __int64)((double)dword_FADE18 * 0.2);
        if ( byte_B722E4 )
          v11 = 1;
        sprintf(Buffer, "%s_%s", (const char *)(this + 848), "WEIGHTPENALTY");
        v12 = sub_616840(Buffer);
        if ( v12 )
        {
          v13 = (_DWORD *)sub_616630("MAXIMUM");
          if ( v13 )
          {
            v14 = sub_48D380(v13);
            v45 = atol(v14);
          }
          v15 = (_DWORD *)sub_616630("DEFAULT");
          if ( v15 )
          {
            v16 = sub_48D380(v15);
            v44 = atol(v16);
          }
        }
        v17 = dword_B763DC;
        v18 = (_DWORD *)(22616 * *(_DWORD *)(this + 820) + dword_B763DC);
        if ( v18[4821] >= v11 && !*(_BYTE *)(this + 828) )
        {
          if ( byte_B722E4 )
          {
            v19 = 1;
            while ( 1 )
            {
              v20 = 5654 * *(_DWORD *)(this + 820);
              v21 = *(_DWORD *)(v17 + 4 * (v20 + v19) + 19332);
              v22 = *(_DWORD *)(v17 + 4 * (v20 + v19) + 19352);
              v42 = (unsigned __int64)(sub_530630(v21, v19) + (double)v42);
              v43 = (unsigned __int64)(sub_5306C0(
                                         (const char *)(22616 * *(_DWORD *)(this + 820) + dword_B763DC + 22000),
                                         v22,
                                         v19)
                                     + (double)v43);
              if ( v12 )
              {
                v40 = 0;
                v23 = (_DWORD *)sub_616630("DEFAULT");
                if ( v23 )
                {
                  v24 = sub_48D380(v23);
                  v40 = atol(v24);
                }
                v25 = (_DWORD *)sub_616610(v22 - 1);
                if ( v25 )
                {
                  v26 = sub_48D380(v25);
                  v40 = atol(v26);
                }
                if ( v19 > 0 )
                {
                  if ( v19 <= 2 )
                  {
                    v40 /= 2;
                  }
                  else if ( v19 == 3 )
                  {
                    v40 = 0;
                  }
                }
                v39 += v40;
              }
              if ( ++v19 >= 5 )
                break;
              v17 = dword_B763DC;
            }
          }
          else
          {
            v27 = v18[4831];
            v41 = v18[4832];
            if ( v27 >= 0 )
            {
              if ( sub_616840("SeasonScoringInfo") && (v29 = (_DWORD *)sub_616610(v27 - 1)) != 0 )
              {
                v30 = sub_48D380(v29);
                v28 = atof(v30);
              }
              else
              {
                v28 = 0.0;
              }
              v17 = dword_B763DC;
            }
            else
            {
              v28 = 0.0;
            }
            v42 = (unsigned __int64)v28;
            v43 = (unsigned __int64)sub_5306C0((const char *)(22616 * *(_DWORD *)(this + 820) + v17 + 22000), v41, 4);
            if ( v12 )
            {
              v31 = (_DWORD *)sub_616630("DEFAULT");
              if ( v31 )
              {
                v32 = sub_48D380(v31);
                v39 = atol(v32);
              }
              v33 = (_DWORD *)sub_616610(v41);
              if ( v33 )
              {
                v34 = sub_48D380(v33);
                v39 = atol(v34);
              }
            }
          }
        }
        if ( a4 )
        {
          v42 *= 2;
          v43 *= 2;
          if ( v39 > 0 )
            v39 *= 2;
        }
        if ( v39 < v44 )
          v39 = v44;
        if ( !a3 )
        {
          v35 = (double)v42;
          *(float *)(this + 4 * a2 + 216) = v35;
          v36 = (double)v43;
          *(float *)(this + 4 * a2 + 600) = v36;
          v37 = v36;
          v38 = v35 + *(float *)(this + 792);
          *(_DWORD *)(this + 824) += v39;
          *(float *)(this + 792) = v38;
          *(float *)(this + 796) = v37 + *(float *)(this + 796);
        }
        if ( *(int *)(this + 824) < 0 )
          *(_DWORD *)(this + 824) = 0;
        result = v45;
        if ( *(_DWORD *)(this + 824) > v45 )
          *(_DWORD *)(this + 824) = v45;
        *(_DWORD *)(this + 816) = *(_DWORD *)(this + 812);
      }
    }
  }
  return result;
}
