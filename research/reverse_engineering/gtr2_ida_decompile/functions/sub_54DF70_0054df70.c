char __userpurge sub_54DF70@<al>(int a1@<ecx>, int a2@<ebx>, int a3@<edi>, char a4, float *a5)
{
  const char *v6; // ebp
  char result; // al
  int v8; // eax
  int v9; // edi
  int v10; // ebx
  int v11; // ebp
  int v12; // edi
  int v13; // eax
  int v14; // eax
  void (__thiscall ***v15)(_DWORD); // ecx
  float v16; // eax
  double v17; // st7
  double v18; // st6
  char v19; // [esp-Ch] [ebp-5Ch]
  float v20; // [esp+0h] [ebp-50h] BYREF
  float v21; // [esp+4h] [ebp-4Ch] BYREF
  float v22; // [esp+8h] [ebp-48h] BYREF
  float v23; // [esp+20h] [ebp-30h]
  int v24; // [esp+24h] [ebp-2Ch]
  char v25[4]; // [esp+28h] [ebp-28h]
  int v26; // [esp+2Ch] [ebp-24h]
  int v27; // [esp+30h] [ebp-20h]
  const char *v28; // [esp+34h] [ebp-1Ch]
  void *v29; // [esp+38h] [ebp-18h]
  int v30; // [esp+40h] [ebp-10h]
  void *v31; // [esp+48h] [ebp-8h]
  char ArgList[4]; // [esp+4Ch] [ebp-4h]
  void *retaddr; // [esp+50h] [ebp+0h]
  const char *v34; // [esp+54h] [ebp+4h]

  if ( a4 )
  {
    v6 = "Bip01 R UpperArm";
    v34 = "Bip01 R Forearm";
    v28 = "Bip01 R Hand";
  }
  else
  {
    v6 = "Bip01 L UpperArm";
    v34 = "Bip01 L Forearm";
    v28 = "Bip01 L Hand";
  }
  if ( *a5 != 0.0 || a5[1] != 0.0 || a5[2] != 0.0 )
  {
    v8 = *(_DWORD *)(a1 + 48);
    *(_DWORD *)v25 = a2;
    v24 = a3;
    v9 = *(_DWORD *)(v8 + 8);
    v10 = ((int (__thiscall *)(int, const char *, int))loc_405290)(v9, v6, v24);
    if ( !v10 )
      return off_16C9864(v34, a5);
    v11 = ((int (__thiscall *)(int, void *))loc_405290)(v9, retaddr);
    if ( v11 )
    {
      v12 = ((int (__thiscall *)(int, int))loc_405290)(v9, v26);
      if ( v12 )
      {
        v31 = operator new(0x38u);
        v30 = 0;
        if ( v31 )
          v13 = sub_5C15B0(*(_DWORD *)(*(_DWORD *)(a1 + 48) + 8), v10, v11, v12);
        else
          v13 = 0;
        v27 = -1;
        *(_DWORD *)(a1 + 68) = v13;
        if ( v13 )
        {
          v29 = operator new(0x24u);
          v27 = 1;
          if ( v29 )
          {
            v21 = *(float *)(a1 + 68);
            LODWORD(v20) = a1 + 64;
            v14 = sub_53E0E0();
          }
          else
          {
            v14 = 0;
          }
          v23 = NAN;
          *(_DWORD *)(a1 + 72) = v14;
          if ( v14 )
          {
            sub_4F80B0();
            sub_4F80B0();
            (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a1 + 68) + 20))(*(_DWORD *)(a1 + 68), 0);
            v16 = v23;
            *(_DWORD *)(a1 + 232) = *(_DWORD *)LODWORD(v23);
            *(_DWORD *)(a1 + 236) = *(_DWORD *)(LODWORD(v16) + 4);
            *(_DWORD *)(a1 + 240) = *(_DWORD *)(LODWORD(v16) + 8);
            sub_5DA7A0(&v20, &v21, &v22);
            v17 = *(float *)(a1 + 240) - v22;
            result = 1;
            v18 = *(float *)(a1 + 236) - v21;
            *(float *)(a1 + 244) = *(float *)(a1 + 232) - v20;
            *(float *)(a1 + 248) = v18;
            *(float *)(a1 + 252) = v17;
            return result;
          }
          v15 = *(void (__thiscall ****)(_DWORD))(a1 + 68);
          if ( v15 )
          {
            v19 = 1;
            (**v15)(v15);
          }
          *(_DWORD *)(a1 + 68) = 0;
          if ( dword_B640C0 != 5
            && (unsigned __int8)sub_5612D0(
                                  (int)byte_FAE910,
                                  1,
                                  "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                                  751) )
          {
            sub_561210((int)byte_FAE910, "Failed to create shifting controller", v19);
          }
        }
        else if ( dword_B640C0 != 5
               && (unsigned __int8)sub_5612D0(
                                     (int)byte_FAE910,
                                     1,
                                     "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                                     741) )
        {
          sub_561210((int)byte_FAE910, "Failed to create shifting IK solver", SLOBYTE(v22));
          return 0;
        }
        return 0;
      }
      if ( dword_B640C0 != 5
        && (unsigned __int8)sub_5612D0(
                              (int)byte_FAE910,
                              1,
                              "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                              734) )
      {
        sub_561210((int)byte_FAE910, "Hand node, %s, not found", v25[0]);
      }
    }
    else if ( dword_B640C0 != 5
           && (unsigned __int8)sub_5612D0(
                                 (int)byte_FAE910,
                                 1,
                                 "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                                 727) )
    {
      sub_561210((int)byte_FAE910, "Elbow node, %s, not found", ArgList[0]);
      return 0;
    }
    return 0;
  }
  if ( dword_B640C0 != 5 )
  {
    if ( (unsigned __int8)sub_5612D0(
                            (int)byte_FAE910,
                            1,
                            "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                            713) )
      sub_561210((int)byte_FAE910, "ShiftStickPosition not set in *.CAR file", v26);
  }
  return 0;
}
