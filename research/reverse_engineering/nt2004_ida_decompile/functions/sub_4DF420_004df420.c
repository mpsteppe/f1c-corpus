void __thiscall sub_4DF420(int *this, int ArgList)
{
  char Buffer[64]; // [esp+4h] [ebp-40h] BYREF

  this[3] -= ArgList;
  sub_4DC690(this, aLappedFieldUnd, 1, 0);
  if ( ArgList == 1 )
    sprintf(Buffer, a1LapAlsoDeduct);
  else
    sub_405480(Buffer, 0x3Fu, "%d Laps Also Deducted", ArgList);
  sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
}
