int __thiscall sub_4B8C00(int this)
{
  *(_WORD *)(this + 840) = 4 * (unsigned __int64)dword_B65F7C[*(_DWORD *)(this + 844)];
  if ( !byte_B65C78 )
    sub_434BB0();
  sub_409FB0((_DWORD *)(this + 52));
  switch ( *(_DWORD *)(this + 844) )
  {
    case 0:
      sub_4D3CF0("MAXIMUM SPEED", -1);
      sub_4D3CF0("SPEED", -1);
      sub_4D3CF0("BALANCED", -1);
      sub_4D3CF0("GRIP", -1);
      sub_4D3CF0("MAXIMUM GRIP", -1);
      break;
    case 1:
      sub_4D3CF0("MAXIMUM UNDERSTEER", -1);
      sub_4D3CF0("UNDERSTEER", -1);
      sub_4D3CF0("BALANCED", -1);
      sub_4D3CF0("OVERSTEER", -1);
      sub_4D3CF0("MAXIMUM OVERSTEER", -1);
      break;
    case 2:
      sub_4D3CF0("VERY SOFT", -1);
      sub_4D3CF0("SOFT", -1);
      sub_4D3CF0("BALANCED", -1);
      sub_4D3CF0("STIFF", -1);
      sub_4D3CF0("VERY STIFF", -1);
      break;
    case 3:
      sub_4D3CF0("MAXIMUM ACCELERATION", -1);
      sub_4D3CF0("ACCELERATION", -1);
      sub_4D3CF0("BALANCED", -1);
      sub_4D3CF0("SPEED", -1);
      sub_4D3CF0("MAXIMUM SPEED", -1);
      break;
    default:
      break;
  }
  sub_4D3CF0("CUSTOM", -1);
  return 0;
}
