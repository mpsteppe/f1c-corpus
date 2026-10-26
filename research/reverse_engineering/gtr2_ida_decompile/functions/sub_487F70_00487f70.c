void __thiscall sub_487F70(int this, int a2, int a3, int a4)
{
  int v5; // eax
  char *v6; // eax
  char *v7; // eax
  int v8; // esi
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  int v12; // esi
  char *v13; // ebx
  const char **v14; // ebp
  int v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  char *v19; // esi
  char *v20; // eax
  char *v21; // eax
  char *v22; // eax
  _BYTE *Block; // [esp+18h] [ebp-7C8h]
  char v24[4]; // [esp+2Ch] [ebp-7B4h] BYREF
  char Buffer[56]; // [esp+54h] [ebp-78Ch] BYREF
  char v26[103]; // [esp+A4h] [ebp-73Ch] BYREF
  char v27; // [esp+123h] [ebp-6BDh]
  char v28[104]; // [esp+124h] [ebp-6BCh] BYREF
  char v29[8]; // [esp+18Ch] [ebp-654h] BYREF
  _BYTE v30[4]; // [esp+194h] [ebp-64Ch] BYREF
  _BYTE v31[516]; // [esp+198h] [ebp-648h] BYREF
  _BYTE v32[12]; // [esp+3A8h] [ebp-438h] BYREF
  _BYTE v33[436]; // [esp+3B4h] [ebp-42Ch] BYREF
  char v34[80]; // [esp+568h] [ebp-278h] BYREF
  _BYTE v35[524]; // [esp+5B8h] [ebp-228h] BYREF
  int v36; // [esp+7C4h] [ebp-1Ch]
  int v37; // [esp+7D0h] [ebp-10h]
  int v38; // [esp+7D4h] [ebp-Ch]
  int v39; // [esp+7D8h] [ebp-8h]
  int v40; // [esp+7DCh] [ebp-4h]

  v5 = *(_DWORD *)(this + 96);
  Buffer[0] = 0;
  if ( v5 )
  {
    v6 = sub_41D840(&byte_91CC38, "There is a vote in progress.");
    sub_630FE0(v26, v6, 127);
    v27 = 0;
    v7 = sub_41D840(&byte_91CC38, "Cannot call vote:");
    sprintf(Buffer, "%s %s", v7, v26);
    sub_47F8E0();
    return;
  }
  if ( *(float *)(this + 80) > -15.0 )
  {
    v8 = (unsigned __int64)(*(float *)(this + 80) + 16.0);
    v9 = sub_41D840(&byte_91CC38, "Vote just ended.  Wait");
    sub_630FE0(v26, v9, 127);
    v27 = 0;
    v10 = sub_41D840(&byte_91CC38, "seconds.");
    sub_630FE0(v28, v10, 127);
    v31[11] = 0;
    v11 = sub_41D840(&byte_91CC38, "Cannot call vote:");
    sprintf(Buffer, "%s %s %d %s", v11, v26, v8, v28);
    sub_47F8E0();
    return;
  }
  v12 = a2;
  if ( a2 != 3 )
  {
    if ( a2 == 1 && *(_DWORD *)dword_B640C8 == 6 )
    {
      v18 = sub_41D840(&byte_91CC38, "Cannot advance session past race.");
      sub_630FE0(v26, v18, 127);
      v27 = 0;
      sprintf(Buffer, "%s %s", "Cannot call vote:", v26);
      sub_47F8E0();
      return;
    }
    goto LABEL_16;
  }
  sub_4744D0(v33);
  v40 = 0;
  sub_47A120();
  v13 = (char *)operator new(0xFFu);
  *(_DWORD *)v24 = strcpy(v13, v34);
  v14 = (const char **)dword_B6CF0C;
  v15 = dword_B6CF10;
  if ( dword_B6CF0C == dword_B6CF10 )
  {
LABEL_10:
    if ( v14 && (dword_B6CF10 - (int)v14) >> 2 < (unsigned int)((dword_B6CF14 - (int)v14) >> 2) )
    {
      *(_DWORD *)dword_B6CF10 = v13;
      dword_B6CF10 = v15 + 4;
    }
    else
    {
      sub_407CB0();
    }
    v37 = -1;
    nullsub_7(v32);
    v12 = v39;
LABEL_16:
    ++*(_DWORD *)(this + 84);
    *(_DWORD *)(this + 80) = 1110704128;
    *(_DWORD *)(this + 96) = v12;
    *(_DWORD *)(this + 92) = dword_757C10;
    *(_DWORD *)(this + 88) = (unsigned __int64)((double)*(int *)(this + 92) * 0.50999999 + 1.0);
    *(_DWORD *)(this + 520) = 0;
    *(_DWORD *)(this + 524) = 0;
    if ( v12 )
    {
      *(_DWORD *)(this + 104) = v40;
      ++*(_DWORD *)(this + 520);
      sub_4744D0(v35);
      v37 = -1;
      nullsub_7(v35);
    }
    sub_4744D0(v31);
    v37 = 3;
    sub_47A120();
    if ( sub_473440(v29, 1) )
    {
      v16 = sub_41D840(&byte_91CC38, "SERVER");
      sub_630FE0(v30, v16, 31);
      v31[27] = 0;
    }
    Block = operator new(0x80u);
    *Block = 0;
    LOBYTE(v36) = 4;
    *(_DWORD *)(this + 100) = v38;
    sub_615A50(&word_6F6668);
    switch ( *(_DWORD *)(this + 96) )
    {
      case 1:
        v17 = sub_41D840(&byte_91CC38, "advance to next session");
        break;
      case 2:
        v17 = sub_41D840(&byte_91CC38, "advance to next event");
        break;
      case 3:
        v17 = sub_41D840(&byte_91CC38, "kick player");
        break;
      default:
        v17 = "<no issue>";
        break;
    }
    sub_615A50(v17);
    if ( *(_DWORD *)(this + 96) == 3 )
    {
      v19 = (char *)&unk_9204A0 + 22616 * *(_DWORD *)(this + 100);
      sub_615A50(CommandLine);
      sub_615A50(v19 + 21568);
    }
    sub_615A50(&word_6F6668);
    v20 = sub_41D840(&byte_91CC38, " proposed by ");
    sub_615A50(v20);
    sub_615A50(v30);
    sub_615A50(".");
    v21 = sub_41D840(&byte_91CC38, " Vote needs ");
    sub_615A50(v21);
    sprintf(v24, "%d", *(_DWORD *)(this + 88) - *(_DWORD *)(this + 520));
    sub_615A50(v24);
    v22 = sub_41D840(&byte_91CC38, " to pass.");
    sub_615A50(v22);
    sub_47F8E0();
    if ( Block )
      j_j__free(Block);
    v36 = -1;
    nullsub_7(v29);
    return;
  }
  while ( strcmp(*v14, v13) )
  {
    v13 = *(char **)v24;
    if ( ++v14 == (const char **)dword_B6CF10 )
    {
      v14 = (const char **)dword_B6CF0C;
      goto LABEL_10;
    }
  }
  sub_41D840(&byte_91CC38, "Cannot Kick more than once per game.");
  off_16C9564(3, a3, a4);
}
