int __cdecl sub_4993DC(int Buffer)
{
  int v1; // ecx
  int v2; // esi
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  int v6; // ebp
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  double v18; // [esp+0h] [ebp-34h]
  double v19; // [esp+0h] [ebp-34h]
  double v20; // [esp+0h] [ebp-34h]
  double v21; // [esp+0h] [ebp-34h]
  char *v22; // [esp+4h] [ebp-30h]
  int v23; // [esp+Ch] [ebp-28h]
  int v24; // [esp+Ch] [ebp-28h]
  int v25; // [esp+Ch] [ebp-28h]
  int v26; // [esp+Ch] [ebp-28h]
  int v27; // [esp+Ch] [ebp-28h]
  double v28; // [esp+Ch] [ebp-28h]
  double v29; // [esp+Ch] [ebp-28h]
  double v30; // [esp+Ch] [ebp-28h]
  double v31; // [esp+Ch] [ebp-28h]
  char *v32; // [esp+10h] [ebp-24h]
  int v33; // [esp+14h] [ebp-20h]
  int v34; // [esp+14h] [ebp-20h]
  int v35; // [esp+14h] [ebp-20h]
  int v36; // [esp+14h] [ebp-20h]
  int v37; // [esp+14h] [ebp-20h]
  double v38; // [esp+18h] [ebp-1Ch]
  double v39; // [esp+18h] [ebp-1Ch]
  double v40; // [esp+18h] [ebp-1Ch]
  double v41; // [esp+18h] [ebp-1Ch]
  char *v42; // [esp+1Ch] [ebp-18h]
  int v43; // [esp+1Ch] [ebp-18h]
  int v44; // [esp+1Ch] [ebp-18h]
  int v45; // [esp+1Ch] [ebp-18h]
  int v46; // [esp+1Ch] [ebp-18h]
  int v47; // [esp+1Ch] [ebp-18h]
  int v48; // [esp+24h] [ebp-10h]
  _UNKNOWN *retaddr; // [esp+34h] [ebp+0h] BYREF

  v2 = v1;
  Buffer = 0;
  v3 = sub_501480(&byte_B6F530);
  sub_615860(v3);
  sub_4D0AC0(v48);
  sub_4CE140(v2, &Buffer);
  v4 = dword_B76320;
  v5 = dword_B76324;
  v6 = dword_B76328;
  v42 = sub_41D840(&byte_91CC38, "Laps");
  v32 = sub_41D840(&byte_91CC38, "Laps");
  v22 = sub_41D840(&byte_91CC38, "Laps");
  v7 = (const char *)sub_4CFC00(0);
  sprintf(
    (char *const)&Buffer,
    "%s%s%i %s%s%i %s%s%i %s",
    v7,
    (const char *)&retaddr,
    v6,
    v22,
    (const char *)&retaddr,
    v5,
    v32,
    (const char *)&retaddr,
    v4,
    v42);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  sub_4D93B0(CommandLine, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v43 = dword_B7632C;
  v33 = dword_B76330;
  v23 = dword_B76334;
  v8 = (const char *)sub_4CFC00(1);
  sprintf(
    (char *const)&Buffer,
    "%s%s%i%s%i%s%i",
    v8,
    (const char *)&retaddr,
    v23,
    (const char *)&retaddr,
    v33,
    (const char *)&retaddr,
    v43);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v44 = dword_B7635C;
  v34 = dword_B76360;
  v24 = dword_B76364;
  v9 = (const char *)sub_4CFC00(8);
  sprintf(
    (char *const)&Buffer,
    "%s%s%i%s%i%s%i",
    v9,
    (const char *)&retaddr,
    v24,
    (const char *)&retaddr,
    v34,
    (const char *)&retaddr,
    v44);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  sub_4D93B0(CommandLine, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v45 = dword_B76368;
  v35 = dword_B7636C;
  v25 = dword_B76370;
  v10 = (const char *)sub_4CFC00(6);
  sprintf(
    (char *const)&Buffer,
    "%s%s%i%s%i%s%i",
    v10,
    (const char *)&retaddr,
    v25,
    (const char *)&retaddr,
    v35,
    (const char *)&retaddr,
    v45);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v46 = dword_B76344;
  v36 = dword_B76348;
  v26 = dword_B7634C;
  v11 = (const char *)sub_4CFC00(7);
  sprintf(
    (char *const)&Buffer,
    "%s%s%i%s%i%s%i",
    v11,
    (const char *)&retaddr,
    v26,
    (const char *)&retaddr,
    v36,
    (const char *)&retaddr,
    v46);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v47 = dword_B76350;
  v37 = dword_B76354;
  v27 = dword_B76358;
  v12 = (const char *)sub_4CFC00(9);
  sprintf(
    (char *const)&Buffer,
    "%s%s%i%s%i%s%i",
    v12,
    (const char *)&retaddr,
    v27,
    (const char *)&retaddr,
    v37,
    (const char *)&retaddr,
    v47);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  sub_4D93B0(CommandLine, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v38 = flt_B763A4;
  v28 = flt_B763A8;
  v18 = flt_B763AC;
  v13 = (const char *)sub_4CFC00(2);
  sprintf(
    (char *const)&Buffer,
    "%s%s%.1f%s%.1f%s%.1f",
    v13,
    (const char *)&retaddr,
    v18,
    (const char *)&retaddr,
    v28,
    (const char *)&retaddr,
    v38);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v39 = flt_B763B0;
  v29 = flt_B763B4;
  v19 = flt_B763B8;
  v14 = (const char *)sub_4CFC00(3);
  sprintf(
    (char *const)&Buffer,
    "%s%s%.1f%s%.1f%s%.1f",
    v14,
    (const char *)&retaddr,
    v19,
    (const char *)&retaddr,
    v29,
    (const char *)&retaddr,
    v39);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v40 = flt_B763BC;
  v30 = flt_B763C0;
  v20 = flt_B763C4;
  v15 = (const char *)sub_4CFC00(4);
  sprintf(
    (char *const)&Buffer,
    "%s%s%.1f%s%.1f%s%.1f",
    v15,
    (const char *)&retaddr,
    v20,
    (const char *)&retaddr,
    v30,
    (const char *)&retaddr,
    v40);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v41 = flt_B763C8;
  v31 = flt_B763CC;
  v21 = flt_B763D0;
  v16 = (const char *)sub_4CFC00(5);
  sprintf(
    (char *const)&Buffer,
    "%s%s%.1f%%%s%.1f%%%s%.1f%%",
    v16,
    (const char *)&retaddr,
    v21,
    (const char *)&retaddr,
    v31,
    (const char *)&retaddr,
    v41);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  return sub_4D93B0(&retaddr, 0, 0, 0, 0, 0, -1, -1, -1, -1);
}
