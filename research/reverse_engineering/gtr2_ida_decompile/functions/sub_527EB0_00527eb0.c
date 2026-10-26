// bad sp value at call has been detected, the output may be wrong!
void __userpurge sub_527EB0(int a1@<ecx>, int a2@<ebx>, int a3@<edi>, char a4, int a5)
{
  bool v6; // zf
  int i; // edi
  double v8; // st7
  char *v9; // eax
  int v10; // eax
  int v11; // eax
  const CHAR *v12; // ecx
  int v13; // edi
  const CHAR *v14; // eax
  int j; // eax
  const CHAR *v16; // eax
  const CHAR *v17; // eax
  double v18; // st7
  char *v19; // eax
  char *v20; // eax
  const CHAR *v21; // eax
  const CHAR *v22; // eax
  float v23; // ecx
  int *v24; // eax
  int v25; // eax
  int v26; // edi
  int k; // eax
  char *v28; // [esp-14h] [ebp-510h]
  char v29; // [esp-10h] [ebp-50Ch]
  int Block; // [esp+0h] [ebp-4FCh]
  float v31; // [esp+4h] [ebp-4F8h]
  _DWORD v32[2]; // [esp+8h] [ebp-4F4h] BYREF
  int v33; // [esp+20h] [ebp-4DCh] BYREF
  int v34; // [esp+24h] [ebp-4D8h]
  float v35; // [esp+30h] [ebp-4CCh]
  _BYTE v36[48]; // [esp+34h] [ebp-4C8h] BYREF
  _BYTE v37[8]; // [esp+64h] [ebp-498h] BYREF
  int v38[6]; // [esp+78h] [ebp-484h] BYREF
  _BYTE v39[56]; // [esp+90h] [ebp-46Ch] BYREF
  _BYTE v40[8]; // [esp+C8h] [ebp-434h] BYREF
  _BYTE v41[1004]; // [esp+D0h] [ebp-42Ch] BYREF
  int v42; // [esp+4C8h] [ebp-34h]
  char v43; // [esp+4DCh] [ebp-20h]
  int v44; // [esp+4F4h] [ebp-8h]

  sub_526070();
  if ( *(_DWORD *)(a1 + 1784) )
  {
    if ( a5 )
      sub_615860(a5);
    v6 = *(_DWORD *)(a1 + 1872) == 1;
    v34 = a3;
    if ( v6 )
    {
      if ( a4 )
      {
        if ( *(_DWORD *)(a1 + 2892916) == 1 )
          sub_521740((_DWORD *)(a1 + 2892996), (_DWORD *)dword_91E084);
        for ( i = 0; i < 105; ++i )
          sub_5253A0((_DWORD *)a1, a2, 0, i);
        sub_5272D0((int *)a1);
        v8 = *(float *)(a1 + 2892848) - *(float *)(a1 + 2892844);
        v35 = v8;
        if ( dword_B640C0 != 4 && v8 > 0.0 )
        {
          if ( *(_DWORD *)(a1 + 2892916) && v35 > 60.0 )
          {
            v9 = sub_41D840(&byte_91CC38, "Please wait...");
            sub_4EB900(&unk_B6F134, (int)v9);
          }
          sub_613B30(v36);
          v10 = *(_DWORD *)(a1 + 2890576);
          v44 = 0;
          switch ( v10 )
          {
            case 0:
              v11 = 0;
              break;
            case 1:
              v11 = 1;
              break;
            case 2:
              v11 = 2;
              break;
            case 3:
              v11 = 3;
              break;
            default:
              v11 = 4;
              break;
          }
          v12 = *(const CHAR **)(a1 + 2892988);
          if ( !v12 )
            v12 = WindowName;
          if ( (unsigned __int8)sub_6146B0(v12, v11, 0, 1, 1) )
          {
            sub_521FC0(a1, &v33, *(float *)(a1 + 2892844), *(float *)(a1 + 2892848));
            v13 = a1 + 1780;
            (*(void (__thiscall **)(int))(*(_DWORD *)(a1 + 1780) + 20))(a1 + 1780);
            v14 = *(const CHAR **)(a1 + 1876);
            if ( !v14 )
              v14 = WindowName;
            (*(void (__thiscall **)(int, const CHAR *, _DWORD))(*(_DWORD *)v13 + 16))(a1 + 1780, v14, 0);
            for ( j = (*(int (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)v13 + 28))(a1 + 1780, v41, 1024);
                  j > 0;
                  j = (*(int (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)v13 + 28))(a1 + 1780, v40, 1024) )
            {
              sub_613C90(v40, j);
            }
            sub_613C30(v32);
            if ( dword_B640C0 != 5
              && (unsigned __int8)sub_5612D0(
                                    (int)byte_FAE910,
                                    2,
                                    "\\Dev\\Src\\Copperhead\\App\\Source\\Replay.cpp",
                                    3479) )
            {
              v16 = *(const CHAR **)(a1 + 2892988);
              if ( !v16 )
                v16 = WindowName;
              sub_561210((int)byte_FAE910, "Successfully created replay file: \"%s\"", (char)v16);
            }
          }
          else if ( dword_B640C0 != 5
                 && (unsigned __int8)sub_5612D0(
                                       (int)byte_FAE910,
                                       1,
                                       "\\Dev\\Src\\Copperhead\\App\\Source\\Replay.cpp",
                                       3483) )
          {
            v17 = *(const CHAR **)(a1 + 2892988);
            if ( !v17 )
              v17 = WindowName;
            v32[0] = v17;
            sub_561210((int)byte_FAE910, v28, v29);
          }
          v42 = -1;
          sub_614140(v32);
        }
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)(a1 + 1780) + 20))(a1 + 1780);
      sub_5246E0();
    }
    else if ( *(_BYTE *)(a1 + 1760) )
    {
      v18 = *(float *)(a1 + 2892848);
      *(_BYTE *)(a1 + 1760) = 0;
      if ( v18 - *(float *)(a1 + 2892844) > 60.0 )
      {
        v19 = sub_41D840(&byte_91CC38, "Please wait...");
        sub_4EB900(&unk_B6F134, (int)v19);
      }
      v20 = *(char **)(a1 + 2892980);
      if ( !v20 )
        v20 = (char *)WindowName;
      sub_520820(v20, 0);
      sub_613B30(v39);
      v21 = *(const CHAR **)(a1 + 2892980);
      v44 = 1;
      if ( !v21 )
        v21 = WindowName;
      if ( (unsigned __int8)sub_6146B0(v21, 4, 0, 1, 1) )
      {
        v22 = *(const CHAR **)(a1 + 1788);
        if ( !v22 )
          v22 = WindowName;
        v32[0] = v22;
        sub_409B50();
        v23 = *(float *)(a1 + 2892844);
        v31 = *(float *)(a1 + 2892848);
        v43 = 2;
        sub_521FC0(a1, v38, v23, v31);
        v24 = *(int **)(a1 + 1884);
        *(_DWORD *)(a1 + 1892) = v24;
        if ( v24 )
        {
          v25 = *v24;
          if ( v25 )
          {
            v26 = a1 + 1780;
            (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)(a1 + 1780) + 52))(
              a1 + 1780,
              *(_DWORD *)(v25 + 4),
              v32[0]);
            Block = 1024;
            for ( k = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)(a1 + 1780) + 28))(a1 + 1780, v41);
                  k > 0;
                  k = (*(int (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)v26 + 28))(a1 + 1780, v40, 1024) )
            {
              sub_613C90(v40, k);
            }
            sub_613C30(v37);
            (*(void (__thiscall **)(int))(*(_DWORD *)v26 + 20))(a1 + 1780);
            sub_520820((char *)0x400, 0);
          }
        }
        if ( Block )
          j_j__free((void *)Block);
      }
      v42 = -1;
      sub_614140(v37);
    }
    else
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)(a1 + 1780) + 20))(a1 + 1780, v34);
    }
  }
  *(_DWORD *)(a1 + 1872) = 0;
  sub_526340();
  sub_526220();
  if ( dword_91BF28 != dword_91BF4C && dword_91BF40 )
    sub_4124A0();
  v6 = *(_DWORD *)(a1 + 2892932) == 0;
  *(_DWORD *)(a1 + 2892844) = 0;
  *(_DWORD *)(a1 + 2892848) = 0;
  if ( !v6 )
  {
    j_j__free(*(void **)(a1 + 2892936));
    *(_DWORD *)(a1 + 2892928) = 0;
    *(_DWORD *)(a1 + 2892932) = 0;
    *(_DWORD *)(a1 + 2892936) = 0;
  }
}
