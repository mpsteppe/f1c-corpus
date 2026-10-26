char __userpurge sub_529E10@<al>(int a1@<ecx>, const char *a2@<ebp>, int a3)
{
  int v4; // eax
  CHAR *v5; // edi
  char *v6; // eax
  int i; // eax
  int v8; // eax
  _DWORD *v9; // edi
  int v10; // eax
  int v12; // [esp-Ah] [ebp-4FCh]
  char v13; // [esp+1h] [ebp-4F1h]
  void *Block; // [esp+2h] [ebp-4F0h]
  int v15; // [esp+Ah] [ebp-4E8h]
  _DWORD v16[2]; // [esp+Eh] [ebp-4E4h] BYREF
  char *Str1; // [esp+1Eh] [ebp-4D4h]
  int v18; // [esp+22h] [ebp-4D0h]
  _BYTE v19[64]; // [esp+2Ah] [ebp-4C8h] BYREF
  _BYTE v20[8]; // [esp+6Ah] [ebp-488h] BYREF
  _BYTE v21[20]; // [esp+72h] [ebp-480h] BYREF
  _BYTE v22[72]; // [esp+86h] [ebp-46Ch] BYREF
  _BYTE v23[1016]; // [esp+CEh] [ebp-424h] BYREF
  int v24; // [esp+4CEh] [ebp-24h]
  int v25; // [esp+4EAh] [ebp-8h]

  sub_615860(a3);
  sub_527EB0(*(_DWORD *)(a1 + 24), 0, a3, 0, 0);
  v4 = *(_DWORD *)(a1 + 24);
  v16[0] = 0;
  HIBYTE(Str1) = 0;
  *(_DWORD *)(v4 + 2892924) = 2;
  sub_53F190(&unk_925CF8, v16[0], v16[1]);
  sub_52B7E0(dword_91E084 + 19272);
  sub_613B30(v19);
  v25 = 0;
  if ( !(unsigned __int8)sub_614460(a3, 0) )
    goto LABEL_18;
  Str1 = (char *)operator new(0x80u);
  *Str1 = 0;
  v18 = 128;
  LOBYTE(v25) = 1;
  sub_615860(Str2);
  sub_615A50("__play.tmp");
  v5 = Str1;
  if ( !Str1 )
    v5 = (CHAR *)WindowName;
  if ( !strncmp(v5, Str2, 2u) )
    sub_614A60(v5);
  else
    sub_617680(v5);
  sub_613B30(v22);
  v6 = Str1;
  LOBYTE(v25) = 2;
  if ( !Str1 )
    v6 = (char *)WindowName;
  if ( (unsigned __int8)sub_6146B0(v6, 0, 0) )
  {
    for ( i = sub_613CE0(v23, 1024); i > 0; i = sub_613CE0(v23, 1024) )
      sub_613C90(v23, i);
    sub_613C30(v21);
    if ( (unsigned __int8)sub_528A30(*(int **)(a1 + 24), (int)v5, 1, 0) )
    {
      *(_DWORD *)(*(_DWORD *)(a1 + 24) + 2892972) = 6;
      *(_BYTE *)(*(_DWORD *)(a1 + 24) + 2892960) = 1;
      sub_522DB0();
      v8 = *(_DWORD *)(a1 + 24);
      v9 = (_DWORD *)((char *)&unk_9204A0 + 22616 * *(_DWORD *)(v8 + 2892924));
      v9[4859] = *(_DWORD *)(v8 + 2893232);
      v9[4862] = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 2893232);
      v9[4860] = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 2893236);
      v9[4863] = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 2893236);
      v9[4861] = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 2893240);
      v9[4864] = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 2893240);
      v9[4821] = 0;
      v9[4822] = 0;
      sub_53F0E0(0);
      sub_53F190(v9, 1, v12);
    }
    else
    {
      sub_520820((char *)1, a2);
    }
  }
  sub_613C30(v16);
  LOBYTE(v24) = 1;
  sub_614140(v20);
  LOBYTE(v24) = 0;
  if ( Block )
    j_j__free(Block);
  if ( v13 )
  {
    v10 = *(_DWORD *)(a1 + 24);
    *(_DWORD *)a1 = 2;
    *(_BYTE *)(a1 + 9) = 1;
    v15 = *(int *)(v10 + 2892844);
    *(float *)(v10 + 2892856) = *(float *)&v15;
    sub_522980(*(void **)(a1 + 24), v15);
  }
  else
  {
LABEL_18:
    *(_DWORD *)a1 = 0;
    *(_BYTE *)(a1 + 9) = 0;
  }
  if ( byte_B731E0 )
  {
    sub_524780(*(_DWORD **)(a1 + 24));
    *(_DWORD *)(a1 + 20) = 1;
  }
  else
  {
    sub_546C00(&unk_BE2728, 12);
    *(_DWORD *)(a1 + 20) = 0;
  }
  v24 = -1;
  sub_614140(v16);
  return v13;
}
