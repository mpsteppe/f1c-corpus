int __userpurge sub_5FF750@<eax>(
        int *a1@<ecx>,
        __int32 a2@<ebx>,
        int a3@<edi>,
        int a4,
        int a5,
        _DWORD *a6,
        float a7,
        int a8,
        int a9)
{
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v17; // [esp+18h] [ebp-4h]

  if ( !a4 )
  {
    sub_5D8C80((int)a1, (char *)0xFFFFFFFF, "Invalid scene parameter.", v17);
    return -1;
  }
  v11 = a9;
  a1[75] = a4;
  *a1 |= v11;
  (*(void (__thiscall **)(int, _DWORD, _DWORD, int *, int))(*(_DWORD *)dword_FB27A4 + 636))(dword_FB27A4, 0, 0, &a4, a3);
  if ( a5 == 514 || a5 == 1028 || a5 == 1032 )
  {
    v14 = *(_DWORD *)dword_FB27A4;
    if ( (*a1 & 0x100) != 0 )
    {
      a1[70] = (*(int (__stdcall **)(const char *))(v14 + 632))("L1PROJECTSTRIP");
      v13 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
              dword_FB27A4,
              "L1PROJECTBUMPSTRIP",
              0);
      goto LABEL_14;
    }
    a1[70] = (*(int (__stdcall **)(const char *, _DWORD, int))(v14 + 632))("L1SHADOWPROJECT", 0, v17);
    a1[71] = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
               dword_FB27A4,
               "L1SHADOWPROJECTSTRIP",
               0);
  }
  else
  {
    v12 = *(_DWORD *)dword_FB27A4;
    if ( (*a1 & 0x100) == 0 )
    {
      a1[70] = (*(int (__stdcall **)(const char *))(v12 + 632))("L0SHADOWPROJECT");
      a1[71] = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
                 dword_FB27A4,
                 "L0SHADOWPROJECTSTRIP",
                 0);
      v13 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
              dword_FB27A4,
              "L0SHADOWPROJECTBUMPSTRIP",
              0);
      goto LABEL_14;
    }
    a1[70] = (*(int (__stdcall **)(const char *, _DWORD, int))(v12 + 632))("L0PROJECTSTRIP", 0, v17);
  }
  v13 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 632))(dword_FB27A4);
LABEL_14:
  a1[72] = v13;
  if ( (v11 & 0x200) != 0 )
    a1[10] = *(_DWORD *)(a1[75] + 592);
  else
    a1[10] = *(_DWORD *)(a1[75] + 576);
  if ( sub_5FF600((int)a1, a2, a5, a6, a7, a8) )
    return -1;
  if ( (*a1 & 0x100) != 0 )
  {
    a1[44] = 32;
    a1[46] = (int)operator new(0x80u);
LABEL_20:
    v15 = sub_5F5CE0((__int32)a1, 1);
    a1[74] = v15;
    sub_5F5B90(v15);
    return 0;
  }
  if ( !sub_5FEA10(a1, 1, 0) )
    goto LABEL_20;
  return 16;
}
