void __usercall sub_4AA890(
        const char *a1@<ecx>,
        int a2@<ebx>,
        float a3@<edi>,
        int a4@<esi>,
        int a5,
        int a6,
        int a7,
        double a8,
        int a9,
        int a10,
        int a11,
        int a12,
        double a13,
        __int128 a14,
        char a15,
        int a16,
        char a17,
        int a18,
        char a19,
        int a20,
        char a21,
        int a22,
        int a23,
        __int128 a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        char Buffer,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36)
{
  const CHAR *v36; // eax
  int v37; // edi
  int v38; // ecx
  int v39; // esi
  char *v40; // eax
  int v41; // eax
  const char *v42; // ecx
  bool v43; // bl
  char *v44; // eax
  char *v45; // eax
  char *v46; // eax
  double v47; // st7
  int v48; // ebx
  double v49; // st7
  unsigned __int64 v50; // rax
  const char *v51; // eax
  const char *v52; // eax
  const char *v53; // eax
  int v54; // eax
  int v55; // edi
  const char *v56; // eax
  int v57; // edi
  const char *v58; // eax
  const char *v59; // eax
  const char *v60; // eax
  const char *v61; // eax
  const char *v62; // eax
  unsigned int v63; // kr00_4
  __int32 v64; // edi
  int v65; // [esp+3C54h] [ebp-34h]
  int v66; // [esp+3C54h] [ebp-34h]
  int v67; // [esp+3C5Ch] [ebp-2Ch]
  char *v68; // [esp+3C60h] [ebp-28h] BYREF
  float v69; // [esp+3C64h] [ebp-24h]
  unsigned int *v70; // [esp+3C70h] [ebp-18h]
  char *v71; // [esp+3C74h] [ebp-14h]
  const char *v72; // [esp+3C78h] [ebp-10h] BYREF
  float v73; // [esp+3C7Ch] [ebp-Ch]
  int v74; // [esp+3C80h] [ebp-8h]
  int *v75; // [esp+3C84h] [ebp-4h]
  int vars0; // [esp+3C88h] [ebp+0h] BYREF
  _UNKNOWN *retaddr; // [esp+3C8Ch] [ebp+4h]

  v72 = a1;
  sub_631BD0();
  vars0 = a2;
  v75 = &vars0;
  v74 = a4;
  *(_WORD *)((char *)&retaddr + 1) = 0;
  v73 = a3;
  HIBYTE(retaddr) = 0;
  v36 = dword_B6F708;
  v37 = 0;
  v39 = v38;
  LOBYTE(retaddr) = 0;
  if ( !dword_B6F708 )
    v36 = WindowName;
  sub_615860(v36);
  sub_4D0AC0(LODWORD(v73));
  sub_4CE140(v39, &a5);
  v40 = dword_B6F708;
  if ( !dword_B6F708 )
    v40 = (char *)WindowName;
  v41 = sub_539670(v40);
  a10 = v41;
  LOBYTE(STACK[0x3E2C]) = 0;
  if ( v41 )
  {
    v42 = *(const char **)(v41 + 8);
    if ( !v42 )
      v42 = WindowName;
    strcpy((char *)&STACK[0x3E2C], v42);
  }
  sub_5875F0(&STACK[0x3EAC]);
  STACK[0x7B30] = 0;
  sub_435800(SLODWORD(v73), v74);
  v72 = 0;
  v71 = &byte_B64150;
  v70 = &STACK[0x3E2C];
  LOBYTE(STACK[0x7B30]) = 1;
  sub_5886A0(v70, v71, v72);
  sub_434BB0();
  v43 = dword_B72454 == 1;
  HIBYTE(a6) = dword_B72454 == 1;
  a12 = (unsigned __int64)dbl_FAF608;
  if ( dword_B72454 == 1 )
    v72 = (const char *)&off_6F3E1C;
  else
    v72 = (const char *)&unk_6FF76C;
  v44 = sub_41D840(&byte_91CC38, v72);
  sub_630FE0(&a17, v44, 7);
  HIBYTE(a18) = 0;
  if ( v43 )
    v72 = (const char *)&unk_6FF768;
  else
    v72 = (const char *)&unk_6FF764;
  v45 = sub_41D840(&byte_91CC38, v72);
  sub_630FE0(&a19, v45, 7);
  HIBYTE(a20) = 0;
  v46 = sub_41D840(&byte_91CC38, "nm");
  sub_630FE0(&a15, v46, 7);
  HIBYTE(a16) = 0;
  if ( dword_FAFD5C <= 0 )
    v47 = 0.0;
  else
    v47 = dbl_FAFD48[3 * dword_FAFD5C];
  v48 = 0;
  a5 = (unsigned __int64)v47;
  LODWORD(a8) = 0;
  a9 = 0;
  a11 = 0;
  a7 = 100;
  if ( a5 > 100 )
  {
    do
    {
      v72 = (const char *)&a13;
      a8 = (double)a7;
      v71 = &a21;
      sub_585E70(&unk_FAF5C8, LODWORD(a8), HIDWORD(a8));
      if ( (int)(unsigned __int64)(a8 * a13 * 0.001818181818181818) > v37 )
      {
        v37 = (unsigned __int64)(a8 * a13 * 0.001818181818181818);
        v48 = (unsigned __int64)((double)a7 * 60.0 * 0.1591549430918953);
      }
      if ( (double)a9 < a13 )
      {
        a9 = (unsigned __int64)a13;
        a11 = (unsigned __int64)((double)a7 * 60.0 * 0.1591549430918953);
      }
      a7 += 5;
    }
    while ( a7 < (int)&vars0 );
    LODWORD(a8) = v37;
  }
  LODWORD(a8) = (unsigned __int64)((double)SLODWORD(a8) * 0.73760003);
  if ( byte_B65C58 )
    v49 = (double)dword_B65714 * dbl_B65708 + dbl_B65700;
  else
    v49 = (double)a5;
  sub_431910(v49 * 9.549296585513721);
  a14 = 0u;
  strcpy((char *)&a23, "class");
  memset((char *)&a24 + 2, 0, 0x38u);
  HIWORD(a35) = 0;
  sub_538F10(a10, &a14, 15, &a23, 63, 0);
  if ( HIBYTE(v74) )
  {
    v50 = (unsigned __int64)((double)SLODWORD(a8) * 2.2);
  }
  else
  {
    vars0 = (unsigned __int64)((double)vars0 * 0.746);
    LODWORD(v50) = LODWORD(a8);
  }
  v67 = v50;
  v51 = (const char *)sub_4CFC00(0);
  sprintf(&Buffer, "%s%s %d %s", v51, (const char *)&v72, v67, (const char *)&a14 + 4);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  sub_4331B0((int)&byte_B64150, (const char **)3);
  v52 = (const char *)sub_4CFC00(1);
  sprintf(&Buffer, "%s%s %s", v52, (const char *)&v72, byte_B64DDE);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v53 = (const char *)sub_4CFC00(2);
  sprintf(&Buffer, "%s%s %s", v53, (const char *)&v72, byte_B65E7A);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  LODWORD(v73) = v48 / 100;
  v69 = (float)(v48 / 100);
  v54 = sub_4015C0(v69);
  v69 = COERCE_FLOAT(&v72);
  v68 = (char *)&a36;
  v63 = __readeflags();
  v64 = __ROR4__(off_16C6E78, 1);
  __writeeflags(v63);
  _InterlockedExchange((volatile __int32 *)&v68, v64);
  v55 = v54;
  v68 = sub_41D840(&byte_91CC38, v68);
  v65 = vars0;
  v56 = (const char *)sub_4CFC00(3);
  sprintf(&Buffer, "%s%s %d %s@%d00 %s", v56, (const char *)&v72, v65, (const char *)&a14 + 12, v55, v68);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v73 = (float)(a7 / 100);
  v57 = sub_4015C0(v73);
  v69 = COERCE_FLOAT(&v72);
  v68 = sub_41D840(&byte_91CC38, (const char *)&off_6FF724);
  v66 = a5;
  v58 = (const char *)sub_4CFC00(4);
  sprintf(&Buffer, "%s%s %d %s@%d00 %s", v58, (const char *)&v72, v66, (const char *)&a13 + 4, v57, v68);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v69 = COERCE_FLOAT(&v72);
  v68 = (char *)&vars0;
  v59 = (const char *)sub_4CFC00(5);
  sprintf(&Buffer, "%s%s %d%03d%s", v59, (const char *)&v72, (int)&vars0 / 1000, v68, (const char *)LODWORD(v69));
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v69 = COERCE_FLOAT(&v72);
  v68 = (char *)&a18;
  v60 = (const char *)sub_4CFC00(6);
  sprintf(&Buffer, "%s%s %s", v60, (const char *)&v72, v68);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v69 = COERCE_FLOAT(&v72);
  v68 = (char *)(a6 + 2044);
  v61 = (const char *)sub_4CFC00(7);
  sprintf(&Buffer, "%s%s %s", v61, (const char *)&v72, v68);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  v69 = COERCE_FLOAT(&v72);
  v68 = (char *)&unk_FAF650;
  v62 = (const char *)sub_4CFC00(8);
  sprintf(&Buffer, "%s%s %s", v62, (const char *)&v72, v68);
  sub_4D93B0(&Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  LOBYTE(STACK[0x7B1C]) = 2;
  sub_431A70(&STACK[0x7758]);
  if ( STACK[0x5CD0] )
    j_j__free((void *)STACK[0x5CD0]);
  if ( STACK[0x3EC4] )
    j_j__free((void *)STACK[0x3EC4]);
  if ( STACK[0x3EBC] )
    j_j__free((void *)STACK[0x3EBC]);
  if ( STACK[0x3EB4] )
    j_j__free((void *)STACK[0x3EB4]);
  if ( STACK[0x3EAC] )
    j_j__free((void *)STACK[0x3EAC]);
  if ( STACK[0x3EA4] )
    j_j__free((void *)STACK[0x3EA4]);
  if ( STACK[0x3E98] )
    j_j__free((void *)STACK[0x3E98]);
}
