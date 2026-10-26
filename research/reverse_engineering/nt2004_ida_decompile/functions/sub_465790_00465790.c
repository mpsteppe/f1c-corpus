char __thiscall sub_465790(void *this)
{
  char result; // al

  result = 0;
  if ( *(_BYTE *)(*(_DWORD *)this + 164) )
  {
    *(_DWORD *)dword_7689CC = 5;
    if ( dword_7689D4 <= 5 )
    {
      if ( dword_7689D8 < 5 )
        *(_DWORD *)dword_7689CC = dword_7689D8;
    }
    else
    {
      *(_DWORD *)dword_7689CC = dword_7689D4;
    }
    byte_769968 = 1;
    if ( (unsigned __int8)byte_76996A <= 1u )
      byte_769968 = byte_76996B != 0;
    else
      byte_769968 = byte_76996A;
    sub_56A650(*(_DWORD *)(*(_DWORD *)this + 6708));
    sub_4CE760(&unk_7663E0);
    if ( sub_4658A0(this) )
      sub_4AD720(aVehicleSelect, 1);
    else
      sub_4AD720(aMultiplayerCre, 1);
    return 1;
  }
  return result;
}
