int __thiscall sub_42FCC0(_DWORD *this)
{
  char v3; // [esp+0h] [ebp-4h]

  *this = 1;
  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_2, 486) )
    sub_500FE0((int)&unk_7D7920, aEnteredGameEnt, v3);
  if ( sub_42FAB0(this) )
    return 1;
  if ( sub_527B50(&unk_7DA938) )
    return 1;
  sub_4F69B0(&unk_7D73D0);
  sub_42E110(&unk_62BF64);
  sub_4CE9E0(&unk_7663E0);
  if ( sub_4EFEF0(&byte_7D6B78) )
    return 1;
  if ( sub_458310(&ppvOut) )
    return 1;
  nullsub_6(&unk_76612C);
  nullsub_6(&dword_7D5DA4);
  sub_4B7960(&dword_765E70);
  nullsub_6(&unk_7D7428);
  sub_465D30(&unk_764D70);
  sub_4E9710(&unk_7D6B5C);
  return 0;
}
