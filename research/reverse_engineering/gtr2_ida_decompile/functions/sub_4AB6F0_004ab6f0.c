void __userpurge sub_4AB6F0(int a1@<ecx>, char *a2@<ebp>, int a3@<esi>, const char *a4)
{
  char *v4; // edx
  unsigned int v5; // kr00_4
  __int32 v6; // edx
  const char *v8; // eax
  void *v9; // eax
  _DWORD *v10; // eax
  char *v11; // eax
  _DWORD *v12; // eax
  char *v13; // eax
  const CHAR **v14; // esi
  const CHAR *v15; // eax
  _DWORD *v16; // eax
  char *v17; // eax
  const CHAR *v18; // eax
  CHAR FileName[8]; // [esp+8h] [ebp-16Ch] BYREF
  int v20; // [esp+10h] [ebp-164h]
  char *v21; // [esp+14h] [ebp-160h] BYREF
  char Buffer[224]; // [esp+68h] [ebp-10Ch] BYREF
  int v23; // [esp+150h] [ebp-24h]

  if ( a4 )
  {
    v8 = *(const char **)dword_91CAC8;
    if ( !*(_DWORD *)dword_91CAC8 )
      v8 = WindowName;
    sub_41D810(Buffer, 0xFFu, "%s%s.dst", v8, a4);
    v21 = v4;
    v5 = __readeflags();
    v6 = dword_16C6E34 - (loc_44A5B7 + 1);
    __writeeflags(v5);
    _InterlockedExchange((volatile __int32 *)&v21, v6);
    v9 = (void *)sub_616840(v21);
    if ( v9 )
      sub_616960(v9);
    v21 = a2;
    v20 = a3;
    sub_616F90(Buffer, 0);
    sub_616840("DrivingSchool");
    v10 = (_DWORD *)sub_616630("Track");
    if ( v10 )
    {
      v11 = sub_48D380(v10);
      sub_538860(&unk_BE1CFD, v11, v20, v21);
      sub_53A160(0);
    }
    v12 = (_DWORD *)sub_616630((char *)off_6FF7B8);
    if ( v12 )
    {
      v13 = sub_48D380(v12);
      sub_53AE90(&unk_BE1CDC, v13);
      v14 = (const CHAR **)sub_538790(&unk_BE1CDC);
      v15 = *v14;
      if ( !*v14 )
        v15 = WindowName;
      sub_615860(v15);
      sub_615860(v14 + 463);
      sub_53BDE0(&unk_BE1CE0, "AND: SIM_FULL");
      sub_539FF0(&unk_BE1CE0);
      dword_BE1BD0 = sub_53A0E0(&unk_BE1CE0);
    }
    *(_DWORD *)(a1 + 596) = 0;
    *(_DWORD *)(a1 + 600) = 0;
    *(_BYTE *)(a1 + 608) = 0;
    v16 = (_DWORD *)sub_616630("Filter");
    if ( v16 )
    {
      v17 = sub_48D380(v16);
      sub_630FE0(a1 + 608, v17, 7);
      *(_BYTE *)(a1 + 615) = 0;
      *(_DWORD *)(a1 + 596) = sub_41DA80();
      *(_DWORD *)(a1 + 600) = sub_41DA80();
      sub_615FC0(&unk_FAECBC);
      sub_41D810(FileName, 0x3Fu, "%s*.ds", (const char *)(a1 + 608));
      v18 = *(const CHAR **)dword_91CAC8;
      v23 = 0;
      if ( !*(_DWORD *)dword_91CAC8 )
        v18 = WindowName;
      sub_615860(v18);
      sub_615FE0(FileName, 1, (char *)WindowName, 0);
      *(_DWORD *)(a1 + 604) = sub_615D30(&unk_FAECBC);
    }
  }
}
