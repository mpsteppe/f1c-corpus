// f1c  0x00492030  size=124
int __thiscall sub_492030(_DWORD *this)
{
  int v2; // edi

  v2 = 1;
  if ( sub_491FB0(this) )
  {
    while ( !sub_587C20(&unk_7CDB70, asc_5CC4F8) && sub_491FB0(this) )
      ;
  }
  do
  {
    if ( !sub_491FB0(this) )
      break;
    if ( sub_587C20(&unk_7CDB70, asc_5CC4F8) )
      ++v2;
    if ( sub_587C20(&unk_7CDB70, asc_5CC4F4) )
      --v2;
  }
  while ( v2 >= 1 );
  --this[101];
  return 0;
}
