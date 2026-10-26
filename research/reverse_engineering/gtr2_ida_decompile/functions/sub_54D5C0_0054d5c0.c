char __thiscall sub_54D5C0(_DWORD *this, const char *ArgList, int a3, int a4, int a5)
{
  int v6; // eax
  int *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  _DWORD ***v12; // eax
  _DWORD **v13; // eax
  _DWORD *v14; // eax
  char v15; // bl
  int v16; // eax
  int v17; // eax
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  char *v21; // edi
  int v22; // eax
  char v23; // [esp-Ch] [ebp-54h]
  const char *v24; // [esp+0h] [ebp-48h] BYREF
  int v25; // [esp+4h] [ebp-44h] BYREF
  int v26; // [esp+Ch] [ebp-3Ch] BYREF
  char v27; // [esp+14h] [ebp-34h]
  int v28; // [esp+2Ch] [ebp-1Ch]
  int v29; // [esp+30h] [ebp-18h]
  int v30; // [esp+38h] [ebp-10h]
  char v31[4]; // [esp+44h] [ebp-4h]

  v6 = sub_5DA9A0("FPDRIVER", ArgList);
  this[8] = v6;
  if ( !v6 )
  {
    if ( dword_B640C0 != 5 )
    {
      if ( (unsigned __int8)sub_5612D0(
                              (int)byte_FAE910,
                              1,
                              "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                              543) )
        sub_561210((int)byte_FAE910, "First person driver instance not found.", v27);
    }
    return 0;
  }
  if ( *(_DWORD *)(v6 + 544) != 1 )
  {
    if ( dword_B640C0 != 5
      && (unsigned __int8)sub_5612D0(
                            (int)byte_FAE910,
                            1,
                            "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                            549) )
    {
      sub_561210(
        (int)byte_FAE910,
        "First person driver file has %i meshes, only one allowed.",
        *(_DWORD *)(this[8] + 544));
    }
    return 0;
  }
  if ( *(int *)(v6 + 544) > 0 && (v8 = *(int **)(v6 + 532)) != 0 )
    v9 = *v8;
  else
    v9 = 0;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_FB27A4 + 400))(dword_FB27A4, v9);
  v10 = this[8];
  v11 = *(_DWORD *)(v10 + 544);
  v12 = (_DWORD ***)(v10 + 532);
  if ( v11 > 0 && (v13 = *v12) != 0 )
    v14 = *v13;
  else
    v14 = 0;
  *v14 |= 0x20000000u;
  sub_5DCFF0(this[8], 1);
  v15 = (char)ArgList;
  v16 = sub_408CB0((char *)dword_91BE2C, ArgList, 0);
  this[12] = v16;
  if ( !v16 )
  {
    if ( dword_B640C0 != 5 )
    {
      v25 = 563;
      goto LABEL_22;
    }
    return 0;
  }
  v25 = this[8];
  if ( (unsigned __int8)((int (__thiscall *)(int))unk_4070A0)(v16) )
  {
    v15 = (char)ArgList;
    v24 = ArgList;
    v17 = sub_408F00();
    this[13] = v17;
    if ( v17 )
    {
      sub_5BFC10(&v26);
      v18 = this[12];
      v26 = 0;
      v19 = *(_DWORD *)(v18 + 8);
      v30 = 0;
      v20 = sub_5BBFE0(v19);
      this[14] = v20;
      if ( v20 )
      {
        v21 = *(char **)v31;
        v23 = v31[0];
        *(double *)v20 = *(float *)(*(_DWORD *)(v20 + 60) + 20) * 0.5;
        *(_BYTE *)(this[14] + 80) = 1;
        v22 = sub_408F00();
        this[15] = v22;
        if ( v22 )
        {
          v28 = -1;
          nullsub_7(&v24);
          return 1;
        }
        if ( dword_B640C0 != 5
          && (unsigned __int8)sub_5612D0(
                                (int)byte_FAE910,
                                1,
                                "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                                599) )
        {
          sub_561210((int)byte_FAE910, v21, v23);
        }
      }
      else if ( dword_B640C0 != 5
             && (unsigned __int8)sub_5612D0(
                                   (int)byte_FAE910,
                                   1,
                                   "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                                   588) )
      {
        sub_561210((int)byte_FAE910, "Error playing motion %s.", (char)ArgList);
      }
      v29 = -1;
      nullsub_7(&v25);
    }
    else if ( dword_B640C0 != 5 )
    {
LABEL_22:
      if ( (unsigned __int8)sub_5612D0(
                              (int)byte_FAE910,
                              1,
                              "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                              v25) )
      {
        sub_561210((int)byte_FAE910, "Error loading %s.", v15);
        return 0;
      }
    }
    return 0;
  }
  if ( dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0(
                          (int)byte_FAE910,
                          1,
                          "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                          569) )
  {
    sub_561210((int)byte_FAE910, "Error in %s.", (char)ArgList);
  }
  sub_408A90(this + 12);
  return off_16C94C8(v29, ArgList, a3, a4, a5);
}
