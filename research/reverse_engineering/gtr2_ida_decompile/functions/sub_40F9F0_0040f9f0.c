int __userpurge sub_40F9F0@<eax>(
        char a1@<cl>,
        int a2,
        int a3,
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
        char a21)
{
  _DWORD *v21; // ecx
  _DWORD *v22; // ebx
  int v23; // esi
  int v24; // eax
  unsigned int *v26; // edi
  int *v27; // eax
  _DWORD *v28; // edi
  int v29; // edi
  int v30; // esi
  int v31; // [esp+5770h] [ebp-1Ch]
  _BYTE v32[8]; // [esp+5774h] [ebp-18h] BYREF
  int v33; // [esp+577Ch] [ebp-10h]
  _BYTE v34[12]; // [esp+5780h] [ebp-Ch] BYREF

  sub_631BD0(a1);
  v22 = v21;
  sub_613B30(v34);
  v23 = 0;
  memset(&STACK[0x59F8], 0, 0x200u);
  STACK[0xAF04] = 0;
  STACK[0x59E0] = 0;
  STACK[0x59F4] = 0;
  STACK[0x59EC] = 0;
  STACK[0x59F0] = 0;
  LOBYTE(STACK[0x59E4]) = 1;
  v33 = 1;
  sub_630A11(&STACK[0x5CF8], 164, 128, sub_46B930, sub_46B2D0);
  LOBYTE(STACK[0xAF04]) = 1;
  v24 = sub_5E5670(aMainview, 0);
  if ( v24 )
    v22[1] = v24;
  if ( (unsigned __int8)sub_614460(a2, 1) )
  {
    if ( sub_613DE0((char *)&STACK[0x59F8], 512) )
    {
      v26 = &STACK[0x5CF8];
      do
      {
        if ( !sub_612EB0(&a21) && sub_6137E0(&a21) && v23 < 128 )
        {
          sub_46B9C0(v32, &STACK[0x5BEC]);
          ++v23;
          v26 += 41;
        }
      }
      while ( sub_613DE0((char *)&STACK[0x59EC], 512) );
      if ( v23 > 0 )
      {
        v27 = (int *)operator new(164 * v23 + 4);
        LOBYTE(STACK[0xAEF8]) = 2;
        if ( v27 )
        {
          v28 = v27 + 1;
          *v27 = v23;
          sub_630A11(v27 + 1, 164, v23, sub_46B930, sub_46B2D0);
        }
        else
        {
          v28 = 0;
        }
        v22[3] = v28;
        v29 = 0;
        LOBYTE(STACK[0xAEF8]) = 1;
        v22[4] = v23;
        v22[5] = 0;
        v30 = 0;
        do
        {
          sub_46C0B0((char *)&STACK[0x5CEC] + v30);
          ++v29;
          v30 += 164;
        }
        while ( v29 < v22[4] );
        v31 = 0;
      }
    }
    sub_613C30(v32);
    LOBYTE(STACK[0xAEF8]) = 0;
    `eh vector destructor iterator'(&STACK[0x5CEC], 0xA4u, 128, sub_46B2D0);
    STACK[0xAEF8] = -1;
    sub_614140(v32);
    return v31;
  }
  else
  {
    LOBYTE(STACK[0xAF04]) = 0;
    `eh vector destructor iterator'(&STACK[0x5CF8], 0xA4u, 128, sub_46B2D0);
    STACK[0xAF04] = -1;
    sub_614140(v34);
    return 1;
  }
}
