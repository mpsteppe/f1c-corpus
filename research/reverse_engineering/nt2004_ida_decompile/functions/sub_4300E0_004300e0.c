int __thiscall sub_4300E0(_DWORD *this)
{
  int v1; // eax
  char v2; // bl
  char v3; // si

  *this = 5;
  while ( 1 )
  {
    sub_5278E0(&unk_7DA938);
    if ( (unsigned __int8)sub_4634F0(&unk_764D70) )
    {
      v2 = 1;
      goto LABEL_4;
    }
    v1 = sub_4BACD0(&unk_76612C);
    v2 = byte_76617C;
    v3 = v1;
    if ( v1 != 5 )
      break;
LABEL_4:
    sub_4DA510(&dword_7D5DA4);
    sub_465B70(&unk_764D70);
    sub_4DA4E0(&dword_7D5DA4);
    sub_4D1940(&dword_76BC30);
    sub_4BF240(&unk_766318);
    sub_404B10((int)&flt_628F60);
    nullsub_6(&unk_76BC2C);
    sub_4FCB50(&unk_7D7428);
    sub_458570(&ppvOut);
    sub_42E720(&unk_62BF64);
    sub_4D19A0(&dword_79FC40);
    sub_466310(&unk_764D70);
    sub_465BA0(&unk_764D70);
    sub_4DABE0(&dword_7D5DA4);
    sub_4D1940(&dword_79FC40);
    if ( v2 )
    {
      if ( !(unsigned __int8)sub_4634F0(&unk_764D70) )
        sub_4F78B0(&unk_7D73D0);
    }
    else
    {
      sub_40C3D0(&dword_6291CC);
      sub_4F78B0(&unk_7D73D0);
      sub_4D2430(&unk_7D4458);
      sub_4B7AB0(&dword_765E70);
    }
    sub_527910(&unk_7DA938);
    sub_4F0020(&byte_7D6B78);
    sub_4197A0(&unk_629328, 0);
    sub_528430(&unk_7DA938);
    sub_4E9780(&unk_7D6B5C);
    sub_52B1D0(&unk_7DAAE0);
    sub_4BB880(&unk_7661CC);
    if ( (unsigned __int8)sub_4634F0(&unk_764D70) )
      return 0;
  }
  if ( v1 == 4 )
    return 0;
  if ( v1 != 6 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_2, 845) )
    sub_500FE0((int)&unk_7D7920, aNextStateDWasN, v3);
  return 1;
}
