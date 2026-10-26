void __thiscall sub_479360(_DWORD *this, int ArgList)
{
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  char v6; // bl
  int v7; // eax
  char v8; // [esp+0h] [ebp-220h]
  _BYTE v9[4]; // [esp+Ch] [ebp-214h] BYREF
  _DWORD v10[128]; // [esp+10h] [ebp-210h] BYREF
  char v11; // [esp+210h] [ebp-10h]
  char v12; // [esp+211h] [ebp-Fh]
  char v13; // [esp+212h] [ebp-Eh]
  char v14; // [esp+21Ch] [ebp-4h]

  sub_4733E0(v10);
  sub_59B5C0(v10, 528, v9);
  v14 = v14 & 0xF9 | 2;
  if ( dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 4953) )
  {
    sub_561210((int)byte_FAE910, "NetComm::SetSelfAsReady(): Setting self as ready", v8);
  }
  v12 = dword_B7321C;
  switch ( v10[0] )
  {
    case 0:
    case 1:
      goto LABEL_23;
    case 2:
      if ( dword_923E84[5654 * v11] == 2 )
      {
        sub_42C8E0(v11);
        sub_42C8A0(v11);
      }
LABEL_23:
      v7 = this[28332];
      if ( v7 == 2 || v7 == 1 )
      {
        v14 |= 1u;
        if ( dword_B640C0 != 5 )
        {
          if ( (unsigned __int8)sub_5612D0(
                                  (int)byte_FAE910,
                                  1,
                                  "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp",
                                  5012) )
            sub_561210((int)byte_FAE910, "NetComm::SetSelfAsReady(): Setting self as non-participant server node", v8);
        }
      }
      break;
    case 3:
      v3 = this[28332];
      if ( v3 == 2 || v3 == 1 )
      {
        if ( v11 == -1 )
        {
          v4 = sub_473390();
          v5 = this[28329];
          v6 = v4;
          v11 = v4;
          v13 = v4;
          this[v4 + 424] = sub_59B580(v5);
          if ( dword_B640C0 != 5 )
          {
            if ( (unsigned __int8)sub_5612D0(
                                    (int)byte_FAE910,
                                    1,
                                    "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp",
                                    4972) )
              sub_561210((int)byte_FAE910, "NetComm::SetSelfAsReady(): Setting self as slot %d", v6);
          }
        }
        v14 |= 1u;
        if ( dword_B640C0 != 5
          && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 4976) )
        {
          sub_561210((int)byte_FAE910, "NetComm::SetSelfAsReady(): Setting self as server node", v8);
        }
      }
      else if ( ArgList == -1 )
      {
        if ( dword_B640C0 != 5
          && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 4996) )
        {
          sub_561210(
            (int)byte_FAE910,
            "NetComm::SetSelfAsReady(): UNKNOWN NODE ID passed back from server.  No need to set slot",
            v8);
        }
      }
      else
      {
        sub_478FC0(this, ArgList);
        v11 = ArgList;
        v13 = ArgList;
        if ( dword_B640C0 != 5
          && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 4989) )
        {
          sub_561210((int)byte_FAE910, "NetComm::SetSelfAsReady(): Setting self as slot %d", ArgList);
        }
      }
      break;
    default:
      break;
  }
  if ( !sub_59B5A0(v10, 528) )
    sub_42CB90();
}
