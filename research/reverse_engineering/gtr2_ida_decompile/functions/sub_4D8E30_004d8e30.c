int __userpurge sub_4D8E30@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        _UNKNOWN **a26,
        _UNKNOWN **a27,
        _UNKNOWN **a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        char a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63)
{
  int a65; // [esp+12A4h] [ebp+FCh]
  int a66; // [esp+12A8h] [ebp+100h]
  __int32 v66; // ecx
  __int32 v67; // ebx
  int v68; // eax
  int v69; // ebp
  const CHAR *v70; // eax
  int *v71; // esi
  int v72; // eax
  int v73; // ecx
  int v74; // eax
  const CHAR *v75; // eax
  const char *v76; // esi
  signed int i; // edi
  char v78; // al
  char v79; // cl
  const CHAR *v80; // eax
  int v81; // edx
  int v82; // edi
  unsigned int *v83; // esi
  int v84; // eax
  int v85; // ecx
  int v86; // edx
  int v87; // ebp
  const char *v88; // esi
  int v89; // ecx
  int v90; // edx
  int v91; // eax
  char v92; // al
  const CHAR *v93; // edx
  int v94; // esi
  int v95; // edi
  signed int v96; // esi
  unsigned int v97; // eax
  bool v98; // zf
  const CHAR *v99; // eax
  int v101; // [esp+114Ch] [ebp-5Ch]
  int v102; // [esp+1154h] [ebp-54h]
  int v103; // [esp+1158h] [ebp-50h]
  const char *v104; // [esp+1164h] [ebp-44h]
  int v105; // [esp+1168h] [ebp-40h]
  int v106; // [esp+116Ch] [ebp-3Ch]
  signed int v107; // [esp+116Ch] [ebp-3Ch]
  int v108; // [esp+1170h] [ebp-38h]
  int v109; // [esp+1170h] [ebp-38h]
  int v110; // [esp+1174h] [ebp-34h]
  signed int v111; // [esp+1174h] [ebp-34h]
  int v112; // [esp+1178h] [ebp-30h]
  int v113; // [esp+117Ch] [ebp-2Ch] BYREF
  int v114; // [esp+1180h] [ebp-28h] BYREF
  unsigned int v115; // [esp+1184h] [ebp-24h] BYREF
  _DWORD v116[3]; // [esp+1188h] [ebp-20h] BYREF
  int v117; // [esp+1194h] [ebp-14h]
  _DWORD v118[4]; // [esp+1198h] [ebp-10h] BYREF
  int savedregs; // [esp+11A8h] [ebp+0h] BYREF

  v118[0] = a1;
  sub_631BD0();
  v117 = a2;
  v116[2] = &savedregs;
  v67 = v66;
  v68 = *(_DWORD *)(v66 + 244);
  v69 = 0;
  v116[1] = a4;
  v116[0] = a3;
  if ( v68 )
  {
    v70 = *(const CHAR **)(v68 + 64);
    if ( !v70 )
      v70 = WindowName;
    sub_4DF1B0(*(_DWORD *)(v66 + 48), v70);
  }
  if ( *(_DWORD *)(v67 + 244) )
  {
    v71 = (int *)sub_4E29F0(0);
    if ( v71 )
    {
      v72 = *(_DWORD *)(v67 + 4);
      v73 = *(_DWORD *)(v67 + 12);
      v114 = 0;
      v113 = 0;
      v110 = v71[1] - *v71;
      v108 = v72;
      v106 = v73;
      v74 = sub_4DDFE0(&unk_B6E2A0, v110);
      sub_4D5E10((void *)v67, v71[7], *v71, v71[2], v74, v106, v108, v110);
    }
  }
  v75 = *(const CHAR **)(v67 + 168);
  if ( !v75 )
    v75 = WindowName;
  sub_630FE0(&STACK[0x1364], v75, 63);
  LOBYTE(STACK[0x13A3]) = 0;
  v76 = (const char *)sub_6331DF(&STACK[0x1364], CommandLine);
  a13 = 0;
  memset(&a14, 0, 0x38u);
  STACK[0x1328] = 0;
  memset(&STACK[0x132C], 0, 0x38u);
  v117 = 1;
  memset(v118, 0, 0x38u);
  for ( ; v76; v76 = (const char *)sub_6331DF(0, CommandLine) )
  {
    if ( v69 >= 15 )
      break;
    v107 = strlen(v76);
    for ( i = 0; i < v107; ++i )
    {
      if ( sub_633848(v76[i]) )
      {
        v78 = v76[i];
        if ( v78 == 114 || v78 == 82 )
        {
          v118[v69 - 1] = 3;
        }
        else if ( v78 == 99 || v78 == 67 )
        {
          v118[v69 - 1] = 2;
        }
        v79 = v76[i + 1];
        v76[i] = 0;
        if ( v79 )
          *(unsigned int *)((char *)&STACK[0x1328] + v69 * 4) = j__atol(&v76[i + 1]);
      }
    }
    *(int *)((char *)&a13 + v69 * 4) = j__atol(v76);
    ++v69;
  }
  v80 = *(const CHAR **)(v67 + 160);
  if ( !v80 )
    v80 = WindowName;
  sub_630FE0(&STACK[0x13A4], v80, 255);
  LOBYTE(STACK[0x14A3]) = 0;
  v81 = sub_6331DF(&STACK[0x13A4], &word_6FD924);
  LOBYTE(STACK[0x14A4]) = 0;
  memset(&STACK[0x14A5], 0, 0xFCu);
  LOWORD(STACK[0x15A1]) = 0;
  LOBYTE(STACK[0x15A3]) = 0;
  memset(&STACK[0x15A4], 0, 0xE00u);
  v82 = 0;
  v109 = 0;
  if ( v81 )
  {
    v83 = &STACK[0x14A4];
    do
    {
      if ( v82 >= 15 )
        break;
      sub_630FE0(v83, v81, 255);
      *((_BYTE *)v83 + 255) = 0;
      ++v82;
      v83 += 64;
      v81 = sub_6331DF(0, &word_6FD924);
    }
    while ( v81 );
    v109 = v82;
  }
  v84 = *(_DWORD *)(v67 + 8);
  v85 = *(_DWORD *)(v67 + 12);
  v113 = *(_DWORD *)(v67 + 4);
  v86 = *(_DWORD *)(v67 + 16);
  v87 = 0;
  v114 = v84;
  v111 = v85;
  v112 = v86;
  if ( v82 <= 0 )
    return 0;
  v88 = (const char *)&STACK[0x14A4];
  while ( 1 )
  {
    v115 = strlen(v88);
    if ( v115 )
      break;
LABEL_54:
    ++v87;
    v88 += 256;
    v104 = v88;
    if ( v87 >= v82 )
      return 0;
  }
  sub_4D8B10();
  a28 = &off_711A70;
  LOBYTE(STACK[0x1320]) = 1;
  STACK[0x131C] = -1;
  v89 = *(_DWORD *)(v67 + 48);
  v90 = *(_DWORD *)(v67 + 152);
  STACK[0x1318] = v118[v87 - 1];
  v91 = *(_DWORD *)(v67 + 156);
  STACK[0x23B0] = 0;
  a40 = v89;
  a65 = v90;
  a66 = v91;
  if ( v87 < 4 )
  {
    v92 = *(_BYTE *)(v87 + 300 + v67);
    if ( v92 > -1 )
    {
      v93 = *(const CHAR **)(v67 + 276);
      if ( !v93 )
        v93 = WindowName;
      if ( v92 == 2 )
      {
        v93 = *(const CHAR **)(v67 + 284);
        if ( !v93 )
          v93 = WindowName;
      }
      sub_4DF1B0(v89, v93);
    }
  }
  sub_615860(v88);
  v94 = *(&a13 + v87);
  v95 = v109 + *(&a12 + v87);
  if ( v94 <= 0 )
    v96 = v111;
  else
    v96 = v109 + v94 - *(&STACK[0x1324] + v87);
  if ( v95 <= v96 )
  {
    v101 = v113;
    LOBYTE(STACK[0x131C]) = *(_BYTE *)(v67 + 272);
    sub_4E2A80(v112, v101, v95, v96);
    v97 = STACK[0x12FC];
    v98 = STACK[0x12FC] == 0;
    STACK[0x1318] = v96 - v95;
    if ( !v98 )
    {
      if ( a52 )
        v99 = *(const CHAR **)(v97 + 88);
      else
        v99 = *(const CHAR **)(v97 + 64);
      if ( !v99 )
        v99 = WindowName;
      sub_4DF1B0(a39, v99);
    }
    sub_4D0610((int)&a26, (int)v116, (int)&v114, (int)&v115, (int)&v113);
    STACK[0x23A8] = -1;
    a26 = &off_711A70;
    sub_4D82A0(v67, v102);
    v88 = v104;
    v82 = v105;
    goto LABEL_54;
  }
  STACK[0x23AC] = -1;
  a27 = &off_711A70;
  sub_4D82A0(v67, v103);
  return -1;
}
