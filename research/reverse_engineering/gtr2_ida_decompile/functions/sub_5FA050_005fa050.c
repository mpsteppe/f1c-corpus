int __usercall sub_5FA050@<eax>(
        int a1@<ebx>,
        int a2@<ebp>,
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
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        char Buffer)
{
  int *v57; // ecx
  int *v58; // ebp
  _DWORD *v59; // eax
  int v60; // ecx
  _DWORD *v61; // eax
  _DWORD *v62; // esi
  _DWORD *v63; // eax
  int v64; // edi
  _DWORD *v65; // eax
  _DWORD *v66; // esi
  _DWORD *v67; // eax
  int *v68; // esi
  _DWORD *v69; // eax
  int *v70; // esi
  int v71; // edx
  int v72; // eax
  int v73; // eax
  int v74; // eax
  int v75; // esi
  int v76; // edx
  _DWORD *v77; // ecx
  const char *v78; // esi
  int v79; // edx
  char v81; // [esp-10h] [ebp-9Ch]
  const char *v82; // [esp+0h] [ebp-8Ch]
  char *Block; // [esp+8h] [ebp-84h]
  void *v84; // [esp+Ch] [ebp-80h] BYREF
  const char *v85; // [esp+10h] [ebp-7Ch]
  const char *v86; // [esp+14h] [ebp-78h]
  int v87; // [esp+18h] [ebp-74h]
  int v88; // [esp+1Ch] [ebp-70h] BYREF
  char v89; // [esp+20h] [ebp-6Ch] BYREF
  const char *v90; // [esp+34h] [ebp-58h]
  char v91[4]; // [esp+4Ch] [ebp-40h] BYREF
  char *v92; // [esp+50h] [ebp-3Ch]
  size_t v93; // [esp+54h] [ebp-38h]
  int v94; // [esp+58h] [ebp-34h]
  const char *v95; // [esp+5Ch] [ebp-30h]
  int v96; // [esp+60h] [ebp-2Ch]
  int v97; // [esp+64h] [ebp-28h]
  char *v98; // [esp+68h] [ebp-24h]
  size_t v99; // [esp+6Ch] [ebp-20h]
  int v100; // [esp+70h] [ebp-1Ch]
  int v101; // [esp+74h] [ebp-18h]
  int v102; // [esp+78h] [ebp-14h]
  int v103; // [esp+7Ch] [ebp-10h]
  _DWORD *v104; // [esp+84h] [ebp-8h]

  sub_631BD0();
  v103 = a1;
  v102 = a2;
  v58 = v57;
  v101 = a4;
  v100 = a3;
  v59 = v57 + 2271;
  v60 = 6;
  do
  {
    v59[6] = 0;
    *v59 = 0;
    *(v59 - 6) = 0;
    ++v59;
    --v60;
  }
  while ( v60 );
  v61 = operator new(0x180u);
  v104 = v61;
  STACK[0x1408] = 0;
  if ( v61 )
  {
    v99 = (size_t)sub_5F77C0;
    v98 = (char *)sub_5F8040;
    v97 = 1;
    v62 = v61 + 1;
    v96 = 380;
    v95 = (const char *)(v61 + 1);
    *v61 = 1;
    sub_630A11(v95, v96, v97, v98, v99);
  }
  else
  {
    v62 = 0;
  }
  v99 = 63;
  v98 = "Screen space";
  v97 = (int)(v62 + 67);
  STACK[0x1408] = -1;
  sub_630FE0(v97);
  v96 = 63;
  *((_BYTE *)v62 + 280) = 0;
  v95 = "fvf_screenT0";
  sub_630FE0(v62 + 51);
  *((_BYTE *)v62 + 216) = 0;
  v62[90] = 0;
  v62[86] = 0;
  v62[87] = 0;
  v93 = 12;
  v62[90] = 324;
  v62[85] = 0;
  v63 = operator new(v93);
  if ( v63 )
  {
    *v63 = v62;
    v63[1] = 0;
    *((_BYTE *)v63 + 8) = 0;
  }
  else
  {
    v63 = 0;
  }
  if ( v58[2336] )
  {
    *(_DWORD *)(v58[2337] + 4) = v63;
  }
  else
  {
    v58[2336] = (int)v63;
    v58[2338] = (int)v63;
  }
  v64 = v58[2339] + 1;
  v99 = 384;
  v58[2337] = (int)v63;
  v58[2339] = v64;
  v65 = operator new(v99);
  v104 = v65;
  STACK[0x1408] = 1;
  if ( v65 )
  {
    v99 = (size_t)sub_5F77C0;
    v98 = (char *)sub_5F8040;
    v97 = 1;
    v66 = v65 + 1;
    v96 = 380;
    v95 = (const char *)(v65 + 1);
    *v65 = 1;
    sub_630A11(v95, v96, v97, v98, v99);
  }
  else
  {
    v66 = 0;
  }
  v97 = (int)(v66 + 67);
  STACK[0x1408] = -1;
  sub_630FE0(v97);
  v96 = 63;
  *((_BYTE *)v66 + 283) = 0;
  v95 = "default";
  sub_630FE0(v66 + 51);
  *((_BYTE *)v66 + 211) = 0;
  v66[90] = 0;
  v66[86] = 0;
  v66[87] = 0;
  LOBYTE(v99) = 0;
  v98 = (char *)v66;
  v66[90] = 1234;
  v66[85] = 3;
  sub_5FDFB0(v98, v99);
  v67 = operator new(0x194u);
  v104 = v67;
  STACK[0x1408] = 2;
  if ( v67 )
  {
    v99 = (size_t)sub_5F77C0;
    v98 = (char *)sub_5F76A0;
    v97 = 1;
    v68 = v67 + 1;
    v96 = 400;
    v95 = (const char *)(v67 + 1);
    *v67 = 1;
    sub_630A11(v95, v96, v97, v98, v99);
  }
  else
  {
    v68 = 0;
  }
  v99 = 63;
  v98 = "Level 0 default";
  v97 = (int)(v68 + 67);
  STACK[0x1408] = -1;
  sub_5D8EF0(v97, v98, v99);
  sub_5D8EF0((int)(v68 + 51), "default", 63);
  v99 = 1;
  v98 = (char *)v68;
  v68[94] = 0;
  v68[98] = 0x10000;
  v68[96] = 0;
  v68[97] = 0;
  sub_5F84A0((int *)v98, v99);
  v99 = 1;
  sub_5F7920((int)(v58 + 2285), (int)v68);
  v96 = 3;
  sub_5F7970((int)(v58 + 2285), (int)v68);
  v69 = operator new(0x194u);
  v104 = v69;
  STACK[0x1408] = 3;
  if ( v69 )
  {
    v99 = (size_t)sub_5F77C0;
    v98 = (char *)sub_5F76A0;
    v97 = 1;
    v70 = v69 + 1;
    v96 = 400;
    v95 = (const char *)(v69 + 1);
    *v69 = 1;
    sub_630A11(v95, v96, v97, v98, v99);
  }
  else
  {
    v70 = 0;
  }
  v99 = 63;
  v98 = "Level 1/2 default";
  v97 = (int)(v70 + 67);
  STACK[0x1408] = -1;
  sub_5D8EF0(v97, v98, v99);
  sub_5D8EF0((int)(v70 + 51), "none", 63);
  v99 = 0;
  v98 = (char *)v70;
  v70[94] = 0;
  v70[98] = 0;
  v70[96] = 0;
  v70[97] = 0;
  sub_5F84A0((int *)v98, v99);
  v71 = *v58;
  v99 = 0;
  v98 = "Screen space shader";
  v97 = (int)"default";
  v96 = (int)"fvf_screenT0";
  v95 = "Screen space";
  v94 = 0;
  v93 = (size_t)"L0SCREENT0";
  if ( !(*(int (__thiscall **)(int *))(v71 + 616))(v58) )
  {
    v92 = "Error creating screen space shader";
LABEL_23:
    sub_5D8C80((int)(v58 + 1), (char *)0xFFFFFFFF, v92, v93);
    sub_5D8CE0();
    return off_16C96F4(1234, 324);
  }
  v72 = *v58;
  v92 = (char *)1;
  if ( !(*(int (__thiscall **)(int *, const char *, int, const char *, const char *, const char *, const char *))(v72 + 616))(
          v58,
          "L0NOLIGHTING",
          1,
          "Default",
          "default",
          "default",
          "Level 0 multitexture - one texture.") )
  {
    v90 = "Error creating level 0 default shader";
    goto LABEL_23;
  }
  if ( !(*(int (__thiscall **)(int *, const char *, int, const char *, const char *, const char *, const char *, int))(*v58 + 616))(
          v58,
          "L1USEVERTEXONLY",
          2,
          "Default",
          "default",
          "none",
          "Default to Level 0.",
          1) )
  {
    v87 = (int)"Error creating level 1 default shader";
    goto LABEL_23;
  }
  v73 = *v58;
  v87 = 1;
  v86 = "Default to Level 1.";
  v85 = "none";
  v84 = "default";
  Block = "Default";
  v82 = "L2USEVERTEXPIXEL";
  if ( !(*(int (__thiscall **)(int *))(v73 + 616))(v58) )
    goto LABEL_23;
  if ( !*((_BYTE *)v58 + 124) )
  {
    v88 = (int)v58 + 381;
    sub_5D9420(v58 + 1, (int)v58 + 381, 0);
    dword_FB2874 = (int)dword_FB286C;
    if ( dword_FB286C && (v74 = *(_DWORD *)dword_FB286C) != 0 )
    {
      while ( 1 )
      {
        sprintf(&Buffer, "%s\\%s", (const char *)(v74 + 4), "*.GFX");
        Block = (char *)FindFirstFileA(&Buffer, (LPWIN32_FIND_DATAA)&v89);
        if ( Block != (char *)-1 )
          break;
LABEL_37:
        if ( dword_FB2874 )
        {
          dword_FB2874 = *(_DWORD *)(dword_FB2874 + 4);
          if ( dword_FB2874 )
          {
            v74 = *(_DWORD *)dword_FB2874;
            if ( *(_DWORD *)dword_FB2874 )
              continue;
          }
        }
        goto LABEL_40;
      }
      while ( 1 )
      {
        v75 = sub_5E0740(v58 + 1, v91, 0);
        if ( !v75 )
          break;
        sub_5DECA0(&STACK[0x360]);
        STACK[0x368] = *(_DWORD *)(v75 + 8);
        v76 = *v58;
        STACK[0xB70] = *(_DWORD *)v75;
        STACK[0x1390] = 4;
        if ( (*(int (__thiscall **)(int *, unsigned int *))(v76 + 608))(v58, &STACK[0x360]) )
        {
          sub_5DF6E0((void **)v75);
          sub_5D8CE0();
          STACK[0x138C] = -1;
          nullsub_7(&STACK[0x35C]);
          return off_16C96F4(1234, 324);
        }
        sub_5DF6E0((void **)v75);
        STACK[0x138C] = -1;
        nullsub_7(&STACK[0x35C]);
        if ( !FindNextFileA(HANDLE_FLAG_PROTECT_FROM_CLOSE|HANDLE_FLAG_INHERIT, (LPWIN32_FIND_DATAA)&v88) )
        {
          FindClose(HANDLE_FLAG_PROTECT_FROM_CLOSE|HANDLE_FLAG_INHERIT);
          goto LABEL_37;
        }
      }
LABEL_53:
      sub_5D8C80((int)(v58 + 1), (char *)0xFFFFFFFF, "Error opening shader file %s", v81);
    }
    else
    {
LABEL_40:
      if ( sub_5EE940(v58 + 1, (char **)&v84, (char *)v58 + 125, 0) )
      {
        sub_5D9900(v58 + 1, (int)v85, 0);
        sub_5D8C80((int)(v58 + 1), (char *)0xFFFFFFFF, "Error opening core shaders MAS file %s", (_BYTE)v58 + 125);
        sub_5D8CE0();
      }
      else
      {
        v77 = v84;
        if ( *((int *)v84 + 69) > 0 )
        {
          do
          {
            v78 = (const char *)(sub_592C70(v77, 0) + 16);
            if ( strstr(v78, ".GFX") )
            {
              Block = (char *)sub_5E0740(v58 + 1, v78, 0);
              if ( !Block )
              {
                v81 = (char)v78;
                goto LABEL_53;
              }
              sub_5DECA0(&STACK[0xB70]);
              v79 = *v58;
              STACK[0xB78] = *((_DWORD *)Block + 2);
              STACK[0x1380] = *(_DWORD *)Block;
              STACK[0x138C] = 5;
              if ( (*(int (__thiscall **)(int *, unsigned int *))(v79 + 608))(v58, &STACK[0xB70]) )
              {
                sub_5DF6E0((void **)Block);
                sub_5D8CE0();
                STACK[0x1388] = -1;
                nullsub_7(&STACK[0xB6C]);
                return off_16C96F4(1234, 324);
              }
              sub_5DF6E0((void **)Block);
              STACK[0x1388] = -1;
              nullsub_7(&STACK[0xB6C]);
            }
            v77 = Block;
            ++v82;
          }
          while ( (int)v82 < *((_DWORD *)Block + 69) );
        }
        sub_5EEA30((int)(v58 + 1), (int)(v58 + 1), v77, 0);
        sub_5D9900(v58 + 1, (int)v84, 0);
      }
    }
  }
  return off_16C96F4(1234, 324);
}
