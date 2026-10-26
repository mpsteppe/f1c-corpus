int __thiscall sub_552680(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // esi
  _DWORD *v8; // edi
  int result; // eax
  char v10; // [esp+0h] [ebp-8h]

  v2 = sub_5DA9A0("XPITIN", 0);
  this[569] = v2;
  if ( v2 )
  {
    sub_5DB5B0(-11, 2048);
  }
  else if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\steward.cpp", 4807) )
  {
    sub_561210((int)byte_FAE910, "No pit-in poly found", v10);
  }
  v3 = sub_5DA9A0("XPITOUT", 0);
  this[570] = v3;
  if ( v3 )
  {
    sub_5DB5B0(-25, 2048);
  }
  else if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\steward.cpp", 4813) )
  {
    sub_561210((int)byte_FAE910, "No pit-out poly found", v10);
  }
  v4 = sub_5DA9A0("XFINISH", 0);
  this[571] = v4;
  if ( v4 )
  {
    sub_5DB5B0(0, 2048);
  }
  else if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\steward.cpp", 4819) )
  {
    sub_561210((int)byte_FAE910, "No finish poly found", v10);
  }
  v5 = sub_5DA9A0("XSECTOR1", 0);
  this[572] = v5;
  if ( v5 )
  {
    sub_5DB5B0(1, 2048);
  }
  else if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\steward.cpp", 4825) )
  {
    sub_561210((int)byte_FAE910, "No sector 1 poly found", v10);
  }
  v6 = sub_5DA9A0("XSECTOR2", 0);
  this[573] = v6;
  if ( v6 )
  {
    sub_5DB5B0(2, 2048);
  }
  else if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\steward.cpp", 4831) )
  {
    sub_561210((int)byte_FAE910, "No sector 2 poly found", v10);
  }
  v7 = 0;
  v8 = this + 574;
  do
  {
    result = sub_5DA9A0(off_9039C8[v7], 0);
    *v8 = result;
    if ( result )
      result = sub_5DB5B0(v7 + 100, 2048);
    ++v7;
    ++v8;
  }
  while ( v7 < 18 );
  return result;
}
