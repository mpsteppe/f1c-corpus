char __userpurge sub_54CD40@<al>(_DWORD *a1@<ecx>, int a2@<ebp>, int a3, const char *ArgList, int a5, int a6, int a7)
{
  int v8; // eax
  char v10; // bp
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  int v17; // eax
  const char *v18; // [esp+0h] [ebp-44h] BYREF
  int v19; // [esp+4h] [ebp-40h] BYREF
  int v20; // [esp+Ch] [ebp-38h] BYREF
  char v21; // [esp+10h] [ebp-34h]
  int v22; // [esp+2Ch] [ebp-18h]
  int v23; // [esp+30h] [ebp-14h]
  int v24; // [esp+38h] [ebp-Ch]
  char *retaddr; // [esp+44h] [ebp+0h]

  v8 = sub_5DA9A0("EXTDRIVERBODY", a3);
  a1[9] = v8;
  if ( !v8 )
  {
    if ( dword_B640C0 != 5 )
    {
      if ( (unsigned __int8)sub_5612D0(
                              (int)byte_FAE910,
                              1,
                              "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                              613) )
        sub_561210((int)byte_FAE910, "External driver body instance not found.", v21);
    }
    return 0;
  }
  v20 = a2;
  v10 = (char)ArgList;
  v11 = sub_408CB0((char *)dword_91BE2C, ArgList, 0);
  a1[52] = v11;
  if ( !v11 )
  {
    if ( dword_B640C0 != 5 )
    {
      v19 = 621;
      goto LABEL_9;
    }
    return 0;
  }
  v19 = a1[9];
  if ( (unsigned __int8)((int (__thiscall *)(int))unk_4070A0)(v11) )
  {
    v10 = (char)ArgList;
    v18 = ArgList;
    v12 = sub_408F00();
    a1[53] = v12;
    if ( !v12 )
    {
      if ( dword_B640C0 != 5 )
      {
LABEL_9:
        if ( (unsigned __int8)sub_5612D0(
                                (int)byte_FAE910,
                                1,
                                "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                                v19) )
        {
          sub_561210((int)byte_FAE910, "Error loading %s.", v10);
          return 0;
        }
      }
      return 0;
    }
    sub_5BFC10(&v20);
    v13 = a1[52];
    v20 = 0;
    v14 = *(_DWORD *)(v13 + 8);
    v15 = a1[53];
    v24 = 0;
    v16 = sub_5BBFE0(v14, v15, &v20);
    a1[54] = v16;
    if ( !v16 )
    {
      if ( dword_B640C0 != 5
        && (unsigned __int8)sub_5612D0(
                              (int)byte_FAE910,
                              1,
                              "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                              646) )
      {
        sub_561210((int)byte_FAE910, "Error playing motion %s.", (char)ArgList);
      }
LABEL_28:
      v23 = -1;
      nullsub_7(&v19);
      return 0;
    }
    *(double *)v16 = *(float *)(*(_DWORD *)(v16 + 60) + 20) * 0.5;
    *(_BYTE *)(a1[54] + 80) = 1;
    if ( (_BYTE)a3 )
    {
      v17 = sub_408F00();
      a1[55] = v17;
      if ( !v17 )
      {
        if ( dword_B640C0 != 5
          && (unsigned __int8)sub_5612D0(
                                (int)byte_FAE910,
                                1,
                                "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                                660) )
        {
          sub_561210((int)byte_FAE910, retaddr, (char)retaddr);
        }
        goto LABEL_28;
      }
    }
    else
    {
      a1[55] = 0;
    }
    v22 = -1;
    nullsub_7(&v18);
    return 1;
  }
  if ( dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0(
                          (int)byte_FAE910,
                          1,
                          "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                          627) )
  {
    sub_561210((int)byte_FAE910, "Error in %s.", (char)ArgList);
  }
  sub_408A90(a1 + 52);
  return off_16C9668(v23, a3, ArgList, a5, a6, a7);
}
