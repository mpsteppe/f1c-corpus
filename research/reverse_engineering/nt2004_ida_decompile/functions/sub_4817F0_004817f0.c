int __thiscall sub_4817F0(int this)
{
  int result; // eax

  sub_46FBE0((_DWORD *)this);
  dword_766B90 = **(_DWORD **)(this + 840);
  if ( dword_766B90 >= dword_766B98 )
  {
    if ( dword_766B90 > dword_766B9C )
      dword_766B90 = dword_766B9C;
  }
  else
  {
    dword_766B90 = dword_766B98;
  }
  dword_766BD8 = **(_DWORD **)(this + 840);
  if ( dword_766BD8 >= dword_766BE0 )
  {
    if ( dword_766BD8 > dword_766BE4 )
      dword_766BD8 = dword_766BE4;
  }
  else
  {
    dword_766BD8 = dword_766BE0;
  }
  if ( *(_DWORD *)dword_7689CC == 4 )
  {
    result = dword_7683BC;
    dword_7683B4 = 0;
    if ( dword_7683BC <= 0 )
    {
      if ( dword_7683C0 < 0 )
        dword_7683B4 = dword_7683C0;
    }
    else
    {
      dword_7683B4 = dword_7683BC;
    }
  }
  else
  {
    result = dword_768410;
    dword_768408 = 0;
    if ( dword_768410 <= 0 )
    {
      if ( dword_768414 < 0 )
        dword_768408 = dword_768414;
    }
    else
    {
      dword_768408 = dword_768410;
    }
  }
  return result;
}
