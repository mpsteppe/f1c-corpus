int __usercall sub_497510@<eax>(int a1@<ecx>, int a2@<ebp>)
{
  int result; // eax
  int v4; // edi
  const char *v5; // ebx
  const char *v6; // eax
  const char *v7; // ebp
  const CHAR *v8; // ebx
  int v9; // edi
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  int v15; // edi
  int v16; // ebx
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // ebp
  const char *v20; // eax
  int v21; // [esp+28h] [ebp-36Ch]
  double v22; // [esp+2Ch] [ebp-368h]
  const char *v23; // [esp+2Ch] [ebp-368h]
  char *v24; // [esp+30h] [ebp-364h]
  char *v25; // [esp+30h] [ebp-364h]
  const char *v26; // [esp+30h] [ebp-364h]
  const char *v27; // [esp+30h] [ebp-364h]
  const char *v28; // [esp+30h] [ebp-364h]
  int v30; // [esp+44h] [ebp-350h] BYREF
  const char *v31; // [esp+48h] [ebp-34Ch]
  float v32; // [esp+4Ch] [ebp-348h] BYREF
  int v33; // [esp+50h] [ebp-344h] BYREF
  _DWORD v34[2]; // [esp+58h] [ebp-33Ch] BYREF
  char v35; // [esp+60h] [ebp-334h] BYREF
  void *v36; // [esp+64h] [ebp-330h]
  char v37[12]; // [esp+68h] [ebp-32Ch] BYREF
  char v38[12]; // [esp+74h] [ebp-320h] BYREF
  char v39[12]; // [esp+80h] [ebp-314h] BYREF
  char v40[8]; // [esp+8Ch] [ebp-308h] BYREF
  char Buffer[256]; // [esp+94h] [ebp-300h] BYREF
  char v42[136]; // [esp+194h] [ebp-200h] BYREF
  char v43[64]; // [esp+21Ch] [ebp-178h] BYREF
  int v44; // [esp+25Ch] [ebp-138h]
  int v45; // [esp+264h] [ebp-130h]
  int v46; // [esp+268h] [ebp-12Ch]
  int v47; // [esp+26Ch] [ebp-128h]
  int v48; // [esp+270h] [ebp-124h]
  int v49; // [esp+274h] [ebp-120h]
  int v50; // [esp+278h] [ebp-11Ch]
  int v51; // [esp+27Ch] [ebp-118h]
  float v52; // [esp+280h] [ebp-114h]
  char v53[264]; // [esp+28Ch] [ebp-108h] BYREF

  v32 = 0.0;
  strcpy((char *)v34, "NOVICE");
  strcpy(v39, "SEMI-PRO");
  strcpy(v37, "SIMULATION");
  strcpy(v38, "Changeable");
  strcpy(v40, "Raining");
  v36 = &unk_797244;
  strcpy(Buffer, "Monsoon");
  sub_4D0AC0(v30);
  sub_4CE140(a1, &v32);
  result = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 53);
  v4 = result;
  if ( result )
  {
    result = sub_4CE170(result);
    if ( result )
    {
      v5 = *(const char **)dword_BE121C;
      if ( !*(_DWORD *)dword_BE121C )
        v5 = WindowName;
      v6 = (const char *)sub_4CE170(v4);
      sub_41D810(v53, 0xFFu, "%s%s.GTT", v5, v6);
      result = sub_523D70(v53, v42);
      if ( (_BYTE)result )
      {
        v32 = v52;
        v7 = 0;
        switch ( v44 )
        {
          case 0:
            v7 = &v37[4];
            break;
          case 1:
            v7 = (const char *)&v34[1];
            break;
          case 2:
            v7 = &v39[4];
            break;
          case 3:
            v7 = v40;
            break;
          default:
            break;
        }
        if ( v45 )
        {
          if ( v45 == 1 )
            v31 = &v38[4];
          else
            v31 = &v35;
        }
        else
        {
          v31 = (const char *)&v33;
        }
        v8 = *(const CHAR **)(*(_DWORD *)(a1 + 244) + 88);
        if ( !v8 )
          v8 = WindowName;
        v9 = sub_4CF8C0(a1);
        v10 = (const char *)sub_4CFC00(0);
        sprintf(Buffer, "%s%s %s", v10, (const char *)&v30, v43);
        sub_4D93B0(Buffer, 0, v8, 0, 0, v9, 1, 2, -1, -1);
        v11 = (const char *)sub_4CFC00(1);
        sprintf(Buffer, "%s%s %s", v11, (const char *)&v30, v42);
        sub_4D93B0(Buffer, 0, v8, 0, 0, v9, 1, 2, -1, -1);
        v34[0] = 60 * ((int)(unsigned __int64)v32 / 60);
        v22 = v32 - (double)v34[0];
        v21 = (int)(unsigned __int64)v32 / 60;
        v12 = (const char *)sub_4CFC00(2);
        sprintf(Buffer, "%s%s %i:%06.3f", v12, (const char *)&v30, v21, v22);
        sub_4D93B0(Buffer, 0, v8, 0, 0, v9, 1, 2, -1, -1);
        v24 = sub_41D840(&byte_91CC38, v7);
        v13 = (const char *)sub_4CFC00(3);
        sprintf(Buffer, "%s%s %s", v13, (const char *)&v30, v24);
        sub_4D93B0(Buffer, 0, v8, 0, 0, v9, 1, 2, -1, -1);
        v25 = sub_41D840(&byte_91CC38, v31);
        v14 = (const char *)sub_4CFC00(4);
        sprintf(Buffer, "%s%s %s", v14, (const char *)&v30, v25);
        sub_4D93B0(Buffer, 0, v8, 0, 0, v9, 1, 2, -1, -1);
        v15 = sub_4CF8E0(a1, a2);
        v16 = sub_4CF900(a1);
        v26 = (const char *)sub_4CFC00(7);
        v17 = (const char *)sub_4CFC00(6);
        sprintf(Buffer, "%s%s %s", v17, (const char *)&v30, v26);
        sub_4D93B0(Buffer, 0, v15, 0, 0, v16, (v46 == 0) + 1, (v49 == 0) + 1, -1, -1);
        v27 = (const char *)sub_4CFC00(9);
        v18 = (const char *)sub_4CFC00(8);
        sprintf(Buffer, "%s%s %s", v18, (const char *)&v30, v27);
        sub_4D93B0(Buffer, 0, v15, 0, 0, v16, (v47 == 0) + 1, (v48 == 0) + 1, -1, -1);
        v19 = (const char *)sub_4CFC00(v50 + 12);
        v28 = (const char *)sub_4CFC00(v51 + 12);
        v23 = (const char *)sub_4CFC00(11);
        v20 = (const char *)sub_4CFC00(10);
        sub_41D810(Buffer, 0xFFu, "%s: %s%s %s: %s", v20, v19, (const char *)&v30, v23, v28);
        return off_16C95AC();
      }
    }
  }
  return result;
}
