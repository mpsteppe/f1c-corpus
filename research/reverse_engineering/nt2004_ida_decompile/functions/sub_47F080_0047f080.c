int sub_47F080()
{
  unsigned __int8 v1; // bl

  sub_419110(byte_6292D0);
  switch ( *(_DWORD *)dword_7689CC )
  {
    case 4:
      sub_4B9C10(&byte_766124);
      if ( sub_4E5CB0(&unk_76BB28) == 3 )
        sub_49D430(aChEndSeasonSum);
      else
        sub_49D430(aChampionshipMa);
      return -1;
    case 5:
      if ( sub_4634D0(dword_764D70) )
        sub_4AD720(a2003MultiHostM, 1);
      else
        sub_4AD720(a2003MultiClien, 1);
      return -1;
    case 8:
      v1 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 36))(dword_76BB24);
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 76))(dword_76BB24);
      if ( v1 < (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 52))(dword_76BB24) - 1 )
        sub_49D430(a2003CareerMain);
      else
        sub_49D430(a2003CareerPost);
      dword_608F60 = 3;
      return -1;
    default:
      sub_49D430(aMainMenu);
      dword_608F60 = 3;
      return -1;
  }
}
