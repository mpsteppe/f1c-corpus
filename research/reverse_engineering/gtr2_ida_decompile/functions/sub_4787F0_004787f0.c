char __thiscall sub_4787F0(_DWORD *this)
{
  int v2; // eax
  int v4; // [esp+4h] [ebp-158h]
  const CHAR *v5; // [esp+2Ch] [ebp-130h]
  char Buffer[4]; // [esp+34h] [ebp-128h] BYREF
  int v7; // [esp+150h] [ebp-Ch]

  if ( *(_BYTE *)(*this + 1416) )
  {
    v2 = dword_B7231C;
    *(_DWORD *)dword_B72314 = 5;
    if ( dword_B7231C > 5 || (v2 = dword_B72320, dword_B72320 < 5) )
      *(_DWORD *)dword_B72314 = v2;
    sub_59B690(*(_DWORD *)(*this + 113316));
    v5 = *(const CHAR **)(*this + 1684);
    if ( !v5 )
      v5 = WindowName;
    v4 = *this + 1418;
    if ( (unsigned __int8)sub_46B000() )
    {
      if ( sub_4E1810("AutoJoin Wait Page", 0) )
      {
        sub_617DB0(Buffer, v4, v5);
        v7 = 0;
        sub_617DF0(1);
        sub_617E70(Buffer);
        sub_41D840(&byte_91CC38, "Joining Session");
        return off_16C96FC(*this);
      }
      if ( dword_B640C0 != 5
        && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 8522) )
      {
        sub_561210((int)byte_FAE910, "Could not switch to AutoJoin wait page...  Autojoin was not attempted", v4);
        return 0;
      }
    }
    else if ( dword_B640C0 != 5
           && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 8528) )
    {
      sub_561210((int)byte_FAE910, "Could not autojoin session @ \"%s\"", *(_BYTE *)this - 118);
    }
  }
  return 0;
}
