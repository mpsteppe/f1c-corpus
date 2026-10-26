int __thiscall sub_4CEA30(void *this)
{
  char v3; // [esp+0h] [ebp-4h]

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_13, 2637) )
    sub_500FE0((int)&unk_7D7920, aEnteredPlayerf_0, v3);
  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_13, 2651) )
    sub_500FE0((int)&unk_7D7920, aAboutToSavePlr, v3);
  if ( sub_4CDC80((int)this, 1) )
    return 1;
  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_13, 2656) )
    sub_500FE0((int)&unk_7D7920, aSaveCompleteAb, v3);
  if ( sub_4CDA20((int)this, 1) )
    return 1;
  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_13, 2661) )
    sub_500FE0((int)&unk_7D7920, aLoadComplete, v3);
  return 0;
}
