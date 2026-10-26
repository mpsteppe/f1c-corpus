int __thiscall sub_486330(int this)
{
  int result; // eax

  sub_46FBE0((_DWORD *)this);
  dword_7693D4 = **(_DWORD **)(this + 840);
  if ( dword_7693D4 >= dword_7693DC )
  {
    if ( dword_7693D4 > dword_7693E0 )
      dword_7693D4 = dword_7693E0;
  }
  else
  {
    dword_7693D4 = dword_7693DC;
  }
  dword_76941C = **(_DWORD **)(this + 840);
  if ( dword_76941C >= dword_769424 )
  {
    if ( dword_76941C > dword_769428 )
      dword_76941C = dword_769428;
  }
  else
  {
    dword_76941C = dword_769424;
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
