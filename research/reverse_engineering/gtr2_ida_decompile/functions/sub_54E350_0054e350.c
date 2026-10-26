void __userpurge sub_54E350(__int32 a1@<ecx>, __int32 a2@<ebx>, int a3@<edi>, float a4, float a5)
{
  unsigned int v5; // kr00_4
  __int32 v6; // esi
  __int32 v7; // esi
  int v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // edi
  int v14; // eax
  int v15; // eax
  void (__thiscall ***v16)(_DWORD, int); // ecx
  int v17; // edi
  int v18; // eax
  void (__thiscall ***v19)(_DWORD, int); // ecx
  void (__thiscall ***v20)(_DWORD, int); // ecx
  int v21; // edi
  int v22; // eax
  void (__thiscall ***v23)(_DWORD, int); // ecx
  void (__thiscall ***v24)(_DWORD, int); // ecx
  void (__thiscall ***v25)(_DWORD, int); // ecx
  long double v26; // st7
  int v27; // edx
  int v28; // edx
  int v29; // eax
  long double v30; // st7
  int v31; // ecx
  int v32; // ecx
  int v33; // edx
  float v34; // [esp+0h] [ebp-48h]
  float v35; // [esp+0h] [ebp-48h]
  int v36; // [esp+4h] [ebp-44h]
  __int32 v37[3]; // [esp+8h] [ebp-40h] BYREF
  void *v38; // [esp+14h] [ebp-34h]
  float v39; // [esp+18h] [ebp-30h] BYREF
  float v40; // [esp+1Ch] [ebp-2Ch] BYREF
  float v41; // [esp+20h] [ebp-28h] BYREF
  float v42; // [esp+24h] [ebp-24h] BYREF
  float v43; // [esp+28h] [ebp-20h]
  float v44; // [esp+2Ch] [ebp-1Ch]
  float v45[3]; // [esp+30h] [ebp-18h] BYREF
  int v46; // [esp+44h] [ebp-4h]

  v7 = a1;
  if ( *(_DWORD *)(a1 + 32) && *(_DWORD *)(a1 + 48) )
  {
    v37[0] = a2;
    v36 = a3;
    sub_5DA7A0(&v39, &v40, &v41);
    v38 = operator new(0x38u);
    v46 = 0;
    if ( v38 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)(v7 + 48) + 8);
      v9 = ((int (__thiscall *)(int, const char *))loc_405290)(v8, "Bip01 R Foot");
      v10 = ((int (__thiscall *)(int, const char *, int))loc_405290)(v8, "Bip01 R Calf", v9);
      v11 = ((int (__thiscall *)(int, const char *, int))loc_405290)(v8, "Bip01 R Thigh", v10);
      v12 = sub_5C15B0(v8, v11, v36, v37[0]);
    }
    else
    {
      v12 = 0;
    }
    v46 = -1;
    *(_DWORD *)(v7 + 84) = v12;
    if ( v12 )
    {
      v38 = operator new(0x38u);
      v46 = 1;
      if ( v38 )
      {
        v13 = *(_DWORD *)(*(_DWORD *)(v7 + 48) + 8);
        v37[1] = ((int (__thiscall *)(int, const char *))loc_405290)(v13, "Bip01 L Foot");
        v37[0] = v7;
        v5 = __readeflags();
        v6 = __ROL4__(dword_16C6CE8, 108);
        __writeeflags(v5);
        v7 = _InterlockedExchange(v37, v6);
        v37[0] = ((int (__thiscall *)(int))loc_405290)(v13);
        v14 = ((int (__thiscall *)(int))loc_405290)(v13);
        v15 = sub_5C15B0(v13, v14, "Bip01 L Thigh", v37[0]);
      }
      else
      {
        v15 = 0;
      }
      v46 = -1;
      *(_DWORD *)(v7 + 88) = v15;
      if ( v15 )
      {
        v38 = operator new(0x18u);
        v46 = 2;
        if ( v38 )
        {
          v17 = *(_DWORD *)(*(_DWORD *)(v7 + 48) + 8);
          v34 = 0.017453292 * -5.0;
          v37[0] = ((int (__thiscall *)(int, const char *, __int32, _DWORD))loc_405290)(
                     v17,
                     "Bip01 R Foot",
                     v7 + 128,
                     LODWORD(v34));
          LOBYTE(v36) = v17;
          v18 = sub_42FB10();
        }
        else
        {
          v18 = 0;
        }
        v46 = -1;
        *(_DWORD *)(v7 + 76) = v18;
        if ( v18 )
        {
          v38 = operator new(0x18u);
          v46 = 3;
          if ( v38 )
          {
            v21 = *(_DWORD *)(*(_DWORD *)(v7 + 48) + 8);
            v35 = 0.017453292 * -20.0;
            v37[0] = ((int (__thiscall *)(int, const char *, __int32, _DWORD))loc_405290)(
                       v21,
                       "Bip01 L Foot",
                       v7 + 132,
                       LODWORD(v35));
            LOBYTE(v36) = v21;
            v22 = sub_42FB10();
          }
          else
          {
            v22 = 0;
          }
          v23 = *(void (__thiscall ****)(_DWORD, int))(v7 + 84);
          v46 = -1;
          *(_DWORD *)(v7 + 80) = v22;
          if ( v22 )
          {
            v26 = 0.017453292 * a5;
            v44 = 0.0;
            v42 = sin(v26);
            v43 = cos(v26);
            sub_5C1640(&v42);
            v42 = *(float *)(v7 + 136) - v39;
            v43 = *(float *)(v7 + 140) - v40;
            v44 = *(float *)(v7 + 144) - v41;
            sub_5C1620(&v42);
            sub_4F80B0();
            *(_DWORD *)(v7 + 160) = *(_DWORD *)(v7 + 116);
            v27 = *(_DWORD *)(v7 + 124);
            *(_DWORD *)(v7 + 164) = *(_DWORD *)(v7 + 120);
            *(_DWORD *)(v7 + 168) = v27;
            v28 = *(_DWORD *)(v7 + 120);
            v29 = *(_DWORD *)(v7 + 124);
            *(_DWORD *)(v7 + 136) = *(_DWORD *)(v7 + 116);
            *(_DWORD *)(v7 + 140) = v28;
            *(_DWORD *)(v7 + 144) = v29;
            v30 = 0.017453292 * a4;
            v44 = 0.0;
            v42 = sin(v30);
            v43 = cos(v30);
            sub_5C1640(&v42);
            v45[0] = *(float *)(v7 + 148) - v39;
            v45[1] = *(float *)(v7 + 152) - v40;
            v45[2] = *(float *)(v7 + 156) - v41;
            sub_5C1620(v45);
            sub_4F80B0();
            *(_DWORD *)(v7 + 172) = *(_DWORD *)(v7 + 92);
            v31 = *(_DWORD *)(v7 + 100);
            *(_DWORD *)(v7 + 176) = *(_DWORD *)(v7 + 96);
            *(_DWORD *)(v7 + 180) = v31;
            v32 = *(_DWORD *)(v7 + 96);
            *(_DWORD *)(v7 + 148) = *(_DWORD *)(v7 + 92);
            v33 = *(_DWORD *)(v7 + 100);
            *(_DWORD *)(v7 + 152) = v32;
            *(_DWORD *)(v7 + 156) = v33;
            sub_4F80B0();
            sub_4F80B0();
            *(_DWORD *)(v7 + 128) = 0;
            *(_DWORD *)(v7 + 132) = 0;
            *(_DWORD *)(v7 + 28) = 0;
            *(_DWORD *)(v7 + 24) = 0;
            *(_DWORD *)(v7 + 184) = 2;
            *(_DWORD *)(v7 + 188) = 0;
            *(_DWORD *)(v7 + 192) = -1130113270;
            *(_DWORD *)(v7 + 196) = 1017370378;
          }
          else
          {
            if ( v23 )
              (**v23)(v23, 1);
            v24 = *(void (__thiscall ****)(_DWORD, int))(v7 + 88);
            *(_DWORD *)(v7 + 84) = 0;
            if ( v24 )
              (**v24)(v24, 1);
            v25 = *(void (__thiscall ****)(_DWORD, int))(v7 + 76);
            *(_DWORD *)(v7 + 88) = 0;
            if ( v25 )
              (**v25)(v25, 1);
            *(_DWORD *)(v7 + 76) = 0;
            if ( dword_B640C0 != 5
              && (unsigned __int8)sub_5612D0(
                                    (int)byte_FAE910,
                                    1,
                                    "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                                    816) )
            {
              sub_561210((int)byte_FAE910, "Failed to create left foot controller", v36);
            }
          }
        }
        else
        {
          v19 = *(void (__thiscall ****)(_DWORD, int))(v7 + 84);
          if ( v19 )
            (**v19)(v19, 1);
          v20 = *(void (__thiscall ****)(_DWORD, int))(v7 + 88);
          *(_DWORD *)(v7 + 84) = 0;
          if ( v20 )
            (**v20)(v20, 1);
          *(_DWORD *)(v7 + 88) = 0;
          if ( dword_B640C0 != 5
            && (unsigned __int8)sub_5612D0(
                                  (int)byte_FAE910,
                                  1,
                                  "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                                  803) )
          {
            sub_561210((int)byte_FAE910, "Failed to create right foot controller", v36);
          }
        }
      }
      else
      {
        v16 = *(void (__thiscall ****)(_DWORD, int))(v7 + 84);
        if ( v16 )
          (**v16)(v16, 1);
        *(_DWORD *)(v7 + 84) = 0;
        if ( dword_B640C0 != 5
          && (unsigned __int8)sub_5612D0(
                                (int)byte_FAE910,
                                1,
                                "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                                791) )
        {
          sub_561210((int)byte_FAE910, "Failed to create left foot IK solver", v36);
        }
      }
    }
    else if ( dword_B640C0 != 5 )
    {
      if ( (unsigned __int8)sub_5612D0(
                              (int)byte_FAE910,
                              1,
                              "\\Dev\\Src\\Copperhead\\App\\Source\\SteeringAnimation.cpp",
                              781) )
        sub_561210((int)byte_FAE910, "Failed to create right foot IK solver", v36);
    }
  }
}
