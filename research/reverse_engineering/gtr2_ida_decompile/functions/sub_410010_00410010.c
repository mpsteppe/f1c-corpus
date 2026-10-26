int __userpurge sub_410010@<eax>(
        char a1@<cl>,
        int a2@<ebx>,
        int a3@<esi>,
        int a4,
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
        char a23)
{
  _DWORD *v23; // ecx
  _DWORD *v24; // ebx
  int v25; // esi
  int v26; // eax
  unsigned int *v27; // edi
  int *v28; // eax
  _DWORD *v29; // edi
  int v30; // edi
  int v31; // esi
  _DWORD v33[3]; // [esp+8D74h] [ebp-18h] BYREF
  _BYTE v34[12]; // [esp+8D80h] [ebp-Ch] BYREF

  sub_631BD0(a1);
  v33[1] = a2;
  v33[0] = a3;
  v24 = v23;
  sub_613B30(v34);
  v25 = 0;
  memset(&STACK[0x8FF8], 0, 0x200u);
  STACK[0x11B04] = 0;
  STACK[0x8FE0] = 0;
  STACK[0x8FF4] = 0;
  STACK[0x8FEC] = 0;
  STACK[0x8FF0] = 0;
  LOBYTE(STACK[0x8FE4]) = 1;
  sub_630A11(&STACK[0x92F8], 272, 128, dword_46DF20, sub_46E030);
  LOBYTE(STACK[0x11B04]) = 1;
  v26 = sub_5E5670(aMainview, 0);
  if ( v26 )
    v24[1] = v26;
  if ( !(unsigned __int8)sub_614460(a4, 1) || !sub_613DE0((char *)&STACK[0x8FF8], 512) )
    goto LABEL_19;
  v27 = &STACK[0x92F8];
  do
  {
    if ( !sub_612EB0(&a23) && sub_6137E0(&a23) && v25 < 128 )
    {
      sub_46E0E0(v33, &STACK[0x91EC]);
      ++v25;
      v27 += 68;
    }
  }
  while ( sub_613DE0((char *)&STACK[0x8FEC], 512) );
  if ( v25 > 0 )
  {
    v28 = (int *)operator new(272 * v25 + 4);
    LOBYTE(STACK[0x11AF8]) = 2;
    if ( v28 )
    {
      v29 = v28 + 1;
      *v28 = v25;
      sub_630A11(v28 + 1, 272, v25, dword_46DF20, sub_46E030);
    }
    else
    {
      v29 = 0;
    }
    v24[3] = v29;
    v30 = 0;
    LOBYTE(STACK[0x11AF8]) = 1;
    v24[4] = v25;
    v24[5] = 0;
    v31 = 0;
    do
    {
      sub_46D340((char *)&STACK[0x92EC] + v31);
      ++v30;
      v31 += 272;
    }
    while ( v30 < v24[4] );
    LOBYTE(STACK[0x11AF8]) = 0;
    `eh vector destructor iterator'(&STACK[0x92EC], 0x110u, 128, sub_46E030);
    STACK[0x11AF8] = -1;
    sub_614140(v33);
    return 0;
  }
  else
  {
LABEL_19:
    LOBYTE(STACK[0x11AF8]) = 0;
    `eh vector destructor iterator'(&STACK[0x92EC], 0x110u, 128, sub_46E030);
    STACK[0x11AF8] = -1;
    sub_614140(v33);
    return 1;
  }
}
