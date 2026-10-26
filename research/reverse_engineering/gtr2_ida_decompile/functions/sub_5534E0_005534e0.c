int __thiscall sub_5534E0(_DWORD *this)
{
  int v2; // ecx
  int v3; // eax
  char v5; // [esp+14h] [ebp-28h]
  unsigned __int8 v6[13]; // [esp+17h] [ebp-25h] BYREF
  _BYTE v7[4]; // [esp+24h] [ebp-18h] BYREF
  _BYTE v8[4]; // [esp+28h] [ebp-14h] BYREF
  _BYTE v9[16]; // [esp+2Ch] [ebp-10h] BYREF

  if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\steward.cpp", 4845) )
    sub_561210((int)byte_FAE910, "Entered Steward::Init()", v5);
  sub_54FD20((int)"STLITE", (int)"STGLOW");
  sub_54FD20((int)"PTLIT02", (int)"PTGLOW02");
  sub_54FD20((int)"PTLIT01", (int)"PTGLOW01");
  v2 = this[79];
  this[81] = 0;
  if ( v2 )
  {
    sub_5DA840(v7, v8, v9, 0);
    v3 = sub_4031C0();
    if ( v3 )
      this[81] = *(_DWORD *)(v3 + 76);
  }
  sub_552680(this);
  switch ( *(_DWORD *)dword_B72314 )
  {
    case 1:
    case 7:
      sub_430F70(&dword_B640C0, 0);
      break;
    case 2:
      sub_430F70(&dword_B640C0, 6);
      break;
    case 3:
      if ( byte_B6FEBC == 1 || byte_B722E4 )
        goto LABEL_21;
      goto LABEL_11;
    case 5:
      v6[0] = 1;
      sub_478D00(byte_B6FEA8, v6);
      if ( byte_B6FEBC == 1 )
      {
LABEL_21:
        sub_430F70(&dword_B640C0, 1);
      }
      else
      {
LABEL_11:
        if ( byte_B6FED4 == 1 )
        {
          sub_430F70(&dword_B640C0, 2);
        }
        else if ( byte_B6FEEC == 1 )
        {
          sub_430F70(&dword_B640C0, 3);
        }
        else if ( byte_B6FF04 == 1 )
        {
          sub_430F70(&dword_B640C0, 4);
        }
        else if ( byte_B6FF1C == 1 )
        {
          sub_430F70(&dword_B640C0, 5);
        }
        else
        {
          sub_430F70(&dword_B640C0, 6);
        }
      }
      break;
    case 8:
      sub_430F70(&dword_B640C0, 0);
      dword_757C10 = 1;
      sub_42CC30(&unk_920488);
      break;
    default:
      return off_16C9664();
  }
  return off_16C9664();
}
