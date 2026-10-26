void __usercall sub_570690(
        int a1@<edi>,
        int a2@<esi>,
        int a3,
        int a4,
        void *Block,
        int a6,
        void *a7,
        int a8,
        int a9,
        int a10,
        int a11,
        _DWORD *a12,
        char a13,
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
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        char a37)
{
  int v37; // ecx
  int v38; // ebx
  int v39; // esi
  const CHAR *v40; // eax
  const CHAR *v41; // eax
  int v42; // edx
  CHAR v43; // cl
  unsigned int *v44; // eax
  char *v45; // edi
  int v47; // ebp
  void *v48; // edi
  _DWORD *v49; // eax
  int *v50; // ecx
  int *v51; // ecx
  int v52; // esi
  int v53; // ebp
  void *v54; // eax
  bool v55; // zf
  char *v56; // esi
  float retaddr; // [esp+432Ch] [ebp+4h] BYREF

  sub_631BD0();
  v38 = v37;
  sub_435800(a1, a2);
  v39 = 0;
  STACK[0x8654] = 0;
  sub_5875F0(&STACK[0x49D0]);
  v40 = *(const CHAR **)(dword_BE1BD8 + 2824 * *(_DWORD *)(*(_DWORD *)v38 + 22472) + 8);
  LOBYTE(STACK[0x8654]) = 1;
  if ( !v40 )
    v40 = WindowName;
  sub_5886A0(v40, &STACK[0x67A0], 2);
  v41 = (const CHAR *)STACK[0x49F4];
  if ( !STACK[0x49F4] )
    v41 = WindowName;
  v42 = (char *)&STACK[0x47D0] - v41;
  do
  {
    v43 = *v41;
    v41[v42] = *v41;
    ++v41;
  }
  while ( v43 );
  if ( byte_B71E28 )
  {
    v44 = (unsigned int *)((char *)&STACK[0x47D0] + strlen((const char *)&STACK[0x47D0]));
    if ( v44 > &STACK[0x47D0] )
    {
      while ( *(_BYTE *)v44 != 46 )
      {
        v44 = (unsigned int *)((char *)v44 - 1);
        if ( v44 <= &STACK[0x47D0] )
          goto LABEL_13;
      }
      *(_BYTE *)v44 = 0;
    }
LABEL_13:
    v45 = (char *)&STACK[0x47CF];
    while ( *++v45 )
      ;
    strcpy(v45, "_LOW.DMG");
  }
  *(float *)&a3 = 1.0;
  a4 = 0;
  Block = 0;
  a6 = 0;
  a7 = 0;
  LOBYTE(STACK[0x8654]) = 2;
  v47 = 0;
  sub_613B30(&a13);
  memset(&STACK[0x45D0], 0, 0x200u);
  v48 = 0;
  LOBYTE(STACK[0x8654]) = 3;
  STACK[0x45B8] = 0;
  STACK[0x45CC] = 0;
  STACK[0x45C4] = 0;
  STACK[0x45C8] = 0;
  LOBYTE(STACK[0x45BC]) = 1;
  if ( (unsigned __int8)sub_614460(&STACK[0x47D0], 1) )
  {
    while ( sub_613DE0((char *)&STACK[0x45D0], 512) )
    {
      if ( !sub_612EB0(&a37) )
      {
        if ( sub_6134B0("RestrictionSphere", (int)&a8, (int)&a9, (int)&a10, (int)&retaddr, 0, 0, 0, 0) )
          ++v47;
        if ( sub_6134B0("ForceFieldSphere", (int)&a8, (int)&a9, (int)&a10, (int)&retaddr, 0, 0, 0, 0) )
          ++v39;
      }
    }
    v49 = operator new(24 * v39 + 4);
    a12 = v49;
    LOBYTE(STACK[0x8654]) = 4;
    if ( v49 )
    {
      v48 = v49 + 1;
      *v49 = v39;
      sub_630A11(v49 + 1, 24, v39, sub_569660, sub_568D80);
    }
    LOBYTE(STACK[0x8654]) = 3;
    a7 = v48;
    Block = operator new(20 * v47);
    sub_613F20(&a13);
    *(float *)&a11 = 1.0;
    while ( sub_613DE0((char *)&STACK[0x45D0], 512) )
    {
      if ( !sub_612EB0(&a37) )
      {
        if ( sub_6134B0("DefaultLimit", (int)&a3, 0, 0, 0, 0, 0, 0, 0) )
          *(float *)&a3 = *(float *)&a3 * *(float *)&a3;
        sub_6134B0("RestrictionLimit", (int)&a11, 0, 0, 0, 0, 0, 0, 0);
        if ( sub_6134B0("RestrictionSphere", (int)&a8, (int)&a9, (int)&a10, (int)&retaddr, 0, 0, 0, 0) )
        {
          v50 = (int *)((char *)Block + 20 * a4);
          *v50 = a8;
          v50[1] = a9;
          v50[2] = a10;
          *((float *)Block + 5 * a4 + 3) = retaddr * retaddr;
          *((float *)Block + 5 * a4++ + 4) = *(float *)&a11 * *(float *)&a11;
        }
        if ( sub_6134B0("ForceFieldSphere", (int)&a8, (int)&a9, (int)&a10, (int)&retaddr, 0, 0, 0, 0) )
        {
          v51 = (int *)((char *)a7 + 24 * a6);
          *v51 = a8;
          v51[1] = a9;
          v51[2] = a10;
          *((float *)a7 + 6 * a6 + 3) = retaddr * retaddr;
          *((_DWORD *)a7 + 6 * a6 + 4) = 0;
          *((_DWORD *)a7 + 6 * a6++ + 5) = 0;
        }
      }
    }
    sub_613C30(&a13);
  }
  *(_DWORD *)(v38 + 3868) = 1;
  sub_56D410(0, (int)&a3, v38 + 8);
  if ( *(_DWORD *)(v38 + 1648) && *(_BYTE *)(v38 + 1712) && *(_BYTE *)(v38 + 1713) )
  {
    ++*(_DWORD *)(v38 + 3868);
    sub_56D410(0, (int)&a3, v38 + 1648);
  }
  if ( *(_DWORD *)(v38 + 1716) && *(_BYTE *)(v38 + 1780) && *(_BYTE *)(v38 + 1781) )
  {
    ++*(_DWORD *)(v38 + 3868);
    sub_56D410(0, (int)&a3, v38 + 1716);
  }
  v52 = v38 + 1784;
  v53 = 8;
  do
  {
    if ( *(_DWORD *)v52 && *(_BYTE *)(v52 + 64) && *(_BYTE *)(v52 + 65) )
    {
      ++*(_DWORD *)(v38 + 3868);
      sub_56D410(0, (int)&a3, v52);
    }
    v52 += 68;
    --v53;
  }
  while ( v53 );
  LOBYTE(STACK[0x8654]) = 2;
  sub_614140(&a13);
  v54 = Block;
  v55 = Block == 0;
  LOBYTE(STACK[0x8654]) = 1;
  if ( !v55 )
    j_j__free(v54);
  if ( a7 )
  {
    v56 = (char *)a7 - 4;
    `eh vector destructor iterator'(a7, 0x18u, *((_DWORD *)a7 - 1), (void (__thiscall *)(void *))sub_568D80);
    j_j__free(v56);
  }
  if ( STACK[0x49FC] )
    j_j__free((void *)STACK[0x49FC]);
  if ( STACK[0x49F4] )
    j_j__free((void *)STACK[0x49F4]);
  if ( STACK[0x49EC] )
    j_j__free((void *)STACK[0x49EC]);
  if ( STACK[0x49E4] )
    j_j__free((void *)STACK[0x49E4]);
  if ( STACK[0x49DC] )
    j_j__free((void *)STACK[0x49DC]);
  if ( STACK[0x49D0] )
    j_j__free((void *)STACK[0x49D0]);
  STACK[0x8654] = 5;
  sub_431A70(&STACK[0x8290]);
  if ( STACK[0x6808] )
    j_j__free((void *)STACK[0x6808]);
}
