int __thiscall sub_497940(_DWORD *this, int a2, int a3)
{
  int v4; // eax

  if ( a2 && (v4 = UIListSearchByName_76c0(this, a2)) != 0 )
    return UtilityFunction_7890((int)this, v4, a3);
  else
    return 0;
}

