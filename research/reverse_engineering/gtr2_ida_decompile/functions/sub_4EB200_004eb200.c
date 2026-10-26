// bad sp value at call has been detected, the output may be wrong!
int __usercall sub_4EB200@<eax>(int a1@<ebx>)
{
  const char *v1; // eax
  int v2; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // esi
  int v7; // esi
  const char *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  const char *v14; // eax
  int v15; // esi
  int v16; // edi
  char v18[26]; // [esp+0h] [ebp-128h] BYREF
  int v19; // [esp+1Ah] [ebp-10Eh]
  __int16 v20; // [esp+1Eh] [ebp-10Ah]
  char v21[8]; // [esp+20h] [ebp-108h] BYREF
  char Buffer[256]; // [esp+28h] [ebp-100h] BYREF

  sub_501EA0(&byte_B6F530);
  if ( (_BYTE)dword_757C1C && *(_DWORD *)(dword_91E084 + 19324) == 1 && dword_B721D0 == 1 )
  {
    v1 = (const char *)dword_91CAD0;
    if ( !dword_91CAD0 )
      v1 = WindowName;
    sprintf(Buffer, "%s%s", v1, "winRace.bik");
    sub_590B70(&unk_FB1E98, Buffer, 1);
  }
  v2 = sub_532D20(&unk_B76270);
  v3 = v2;
  if ( v2 )
  {
    sub_5373C0(v2);
    if ( sub_534F50(&unk_B76270) == 3 )
    {
      v4 = sub_5304D0(v3, a1);
      if ( v4 )
      {
        v5 = 0;
        if ( sub_616840("CATEGORY") )
        {
          while ( sub_616610(v5++) )
            ;
        }
        v7 = v5 - 1;
        if ( sub_616840("CategoryLists") )
        {
          v8 = (const char *)sub_616930("CategoryLists");
          v7 = atol(v8);
        }
        if ( dword_B721D0 == 1 )
        {
          memset(&v18[14], 0, 12);
          strcpy(v18, "EndSeason.bik");
          v9 = *(_DWORD *)(v4 + 800);
          v19 = 0;
          v20 = 0;
          if ( v9 )
          {
            v10 = v9 - 1;
            if ( v10 )
            {
              if ( v10 == 1 )
                strcpy(v18, "ChampThird.bik");
            }
            else
            {
              strcpy(v18, "ChampSecond.bik");
            }
          }
          else
          {
            strcpy(v18, "ChampVictory.bik");
            sub_535070(&unk_B76270);
          }
          v11 = *(_DWORD *)(v4 + 844);
          if ( v11 > 0 && v11 <= v7 )
          {
            v12 = *(_DWORD *)(v4 + 804);
            if ( v12 < *(_DWORD *)(v4 + 800) )
            {
              if ( v12 )
              {
                v13 = v12 - 1;
                if ( v13 )
                {
                  if ( v13 == 1 )
                    strcpy(v18, "ChampCategoryThird.bik");
                }
                else
                {
                  strcpy(v18, "ChampCategorySecond.bik");
                }
              }
              else
              {
                strcpy(v18, "ChampCategoryVictory.bik");
                sub_535070(&unk_B76270);
              }
            }
          }
          v14 = (const char *)dword_91CAD0;
          if ( !dword_91CAD0 )
            v14 = WindowName;
          sprintf(v21, "%s%s", v14, v18);
          sub_590B70(&unk_FB1E98, v21, 1);
          sub_41F070((int)dword_B761EC, (unsigned __int64)*(float *)(v4 + 792), *(_DWORD *)(v4 + 800));
        }
      }
      sub_537D80(&unk_B76270);
    }
    else
    {
      sub_537D80(&unk_B76270);
      sub_5363D0(&unk_B76270);
    }
  }
  v15 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 42);
  v16 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 44);
  if ( v15 )
    sub_4B8110();
  if ( v16 )
    sub_4B8110();
  dword_75B17C = 3;
  return 0;
}
